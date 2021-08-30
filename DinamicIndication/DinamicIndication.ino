#define A 13
#define B 10
#define C 5
#define D 6
#define E 9
#define F 11
#define G 3
#define A1 2
#define A2 4
#define A3 7
#define A4 8
bool digits[10][7]={
  {true,true,true,true,true,true,false},
  {false,true,true,false,false,false,false},
  {true,true,false,true,true,false,true},
  {true,true,true,true,false,false,true},
  {false,true,true,false,false,true,true},
  {true,false,true,true,false,true,true},
  {true,false,true,true,true,true,true},
  {true,true,true,false,false,false,false},
  {true,true,true,true,true,true,true},
  {true,true,true,true,false,true,true}
};
void setup(){
  Serial.begin(9600);
  for(short int i=2;i<=13;i++)
    pinMode(i, OUTPUT);
  pinMode(A1, OUTPUT);
  digitalWrite(A1, HIGH);
  pinMode(A2, OUTPUT);
  digitalWrite(A2, HIGH);
  pinMode(A3, OUTPUT);
  digitalWrite(A3, HIGH);
  pinMode(A4, OUTPUT);
  digitalWrite(A4, HIGH);
}
char num[4];
short int dig=0;
void loop(){
  while(Serial.available()>0)
  {
    if(dig==4)
    {
      dig=0;
    }
    num[dig]=Serial.read()-'0';
    dig++;
  }
  digitalWrite(A1, LOW);
  draw(num[0]);
  digitalWrite(A1, HIGH);
  digitalWrite(A2, LOW);
  draw(num[1]);
  digitalWrite(A2, HIGH);
  digitalWrite(A3, LOW);
  draw(num[2]);
  digitalWrite(A3, HIGH);
  digitalWrite(A4, LOW);
  draw(num[3]);
  digitalWrite(A4, HIGH);
}
void draw(short int j){
  if(digits[j][0])
    digitalWrite(A, HIGH);
  else
    digitalWrite(A, LOW);
  if(digits[j][1])
    digitalWrite(B, HIGH);
  else
    digitalWrite(B, LOW);
  if(digits[j][2])
    digitalWrite(C, HIGH);
  else
    digitalWrite(C, LOW);
  if(digits[j][3])
    digitalWrite(D, HIGH);
  else
    digitalWrite(D, LOW);
  if(digits[j][4])
    digitalWrite(E, HIGH);
  else
    digitalWrite(E, LOW);
  if(digits[j][5])
    digitalWrite(F, HIGH);
  else
    digitalWrite(F, LOW);
  if(digits[j][6])
    digitalWrite(G, HIGH);
  else
    digitalWrite(G, LOW);
  delay(1);
}
