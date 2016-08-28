int IR_LED = 2;

void setup() {
  pinMode(IR_LED, OUTPUT);
  cli();
}

void loop() {
  // 38 kHz is about 13 microseconds high and 13 microseconds low
   digitalWrite(IR_LED, HIGH);    // this takes about 3 microseconds to happen
   delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working
   digitalWrite(IR_LED, LOW);     // this also takes about 3 microseconds
   delayMicroseconds(10);         // hang out for 10 microseconds, you can also change this to 9 if its not working
 
}
