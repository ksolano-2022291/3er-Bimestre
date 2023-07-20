/*
 * Fundación Kinal
 * Centro educativo técnico laboral Kinal
 * Electrónica
 * Grado: Quinto
 * Sección: "A"
 * Curso: Taller de Electronica y computacion I
 * Nombre: Kevin Audiel Solano Torres
 * Carnet:2022291
 * Proyecto: nivel burbuja, practica 6
*/

#include <LedControl.h>
#include<Wire.h>
#include <SparkFun_ADXL345.h>


 
#define dataPin0   12  
#define dataClock0 11   
#define dataLoad0  10


LedControl MKEVIN = LedControl(dataPin0,dataClock0,dataLoad0,1);
ADXL345 acele = ADXL345(); 
int x;
int y;
int z;


byte agua_0[8]= {      //recto  
B00000011,
B10001000,
B00000000,
B11111111,
B11111111,
B11111111,
B11111111,
B11111111,
};

byte agua_1[8]= {       //inclinado izquierda 
B10000000,
B11000000,
B11100000,
B11110000,
B11111000,
B11111100,
B11111110,
B11111111,
};

byte agua_2[8]= {        //inclinado derecha
B00000001,
B00000011,
B00000111,
B00001111,
B00011111,
B00111111,
B01111111,
B11111111,
};

byte agua_3[8]= {        //semi izquierda
B11000000,
B11110000,
B11111100,
B11111111,
B11111111,
B11111111,
B11111111,
B11111111,
};

byte agua_4[8]= {        //semi derecha
B00000011,
B00001111,
B00111111,
B11111111,
B11111111,
B11111111,
B11111111,
B11111111,
};


void setup() 
{
 Serial.begin(9600);     //Inicio la comunicacion serial a 9600 baudios.
 Serial.println("Uso del acelerometro ADXL345");
 acele.powerOn();             //Enciendo el acelerometro.
 acele.setRangeSetting(8);   //Configuro para medir la aceleracion con 8g.
 MKEVIN.shutdown(0,false);
 MKEVIN.setIntensity(0,15);
 MKEVIN.clearDisplay(0);
}

void loop() 
{
 acele.readAccel(&x,&y,&z);
 Serial.print("La aceleracion en x es de: ");
 Serial.println(x);
 delay(250);


 if(x<0&&x>-8){//recto
  for(int i=0; i<8;i++){
  MKEVIN.setRow(0,i,agua_0[i]);
  delay(10);
                       }
                        
 }


if(x<-10){//derecha
  for(int i=0; i<8;i++){
  MKEVIN.setRow(0,i,agua_2[i]);
  delay(10);
                       }
                        
 }
 


if(x>60){//inclinado iza
  for(int i=0; i<8;i++){
  MKEVIN.setRow(0,i,agua_1[i]);
  delay(10);
                       }
 }

 
}
