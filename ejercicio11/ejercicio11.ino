const int pinLed = 13;
int byteEntrada;

void setup(){
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);
}

void loop(){
  if(Serial.available() > 0);{
    byteEntrada = Serial.read();

    if (byteEntrada == 'H'){
      digitalWrite(pinLed, HIGH);
    }

    if (byteEntrada == 'L'){
      digitalWrite(pinLed, LOW);
    }
  }
}
