#include <Ultrasonido.h> //importamos libreria

Ultrasonido Misensorultra(4,2,100); // (trigger, eco, distancia(cm))

int valorMisensor = 0;
int Rojo = 11; // declaramos los pines PWM que vamos a utilizar
int Verde = 10;
int Azul = 9;

void setup() {
  Serial.begin(9600); // iniciamos el serial para poder leer ver los valores
  pinMode(Rojo, OUTPUT); // declaramos el pin como la salida
  pinMode(Verde, OUTPUT);
  pinMode(Azul, OUTPUT);
}

void loop() {
  valorMisensor = Misensorultra.Distancia();
  Serial.println(valorMisensor);
  delay(500);

  if (valorMisensor < 15){
    analogWrite(Rojo, 124);
    analogWrite(Verde, 0); 
    analogWrite(Azul, 0);
  }if (valorMisensor > 15){
    analogWrite(Verde, 62);
    analogWrite(Azul, 0); 
    analogWrite(Rojo, 124); 
  }if (valorMisensor > 40){
    analogWrite(Azul, 0);
    analogWrite(Verde, 124); 
    analogWrite(Rojo, 0); 
  }//cierra el ciclo if/else
}//cierra el void loop
