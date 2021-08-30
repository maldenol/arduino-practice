void setup(){
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}
short int port[]={3,5,6,9,10,11,13};
void loop(){
  for(int i=0;i<7;i++)
  {
    for(int j=0;j<=256;j++)
    {
      analogWrite(port[i], j);
      if(j>125){
       analogWrite(port[i+1], j-125);       
        }
      if(j==256){
        i=(i+1)%7;
      }
      delay(10);
     }
  }
}
