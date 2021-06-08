/* 2021. 06. 08
 *  두 메뉴중에 하나를 선택하면 선택지에 따라서 메세지가 뜸
 *  그런데 여기서 버튼2를 누르면 exit가 떠야되는데 bye로 뜸
 *  by iknam
 */


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
int curColumn = 0, curRow = 40, menuChoice = 0;
int button, button2;

void setup()
{
  Wire.begin();

  // OLED Display initial setting to operation
  Init_OLED();
  OLED_Display();


  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  //pinMode(A0,

}
void loop() {

  //delay(500);

  int button = digitalRead(3);
  int button2 = digitalRead(4);

  if (button == HIGH) {
  }
  else
  {
    display.clearDisplay();
    menu();
    delay(300);

    display.setCursor(100, curRow);
    display.print("*");
    display.display();
    if (curRow <= 40) {
      curRow += 10;
    } else
    {
      curRow = 40;
    }//display.clearDisplay();
    menuChoice++;

  }


  if (button2 == HIGH) {

  }

  if (button2 == LOW) {
    if ((menuChoice % 2) == 1)
    {
      start();
    }
    else
    {
      quit();
    }

  }



  //display.clearDisplay();
  display.display();
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
  display.setCursor(0, 0);
  //display.println(String( ) + ":" + String( ));

  display.display();
  display.clearDisplay();

}


void menu()
{
  display.setCursor(30, 40);
  display.println("START");

  display.setCursor(30, 50);
  display.print("QUIT");
}

void start()
{ display.clearDisplay();
  display.setCursor(40, 30);
  display.print("Launched");
}

void quit()
{

  display.clearDisplay();

  if (button2 == HIGH) {
    display.setCursor(50, 30);
    display.print("EXIT?");
      display.display();

  }    if (button2 == LOW) {
      display.setCursor(60, 30);
      display.print("BYE");
        display.display();
    }

}
