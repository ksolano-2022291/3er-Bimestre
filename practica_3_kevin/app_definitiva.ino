/*
 * Fundación Kinal
 * Centro educativo técnico laboral Kinal
 * Electrónica
 * Grado: Quinto
 * Sección: "A"
 * Curso: TIC'S
 * Nombre: Kevin Audiel Solano Torres
 * Carnet:2022291
 * Proyecto: practica app
*/
#include <Ticker.h>
#include <SoftwareSerial.h>
#include <DallasTemperature.h>
#include <OneWire.h>
SoftwareSerial bt (10,11);
int sensor=3;
int led=2;
int estado=0;
int temp;
float temperatura;



 void isr_temp(void); 


volatile static bool estado_led;

Ticker isr_accion_temp(isr_temp, 10000);

void setup() {
Serial.begin(9600);
pinMode(led,OUTPUT);
bt.begin(38400);
isr_accion_temp.start();

}

void loop() {
  isr_accion_temp.update();

  if(Serial.available()>0){
    estado = Serial.read();
  }
  switch(estado){
    case('1'):
    digitalWrite(led,HIGH);
    
    break;
    case('2'):
    digitalWrite(led,LOW);
   
    break;
  }

}

void isr_temp(void){
  temp=analogRead(sensor);
temperatura=(((temp*3000.0)/1023)/10);
bt.print(temperatura);
bt.println("C");
Serial.print(temperatura);

}




  
 
