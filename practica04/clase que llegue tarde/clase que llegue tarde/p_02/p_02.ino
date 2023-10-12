int Rojo = 11; // declaramos los pines PWM que vamos a utilizar
int Verde = 10;
int Azul = 9;
void setup(){
pinMode(Rojo, OUTPUT); // declaramos el pin como la salida
pinMode(Verde, OUTPUT);
pinMode(Azul, OUTPUT);
}
void loop(){
analogWrite(Rojo, 124); // escribimos del valor en PIN Rojo
delay(500);
analogWrite(Verde, 28); // escribimos del valor en PIN Verde
delay (500);
analogWrite(Azul, 12); // escribimos del valor en PIN Azul
delay (500);
}
