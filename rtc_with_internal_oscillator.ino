#include <STM32RTC.h>
#include <LiquidCrystal.h>
#include <Wire.h>

const int rs = PB11, en = PB10, d4 = PE3, d5 = PE6, d6 = PE4, d7 = PE2; //STM32F407VG
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Get the rtc object
STM32RTC& rtc = STM32RTC::getInstance();

// Change these values to set the current initial time 
const byte seconds = 4

;
const byte minutes = 33;
const byte hours = 11;

//change these values to set the current initial date
// thrusday 18 June 2020
const byte weekDay = 3;
const byte days = 18;
const byte months = 6;
const byte years = 20;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);//Defining 16*2 LCD
  rtc.begin(); //initialize rtc 24 h format

  rtc.setHours(hours);
  rtc.setMinutes(minutes);
  rtc.setSeconds(seconds);

  //set the date
  rtc.setWeekDay(weekDay);
  rtc.setDay(days);
  rtc.setMonth(months);
  rtc.setYear(years);

}

void loop() {
  // put your main code here, to run repeatedly:
  //print date 
  //print2digits(rtc.getDay());
//  Serial.print("/");
//  print2digits(rtc.getMonth());
//  Serial.print("/");
//  print2digits(rtc.getYear());
//  Serial.print(" ");
//
//  // ... and time 
//  print2digits(rtc.getHours());
//  Serial.print(":");
//  print2digits(rtc.getMinutes());
//  Serial.print(":");
//  print2digits(rtc.getSeconds());
//
//  Serial.println();

lcd.setCursor(0,0);
lcd.print(rtc.getDay());

lcd.setCursor(2,0);
lcd.print("/");

lcd.setCursor(3,0);
lcd.print(rtc.getMonth());

lcd.setCursor(5,0);
lcd.print("/");

lcd.setCursor(6,0);
lcd.print(rtc.getYear());

lcd.setCursor(0,1);
lcd.print(rtc.getHours());

lcd.setCursor(2,1);
lcd.print(":");

lcd.setCursor(3,1);
lcd.print(rtc.getMinutes());

lcd.setCursor(5,1);
lcd.print(":");

lcd.setCursor(6,1);
lcd.print(rtc.getSeconds());

  delay(1000);
}

void print2digits(int number) {
  if (number < 10) {
    lcd.print("0"); //print a 0 before if the number is < than 10
  }
  lcd.print(number);
}
