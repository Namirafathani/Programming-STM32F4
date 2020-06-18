#include <LiquidCrystal.h>
#include <Wire.h>
//#include <SoftWire.h>
#include <RTClib.h>

RTC_DS1307 rtc;

const int rs = PB11, en = PB10, d4 = PE3, d5 = PE6, d6 = PE4, d7 = PE2; //STM32F407VG
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//uint8_t clock[8] = {0x0,0xe,0x15,0x17,0x11,0xe,0x0};
char daysOfTheWeek[7][12] = {"Ming", "Sen", "Sel", "Rab", "Kam", "Jum", "Sab"};
//char bulan[12][12] = {"Jan", "Feb", "Mar", "Apr", "Mei", "Jun", "Jul", "Agt", "Sep", "Okt", "Nov", "Des"};

#define LED PE0

void setup() {
Wire.begin();
rtc.begin();  
lcd.begin(16, 2);//Defining 16*2 LCD
if (! rtc.begin()){
  digitalWrite(LED, HIGH);
}
if (! rtc.isrunning()){
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}
}
 
void loop() {
 DateTime now = rtc.now();
    lcd.setCursor(0,0);
    //lcd.print(now.hour(), DEC);
    lcd.print(now.day(), DEC);

    lcd.setCursor(5,0);
    lcd.print(":");
    lcd.setCursor(6,0);
    //lcd.print(now.minute(), DEC);
    lcd.print(now.month(), DEC);

    lcd.setCursor(8,0);
    lcd.print(":");
    lcd.setCursor(9,0);
    //lcd.print(now.second(), DEC);
    lcd.print(now.year(), DEC);
     
    delay(1000);
}
