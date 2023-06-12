/*
 * Fundación Kinal
 * Centro Educativo Tecnico Laboral Kinal
 * Electrónica 
 * Grado:Quinto
 * Sección:"A"
 * Curso:Taller de Electrónica Digital Y Reparación de Computadoras I
 * fecha:09/06/2023
 * Nombre:Kevin Audiel Solano Torres
 * Carnet:2022291
 * Proyecto:Ohmimetro
 */



//librerias 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//Directivas de preprocesador 
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
#define PIN A0

//variables
float VOUT=0;
float VCC=5;
float R1=0;
float R2=10000;


LiquidCrystal_I2C LCDKEVIN(direccion_lcd, columnas, filas);

//configuraciones
void setup() {
LCDKEVIN.begin(16,2);
LCDKEVIN.init();
LCDKEVIN.backlight();
LCDKEVIN.noBacklight();
LCDKEVIN.print("Ohmimetro");
}

void loop() {
VOUT=analogRead(PIN);
VOUT=VOUT*5/1023;//Regla de 3 para Vout
R1=(R2*5/VOUT)-(R2);//Ecuación para hallar R1
LCDKEVIN.setCursor(0,1);
LCDKEVIN.print(R1);//Imprime en el LCD El valor de R1
delay(100);
}
