#include <SPI.h>
#include <DMD.h>
#include <TimerOne.h>
#include "SystemFont5x7.h"

#define DISPLAYS_ACROSS 2
#define DISPLAYS_DOWN 1

DMD dmd(DISPLAYS_ACROSS, DISPLAYS_DOWN);

char text[] = " SELAMAT DATANG DI STAND SMK NEGERI 2 KOTA JAMBI ";

void ScanDMD() {
  dmd.scanDisplayBySPI();
}

void setup() {
  SPI.begin();                  // 🔥 WAJIB
  Timer1.initialize(2000);      // refresh lebih stabil
  Timer1.attachInterrupt(ScanDMD);

  dmd.clearScreen(true);
  dmd.selectFont(SystemFont5x7);
}

void loop() {

  int textWidth = strlen(text) * 6;

  for (int x = 32; x > -textWidth; x--) {
    dmd.clearScreen(true);
    dmd.drawString(x, 4, text, strlen(text), GRAPHICS_NORMAL);
    delay(80);
  }
}
