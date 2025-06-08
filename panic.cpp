#include <Arduino.h>
#include "API.h"


void panic() {
  Serial.println();
  Serial.println("======================================");
  Serial.println("============ KERNEL PANIC ============");
  Serial.println("======================================");

  Serial.print("Board: ");
  Serial.println(ESP.getChipModel());              
  Serial.print("Revision: ");
  Serial.println(ESP.getChipRevision());           
  Serial.print("Flash size: ");
  Serial.print(ESP.getFlashChipSize() / 1024);     
  Serial.println(" KB");

  Serial.println();
  Serial.println("kernel panic: not syncing");
  Serial.println();
  
  asm volatile("break 0, 0");
  while (true) {
    
  }
}
