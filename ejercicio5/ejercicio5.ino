int piezoPin = 8;
/* conecta el piezo al pin 8 */
void setup(){
pinMode( piezoPin,OUTPUT);
/* declara el pin del piezo como salida */
}
void loop(){
digitalWrite(piezoPin,HIGH);
delayMicroseconds(1136);
/* el tiempo aquí determinará el tono */
digitalWrite(piezoPin,LOW);
delayMicroseconds(1136);
/* el tiempo aquí determinará el tono */
}
