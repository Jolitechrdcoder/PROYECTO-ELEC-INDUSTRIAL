#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(34, 16, 2);
int sensor1 = 2;//infrarojo llenado
int sensor2 = 5;
int rele = 3;//rele que enciende cinta 
int estado = 0;
int estado2 = 0;
int bomba =4;
int sellado=13;
void setup()
{

  Serial.begin(9600);
   lcd.init();
  lcd.backlight();    
  pinMode(sensor1,INPUT);
  pinMode(rele,OUTPUT);
  pinMode(bomba,OUTPUT);
  pinMode(sellado,OUTPUT);
}

void loop()
{
  estado = digitalRead(sensor1);//LECTURA SENSOR
  estado2= digitalRead(sensor2);//LECTURA SENSOR 2
  
  if(estado == 0){//ESTADO CUANDO LLEGA BOTELLA = 0 LOGICO EN EL SENSOR
  
  digitalWrite(rele,1);//DETENGO MOTOR CINTA
    digitalWrite(bomba,1);//enciendo bomba
    Serial.println("!!LLENANDO!!");
    delay(30000);//tiempo de llenado
  
  }
  else{
    
    digitalWrite(rele,0);
    digitalWrite(bomba,0);
    
    }

    if(estado2 == 0){
      digitalWrite(sellado,1);
      Serial.println("!!SELLANDO!!");
      delay(10000);//tiempo de llenado
      
      }
      else{
        
        digitalWrite(sellado,0);
        }
 
}
