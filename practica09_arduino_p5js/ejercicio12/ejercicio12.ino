const int pinPote = 2;
const int pinLdr = 0;

int valorPote = 0;
int valorLdr = 0;
int valorSensorX = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  valorSensorX = random(255);
  valorPote = analogRead(pinPote);
  valorLdr = analogRead (pinLdr);

  valorPote = map(valorPote, 0, 1023, 0, 255);
  valorLdr = map(valorLdr, 0, 1023, 0, 255);

  Serial.print(valorPote);
  Serial.print(',');
  Serial.print(valorLdr);
  Serial.print(',');
  Serial.print(valorSensorX);
  Serial.print(';');
}
