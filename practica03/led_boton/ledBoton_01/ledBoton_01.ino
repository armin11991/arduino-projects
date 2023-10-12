int led_1 = 12; 
int led_2 = 11;
int led_3 = 10;
int led_4 = 9;
int pinBoton = 2;
int valorBoton = 0;
int varPlus = 0


void setup() {
  Serial.begin (9600); // conecta con el serial
  pinMode(led_1,OUTPUT); //se ha definido el pin 12 como output de la placa
  pinMode(led_2,OUTPUT); //se ha definido el pin 11 como output de la placa
  pinMode(led_3,OUTPUT); //se ha definido el pin 10 como output de la placa
  pinMode(led_4,OUTPUT); //se ha definido el pin 10 como output de la placa
  pinMode(pinBoton,INPUT); //declaramos que el pin es INPUT, porque es un botón, si fuese un led seria OUTPUT
}

void loop() {

  valorBoton = digitalRead(pinBoton); //recoge el valor del botón
  Serial.println(valorBoton);

  if (valorBoton == 1){
    varPlus =+ 1
  }
  digitalWrite(led_1, LOW);
  
  for ( = 0; i <= 255; i++) {
    analogWrite(PWMpin, i);
    delay(10);
  }
 
  if (valorBoton == 0) digitalWrite(led_1, LOW);
  if (valorBoton == 0) digitalWrite(led_2, LOW);
  if (valorBoton == 0) digitalWrite(led_3, LOW);
  if (valorBoton == 0) digitalWrite(led_4, LOW);

  if (valorBoton == 1) digitalWrite(led_1, HIGH);
  if (valorBoton == 1) digitalWrite(led_2, HIGH);
  if (valorBoton == 1) digitalWrite(led_3, HIGH);
  if (valorBoton == 1) digitalWrite(led_4, HIGH);

}
