#define R 3
#define G 5
#define B 6
void setup(){
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  for(short int i=0;i<=255;i++)
  {
    analogWrite(R, i);
    delay(5);
  }
  delay(15);
}
short int RED=0, GREEN=0, BLUE=0;
void loop(){
  for(short int i=255;i>=0;i--)
  {
    analogWrite(R, i);
    delay(5);
  }
  for(short int i=0;i<=255;i++)
  {
    analogWrite(G, i);
    delay(15);
  }
  for(short int i=0;i<=255;i++)
  {
    analogWrite(B, i);
    delay(15);
  }
  for(short int i=255;i>=0;i--)
  {
    analogWrite(G, i);
    delay(15);
  }
  for(short int i=0;i<=255;i++)
  {
    analogWrite(R, i);
    delay(15);
  }
  delay(50);
  for(short int i=255;i>=0;i--)
  {
    analogWrite(B, i);
    delay(15);
  }
}
