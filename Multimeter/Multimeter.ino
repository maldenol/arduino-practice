/*
  Multimeter
  By MalDenOl
  Maluovany Denis Olegovich (21.11.2003, Vinnytsia, Ukraine)
  06-07.02.2019
*/

#include <iarduino_OLED_txt.h>

#define COUNT 3
#define TPS 1

String STRINGS[COUNT][2] = {
  {"Voltage : " , " "},
  {"Resistance : " , " "},
  {"Amperage : " , " "},
};
int SENSOR[COUNT] = {
  A1,
  A2,
  A3,
};
int SENSON[COUNT] = {0};
float RESIST[COUNT] = {
  100,
  100,
  100,
};

iarduino_OLED_txt oled(0x78);
extern uint8_t SmallFontRus[];

void setup() {
  Serial.begin(9600);
  
  for(int i = 0; i < COUNT; i++)
    pinMode(SENSOR[i], INPUT);
  
  oled.begin();
  oled.setFont(SmallFontRus);
};

void loop() {
  oled.clrScr();
  
  for(int i = 0; i < COUNT; i++)
  {
    oled.print(STRINGS[i][0], 0, i);
    oled.print((SENSON[i]) ? analogRead(SENSOR[i] : 0);
    oled.print(STRINGS[i][1]);
  }
  
  delay(1 / TPS);
};

