#include <Ultrasonido.h> //importamos libreria

Ultrasonido Misensorultra(4,2,100); // (trigger, eco, distancia(cm))

const int pinLdr = 0;

int valorLdr = 0;
int valorMisensorX = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){

  valorMisensorX = Misensorultra.Distancia();
  valorLdr = analogRead (pinLdr);
  valorLdr = map(valorLdr, 0, 1023, 0, 255);
  
  Serial.print(valorMisensorX);
  Serial.print(',');
  Serial.print(valorLdr);
  Serial.print(';');
  delay(500);
}
