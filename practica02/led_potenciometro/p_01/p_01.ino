int led_1 = 12; 
int led_2 = 11;
int led_3 = 10;
int potenciometro = 1; //hemos señalado el pin analógico
int valPot = 0; //inicializar la variable


void setup() {
  Serial.begin (9600); // conecta con el serial
  pinMode(led_1,OUTPUT); //se ha definido el pin 12 como output de la placa
  pinMode(led_2,OUTPUT); //se ha definido el pin 11 como output de la placa
  pinMode(led_3,OUTPUT); //se ha definido el pin 10 como output de la placa
}

void loop() {
 
  valPot = analogRead(potenciometro); // captura el pin de entrada del potenciómetro
  //Serial.println(valPot,DEC); // imprime en el monitor serial el valor del potenciómetro.
  //delay(50); // // espera un segundo y sigue

  if (valPot < 10) digitalWrite(led_1, LOW);
  if (valPot < 10) digitalWrite(led_2, LOW);
  if (valPot < 10) digitalWrite(led_3, LOW);
  if (valPot < 10) Serial.println("APAGADO");

  if (valPot > 10) digitalWrite(led_1, HIGH);
  if (valPot > 10) digitalWrite(led_2, HIGH);
  if (valPot > 10) digitalWrite(led_3, HIGH);
  if (valPot > 10) Serial.println("");

}
