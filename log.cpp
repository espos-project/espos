
#include <Arduino.h>
#include "log.h"

void logln(const String& message, const char* color) {
  Serial.print(color);
  Serial.print("[");
  Serial.print(millis());
  Serial.print(" ms] ");
  Serial.print(message);
  Serial.println(ANSI_RESET);
}
