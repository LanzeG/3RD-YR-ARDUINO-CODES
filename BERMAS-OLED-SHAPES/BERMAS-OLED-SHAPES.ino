//BERMAS, LESTER LANCE J.
//BSIT-NS-3A-M
//PROJECT 12
//PROF. DARWIN VARGAS

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
// Declaration for SSD1306 display connected using I2C
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
// Declaration for SSD1306 display connected using software SPI:
//#define OLED_MOSI 9
//#define OLED_CLK 10
//#define OLED_DC 11
//#define OLED_CS 12
//#define OLED_RESET 13
//Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_MOSI, OLED_CLK,OLED_DC, OLED_RESET, OLED_CS);

void setup(){
  Serial.begin(9600);

  // initialize the OLED object
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  
  // Uncomment this if you are using SPI
  //if(!display.begin(SSD1306_SWITCHCAPVCC)) {
  // Serial.println(F("SSD1306 allocation failed"));
  // for(;;); // Don't proceed, loop forever
  //}
  
  // Clear the buffer.
  display.clearDisplay();
  
  // Draw Rectangle
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Rectangle");
  display.drawRect(0, 15, 60, 40, WHITE);
  display.display();
  delay(2000);
  display.clearDisplay();
  
  // Draw Filled Rectangle
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Filled Rectangle");
  display.fillRect(0, 15, 60, 40, WHITE);
  display.display();
  delay(2000);
  display.clearDisplay();
  
  // Draw Round Rectangle
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Round Rectangle");
  display.drawRoundRect(0, 15, 60, 40, 8, WHITE);
  display.display();
  delay(2000);
  display.clearDisplay();
  
  // Draw Filled Round Rectangle
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Filled Round Rectangl");
  display.fillRoundRect(0, 15, 60, 40, 8, WHITE);
  display.display();
  delay(2000);
  display.clearDisplay();
  
  // Draw Circle
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Circle");
  display.drawCircle(20, 35, 20, WHITE);
  display.display();
  delay(2000);
  display.clearDisplay();
  
  // Draw Filled Circle
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Filled Circle");
  display.fillCircle(20, 35, 20, WHITE);
  display.display();
  delay(2000);
  display.clearDisplay();
  
  // Draw Triangle
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Triangle");
  display.drawTriangle(30, 15, 0, 60, 60, 60, WHITE);
  display.display();
  delay(2000);
  display.clearDisplay();
  
  // Draw Filled Triangle
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Filled Triangle");
  display.fillTriangle(30, 15, 0, 60, 60, 60, WHITE);
  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
}
