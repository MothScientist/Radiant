void train() {
  static bool dir = true;
  static byte colors_refresh = 0;
  static byte i = 0;
  EVERY_N_MILLISECONDS(15) { // one step of train
    for (int j = 0; j < (LED_NUM / 10); j++) {
      leds[i + j].setHSV(0 + colors_refresh, 255, 255);
    }

    for (int j = i + (LED_NUM / 10); j < LED_NUM; j++) {
      leds[j].setHSV(0 + colors_refresh, 255, 100);
    }
    for (int j = i - 1; j >= 0; j--) {
      leds[j].setHSV(0 + colors_refresh, 255, 100);
    }

    FastLED.show();

    if (dir) {
      i++;
    }
    if (!dir) {
      i--;
    }
    if (i + (LED_NUM / 10) == LED_NUM) {
      dir = !dir;
      colors_refresh += 4;
    }
    if (i == 0) {
      dir = !dir;
      colors_refresh += 4;
    }
  }
}

// 15ms
