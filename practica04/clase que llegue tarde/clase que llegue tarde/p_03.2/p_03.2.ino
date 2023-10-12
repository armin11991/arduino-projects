int valorPot = 0;
int valorMapPot = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  valorPot = analogRead(0);
  valorMapPot = map(valorPot, 0, 1023, 0, 255);
  Serial.println(valorMapPot,DEC);
  analogWrite(9,0);//PWM Rojo
  analogWrite(10,0);//PWM Verde
  analogWrite(11,255);//PWM Azul
  delay(100);
}
