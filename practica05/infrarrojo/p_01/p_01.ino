int valorSensorIR;


void setup() {
  pinMode(7,INPUT); //sensor IR
  Serial.begin(9600);

}

void loop() {
  valorSensorIR = digitalRead(7);
  Serial.println(valorSensorIR);
  delay(500);

}
