// inclusione della libreria Stepper 
#include <Stepper.h>

// definizione del numero di passi per rotazione
const int stepsPerRevolution = 2048;

// creazione dell'istanza della classe stepper

/*
 * IN1 -> 7
 * IN2 -> 6
 * IN3 -> 5
 * IN4 -> 4
 */
 
Stepper myStepper(stepsPerRevolution, 7, 6, 5, 4);

void setup() {
  /* 
   * non è necessario impostare i pin di Arduino
   * a cui collegare la scheda dello stepper 
   * vengono gestiti dalla libreria
   */
  
  // imposta la velocità a 15 rpm:
  myStepper.setSpeed(17);
  
  // inizializzazione della porta seriale
  Serial.begin(9600);
}

void loop() {
  // imposta una rotazione in senso orario
  Serial.println("orario");
  myStepper.step(stepsPerRevolution);
  delay(500);

  // imposta una rotazione in senso antiorario
  Serial.println("antiorario");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}