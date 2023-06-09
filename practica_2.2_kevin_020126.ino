/*
 * Fundacion Kinal
 * Centro Educativo Tecnico Laboral Kinal
 * Electronica 
 * Grado:Quinto
 * Sección:A
 * Curso:Taller de Electronica Digital Y Reparación de Computadoras I
 * fecha:09/06/2023
 * Nombre:Kevin Audiel Solano Torres
 * Carnet:2022291
 * Proyecto:Control de una secuencia de Colores RGB
 */

//Directivas de preprocesador
#define LEDR 3 //Pin3 donde utilizo el PWM como salida
#define LEDG 5//Pin5 donde utilizo el PWM como salida
#define LEDB 6//Pin6 donde utilizo el PWM como salida
#define POT  A0//Potenciometro conectad a el puerto analogo A0
//Variables
int frec=0;//Variable utilizada para la frecuencia
int color=0;//Variable utilizada para el color

//Configuraciones
void setup() {
pinMode(LEDR,OUTPUT);
pinMode(LEDG,OUTPUT);
pinMode(LEDB,OUTPUT);
pinMode(POT,OUTPUT);

}

void loop() {
  color=analogRead(POT);//leo el canal analogico A0
  frec=map(color,0,1022,100,1000);
  analogWrite(LEDR,174);
  analogWrite(LEDG,92);
  analogWrite(LEDB,230);
  delay(100);
  analogWrite(LEDR,255);
  analogWrite(LEDG,255);
  analogWrite(LEDB,255);
  delay(250);
  analogWrite(LEDR,0);
  analogWrite(LEDG,255);
  analogWrite(LEDB,255);
  delay(500);
  analogWrite(LEDR,189);
  analogWrite(LEDG,174);
  analogWrite(LEDB,20);
  delay(750);
  analogWrite(LEDR,225);
  analogWrite(LEDG,87);
  analogWrite(LEDB,35);
  delay(1000);
}
