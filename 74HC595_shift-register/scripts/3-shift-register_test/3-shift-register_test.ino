#define DataPin 11     // ds
#define LatchPin 12    // ST_CP   
#define ClockPin 13    // SH_CP   i pin dello shift register per la gestione delle uscita dello shift register

/*
  LP = 0 -> L'integrato scrive su Q0-Q7
  LP = 1 -> ?
*/

void setup () {
    pinMode(ClockPin, OUTPUT);
    pinMode(LatchPin, OUTPUT);
    pinMode(DataPin, OUTPUT);
    
    digitalWrite(LatchPin, LOW);
    // il valore delle uscite viene scritto in esadecimare
    shiftOut(DataPin, ClockPin, MSBFIRST, 0xff);
    digitalWrite(LatchPin, HIGH);

}

void loop() {
  digitalWrite(LatchPin, LOW);
  delay(200);

  digitalWrite(DataPin, HIGH);
  delay(200);
  digitalWrite(DataPin, LOW);
  delay(200);
  
  digitalWrite(DataPin, HIGH);
  delay(200);
  digitalWrite(DataPin, LOW);
  delay(200);
  
  digitalWrite(LatchPin, HIGH);
  delay(200);
  
 

}
