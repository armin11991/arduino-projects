int valorPot = 0;

void setup(){
Serial.begin(9600); // abro el serial para ver el valor que me da el sensor
}

void loop(){
  valorPot = analogRead(0);
  Serial.write(valorPot);
  //Serial.println(valorPot);
  delay(10);
}
