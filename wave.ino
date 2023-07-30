void wave2() {
  uint16_t beatA = beatsin16(30, 0, 255); // you can change mix of light
  uint16_t beatB = beatsin16(20, 0, 255);
  fill_rainbow(leds, LED_NUM, (beatA + beatB) / 2, 8);
  FastLED.show();
}
