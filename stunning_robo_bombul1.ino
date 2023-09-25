#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
byte button1 = 9;
byte button2 = 8;
byte arrow[] = {
  0b01000,
  0b01100,
  0b01110,
  0b01111,
  0b01111,
  0b01110,
  0b01100,
  0b01000
};
byte lastButton1,currentButton1;
byte lastButton2,currentButton2;
byte counter = 0;
void setup() {
pinMode(8, INPUT_PULLUP);
pinMode(9, INPUT_PULLUP);

lcd.init();
lcd.backlight();

lcd.createChar(0, arrow);
lcd.setCursor(0, 0);
lcd.write(byte(0));
lcd.print("Select Program");

lcd.setCursor(1, 1);
lcd.print("SettingS");

}

void loop() {

lastButton1 = currentButton1;
lastButton2 = currentButton2;

currentButton1 = digitalRead(9);
currentButton2 = digitalRead(8);

if(currentButton2 == LOW && lastButton2 == HIGH && counter == 0)
{
  secondMode();
  counter = 1;
}
else if(currentButton2 == LOW && lastButton2 == HIGH && counter == 1)
{
  thirdMode();
  counter = 2;
}
else if(currentButton2 == LOW && lastButton2 == HIGH && counter == 2)
{
 fourthMode();
 counter = 3;
}
else if(currentButton1 == LOW && lastButton1 == HIGH && counter == 1)
{
  firstMode();
  counter = 0;
}
else if(currentButton1 == LOW && lastButton1 == HIGH && counter == 2)
{
  secondMode();
  counter = 1;
}
else if(currentButton1 == LOW && lastButton1 == HIGH && counter == 3)
{
  thirdMode();
  counter = 2;
}
}
void firstMode(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.write(byte(0));
  lcd.print("Select Program");
  lcd.setCursor(1, 1);
  lcd.print("Settings");
}
void secondMode(){
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.write(byte(0));
  lcd.setCursor(1, 0);
  lcd.print("Select Program");
  lcd.setCursor(1, 1);
  lcd.print("Settings");
}
void thirdMode(){
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.write(byte(0));
  lcd.setCursor(1, 0);
  lcd.print("Settings");
  lcd.setCursor(1, 1);
  lcd.print("Power Saving");
}
void fourthMode(){
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.write(byte(0));
  lcd.setCursor(1, 0);
  lcd.print("Power Saving");
  lcd.setCursor(1, 1);
  lcd.print("Shut down");
}