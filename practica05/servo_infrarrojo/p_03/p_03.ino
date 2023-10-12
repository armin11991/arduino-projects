#include <Servo.h>
#include <Ultrasonido.h>

Servo Miservo;
Ultrasonido Misensorultra(4, 2, 100); //(trigger, echo, distancia(cm))

int valorMisensor = 0;
int valorSensorIR;


void setup() {
  Serial.begin(9600);
  Miservo.attach(11); //le digo donde el servo físico
  pinMode(7,INPUT); //sensor IR
 

}

void loop() {

  valorSensorIR = digitalRead(7);
  valorMisensor = Misensorultra.Distancia();
  Serial.println(valorMisensor);
  Serial.println(valorSensorIR);

  if(valorSensorIR == 1){
    for(int pos = 0; pos < valorMisensor; pos++){
      Miservo.write(pos);
      delay(15);
      }
  }else{
    for(int pos = valorMisensor; pos >=1; pos--){
      Miservo.write(pos);
      delay(15);
      }
  } //fin else


}
