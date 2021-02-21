#include <Wire.h>
#include <LiquidCrystal.h>

const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int x = 16;
int y = 0;
int satir = 0;
int gelenDerece = 1;
const byte interruptPin = 2;

void setup() {
  Wire.begin(8); // join i2c bus with address #8
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), satirIslemi, RISING);
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);
  lcd.begin(16, 2);


}

int satirIslemi() {
  lcd.clear();
  if (satir == 0) satir = 1;
    else satir = 0;
    

  if (gelenDerece == 0) gelenDerece = 1;
  else gelenDerece = 0;
   
  return satir, gelenDerece;
}



void loop() {
  isimYaz(satir);
  delay(150);
}


String Scroll_LCD_Left(String StrDisplay) {
  String result;
  String StrProcess = "                " + StrDisplay + "               ";
  result = StrProcess.substring(x, y);
  x++;
  y++;
  if (x > StrProcess.length()) {
    x = 16;
    y = 0;
  }
  return result;

}
void Clear_Scroll_LCD_Left() {
  x = 16;
  y = 0;
}
void isimYaz(int satir) {
  lcd.setCursor(0, satir);
  lcd.print(Scroll_LCD_Left("MERVE GORMUS"));

}
void receiveEvent() {
  gelenDereceVerisi(gelenDerece);

}
void gelenDereceVerisi(int gelenDerece) {

  int yeniDerece;
  while (Wire.available()) {

    yeniDerece = Wire.read();
  }
  int derece1 = int(yeniDerece);


  if (derece1 < 25 && derece1 > 0)
  {
    lcd.setCursor(0, gelenDerece);
    lcd.clear();
    lcd.setCursor(4, gelenDerece);
    lcd.print(derece1);
    lcd.print(" ");
    lcd.write("NORMAL");
  }

  if (derece1 >= 25 && derece1 <= 30) {
    lcd.setCursor(0, gelenDerece);
    lcd.clear();
    lcd.setCursor(3, gelenDerece);
    lcd.print(derece1);
    lcd.print(" ");
    lcd.write("SICAK");
    ;
  }

  if (derece1 > 30 ) {
    lcd.setCursor(0, gelenDerece);
    lcd.clear();
    lcd.setCursor(2, gelenDerece);
    lcd.print(derece1);
    lcd.print(" ");
    lcd.write("COK SICAK");

  }
}
