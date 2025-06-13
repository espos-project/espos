#ifndef API_H
#define API_H

#include <Arduino.h>

void panic(const String& panicName = "");  // Añadido parámetro opcional
void cls();

void printColor(const String& colorName, const String& text);
void printColorln(const String& colorName, const String& text);
void printColorBg(const String& fgColor, const String& bgColor, const String& text);
void printColorBgln(const String& fgColor, const String& bgColor, const String& text);

#endif // API_H
