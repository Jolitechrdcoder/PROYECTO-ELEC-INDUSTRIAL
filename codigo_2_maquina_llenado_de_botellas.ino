#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int sensor1 = 2;//sensor 1
int cinta = 3;//rele que enciende cinta
int bomba =4;//rele2 
int estado = 0;//estado del sensor 1
int cont = 0;
void setup()
{

  Serial.begin(9600);
   lcd.init();
  lcd.backlight();    
  pinMode(sensor1,INPUT);
  pinMode(cinta,OUTPUT);
  pinMode(bomba,OUTPUT);
  
}
//Algoritmo maquina llenado
void loop()
{
  estado = digitalRead(sensor1);//Almacena lectura del sensor 
 
  
  if(estado == 0){//Condicional cinta transportadora y llenado.
  cont++;
   Serial.println(cont);
  digitalWrite(cinta,1);//DETENGO MOTOR CINTA
  delay(500);
  digitalWrite(cinta,0);
  delay(500);
  digitalWrite(cinta,1);
    digitalWrite(bomba,1);//enciendo bomba
    Serial.println("!!LLENANDO!!");
    delay(6000);//tiempo de llenado
   
  }
  else{
    
    digitalWrite(cinta,0);
    digitalWrite(bomba,0);
    
    }

    
 
}
