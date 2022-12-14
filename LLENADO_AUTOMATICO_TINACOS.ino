#include <LiquidCrystal_I2C.h>
#include<Wire.h>
LiquidCrystal_I2C lcd(34,16,2);
int TRIG = 10;			// trigger en pin 10
int ECO = 9;			// echo en pin 9
int LED = 3;			// LED en pin 3
int DURACION;
int DISTANCIA;    // hola jorge es julio xdxd
int VERDE = 4;
int NARANJA = 5;
int ROJO= 6;
int tenpo = 200;
int BUZZER = 2;

void setup(){
  lcd.init();
    lcd.backlight();
  pinMode(BUZZER,OUTPUT);
  
  digitalWrite(BUZZER,1);
  delay(100);
  digitalWrite(BUZZER,0);
  delay(100);
  digitalWrite(BUZZER,1);
  delay(100);
    digitalWrite(BUZZER,0);
  lcd.setCursor(0,0);
  lcd.print (" Sistema LLenado ");
    lcd.setCursor(0,1);
  lcd.print ("  !Automatico!");
  delay(2000);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print ("  !!Cargando!!");
  delay(tenpo);

  lcd.setCursor(0,1);
  lcd.print ("©");
  delay(tenpo);
  
  lcd.setCursor(1,1);
  lcd.print ("©");
  delay(tenpo);
  
   lcd.setCursor(2,1);
  lcd.print ("©");
  delay(tenpo);
 
  lcd.setCursor(3,1);
  lcd.print ("©");
  delay(tenpo);
  
  lcd.setCursor(4,1);
  lcd.print ("©");
  delay(tenpo);
  
   lcd.setCursor(5,1);
  lcd.print ("©");
  delay(tenpo);
  
  lcd.setCursor(6,1);
  lcd.print ("©");
  delay(tenpo);
  
  lcd.setCursor(7,1);
  lcd.print ("©");
  delay(tenpo);
  
  lcd.setCursor(8,1);
  lcd.print ("©");
  delay(tenpo);
  
   lcd.setCursor(9,1);
  lcd.print ("©");
  delay(tenpo);
  
   lcd.setCursor(10,1);
  lcd.print ("©");
  delay(tenpo);
  
   lcd.setCursor(11,1);
  lcd.print ("©");
  delay(tenpo);
  
   lcd.setCursor(12,1);
  lcd.print ("©");
  delay(tenpo);
  
   lcd.setCursor(13,1);
  lcd.print ("©");
  delay(tenpo);
 
   lcd.setCursor(14,1);
  lcd.print ("©");
  delay(tenpo);
  
   lcd.setCursor(15,1);
  lcd.print ("©");
  delay(tenpo);
  lcd.clear();
 pinMode(TRIG, OUTPUT); 	// trigger como salida
  pinMode(ECO, INPUT);		// echo como entrada
  pinMode(LED, OUTPUT);		// LED como salida
  Serial.begin(9600);  		// inicializacion de comunicacion serial a 9600 bpsl Echo
}

void loop(){
  digitalWrite(TRIG, HIGH); 		// generacion del pulso a enviar
  delay(1);				// al pin conectado al trigger
  digitalWrite(TRIG, LOW);		// del sensor
  
  DURACION = pulseIn(ECO, HIGH);	// con funcion pulseIn se espera un pulso
  					
  DISTANCIA = DURACION / 58.2;		// distancia medida en centimetros
  Serial.println(DISTANCIA);		// envio de valor de distancia por monitor serial
  delay(200);	
 
             
                              //Monitorización en centímetros por el monitor serial
  Serial.println("Distancia ");   //Imprimimos "Distancia" sobre el Monitor Serial
  Serial.println(DISTANCIA);   //Mostramos el Valor de la distancia real sobre el Monitor Serial 
  Serial.println(" cm");   //Imprimimos " cm" sobre el Monitor Serial
  lcd.setCursor(0,0);
  lcd.print("NIVEL:");
   lcd.print(DISTANCIA);
    lcd.print(" ");
   lcd.setCursor(10,0);
      lcd.print(" ");
  
  // condicion tanque lleno
  if (DISTANCIA <= 40 && DISTANCIA >= 0){	// si distancia entre 0 y 20 cms.
    digitalWrite(LED, 0);	
    digitalWrite(VERDE,1);
     lcd.setCursor(0,1);
     lcd.print("!!LLENO!!");
     Serial.println("TANQUE LLENO");
    }
  else{
    digitalWrite(VERDE,0);
    digitalWrite(LED,1);
    lcd.setCursor(0,1);
     lcd.print("          ");
    
    
  }
  //condicion tanque mitad
  
  if(DISTANCIA<=60 && DISTANCIA >=40 ){
  
  
   digitalWrite(NARANJA,1);
  lcd.setCursor(0,1);
     lcd.print("!!MEDIO!!");
    Serial.println("TANQUE MEDIO");
  
  }
  else{
   digitalWrite(NARANJA,0);
    
    
  }
  //condicion tanque vacio
  if(DISTANCIA<=120 &&  DISTANCIA >=60){
   
  digitalWrite(ROJO,1);
  lcd.setCursor(0,1);
     lcd.print("!!BAJO!!");
    Serial.println("TANQUE BAJO");
  
  }
  else{
  
  digitalWrite(ROJO,0);
   
  }
  delay(1000); //Cada que Tiempo se imprimira el valor de la distancia 
}
