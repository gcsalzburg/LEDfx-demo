#include <Arduino.h>
#include <LEDfx.h>

// Declare pin defs
#define LED_PIN 14
#define NUM_LEDS 72

// Create array of LED colour data
CRGB leds[NUM_LEDS];

// Create panel for animation
LEDfx::panel my_strip(leds, NUM_LEDS);

// Create a few effects
LEDfx::effect swipe_col1(LEDfx::SWIPE, CRGB::Green, CRGB::Blue);
LEDfx::effect swipe_col2(LEDfx::SWIPE, CRGB::Blue, CRGB::Green);

LEDfx::step steps[] = {
	{my_strip, swipe_col1, 1000},
	{my_strip, swipe_col2, 1000},
	{my_strip, swipe_col1, 300},
	{my_strip, swipe_col2, 300}
};
LEDfx::animation my_animation(steps, 4);


void setup() {
	Serial.begin(115200);

	my_strip.fill(CRGB::Black);

	// Setup LEDs using Parallel Output method
	FastLED.addLeds<NEOPIXEL,LED_PIN>(leds, NUM_LEDS);
	FastLED.setBrightness(120); // 255 = full brightness
	FastLED.show();

	my_animation.start();
}

void loop() {
	my_animation.draw();
	FastLED.show();
}