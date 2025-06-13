#ifndef LOG_H
#define LOG_H

#include <Arduino.h>

// Colores ANSI (recomendable moverlos aquí también, para no duplicar)
#define ANSI_RED     "\033[31m"
#define ANSI_YELLOW  "\033[33m"
#define ANSI_GREEN   "\033[32m"
#define ANSI_RESET   "\033[0m"

// Prototipo de la función
void logln(const String& message, const char* color = ANSI_YELLOW);

#endif // LOG_H
