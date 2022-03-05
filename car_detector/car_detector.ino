#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_TFTLCD.h> 

#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4

// Agar warna mudah dimengerti (Human Readable color):
#define TFT_BLACK   0x0000
#define TFT_BLUE    0x001F
#define TFT_RED     0xF800
#define TFT_GREEN   0x07E0
#define TFT_CYAN    0x07FF
#define TFT_MAGENTA 0xF81F
#define TFT_YELLOW  0xFFE0
#define TFT_WHITE   0xFFFF
#define TFT_GREY    0x5AEB

int ir = A5;

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

void setup(void) {
  Serial.begin(9600);
  pinMode(ir, INPUT);
  
  tft.reset();  
  tft.begin(0x9341); 
  tft.setRotation(2);
  tft.fillScreen(TFT_RED);// background color
  delay(1000);
}

void loop() {
  if(!digitalRead(ir))
  {
    tft.fillScreen(TFT_GREEN);// background color
  }
  else
  {
    tft.fillScreen(TFT_RED);
  }
}
