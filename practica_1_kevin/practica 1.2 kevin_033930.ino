/*
 *Fundación Kinal
 *Centro Educativo Tecnico Laboral Kinal
 *Electronica
 *Grado:Quinto 
 *Sección: A 
 *Curso: Taller de Electronica digital y reparación de computadoras I 
 *Nombre: Kevin Audiel Solano Torres
 *Carnet:2022291 
 *Proyecto:Interrupciones por medio de software 
 */

//librerias
#include <Ticker.h>
#include <OneWire.h>
#include <DallasTemperature.h>


//directivas de preprocesador
#define botton 3



//Funciones de ISR
void isr_temperatura(void);
void isr_botton(void);

//constructores
OneWire ourWire(2);
DallasTemperature sensors(&ourWire);

Ticker isr_accion_temperatura(isr_temperatura,3000);
Ticker isr_accion_botton(isr_botton,6000);


void setup() {//configuraciones
 pinMode(botton,OUTPUT);
 Serial.begin(9600);
 sensors.begin();
 Serial.println("interrupciones por medio de Software");
 isr_accion_temperatura.start();
 isr_accion_botton.start();
}

void loop() {
isr_accion_temperatura.update();
isr_accion_botton.update();
sensors.requestTemperatures();

}





void isr_temperatura(void){
float tempC=sensors.getTempCByIndex(0);
Serial.println("TemperaturaC:");
Serial.println(tempC);
delay(200);
} 



void isr_botton(void){

 if(digitalRead(botton)==HIGH){
  Serial.println("El boton se encuentra:");
  Serial.println("Cerrado");
  delay(200);
 }

if(digitalRead(botton)==  LOW){
  Serial.println("El boton se encuentra:");
  Serial.println("Abierto");
  delay(200);
 }

 
}
