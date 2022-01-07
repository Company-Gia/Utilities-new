#define DataPin 11     // ds
#define LatchPin 12    // ST_CP   
#define ClockPin 13    // SH_CP   i pin dello shift register per la gestione delle uscita dello shift register

/*
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

}
