let serial;
let latestData = "waiting for data";

let mensajeSaliente = 'L';
let puertoArduino = 'COM4';

function setup() {
 createCanvas(500, 400);

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
    let actual = serial.readLine();
    console.log(actual);

}

function draw() {
    background(200);
    fill(0);
    text("Click para encender el LED", 50, 50);
}

function mouseReleased(){
    serial.write(mensajeSaliente);
    if(mensajeSaliente === 'H'){
        mensajeSaliente = 'L';
    } else{
        mensajeSaliente = 'H';
    }
}
