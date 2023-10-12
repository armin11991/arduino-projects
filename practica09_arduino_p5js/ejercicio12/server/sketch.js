let serial;
let latestData = "waiting for data";

let puertoArduino = 'COM4';
let datosEntrada = false;

let valorPote;
let valorLdr;
let valorSensorX;

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
}

function draw() {
    if(datosEntrada != false){
        valorPote = int(datosEntrada[0]);
        valorLdr = Number(datosEntrada[1]);
        valorSensorX = int(datosEntrada[2]);
    }else{
        return;
    }

    background(valorPote, valorLdr, valorSensorX);
    fill(255);
    text(valorPote, 10, 30);
    text(valorLdr, 10, 50);
    text(valorSensorX, 10, 70);
}

