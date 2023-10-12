let serial;
let latestData = "waiting for data";

let puertoArduino = '/dev/tty.usbserial-10';

let pinLdr = 0;
let valorLdr;
let valorMisensorX;

function setup() {
 createCanvas(500, 500);

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
    let inData = serial.readStringUntil(';');
    datosEntrada = inData.split(',');
    
    valorMisensorX = datosEntrada[0];
    valorLdr = datosEntrada[1];
}

function draw() {

    if (valorLdr < 100){
        background(255);//fondo blanco
        fill(0);//letra negra
        text("valor sensor LDR < 50", 50, 50);
    }if (valorLdr > 100){
        background(0);//fondo negro
        fill(255);//letra blanca
        text("valor sensor LDR > 50", 50, 50);
    }if (valorMisensorX < 50){
        background(255,0,0); //fondo rojo
        fill(0); //letra negra
        text("Cuidado estás muy cerca", 50, 50);
    }
}




