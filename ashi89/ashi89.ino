#include <SPI.h>
#include "epd1in54_V2.h"
#include "imagedata.h"
#include "epdpaint.h"
#include <stdio.h>

Epd epd;
unsigned char image[1024];
Paint paint(image, 0, 0);

unsigned long time_start_ms;
unsigned long time_now_s;
#define COLORED     0
#define UNCOLORED   1

void setup()
{
  // put your setup code here, to run once: AQUI NO HAY NADA
  Serial.begin(115200);
  Serial.println("e-Paper init and clear");
  epd.LDirInit();
  epd.Clear();

  paint.SetWidth(200);
  paint.SetHeight(24);

  Serial.println("WELCOME TO");
  paint.Clear(COLORED);
  paint.DrawStringAt(30, 4, "WELCOME TO", &Font16, UNCOLORED);
  epd.SetFrameMemory(paint.GetImage(), 0, 10, paint.GetWidth(), paint.GetHeight());

  paint.Clear(UNCOLORED);
  paint.DrawStringAt(30, 4, "CIRCUIT DIGEST", &Font16, COLORED);
  epd.SetFrameMemory(paint.GetImage(), 0, 30, paint.GetWidth(), paint.GetHeight());

  paint.SetWidth(64);
  paint.SetHeight(64);


  epd.DisplayFrame();
  delay(2000);

  Serial.println("e-Paper show pic");

  // epd.Display(IMAGE_DATA);

  //Part display
  epd.HDirInit();
  epd.DisplayPartBaseImage(IMAGE_DATA);

  paint.SetWidth(50);
  paint.SetHeight(60);
}

void loop()
{

}
