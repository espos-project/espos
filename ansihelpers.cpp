#include <Arduino.h>
#include "api.h"

// Limpia pantalla y mueve cursor arriba izquierda
void cls() {
  Serial.print("\033[2J\033[H");
}

// Convierte nombre de color de texto a código ANSI (30-37)
int fgColorCodeFromName(const String& colorName) {
  if (colorName.equalsIgnoreCase("black"))   return 30;
  if (colorName.equalsIgnoreCase("red"))     return 31;
  if (colorName.equalsIgnoreCase("green"))   return 32;
  if (colorName.equalsIgnoreCase("yellow"))  return 33;
  if (colorName.equalsIgnoreCase("blue"))    return 34;
  if (colorName.equalsIgnoreCase("magenta")) return 35;
  if (colorName.equalsIgnoreCase("cyan"))    return 36;
  if (colorName.equalsIgnoreCase("white"))   return 37;
  return 37; // Default white
}

// Convierte nombre de color de fondo a código ANSI (40-47)
int bgColorCodeFromName(const String& colorName) {
  if (colorName.equalsIgnoreCase("black"))   return 40;
  if (colorName.equalsIgnoreCase("red"))     return 41;
  if (colorName.equalsIgnoreCase("green"))   return 42;
  if (colorName.equalsIgnoreCase("yellow"))  return 43;
  if (colorName.equalsIgnoreCase("blue"))    return 44;
  if (colorName.equalsIgnoreCase("magenta")) return 45;
  if (colorName.equalsIgnoreCase("cyan"))    return 46;
  if (colorName.equalsIgnoreCase("white"))   return 47;
  return -1; // No background / invalid
}

// Función para imprimir texto con color y fondo opcional
void printColorBg(const String& fgColor, const String& bgColor, const String& text) {
  int fgCode = fgColorCodeFromName(fgColor);
  int bgCode = bgColorCodeFromName(bgColor);

  Serial.print("\033["); 
  Serial.print(fgCode);
  if (bgCode != -1) {
    Serial.print(";");
    Serial.print(bgCode);
  }
  Serial.print("m");

  Serial.print(text);

  Serial.print("\033[0m"); // Reset colores
}

void printColorBgln(const String& fgColor, const String& bgColor, const String& text) {
  printColorBg(fgColor, bgColor, text + "\n");
}
