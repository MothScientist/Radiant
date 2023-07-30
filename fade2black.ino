CRGBPalette16 bluePalette = CRGBPalette16 (
    CRGB::MidnightBlue,
    CRGB::Cyan,
    CRGB::DarkTurquoise,
    CRGB::Navy,

    CRGB::Cyan,
    CRGB::MediumBlue,
    CRGB::SeaGreen,
    CRGB::Teal,

    CRGB::CadetBlue,
    CRGB::Blue,
    CRGB::DarkCyan,
    CRGB::CornflowerBlue,

    CRGB::Aquamarine,
    CRGB::SeaGreen,
    CRGB::Aqua,
    CRGB::LightSkyBlue
);
                              
CRGBPalette16 myPal2 = bluePalette;

void fadeToBlack2() {
  EVERY_N_MILLISECONDS(50) {
    // Switch on an LED at random, choosing a random color from the palette
    leds[random8(0, LED_NUM - 1)] = ColorFromPalette(myPal2, random8(), 255, LINEARBLEND);
  }

  // Fade all LEDs down by 1 in brightness each time this is called
  fadeToBlackBy(leds, LED_NUM, 1);

  FastLED.show();
}
