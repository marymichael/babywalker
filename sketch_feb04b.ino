void setup() 
{
  pinMode(9,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
}
void loop() 
{
  

for(int fadeValue = 0;fadeValue<=255;fadeValue+=225)
  {
    analogWrite(9,fadeValue);
    delay(30);
  }
  for(int fadeValue = 255;fadeValue>=0;fadeValue-=225)
  {
    analogWrite(9,fadeValue);
    delay(30);
  }for(int fadeValue = 0;fadeValue<=255;fadeValue+=225)
  {
    analogWrite(3,fadeValue);
    delay(60);
  }
  for(int fadeValue = 255;fadeValue>=0;fadeValue-=225)
  {
    analogWrite(3,fadeValue);
    delay(60);
  }for(int fadeValue = 0;fadeValue<=255;fadeValue+=225)
  {
    analogWrite(5,fadeValue);
    delay(90);
  }
  for(int fadeValue = 255;fadeValue>=0;fadeValue-=225)
  {
    analogWrite(5,fadeValue);
    delay(90);
  }
}
