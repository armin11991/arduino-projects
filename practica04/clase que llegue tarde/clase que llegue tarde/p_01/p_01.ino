int valorPot = 0;
int valorMapPot = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  valorPot = analogRead(0);
  valorMapPot = map(valorPot, 0, 1023, 0, 255);
  Serial.println(valorPot,DEC);
  analogWrite(11,valorPot/4);//PWM
}
