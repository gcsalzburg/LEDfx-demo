#include <Arduino.h>

// Use #pragma here to stop warning messages from FastLED unused variable in the library
#define FASTLED_INTERNAL // Disable #pragma message from FastLED
#pragma GCC diagnostic push 						// save diagnostic state
#pragma GCC diagnostic ignored "-Wunused-variable"	// turn off the specific warning. Can also use "-Wall"
#include <FastLED.h>
#pragma GCC diagnostic pop							// turn the warnings back on
#include <LEDfx.h>

#define NUM_LEDS 72
#define NUM_STRIPS 4

CRGB leds[NUM_LEDS*NUM_STRIPS];

LEDfx::panel my_strip(leds, NUM_LEDS, LEDfx::BLUE_WIRES, NUM_LEDS);

void setup() {

	// Setup LEDs using Parallel Output method
	FastLED.addLeds<WS2811_PORTDC,NUM_STRIPS>(leds, NUM_LEDS);
	FastLED.setBrightness(120); // 255 = full brightness

	// Turn off all LEDs
	for(int i = 0; i < NUM_STRIPS; i++) {
		for(int j = 0; j < NUM_LEDS; j++) {
			leds[(i*NUM_LEDS) + j] = CRGB::Black;
		}
	}
	FastLED.show();
}

void loop() {
	// put your main code here, to run repeatedly:

	my_strip.fill(CRGB::Blue);
	FastLED.show();
}