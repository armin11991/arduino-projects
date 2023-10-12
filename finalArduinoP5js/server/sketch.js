let serial;
let latestData = "waiting for data";

let mensajeSaliente = 'H';
let puertoArduino = '/dev/tty.usbserial-10';
let datosEntrada = false;

let valorPote; //se declara ka variable que contendrá el valor del potenciometro
let valorSensorA; //se declara una variable random
let valorSensorB; //se declara una segunda variable random

var musica; //se declara la variable para la música de fondo

function preload() {
  musica = loadSound("song.mp3"); //se declara el archivo mp3 que contendrá la variable musica
  musica.play(); //se inicializa la música de fondo
  noLoop(); //se declara que solo suene una vez al inicio y inicie nuevamente en cada ciclo
}


//particula
// se declaran las características de la partícula
class Particle {
    // se declaran las coordenadas y el radio
    // se determina la velocidad de las partículas en ambos axis
      constructor(){
        this.x = random(0,windowWidth);
        this.y = random(0,windowHeight);
        this.r = random(1,8);
        this.xSpeed = random(-2,2);
        this.ySpeed = random(-1,1.5);
      }
    
    // se crea la partícula
      createParticle() {
        noStroke();
        fill('rgba(200,169,169,0.5)');
        ellipse(this.x,this.y,this.r);
      }
    
    // se ponen en movimiento las partículas
      moveParticle() {
        if(valorPote > 100 || valorPote > windowWidth)
          this.xSpeed*=-1;
        if(valorPote > 100 || valorPote > windowHeight)
          this.ySpeed*=-1;
        this.x+=this.xSpeed;
        this.y+=this.ySpeed;
      }
    
    // con esto se crean las líneas que conectan las partículas
    // se estabelece también la distancia que habrá entre las partículas 
      joinParticles(particles) {
        particles.forEach(element =>{
          let dis = dist(this.x,this.y,element.x,element.y);
          if(dis<85) {
            stroke(255);
            line(this.x,this.y,element.x,element.y);
          }
        });
      }
    }
    
    // en este array se añanden las partículas
    let particles = [];
    //con esto se terminan de establecer las características generales de las partículas y sus elementos


function setup() {

  createCanvas(windowWidth, windowHeight); //se crea un canvas con el ancho y alto de la ventana en que se abra
  
  //se declara el ciclo for de las partículas
  for(let i = 0;i<windowWidth/10;i++){
    particles.push(new Particle());
    }

 //se inicializa el puerto de conexión   

 serial = new p5.SerialPort();

 serial.list();
 serial.open(puertoArduino);

 serial.on('connected', serverConnected);

 serial.on('list', gotList);

 serial.on('data', gotData);

 serial.on('error', gotError);

 serial.on('open', gotOpen);

 serial.on('close', gotClose);

}

// parametros generales del puerto de conexión entre Arduino y P5js 
function serverConnected() {
 print("Connected to Server");
}

function gotList(thelist) {
 print("List of Serial Ports:");

 for (let i = 0; i < thelist.length; i++) {
  print(i + " " + thelist[i]);
 }
}

function gotOpen() {
 print("Serial Port is Open");
}

function gotClose(){
 print("Serial Port is Closed");
 latestData = "Serial Port is Closed";
}

function gotError(theerror) {
 print(theerror);
}

function gotData() {
  let actual = serial.readLine();
  console.log(actual);
    
  let inData = serial.readStringUntil(';');
  datosEntrada = inData.split(',');
}


//se inicializa la función que dibuja las cosas en la pantalla
function draw() {  

    if(datosEntrada != false){
        valorPote = int(datosEntrada[0]);
        valorSensorA = Number(datosEntrada[1]);
        valorSensorB = int(datosEntrada[2]);
    }else{
        return;
    } // se llaman los valores del potenciometro y los otros dos randoms

    background('#0f0f0f'); //se establece el fondo general

    for(let i = 0;i<particles.length;i++) {
        particles[i].createParticle();
        particles[i].moveParticle();
        particles[i].joinParticles(particles.slice(i));
    }// se crean las partículas
    
    //se define la función que dibujará los círculos aleatorios en la pantalla
    function circulo() {
        stroke(255)
        strokeWeight(3)
        fill(valorSensorA, valorPote, valorSensorB)
        if(valorPote > 200){
            fill(255,0,0)
            ellipse(255, 255, 150, 150)
        }else{
            ellipse(valorSensorA, valorSensorB, valorPote, valorPote)
        }
        
    }

    //se define la función que escribira el texto aleatorio en la pantalla
    function textoCirculo() { 
      if(valorPote > 200){
        fill(255);
        strokeWeight(1);
        textSize(35);
        text("PAUSA", 273, 268);
        }else{    
          fill(255);
          strokeWeight(1);
          textSize(random(100));
          text("GENERANDO", random(0, 500), random(0, 500));
      }
    }

    //se declara la función que escribirá el texto con las indicaciones en una esquina de la pantalla
    function textoGeneral() {
      fill(255);
      textSize(20);
      text("Haz click en la pantalla para encender el LED por 1 segundo", 30, 30);
      text("Gira el potenciómetro a la izquierda para parar", 30, 60);
    }

    circulo(); //se llama la función que dibuja los círculos
    textoCirculo(); //se llama la función que escribe el texto 
    textoGeneral(); //se llama la función que escribe el texto con las instrucciones
    
  }

//se define la función que encenderá el led por 1 segundo
function mouseClicked() {
  serial.write(mensajeSaliente);
  if(mensajeSaliente === 'H'){
      mensajeSaliente = 'L';
  } else{
      mensajeSaliente = 'H';
  }
}



  
 


  




