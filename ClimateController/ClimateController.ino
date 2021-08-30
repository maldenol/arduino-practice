/*
  Climate Controller
  By MalDenOl
  Maluovany Denis Olegovich (21.11.2003, Vinnytsia, Ukraine)
  24.12.2018
*/

#include <iarduino_OLED_txt.h>
#include <DHT.h>

#define THP_PIN 2
#define PHOTORESISTOR_PIN 1
#define RADIO_PIN 4
#define SIGNAL_PIN 2
#define SENSORS 4
#define SECONDS 3

String STRINGS[SENSORS][2] = {
  {"Temperat : " , " C  "},
  {"Humidity : " , " %  "},
  {"Pressure : " , " mmm"},
  {"Illumina : " , " Lux"},
};
int READINGS[SENSORS] = {0};
const int READLIMITS[SENSORS][2] = {
  {18, 25},
  {40, 65},
  {720, 740},
  {0, 0x7FFFFFFF},
};

int timeArray[5] = {0};
const int timeIndicators = 5;
const int timeLimits[timeIndicators] = {0x7FFFFFFF, 365, 24, 60, 60};

DHT sens(THP_PIN, DHT22);

iarduino_OLED_txt oled(0x78); // can be cuted
extern uint8_t SmallFontRus[]; // can be cuted

void setup()
{
  Serial.begin(9600);
  
  pinMode(THP_PIN, INPUT);
  pinMode(PHOTORESISTOR_PIN, INPUT);
  pinMode(RADIO_PIN, INPUT);
  pinMode(SIGNAL_PIN, OUTPUT);
  
  sens.begin();
  
  oled.begin();
  oled.setFont(SmallFontRus);
};

void loop()
{
	READINGS[0] = sens.readTemperature();
  READINGS[1] = sens.readHumidity();
  
  oled.clrScr();
  for(int i = 0; i < SENSORS; i++)
  {
    oled.print(STRINGS[i][0], 0, i);
    oled.print(READINGS[i]);
    oled.print(STRINGS[i][1]);
  }

  oled.print("", 0, SENSORS + 1);
  for(int i = 0; i < timeIndicators; i++)
  {
    if(timeArray[i] < 10)
      oled.print("0");
    oled.print(timeArray[i]);
    if(i < timeIndicators - 1)
      oled.print(":");
  }

  sign();
  
  delay(1000 * SECONDS);

  timeCounter(4, SECONDS);
};

void timeCounter(int i, int add)
{
  if(i < 0 || i >= timeIndicators)
    return;
  timeArray[i] += add;
  if(i > 0 && timeArray[i] >= timeLimits[i])
  {
    add = timeArray[i] / timeLimits[i];
    timeArray[i] %= timeLimits[i];
    timeCounter(i - 1, add);
  }
};

void sign()
{
  boolean on = false;
  for(int i = 0; i < SENSORS; i++)
    if(READINGS[i] < READLIMITS[i][0] || READINGS[i] > READLIMITS[i][1])
    {
      on = true;
      break;
    }
  if(on)
  {
    pinMode(SIGNAL_PIN, HIGH);
    return;
  }
  pinMode(SIGNAL_PIN, LOW);
};

