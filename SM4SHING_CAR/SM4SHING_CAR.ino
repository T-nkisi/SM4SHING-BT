#include <SoftwareSerial.h>
SoftwareSerial BT05(0,1);
char Dato;

#define A1 9
#define A2 8
#define B1 3
#define B2 4

#include <Servo.h>
Servo MB;

void setup() {

  BT05.begin(9600);
  
  pinMode(A1, OUTPUT); // Asignamos Pines como salidas ' 1 = OUTPUT ; 0 = INPUT '
  pinMode(A2, OUTPUT);
  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT); 

  MB.attach(6);
  MB.writeMicroseconds(1000);
  delay(5000);
}

void loop() {

  /*if(BT05.available()){        // lee el bluetooth y almacena en estado */
  Dato = BT05.read();  // Dato leera los comando que enviemos a BT
  delay(100);
  /*} */

  if(Dato == '0')  // Detenido
  {
    digitalWrite(A1, LOW);
    digitalWrite(A2, LOW);
    digitalWrite(B1, LOW);
    digitalWrite(B2, LOW);
  }
  
  if(Dato == '1')  // Adelante
  {
    digitalWrite(A1, LOW);
    digitalWrite(A2, HIGH);
    digitalWrite(B1, LOW);
    digitalWrite(B2, HIGH); 
  }

  if(Dato == '2')  // Derecha
  {
    digitalWrite(A1, HIGH);
    digitalWrite(A2, LOW);
    digitalWrite(B1, LOW);
    digitalWrite(B2, HIGH); 
  } 

   if(Dato == '3')  // Atras
  {
    digitalWrite(A1, HIGH);
    digitalWrite(A2, LOW);
    digitalWrite(B1, HIGH);
    digitalWrite(B2, LOW);
  } 
 
  if(Dato == '4')  // Izquierda
  {
    digitalWrite(A1, LOW);
    digitalWrite(A2, HIGH);
    digitalWrite(B1, HIGH);
    digitalWrite(B2, LOW);
  } 

  if(Dato == '8')  // Motor Brushless activo
  {
    MB.write(55);
  }

  if(Dato == '9')  // Motor Brushless activo
  {
    MB.write(0);
  } 
}
