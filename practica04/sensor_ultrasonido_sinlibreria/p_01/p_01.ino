//sin libreria
int Trigger = 4;
int echo = 2;

void setup() {
  
  Serial.begin(9600); //inicializamos la comunicación
  pinMode(Trigger,OUTPUT); //envio pulso
  pinMode(echo,INPUT); //recibe pulso
  digitalWrite(Trigger,LOW); //inicializamos el pin con 0
}

void loop() {
  
long tiempo; //tiempo que demora en llegar el eco
long distancia; //distancia en centimetros
digitalWrite(Trigger, HIGH);
delayMicroseconds(10); //Enviamos un pulso de 10us (milisegundos) . Capacidad de enviar este sensor (ver data sheet)
digitalWrite(Trigger, LOW);
tiempo = pulseIn(echo, HIGH); //obtenemos el ancho del pulso
distancia = tiempo/58; //escalamos el tiempo a una distancia en cm - Ver nota al pie para entender el 58
Serial.print("Distancia: ");
Serial.print(distancia); //Enviamos serialmente el valor de la distancia
Serial.print("cm");
Serial.println();
delay(1000); //Hacemos una pausa de 100ms 

}
