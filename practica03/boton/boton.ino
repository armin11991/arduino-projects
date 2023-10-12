int pinBoton = 2;
int valorBoton = 0;

void setup() {
  Serial.begin(9600);  //inicia el serial
  pinMode(pinBoton,INPUT); //declaramos que el pin es INPUT, porque es un botón, si fuese un led seria OUTPUT
}

void loop() {
  valorBoton = digitalRead(pinBoton); //recoge el valor del botón
  Serial.println(valorBoton);
  delay(1000);
}
