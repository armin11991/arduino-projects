#include <Ultrasonido.h> //libreria
//libreria
Ultrasonido Misensorultra(4, 2, 100); //(trigger, echo, distancia(cm));
//

int valorMisensor = 0; 

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  valorMisensor = Misensorultra.Distancia();
  Serial.println(valorMisensor);
  delay (500);

}
