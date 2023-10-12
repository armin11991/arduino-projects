int led_1 = 12; 
int led_2 = 11;
int led_3 = 10;
int led_4 = 9;
int pinBoton = 2;
int valorBoton = 0;
int varPlus = 0;
int ranNum;
int RANDOM;

int pinsCount=4;                        // declaring the integer variable pinsCount
int pins[] = {9,10,11,12};          // declaring the array pins[]

void setup() {
  Serial.begin(9600); //activar el serial
  for (int i=0; i<pinsCount; i=i+1){    // counting the variable i
    pinMode(pins[i], OUTPUT);            // initialising the pin at index i of the array of pins as OUTPUT
  }

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
    varPlus += 1;
  }

  switch (varPlus) {
  
  case 1:
    if (varPlus == 1){
     digitalWrite(led_1, HIGH);
     digitalWrite(led_2, LOW);
     digitalWrite(led_3, LOW);
     digitalWrite(led_4, LOW);
     delay(500);
    }
    break;
    
  case 2:   
    if (varPlus == 2){
     digitalWrite(led_1, LOW);
     digitalWrite(led_2, HIGH);
     digitalWrite(led_3, LOW);
     digitalWrite(led_4, LOW);
     delay(500); 
    }   
    break;
     
  case 3:  
    if (varPlus == 3){
     digitalWrite(led_1, LOW);
     digitalWrite(led_2, LOW);
     digitalWrite(led_3, HIGH);
     digitalWrite(led_4, LOW);
     delay(500);  
    } 
    break;

  case 4:  
    if (varPlus == 4){
     digitalWrite(led_1, LOW);
     digitalWrite(led_2, LOW);
     digitalWrite(led_3, LOW);
     digitalWrite(led_4, HIGH);
     delay(500);  
    }
    break;

  case 5:
    if (varPlus == 5){
     digitalWrite(led_1, LOW);
     digitalWrite(led_2, LOW);
     digitalWrite(led_3, LOW);
     digitalWrite(led_4, LOW);
     RANDOM = random(0, 3);
     digitalWrite(pins[RANDOM], HIGH);
     delay(500);
     digitalWrite(pins[RANDOM], LOW);
     delay(500);
    }
    break;

  case 6:
    if (varPlus == 6){
     digitalWrite(led_1, HIGH);
     digitalWrite(led_2, HIGH);
     digitalWrite(led_3, HIGH);
     digitalWrite(led_4, HIGH);
     delay(500);
     varPlus = 0;
    }
    break;

    
  default:
    
    if (varPlus == 0){
     delay(3000);
     digitalWrite(led_1, LOW);
     digitalWrite(led_2, LOW);
     digitalWrite(led_3, LOW);
     digitalWrite(led_4, LOW);
     delay(500);
    }
    break;

}
    
  delay(500);
  
}
