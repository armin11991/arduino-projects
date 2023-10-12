const int pinPote = 0; //asigno el pin al potenciometro
int pinLed = 8; //asigno el pin al led
int byteEntrada;

int valorPote = 0; //inicializo el valor del potenciomeotro a cero
int valorSensorA; //declaro una primera variable random (se usará pára cambiar el color de los círculos y su posición)
int valorSensorB; //declaro una segunda variable random (se usará pára cambiar el color de los círculos y su posición)

void setup(){
  Serial.begin(9600); //se inicializa el serial
  pinMode(pinLed,OUTPUT); //se declara el pin Led como un output
}

void loop(){

  if(Serial.available() > 0);{
    byteEntrada = Serial.read();

    if (byteEntrada == 'H'){
      digitalWrite(pinLed, HIGH);
      delay(1000);
    }

    if (byteEntrada == 'L'){
      digitalWrite(pinLed, LOW);
    }
    
  }
  
  valorSensorA = random(500); //se asigna un valor random de hasta 500 al sensor A 
  valorPote = analogRead(pinPote); //se asigna el valor del potenciometro al valorPote
  valorSensorB = random(500);  //se asigna un valor random de hasta 500 al sensor B

  valorPote = map(valorPote, 0, 1023, 0, 500); //se mapea el valor del potenciomentreo para que su valor mínimo sea 0 y el máximo 255

  Serial.print(valorPote); //se imprime el valor del potenciomentro en el serial
  Serial.print(','); //se separan los valores con una ","
  Serial.print(valorSensorA); //se imprime el valor del sensor A
  Serial.print(','); //se separan los valores con una ","
  Serial.print(valorSensorB); //se imprime el valor del sensor B
  Serial.print(';'); //se finaliza el array con un ";"
}
