let serial;
let portName = "COM8";
let inputData;

function setup(){
    createCanvas(500,500)
    serial = new p5.SerialPort();
    serial.on('data', serialEvent);
    serial.on('error', gotError);

    serial.open(portName);
    serial.clear();
}

function draw(){
    background(0);
    fill(200);
    ellipse(inputData, 250, 100, 100);
}

function serialEvent(){
    let  inByte = serial.read();
    print("inByte: " + inByte);
    inputData = inByte;
}

function gotError(theerror){
    print("Algo pasa!!" + str(theerror));
}