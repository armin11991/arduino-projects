int potenciometro = 0; //hemos señalado el pin analógico
int valorPot = 0; //inicializar la variable

void setup() {
  Serial.begin(9600); //activar el serial
}

void loop() {
  //leer el potenciometro
  valorPot = analogRead(potenciometro);
  Serial.print(valorPot,DEC);
  Serial.print(',');
  Serial.print(random(0,0));
  Serial.print(',');
  Serial.print(random(0,0));
  Serial.println(';');
  delay(500);
  
}
