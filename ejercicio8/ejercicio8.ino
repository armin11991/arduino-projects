int piezoPin = 2; // conecta el piezo al pin 2 analógico
int Valorpiezo = 0; // variable que recoge el valor del piezo
void setup(){
Serial.begin(9600); // abro el serial para ver el valor que me da el piezo
}
void loop(){
Valorpiezo = analogRead(piezoPin); // le paso el valor analógico que leo del piezo
delay(100);
Serial.println(Valorpiezo); // muestra en el monitor serie el valor del piezo
/*
ahora ya podemos utilizar ese valor (Valorpiezo) para lo que queramos: generar un tono, activar
un led, cambiar el color RGB, encender un relay, etc.
*/
}
