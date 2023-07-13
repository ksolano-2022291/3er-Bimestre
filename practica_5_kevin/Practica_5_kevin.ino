/*
 * Fundación Kinal
 * Centro educativo técnico laboral Kinal
 * Electrónica
 * Grado: Quinto
 * Sección: "A"
 * Curso: Taller de Electronica y computacion I
 * Nombre: Kevin Audiel Solano Torres
 * Carnet:2022291
 * Proyecto: Sensor de Gas, practica 5
*/

#include <LedControl.h>
#include <Ticker.h>


 
#define dataPin0   12  
#define dataClock0 11   
#define dataLoad0  10
int adc,conver;

LedControl MKEVIN = LedControl(dataPin0,dataClock0,dataLoad0,1);

byte fuego_0[8]= {        
 B00001001,
 B00011011,
 B10101101,
 B11000001,
 B10000001,
 B10000010,
 B01000100,
 B00111000,

};
byte copo_1[8]= {       
 B00011000,
 B10011001,
 B01011010,
 B00111100,
 B11111111,
 B00111100,
 B01011010,
 B10011001,

};




void isr_gas1(void); 




Ticker isr_accion_gas(isr_gas1, 2000); 

void setup() {
  Serial.begin(9600);  
  Serial.println("Uso de ticker");
  isr_accion_gas.start(); 
  MKEVIN.shutdown(0,false);
  MKEVIN.setIntensity(0,15);
  MKEVIN.clearDisplay(0);
}

void loop() {
isr_accion_gas.update();
}
/*delay(250);
MKEVIN.clearDisplay(0);
delay(250);
for(int i=0; i<8;i++){
  MKEVIN.setRow(0,i,fuego_0[i]); 
  }*/


void isr_gas1(void)
{

 if(conver>=20){
for(int i=0; i<8;i++){
  MKEVIN.setRow(0,i,fuego_0[i]); 
  delay(250);
  }
   MKEVIN.clearDisplay(0);
 }
else {
  isr_accion_gas.update();
for(int i=0; i<8;i++){
  MKEVIN.setRow(0,i,copo_1[i]); 
  delay(250);
  }
  
}

  
  adc=analogRead(A0);
  conver=map(adc,0,1024,0,100);

  Serial.print("adc:");
   Serial.print(adc);
   Serial.print("     porcentaje:");
   Serial.println(conver);
   delay(100);
}
