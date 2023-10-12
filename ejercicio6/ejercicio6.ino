int pinBuzzer = 8; //conecta el piezo al pin 8
int A_4 = 440;

void setup(){
pinMode(pinBuzzer,OUTPUT); //declara el pin del piezo como salida
}

void loop(){
  tone(pinBuzzer,A_4);
  delay(500);
  noTone(pinBuzzer);
  delay(500);
}
