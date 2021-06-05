//---------- I2C setting ------------------------------------------------------------------------
#include <Wire.h> 

//---------- 128x64 OLED setting ----------------------------------------------------------------
#define OLED_096_INCH   1
#define OLED_130_INCH   2

#define DISPLAY_SIZE OLED_130_INCH    // Select Display Size

#define OLED_RESET 13

#include <Adafruit_GFX.h>

#if (DISPLAY_SIZE == OLED_096_INCH)
 #include <Adafruit_SSD1306.h>
#endif
#if (DISPLAY_SIZE == OLED_130_INCH)
 #include <Adafruit_SH1106.h>
#endif

#if (DISPLAY_SIZE == OLED_096_INCH)
 Adafruit_SSD1306 display(OLED_RESET);
#endif
#if (DISPLAY_SIZE == OLED_130_INCH)
 Adafruit_SH1106 display(OLED_RESET);
#endif

int i, j = 0;
int curColumn = 0, curRow = 40, countOnOff = 0;

void menu()
{   
  display.setCursor(30, 40);
  display.println("START");
  
  display.setCursor(30, 50);
  display.print("QUIT");
  display.display();
//display.clearDisplay();
}

void start()
{display.clearDisplay();
  display.print("start");
}

void quit()
{display.clearDisplay();
display.print("quit");
}

void setup()
{
  Wire.begin();
  
  // OLED Display initial setting to operation
  Init_OLED(); 
  OLED_Display();
 

  pinMode(3, INPUT_PULLUP);

}
void loop(){

//delay(500);
menu();
  int button = digitalRead(3);
  
  if(button == HIGH) {
    
  }
  else
  {countOnOff++;
    display.clearDisplay();
    display.setCursor(100, curRow);
    
    display.print("*");
    
    delay(500);

    if(curRow <= 40){
      curRow += 10;
    }else
    {
      curRow = 40;
    }
   
    if ((countOnOff % 2) == true) start();
  else quit();
     display.display(); 
  }
  
      
}

void Init_OLED() {
  
  // OLED Display initial setting to operation
  #if (DISPLAY_SIZE == OLED_096_INCH)
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  #endif
  #if (DISPLAY_SIZE == OLED_130_INCH)
   display.begin(SH1106_SWITCHCAPVCC, 0x3C);
  #endif
  display.display();
  delay(1);
  display.clearDisplay();

}

void OLED_Display() {
  
  display.setTextSize(1); // Or display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  //display.println(String( ) + ":" + String( ));

  display.display();
  display.clearDisplay();
    
}
