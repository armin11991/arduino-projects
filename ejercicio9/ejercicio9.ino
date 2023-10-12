#include <CapacitiveSensor.h>

CapacitiveSensor cs_4_2 = CapacitiveSensor(4,2); // Pin 4 digital es envio, y pin 2 digital recibo
// conecto el sensor al pin2 digital a arduino (pin 2 es antena)
// Si queremos poner más sensores compartiremos el pin 4 como envío y el 2 será el 3, así sucesivamente.
void setup(){
cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF); // Autocalibrado del capacitivo del pin 2
Serial.begin(9600); // abro el serial para ver el valor que me da el sensor
}
void loop(){
unsigned long ValorCapacitivo= cs_4_2.capacitiveSensor(30);
// recojo en una variable long el valor del sensor ( 30 es la sensibilidad, puedo variarla) pongo unsigned long para
// recoger solo los valores positivos y que no use los negativos.
Serial.println(ValorCapacitivo); // muestra en el monitor serie el valor del sensor
delay(10); // damos un delay para no saturar el serial
/*
NOTA: os dará un número muy alto y tendréis que mapearlo
*/
}
