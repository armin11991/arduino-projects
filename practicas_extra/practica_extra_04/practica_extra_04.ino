int ledAzul = 11; // declaramos los pines PWM que vamos a utilizar
int ledVerde = 10;
int ledRojo = 9;

int ledRojo2 = 8;
int ledVerde2 = 7;

int numeroRandomVerde; // variable donde almacenamos los valores aleatorios a utilizar en el led RGB
int numeroRandomRojo;
//int numeroRandomAzul;

int pinBoton = 6;
int valorBoton = 0;

void setup(){
    Serial.begin(9600);    
    pinMode(ledAzul, OUTPUT); // declaramos el pin como la salida
    pinMode(ledVerde, OUTPUT);
    pinMode(ledRojo, OUTPUT);
    pinMode(ledVerde2, OUTPUT);
    pinMode(ledRojo2, OUTPUT);
    pinMode(pinBoton, INPUT);
}

void loop(){
  valorBoton = digitalRead(pinBoton);
  Serial.println(valorBoton);
  delay(500);

  numeroRandomVerde = random(50,60);
  numeroRandomRojo = random(50,60);
  //numeroRandomAzul = random(10,55);

if (valorBoton == 0){
    analogWrite(ledAzul, 55); // escribimos del valor en PIN Rojo
    analogWrite(ledVerde, 0); // escribimos del valor en PIN Verde
    analogWrite(ledRojo, 0); // escribimos del valor en PIN Azul
    delay (500);
    analogWrite(ledAzul, 0); // escribimos del valor en PIN Rojo
    analogWrite(ledVerde, 55); // escribimos del valor en PIN Verde
    analogWrite(ledRojo, 0); // escribimos del valor en PIN Azul
    delay (500);
    analogWrite(ledAzul, 0); // escribimos del valor en PIN Rojo
    analogWrite(ledVerde, 0); // escribimos del valor en PIN Verde
    analogWrite(ledRojo, 55); // escribimos del valor en PIN Azul
    delay (500);
}else{
    //analogWrite(ledAzul, numeroRandomAzul); // escribimos del valor en PIN Rojo
    analogWrite(ledVerde, numeroRandomVerde); // escribimos del valor en PIN Verde
    analogWrite(ledRojo, numeroRandomRojo); // escribimos del valor en PIN Azul
    delay (3000);

    // comienza bloque que determina que led alternativo  se encenderá
    if (numeroRandomVerde > numeroRandomRojo){
      digitalWrite(ledVerde2, HIGH);
      digitalWrite(ledRojo2, LOW);
    }if (numeroRandomRojo > numeroRandomVerde){
      digitalWrite(ledRojo2, HIGH);
      digitalWrite(ledVerde2, LOW);
    }if (numeroRandomVerde == numeroRandomRojo){
      digitalWrite(ledRojo2, LOW);
      digitalWrite(ledVerde2, LOW);
    }
    // termina bloque que determina que led alternativo se encenderá
 
    analogWrite(ledAzul, 0); // escribimos del valor en PIN Rojo
    analogWrite(ledVerde, 0); // escribimos del valor en PIN Verde
    analogWrite(ledRojo, 0); // escribimos del valor en PIN Azul
    delay (100);

    analogWrite(ledAzul, 0); // escribimos del valor en PIN Rojo
    analogWrite(ledVerde, 0); // escribimos del valor en PIN Verde
    analogWrite(ledRojo, 55); // escribimos del valor en PIN Azul
    delay (1000);

    analogWrite(ledAzul, 0); // escribimos del valor en PIN Rojo
    analogWrite(ledVerde, 0); // escribimos del valor en PIN Verde
    analogWrite(ledRojo, 0); // escribimos del valor en PIN Azul
    delay (300);

    analogWrite(ledAzul, 0); // escribimos del valor en PIN Rojo
    analogWrite(ledVerde, 0); // escribimos del valor en PIN Verde
    analogWrite(ledRojo, 55); // escribimos del valor en PIN Azul
    delay (1000);
    

}// corchete que cierra el if/else

    
} // Corchete que cierra el void loop
