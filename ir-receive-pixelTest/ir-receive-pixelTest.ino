#include <Adafruit_NeoPixel.h>
int PIN = 9;
int IR_SENSOR = 12;
int LED = 2;
int NUM_PIX = 4;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIX, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pinMode(IR_SENSOR, INPUT);
  pinMode(LED, OUTPUT);
  strip.begin();
  strip.show();
}

void loop() {
  if (digitalRead(IR_SENSOR)) {
    digitalWrite(LED, HIGH);
    timedRainbowCycle(500, 10);
  } else {
    digitalWrite(LED, LOW);
  }
}

void timedRainbowCycle(uint32_t milliseconds, uint8_t wait) {
  // Get the starting time in milliseconds.
  uint32_t start = millis();
  // Use a counter to increment the current color position.
  uint32_t j = 0;
  // Loop until it's time to stop (desired number of milliseconds have elapsed).
  while (millis() - start < milliseconds) {
    // Change all the light colors.
    for (int i = 0; i < strip.numPixels(); ++i) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    // Wait the deisred number of milliseconds.
    delay(wait);
    // Increment counter so next iteration changes.
    j += 1;
  }
  // Turn all the pixels off after the animation is done.
  for (int i = 0; i < strip.numPixels(); ++i) {
    strip.setPixelColor(i, 0);
  }
  strip.show();
}

uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
