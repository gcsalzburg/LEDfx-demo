#include <Arduino.h>

// Use #pragma here to stop warning messages from FastLED unused variable in the library
#define FASTLED_INTERNAL // Disable #pragma message from FastLED
#pragma GCC diagnostic push 						// save diagnostic state
#pragma GCC diagnostic ignored "-Wunused-variable"	// turn off the specific warning. Can also use "-Wall"
#include <FastLED.h>
#pragma GCC diagnostic pop							// turn the warnings back on
#include <LEDfx.h>

// Declare pin defs
#define LED_PIN 14
#define NUM_LEDS 72
#define NUM_STRIPS 4

// Create array of LED colour data
CRGB leds[NUM_LEDS*NUM_STRIPS];

// Create panel for animation
LEDfx::panel my_strip(leds, NUM_LEDS);

void setup() {

	my_strip.fill(CRGB::Black);

	// Setup LEDs using Parallel Output method
	FastLED.addLeds<NEOPIXEL,LED_PIN>(leds, NUM_LEDS);
	FastLED.setBrightness(120); // 255 = full brightness
	FastLED.show();
}

void loop() {
	// put your main code here, to run repeatedly:

	my_strip.fill(CRGB::Blue);
	FastLED.show();
}