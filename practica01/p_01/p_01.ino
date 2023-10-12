int pinUso = 12; //es el pin del led

void setup() {
  pinMode(pinUso,OUTPUT); //se ha definido el pin 12 como output de la placa
}

void loop() {
  digitalWrite (pinUso,HIGH);
  delay(1000);
  digitalWrite (pinUso,LOW);
  delay(1000); 
}
