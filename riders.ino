/*
 this effect works, but it’s better not to get into it, I myself don’t know how it worked for me
*/
void riders() {
  static unsigned long timer = 0;
  static byte i;
  i = 0;
  while (i <= (LED_NUM / 2)) {
    if (millis() - timer >= 30) {
      leds[i].setRGB(255, 0, 255);  //rider 1
      leds[LED_NUM - i].setRGB(0, 255, 255); // rider 2
      leds[i - 1].setRGB(0, 0, 0);  //очистка rider 1
      leds[LED_NUM - i + 1].setRGB(0, 0, 0);  //очистка rider 2
      FastLED.show();
      i++;
      timer = millis();

      if (!digitalRead(3) && millis() - cmTimer >= 500) {
        cmTimer = millis(); // защита от дребезга
        lock = !lock;
        if (lock) {
          digitalWrite(13, HIGH);
        }
        else {
          digitalWrite(13, LOW);
        }
      }

      if (millis() - cmTimer >= 500 && !digitalRead(2)) {
        cmTimer = millis();
        mode++;
        if (mode >= effects) {
          mode = 0;
        }
        FastLED.clear();
        Serial.println(prime[mode]);
      }
    }
  }
  FastLED.clear();
  i = 0;
  while (i <= (LED_NUM / 2)) {
    if (millis() - timer >= 30) {
      leds[(LED_NUM / 2) - i].setRGB(0, 255, 255); //rider 2
      leds[(LED_NUM / 2) + i].setRGB(255, 0, 255); // rider 1

      FastLED.show();
      i++;
      timer = millis();
      if (!digitalRead(3) && millis() - cmTimer >= 500) {
        cmTimer = millis(); // защита от дребезга
        lock = !lock;
        if (lock) {
          digitalWrite(13, HIGH);
        }
        else {
          digitalWrite(13, LOW);
        }
      }

      if (millis() - cmTimer >= 500 && !digitalRead(2)) {
        cmTimer = millis();
        mode++;
        if (mode >= effects) {
          mode = 0;
        }
        FastLED.clear();
        Serial.println(prime[mode]);
      }
    }
  }
  FastLED.clear();
}
