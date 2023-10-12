int led_1 = 12; 
int led_2 = 11;
int led_3 = 10;
int led_4 = 9;
int led_5 = 8;

void setup() {
  pinMode(led_1,OUTPUT); //se ha definido el pin 12 como output de la placa
  pinMode(led_2,OUTPUT); //se ha definido el pin 11 como output de la placa
  pinMode(led_3,OUTPUT); //se ha definido el pin 10 como output de la placa
  pinMode(led_4,OUTPUT); //se ha definido el pin 9 como output de la placa
  pinMode(led_5,OUTPUT); //se ha definido el pin 8 como output de la placa
}

void loop() {

  //CODIGO IDA
  //pin 12 que controla el led_1
  digitalWrite (led_1,HIGH);
  delay(50);
  digitalWrite (led_1,LOW);
  delay(50); 

  //pin 11 que controla el led_2
  digitalWrite (led_2,HIGH);
  delay(50);
  digitalWrite (led_2,LOW);
  delay(50); 

  //pin 10 que controla el led_3
  digitalWrite (led_3,HIGH);
  delay(50);
  digitalWrite (led_3,LOW);
  delay(50); 

  //pin 9 que controla el led_4
  digitalWrite (led_4,HIGH);
  delay(50);
  digitalWrite (led_4,LOW);
  delay(50); 

  //pin 8 que controla el led_5
  digitalWrite (led_5,HIGH);
  delay(50);
  digitalWrite (led_5,LOW);
  delay(50); 

  //CODIGO VUELTA
  //pin 8 que controla el led_5
  digitalWrite (led_5,HIGH);
  delay(50);
  digitalWrite (led_5,LOW);
  delay(50); 

  //pin 9 que controla el led_4
  digitalWrite (led_4,HIGH);
  delay(50);
  digitalWrite (led_4,LOW);
  delay(50); 

  //pin 10 que controla el led_3
  digitalWrite (led_3,HIGH);
  delay(50);
  digitalWrite (led_3,LOW);
  delay(50); 

  //pin 11 que controla el led_2
  digitalWrite (led_2,HIGH);
  delay(50);
  digitalWrite (led_2,LOW);
  delay(50); 

  //pin 12 que controla el led_1
  digitalWrite (led_1,HIGH);
  delay(50);
  digitalWrite (led_1,LOW);
  delay(500); 
  

}
