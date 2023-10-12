#include <Servo.h>
#include <Ultrasonido.h>

Servo Miservo;
Ultrasonido Misensorultra(4, 2, 100); //(trigger, echo, distancia(cm))

int valorMisensor = 0;


void setup() {
  Serial.begin(9600);
  Miservo.attach(11); //le digo donde el servo físico

}

void loop() {
  valorMisensor = Misensorultra.Distancia();
  Serial.println(valorMisensor);

  for(int pos = valorMisensor; pos < 150; pos++){
    Miservo.write(pos);
    delay(15);
  }

  for(int pos = valorMisensor; pos >=1; pos--){
    Miservo.write(pos);
    delay(15);
  }

  /*
  Miservo.write(150);
  delay(1000);
  Miservo.write(0);
  delay(1000);

  Miservo.write(60);
  delay(1000);
  Miservo.write(0);
  delay(1000);
  */


}
