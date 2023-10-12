#include <Servo.h>
Servo Miservo; 
Servo Miservo2;

void setup() {
  Miservo.attach(11); //le digo donde el servo físico
  Miservo2.attach(10); //le digo donde el servo físico

}

void loop() {
  Miservo.write(150);
  delay(1000);
  Miservo.write(0);
  delay(1000);

  Miservo.write(60);
  delay(1000);
  Miservo.write(0);
  delay(1000);

  Miservo2.write(150);
  delay(1000);
  Miservo2.write(0);
  delay(1000);

  Miservo2.write(60);
  delay(1000);
  Miservo2.write(0);
  delay(1000);

}
