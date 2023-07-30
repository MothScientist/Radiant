DEFINE_GRADIENT_PALETTE( Sunset_Real_gp ) {
    0, 120,   0,   0,
   22, 179,  22,   0,
   51, 255, 104,   0,
   85, 167,  22,  18,
  135, 100,   0, 103,
  198,  16,   0, 130,
  255,   0,   0, 160
};

CRGBPalette16 myPal3 = Sunset_Real_gp;


void sunset() {
    fill_palette(leds, LED_NUM, paletteIndex, 255 / LED_NUM, myPal3, 255, LINEARBLEND);
  EVERY_N_MILLISECONDS(30){
    paletteIndex++;
  }
  FastLED.show();
}
