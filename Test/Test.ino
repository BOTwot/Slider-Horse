 /* read a rotary encoder with interrupts
   Encoder hooked up with common to GROUND,
   encoder0PinA to pin 2, encoder0PinB to pin 4 (or pin 3 see below)
   it doesn't matter which encoder pin you use for A or B

   uses Arduino pull-ups on A & B channel outputs
   turning on the pull-ups saves having to hook up resistors
   to the A & B channel outputs

*/

#define encoder0PinA  2
//#define encoder0PinB  3
//#define pin1 10
//#define pin2 11
float angle;
volatile unsigned int encoder0Pos = 0;

void setup() {
  pinMode(encoder0PinA, INPUT_PULLUP);
       // turn on pull-up resistor
  //pinMode(encoder0PinB, INPUT_PULLUP);
       // turn on pull-up resistor
//  pinMode(pin1,OUTPUT);
//  pinMode(pin2,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), doEncoder, CHANGE);
//    attachInterrupt(digitalPinToInterrupt(3), doEncoder, CHANGE);// encoder pin on interrupt 0 - pin 2
  Serial.begin (9600);
  Serial.println("start");                // a personal quirk
}

void loop() {
    Serial.println (encoder0Pos);
}
void doEncoder() {
    encoder0Pos++;
    //angle=encoder0Pos*1.285714;
}

