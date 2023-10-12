int potenciometro = 0; //hemos señalado el pin analógico
int valorPot = 0; //inicializar la variable

int pinsCount=4;                        // declaring the integer variable pinsCount
int pins[] = {9,10,11,12};          // declaring the array pins[]

int delay1;  // to define the variable

void setup() {
  Serial.begin(9600); //activar el serial
  for (int i=0; i<pinsCount; i=i+1){    // counting the variable i
    pinMode(pins[i], OUTPUT);            // initialising the pin at index i of the array of pins as OUTPUT
  }
}

void loop() {
  
  //leer el potenciometro
  valorPot = analogRead(potenciometro);
  delay1 = analogRead(A0); //to read voltage at (A0) pin 
  Serial.println(valorPot,DEC); 

//CICLO FOR LED CHASER
  for (int i=0; i<pinsCount; i=i+1){    // chasing right
    digitalWrite(pins[i], HIGH);         // switching the LED at index i on
    delay(delay1);                          // stopping the program for 100 milliseconds
    digitalWrite(pins[i], LOW);          // switching the LED at index i off
  }
  for (int i=pinsCount-1; i>0; i=i-1){   // chasing left (except the outer leds)
    digitalWrite(pins[i], HIGH);         // switching the LED at index i on
    delay(delay1);                          // stopping the program for 100 milliseconds
    digitalWrite(pins[i], LOW);          // switching the LED at index i off
  }

//POTENCIOMETRO "APAGADO" 
  if (valorPot <= 10) {  
    for (int i=pinsCount-1; i>0; i=i-1){
    digitalWrite(pins[i], LOW);         // switching the LED at index i off
    Serial.println("APAGADO");
    delay(900);
    }
  }

    
  //delay(500);
  
}
