const byte red = 11;
const byte green = 12;
const byte blue = 13;
void colorLED(int,boolean,boolean,boolean);
void setup() {
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
}//初始化工作
static int offTime,counter = 0;
void loop() {
    boolean a = digitalRead(8);
    boolean b = digitalRead(9);
    boolean c = digitalRead(10);
    while(a||b||c){
      
      if (offTime < 1000 && counter < 1000)
        offTime++;
      else if (counter >= 1000)offTime--;
      if (counter < 1999)counter++;
      else break;
      colorLED(offTime,digitalRead(8),digitalRead(9),digitalRead(10));
    }
    offTime=0;
    counter=0;
     digitalWrite(11,LOW);
     digitalWrite(12,LOW);
     digitalWrite(13,LOW);
}//Main Loop

void colorLED(int DLY,boolean r,boolean g,boolean b)
{
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  delayMicroseconds(1000 - DLY);
  if(r)digitalWrite(red, HIGH);
  if(g)digitalWrite(green, HIGH);
  if(b)digitalWrite(blue, HIGH);
  delayMicroseconds(DLY);
}//LED script
