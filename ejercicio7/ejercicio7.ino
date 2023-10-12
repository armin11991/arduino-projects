int pinBuzzer = 8; //conecta el piezo al pin 8
int A_4 = 440;
int A_5 = 880;
int pinLdr = 0;
int valorLdr = 0;

void setup(){
  Serial.begin(9600);
  pinMode(pinBuzzer,OUTPUT); //declara el pin del piezo como salida
}

void loop(){
  //LDR
  valorLdr = analogRead(pinLdr);
  Serial.println(valorLdr);
  valorLdr = map(valorLdr, 0, 1023, A_4, A_5);
  
  //poner en HIGH
  tone(pinBuzzer,valorLdr);
  delay(500);
  noTone(pinBuzzer);
  delay(500);
}
