


#define AABUTTON  0
#define BBBUTTON  1
#define SLBUTTON  2
#define STBUTTON  3
#define UPBUTTON  4
#define DNBUTTON  5
#define LTBUTTON  6
#define RTBUTTON  7

#define LTC 8
#define CLK 9
#define DTA 10

void setup(){
  //Serial.begin(9600);
  pinMode(AABUTTON, INPUT);
  pinMode(BBBUTTON, INPUT);
  pinMode(SLBUTTON, INPUT);
  pinMode(STBUTTON, INPUT);
  pinMode(UPBUTTON, INPUT);
  pinMode(DNBUTTON, INPUT);
  pinMode(LTBUTTON, INPUT);
  pinMode(RTBUTTON, INPUT);
  pinMode(CLK, INPUT);
  pinMode(LTC, INPUT);
  pinMode(DTA, OUTPUT);
}

void loop()
{

  boolean aa = digitalRead(AABUTTON);
  boolean bb = digitalRead(BBBUTTON);
  boolean sl = digitalRead(SLBUTTON);
  boolean st = digitalRead(STBUTTON);
  boolean up = digitalRead(UPBUTTON);
  boolean dn = digitalRead(DNBUTTON);
  boolean lt = digitalRead(LTBUTTON);
  boolean rt = digitalRead(RTBUTTON);

  while(digitalRead(LTC) == LOW);
  //A
  digitalWrite(DTA, aa);
  digitalWrite(DTA, aa);
  digitalWrite(DTA, aa);
  
  //B
  digitalWrite(DTA, bb);
  digitalWrite(DTA, bb);
  digitalWrite(DTA, bb);
  
  //Select
  digitalWrite(DTA, sl);
  digitalWrite(DTA, sl);
  digitalWrite(DTA, sl);
  
  //Start -- V
  digitalWrite(DTA, st);
  digitalWrite(DTA, st);
  digitalWrite(DTA, st);
  
  // Up
  digitalWrite(DTA, up);
  digitalWrite(DTA, up);
  digitalWrite(DTA, up);
  digitalWrite(DTA, up);
 
  // Down
  digitalWrite(DTA, dn);
  digitalWrite(DTA, dn);
  digitalWrite(DTA, dn);
 
  //Left
  digitalWrite(DTA, lt);
  digitalWrite(DTA, lt);
  digitalWrite(DTA, lt);

  //Right
  digitalWrite(DTA, rt);
  digitalWrite(DTA, rt);
  digitalWrite(DTA, rt);

  digitalWrite(DTA, HIGH);
}
