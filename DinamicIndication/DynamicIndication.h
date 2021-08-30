/* 
 * Dynamic indication library 
 * for seven-segment indicators 
 * by MalDenOl ( Maluovaniy Denis ).
*/

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
int dpins[7], vpins[4];

void setssi(int D[], int V[]){
  short int i = 0;
  while(i < 7)
  {
  	dpins[i]=D[i];
  	pinMode(D[i], OUTPUT);
    i++;
  }
  i = 0;
  while(i < 4)
  {
  	vpins[i]=V[i];
  	pinMode(V[i], OUTPUT);
    i++;
  }
}

void draw(float num, short int point){
  int dig[4] = {int(num*pow(10, point-3))%10, int(num*pow(10, point-2))%10, int(num*pow(10, point-1))%10, int(num*pow(10, point))%10},
            i = 0,
            j = 0;
  while(i < 4)
  {
    j = 0;
    digitalWrite(vpins[i], LOW);
    while(j < 7)
    {
      if(digits[dig[i]][j])
        digitalWrite(dpins[j], HIGH);
      else
        digitalWrite(dpins[j], LOW);
      j++;
    }
    digitalWrite(vpins[i], HIGH);
    i++;
    delay(1);
  }
}

void draw(int num){
  int dig[4] = {num/1000%10, num/100%10, num/10%10, num%10},
            i = 0,
            j = 0;
  while(i < 4)
  {
    j = 0;
    digitalWrite(vpins[i], LOW);
    while(j < 7)
    {
      if(digits[dig[i]][j])
        digitalWrite(dpins[j], HIGH);
      else
        digitalWrite(dpins[j], LOW);
      j++;
    }
    digitalWrite(vpins[i], HIGH);
    i++;
    delay(1);
  }
}
