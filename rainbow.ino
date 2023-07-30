void rainbow() {
  static byte rainbow_counter = 0;
  EVERY_N_MILLISECONDS(50) { // 50 ms
    for (int i = 0; i < LED_NUM; i++)
    {
      leds[i].setHue(rainbow_counter + i * 255 / LED_NUM);
    }
    rainbow_counter++;
    FastLED.show();
  }
}
