#include "class_ByteOfChar.h"

#define Data 11
#define Latch 12
#define Clock 13

void setup(){
  Serial.begin(9600);  
  pinMode(Data, OUTPUT);
  pinMode(Latch, OUTPUT);
  pinMode(Clock, OUTPUT);
}

//byte register_1 = 11000000;   /* x_7..x_0 */
//byte register_2 = 11100000;   /* y_7..y_0 */

// 00110011    54
// 00110010    53

void loop(){
  writeRegister(0x00);

  //ByteOfChar tmp = ByteOfChar('0','1','1','1','1','1','1','0');
  //ByteOfChar tmp = ByteOfChar('0','1','1','1','1','1','1','1');
  ByteOfChar tmp = ByteOfChar('1','1','1','1','1','1','1','1','0');
  Serial.println(tmp.get_n());
  
  //animation1(50);
  //animation2(50);
}

void writeRegister(unsigned int value){
  /*
   *        Register 2   Register 1
   * byte:  0000  0000   0000  0000
   * pos:   y_7....y_0   x_7....x_0
   * 
   * MSBFIRST -> La macchina legge (da SX verso DX): y_7..y_0x_7..x_0
   * LSBFIRST -> La macchina legge (da SX verso DX): x_0..x_7y_0..y_7
  */
  digitalWrite(Latch, LOW);                     // Si abilita la scrittura sugli shift register
  shiftOut(Data, Clock, MSBFIRST, value >> 8);
  shiftOut(Data, Clock, MSBFIRST, value);
  digitalWrite(Latch, HIGH);                    // Si disabilita la scrittura sugli shift register
}

void animation1(unsigned int animationDelay){
  for(int i = 0; i < 16; i++){
    writeRegister(0x1 << i);
    delay(animationDelay);
  }
  for(int i = 0; i < 16; i++){
    writeRegister(0x8000 >> i);
    delay(animationDelay);
  }
}

void animation2(unsigned int animationDelay){
  unsigned int value = 0x1;
  for(int i = 0; i < 16; i++){
    writeRegister(value);
    value = (value << 1) + 1;
    delay(animationDelay);
  }
  for(int i = 0; i < 16; i++){
    writeRegister(value);
    value = value >> 1;
    delay(animationDelay);
  }
}
