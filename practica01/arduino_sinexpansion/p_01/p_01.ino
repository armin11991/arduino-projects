int pinUso = 11; //es el pin del led

void setup() {
  pinMode(pinUso,OUTPUT); //se ha definido el pin 12 como output de la placa
}

void loop() {
  digitalWrite (pinUso,HIGH);
  delay(500);
  digitalWrite (pinUso,LOW);
  delay(50); 
}
