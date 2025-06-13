// panic.cpp
// (C) Pablo 08/09/2025
// Licensed with GNU GPLv3


#include <Arduino.h>
#include "API.h"
#include "log.h"

#define ANSI_RED     "\033[31m"

void panic(const String& panicName) {
  pinMode(2, OUTPUT);
  Serial.println();

  logln("======================================", ANSI_RED);
  logln("============ KERNEL PANIC ============", ANSI_RED);
  logln("======================================", ANSI_RED);

  logln("Board: " + String(ESP.getChipModel()));
  logln("Revision: " + String(ESP.getChipRevision()));
  logln("Flash size: " + String(ESP.getFlashChipSize() / 1024) + " KB");

  for (int i = 0; i < 10; i++) {
    digitalWrite(2, HIGH);
    delay(50);
    digitalWrite(2, LOW);
    delay(50);
  }
  Serial.println();

  if (panicName.length() > 0) {
    logln("kernel Panic - not syncing: (" + panicName + "):", ANSI_RED);
    digitalWrite(2, HIGH);
  } else {
    logln("kernel Panic - not syncing", ANSI_RED);
    digitalWrite(2, LOW);
  }

  Serial.println();

  asm volatile("break 0, 0");
  while (true) {
    // Breakpoint
  }
}
