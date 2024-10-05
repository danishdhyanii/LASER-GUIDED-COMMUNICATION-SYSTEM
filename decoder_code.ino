//DECODER CODE

int sensorPin = A0; 
int sensorValue  = 0; 
int a, f; // flags
void  setup() {
Serial.begin(9600); 
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);

}
void  loop() {

sensorValue = analogRead(sensorPin); // read the value from the  sensor
//Serial.println(sensorValue);
if(sensorValue>1000)
{
  for(int i=0;i<=15;i++)
  {
    sensorValue=analogRead(sensorPin);
    if(sensorValue>1000)
    {
      a++; 
     delay(50);
    }
  else
  {
    f++;  
   delay(50);
  }
  
  }
}
//Serial.print("a= "+a);
//Serial.println("f= "+f);
//Serial.println();


if(a==4 && f==12)
{
  Serial.print("a");
}
if(a==6 && f==10)
{
  Serial.print("b");
}
if(a==8  && f==8)
{
  Serial.print("c");  
}
if(a==1 && f==15)
{
  Serial.print("e");
}
if(a==2  && f==14)
{
  Serial.print("i");
}
if(a==10 && f==6)
{
  Serial.print("j");
}
if(a==7  && f==9)
{
  Serial.print("g");
}
if(a==9 && f==7)
{
  Serial.print("o");
}
if(a==3  && f==13)
{
  Serial.print("s");
}
if(a==13 && f==3){
  Serial.print("f");
}
if(a == 5 && f == 11) {
  Serial.print("d");
}



 else if(a == 4 && f == 8) {
  Serial.print("h");
} else if(a == 7 && f == 6) {
  Serial.print("k");
} else if(a == 6 && f == 9) {
  Serial.print("l");
} else if(a == 6 && f == 7) {
  Serial.print("m");
} else if(a == 4 && f == 9) {
  Serial.print("n");
} else if(a == 8 && f == 6) {
  Serial.print("p");
} else if(a == 10 && f == 5) {
  Serial.print("q");
} else if(a == 5 && f == 5) {
  Serial.print("r");
} else if(a == 3 && f == 7) {
  Serial.print("t");
} else if(a == 5 && f == 7) {
  Serial.print("u");
} else if(a == 6 && f == 3) {
  Serial.print("v");
} else if(a == 7 && f == 5) {
  Serial.print("w");
} else if(a == 8 && f == 5) {
  Serial.print("x");
} else if(a == 10 && f == 3) {
  Serial.print("y");
} else if(a == 8 && f == 1) {
  Serial.print("z");
}
else if(a == 6 && f == 7) {
  Serial.print("f");
}
if(sensorValue>1000){
  digitalWrite(8,HIGH);
  delay(50);}
 else{ digitalWrite(8,LOW);}
 
  if(sensorValue>1000){
  digitalWrite(9,HIGH);
  delay(50);}
 else{ digitalWrite(9,LOW);}
  


// ... remaining code ...

f=a=0;
delay(50);

}