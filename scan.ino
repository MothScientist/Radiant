void scan() {
  static byte d = 1;
  static bool a_scan = true;
  for (int i = 0; i < d; i++) {
    leds[i] = CRGB::Navy;
    leds[LED_NUM - 1 - i] = CRGB::Navy; // you can change color 
  }
  if (a_scan) {
    leds[d] = CRGB::Navy;
    leds[LED_NUM - 1 - d] = CRGB::Navy;
  }
  if (!a_scan) {
    leds[d] = CRGB::Black;
    leds[LED_NUM - 1 - d] = CRGB::Black;
  }
  EVERY_N_MILLISECONDS(5000) {
    d++;
    if (d == LED_NUM / 2) {
      d = 1;
      FastLED.clear();
    }
  }
  EVERY_N_MILLISECONDS(500) {
    a_scan = !a_scan;
  }
  FastLED.show();
}
// delays embedded in this function
