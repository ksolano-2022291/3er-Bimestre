/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Kevin Audiel Solano Torres
 * Carnet: 2022291
 * Proyecto: contador 0-50 con interrupciones
*/

//directivas de preprocesador
//defino los botones y los pines 
#define botton_rising  2   
#define botton_falling 3
#define pin1 4 
#define pin2 5
#define pin3 6
#define pin4 7
#define pin5 8
#define pin6 9
#define pin7 10
#define pin8 11
//creo variables para las decenas y unidades
int unidades=0; 
int decenas=0; 
//funciones ISR son las que se llaman al dispararse una interrupcion externa.
void funcion_ISR_falling(void);
void funcion_ISR_rising(void);

void setup() {
  Serial.begin(19200); //inicio de la comunicación serial
  pinMode(botton_rising,INPUT); //pin 2 como entrada
  pinMode(botton_falling,INPUT); //pin 3 como entrada
  pinMode(pin1,OUTPUT);//pines para utilizar los display de 7 segmentos
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
  pinMode(pin4,OUTPUT);
  pinMode(pin5,OUTPUT);
  pinMode(pin6,OUTPUT);
  pinMode(pin7,OUTPUT);
  pinMode(pin8,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(botton_rising),funcion_ISR_rising,RISING);   
  attachInterrupt(digitalPinToInterrupt(botton_falling),funcion_ISR_falling,FALLING); 

}

void loop() {
//utilizo un if para dar parametros y las intrucciones que necestito.

if((unidades>0)&&(decenas==5)){//de 50 a 00
  unidades=0;
  decenas=0;
}

if((unidades<0)&&(decenas==0)){//de 00 a 50
  unidades=0;
  decenas=5;
 
}

if(unidades>9){// el ascendente
  unidades=0;
  decenas=decenas+1;
}

if(unidades<0){//el descendente
  unidades=9;
  decenas=decenas-1;
  
}


 switch(unidades)//utilizo un switch case para poder utilizar el display de 7 segmentos
 // de manera binaria con el 7448

 
  {
    
    case(0):   
    digitalWrite(pin5,LOW);
    digitalWrite(pin6,LOW);
    digitalWrite(pin7,LOW);
    digitalWrite(pin8,LOW);
    break;

    case(1): 
    digitalWrite(pin5,LOW);
    digitalWrite(pin6,LOW);
    digitalWrite(pin7,LOW);
    digitalWrite(pin8,HIGH);
    break;

    case(2):
    digitalWrite(pin5,LOW);
    digitalWrite(pin6,LOW);
    digitalWrite(pin7,HIGH);
    digitalWrite(pin8,LOW);
    break;

    case(3):
    digitalWrite(pin5,LOW);
    digitalWrite(pin6,LOW);
    digitalWrite(pin7,HIGH);
    digitalWrite(pin8,HIGH);
    break;

    case(4):
    digitalWrite(pin5,LOW);
    digitalWrite(pin6,HIGH);
    digitalWrite(pin7,LOW);
    digitalWrite(pin8,LOW);
    break;

     case(5):
    digitalWrite(pin5,LOW);
    digitalWrite(pin6,HIGH);
    digitalWrite(pin7,LOW);
    digitalWrite(pin8,HIGH);
    break;

    case(6):
    digitalWrite(pin5,LOW);
    digitalWrite(pin6,HIGH);
    digitalWrite(pin7,HIGH);
    digitalWrite(pin8,LOW);
    break;

    case(7):
    digitalWrite(pin5,LOW);
    digitalWrite(pin6,HIGH);
    digitalWrite(pin7,HIGH);
    digitalWrite(pin8,HIGH);
    break;

    case(8):
    digitalWrite(pin5,HIGH);
    digitalWrite(pin6,LOW);
    digitalWrite(pin7,LOW);
    digitalWrite(pin8,LOW);
    break;

    case(9):
    digitalWrite(pin5,HIGH);
    digitalWrite(pin6,LOW);
    digitalWrite(pin7,LOW);
    digitalWrite(pin8,HIGH);
    break;    
  }
switch(decenas){
    case(0):
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,LOW);
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,LOW);
    break;

  
    case(1):
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,LOW);
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,HIGH);
    break;

    case(2):
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,LOW);
    digitalWrite(pin3,HIGH);
    digitalWrite(pin4,LOW);
    break;

    case(3):
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,LOW);
    digitalWrite(pin3,HIGH);
    digitalWrite(pin4,HIGH);
    break;

    case(4):
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,HIGH);
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,LOW);
    break;

    case(5):
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,HIGH);
    digitalWrite(pin3,LOW);
    digitalWrite(pin4,HIGH);
    break;
    
}













}
//Funciones de ISR
void funcion_ISR_rising(void){

unidades++;
  
  
  
}
void funcion_ISR_falling(void){
  
unidades--;
      
  
}
  
