// Definition of interrupt names
#include < avr/io.h >
// ISR interrupt service routine
#include < avr/interrupt.h >

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

boolean aa;
boolean bb;
boolean sl;
boolean st;
boolean up;
boolean dn;
boolean lt;
boolean rt;

void setup(){
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
  InitialiseInterrupt();
}

void loop()
{
  aa = digitalRead(AABUTTON);
  bb = digitalRead(BBBUTTON);
  sl = digitalRead(SLBUTTON);
  st = digitalRead(STBUTTON);
  up = digitalRead(UPBUTTON);
  dn = digitalRead(DNBUTTON);
  lt = digitalRead(LTBUTTON);
  rt = digitalRead(RTBUTTON);
}

void InitialiseInterrupt(){
  cli();		// switch interrupts off while messing with their settings  
  PCICR  = 0x01;          // Enable PCINT0 interrupt
  PCMSK0 = 0b00000001;
  sei();		// turn interrupts back on
}

ISR(PCINT0_vect) {    // Interrupt service routine. Every single PCINT8..14 (=ADC0..5) change
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

