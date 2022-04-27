#include "utils.h"
#include "class_ByteOfChar.h"

#define DATA 11
#define LATCH 12
#define CLOCK 13

void setup(){
  Serial.begin(9600);  
  pinMode(DATA, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLOCK, OUTPUT);
}

void loop () {
    
}
