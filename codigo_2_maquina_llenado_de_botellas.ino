#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(34, 16, 2);
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
  lcd.setCursor(0, 1);
    lcd.print("Botellas:");
  
  
}
//Algoritmo maquina llenado
void loop()
{
  estado = digitalRead(sensor1);//Almacena lectura del sensor 
 
  
  if(estado == 1){//Condicional cinta transportadora y llenado.
  cont++;
    lcd.setCursor(10, 1);
   lcd.print(cont);
   Serial.println(cont);
  digitalWrite(cinta,1);//DETENGO MOTOR CINTA
  delay(500);
  digitalWrite(cinta,0);
  delay(500);
  digitalWrite(cinta,1);
    digitalWrite(bomba,1);//enciendo bomba
    lcd.setCursor(0, 0);
    lcd.print("  !!LLENANDO!!");
    Serial.println("!!LLENANDO!!");
    delay(6000);//tiempo de llenado
   
  }
  else{
    lcd.setCursor(0, 0);
    lcd.print("               ");
    digitalWrite(cinta,0);
    digitalWrite(bomba,0);
    
    }

    
 
}
