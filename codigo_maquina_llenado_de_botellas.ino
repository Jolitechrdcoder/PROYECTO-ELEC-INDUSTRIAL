/* codigo llenado banda version 1.0
  ///////////////////////////////////
  Proyecto Final elec industrial
  - jorge Luis Martinez suarez
  - Julio de la rosa perez
  - Viktor luis zapata de la rosa
  - Emil rafael dirocie
  -Gabriel elias paulino
  ///////////////////////////////////
*/

#include <Stepper.h>

#define STEPS 200//numero de pasos motor


#define motorInterfaceType 1

Stepper stepper(STEPS, 2, 4);

int relay = 13;

int step_num = 700;

void setup() {

  Serial.begin(9600);

  pinMode(relay, OUTPUT);

  stepper.setSpeed(500);

  pinMode(4, OUTPUT);

  pinMode(2, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(3), IR_detected, RISING);

  boolean solenoid_on = false;

  void loop() {

    if (solenoid_on)
    {
      delay(9000); //tiempo de llenado botellas
      solenoid_on = false;

    }

    digitalWrite(relay, LOW);   // se apaga bomba

    stepper.step(step_num);

  }

  void IR_detected()           //funcion sensor

  {

    Serial.println ("LLENANDO BOTELLA");

    stepper.step(150); //pasos motor antes de detenerse

    digitalWrite(relay, HIGH); //enciendo relay o bomba

    stepper.step(0); //parada motor

    solenoid_on = true;


  }
