/*
 * Fundacion Kinal
 * Centro Educativo Tecnico Laboral Kinal
 * Electronica 
 * Grado:Quinto
 * Sección:A
 * Curso:Taller de Electronica Digital Y Reparación de Computadoras I
 * Nombre:Kevin Audiel Solano Torres
 * Carnet:2022291
 * Proyecto:Control del Brillo de un LED
 */

//directivas del preprocesador
#define LED 3
#define POTEC A0

//Variables
int brillopot=0;
int INT=0;


void setup() {
  pinMode(LED,OUTPUT);//Pin donde utilizo el PWM como salida
  pinMode(POTEC,OUTPUT);
}

void loop() {
  INT=analogRead(POTEC);//leo el potenciometro.
  brillopot=map(INT,0,1023,0,255);
  analogWrite(LED,brillopot);
}
