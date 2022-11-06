
// Include Libraries
#include "Arduino.h"
#include "LiquidCrystal_PCF8574.h"
#include "Button.h"


#define PUSHBUTTON_PIN_2  2

#define LCD_ADDRESS 0x27

// Define LCD characteristics
#define LCD_ROWS 2
#define LCD_COLUMNS 16
#define SCROLL_DELAY 150
#define BACKLIGHT 255
// object initialization
LiquidCrystal_PCF8574 lcdI2C;
Button pushButton(PUSHBUTTON_PIN_2);

void setup() 
{
    Serial.begin(9600);
    Serial.println("start");
    
    // initialize the lcd
    lcdI2C.begin(LCD_COLUMNS, LCD_ROWS, LCD_ADDRESS, BACKLIGHT); 
    lcdI2C.clear(); 
    pushButton.init();
    displayText("1234567890abcd"); 
    
}

void loop() 
{
                           
    //delay(1000);

    bool pushButtonVal = pushButton.read();
    //Serial.print(F("Val: ")); Serial.println(pushButtonVal);
}


void displayText(string text) {
  int textLen = text.length();
  int parts = ceil((float) textLen / 16)-1;

    char txtArray[textLen];
    for (int i=0; i<textLen; i++) {
        txtArray[i] = text.at(i); 
    }
    
    char textOutput[parts][15];
    for (int j=0; j<parts+1; j++) {
        for (int i=0; i<16 ;i++) {
            if (j>=1) {
              textOutput[j][i] = txtArray[(16*(j))+i];
              cout << "[" << j <<"] ["<<i<<"] - " << textOutput[j][i] <<endl;
            } else {
              textOutput[j][i] = txtArray[i]; 
              cout << "[" << j <<"] ["<<i<<"] - " << textOutput[j][i] <<endl;
            }
            if (textOutput[j][i] == '\0') {
                break;
            }
        }  
    }
  
//   lcdI2C.clear();

//   if (parts <= 2) {
//      lcdI2C.print(textOutput[0]);
//      lcdI2C.selectLine(2);
//      lcdI2C.print(textOutput[1]); 
//   }
}
