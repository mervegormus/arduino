#include <LiquidCrystal.h>
#include <dht11.h>
#define DHT11PIN 22

LiquidCrystal lcd(0, 1, 4, 5, 6, 7);

dht11 DHT11;

byte Dolu[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

#define DOLU 7

int yeniVeri = 1000;

// LCD ve butonlar için kullanılacak değişkenler
int lcd_key     = 0;
int adc_key_in  = 0;
#define btnSAG    0
#define btnYUKARI 1
#define btnASAGI  2
#define btnSOL    3
#define btnSECIM  4
#define btnYOK    5

// Butonları oku
int read_LCD_buttons()
{
  adc_key_in = analogRead(0);
  // Basılan butona göre A0 pininden bazı değerler okunur.
  // Okunan değere göre butonu belirliyoruz
  if (adc_key_in > 1000) return btnYOK;
  if (adc_key_in < 50)   return btnSAG;
  if (adc_key_in < 195)  return btnYUKARI;
  if (adc_key_in < 380)  return btnASAGI;
  if (adc_key_in < 555)  return btnSOL;
  if (adc_key_in < 790)  return btnSECIM;
  return btnYOK;
}

void butonRead()
{
  int buton = read_LCD_buttons();

  switch(buton)
  {
    case btnYUKARI:
    {
      if(yeniVeri >= 1000 && yeniVeri <= 5000)
      {
        yeniVeri += 500;
      }
      break;
    }
    case btnASAGI:
    {
      if(yeniVeri>=500)
      {
        yeniVeri -= 500;
      }
      break;
    }
  }

}


void setup() {
  lcd.begin(16,2);
  lcd.createChar(7,Dolu);

}

void loop() {

  butonRead();

  int chk = DHT11.read(DHT11PIN);

  lcd.setCursor(1,0);
  lcd.print((float)DHT11.temperature,2);
  lcd.setCursor(10,0);
  lcd.print((float)DHT11.humidity,2);

  int sicaklik = (float)DHT11.temperature;

  lcd.setCursor(0,1);
  lcd.print("      ");
  
  if(sicaklik<0)
  {
    lcd.setCursor(0,1);
    lcd.print("      ");
    lcd.write(byte(DOLU));
  }
  else if(sicaklik>=0 && sicaklik<=5)
  {
    lcd.setCursor(0,1);
    lcd.print("      ");
    for(int i=0;i<2;i++)
    {
      lcd.setCursor(i,1);
      lcd.write(byte(DOLU));
    }
  }
  else if(sicaklik>=6 && sicaklik<=10)
  {
    lcd.setCursor(0,1);
    lcd.print("      ");
    for(int i=0;i<3;i++)
    {
      lcd.setCursor(i,1);
      lcd.write(byte(DOLU));
    }
  }
  else if(sicaklik>=11 && sicaklik<=15)
  {
    lcd.setCursor(0,1);
    lcd.print("      ");
    for(int i=0;i<4;i++)
    {
      lcd.setCursor(i,1);
      lcd.write(byte(DOLU));
    }
  }
  else if(sicaklik>=16 && sicaklik<=20)
  {
    lcd.setCursor(0,1);
    lcd.print("      ");
    for(int i=0;i<5;i++)
    {
      lcd.setCursor(i,1);
      lcd.write(byte(DOLU));
    }
  }
  else
  {
    lcd.setCursor(0,1);
    lcd.print("      ");
    for(int i=0;i<6;i++)
    {
      lcd.setCursor(i,1);
      lcd.write(byte(DOLU));
    }
  }

  int nem = (float) DHT11.humidity;
  
  lcd.setCursor(10,1);
  lcd.print("     ");
  
  if(nem>=0 && nem<=20)
  {
    lcd.setCursor(10,1);
    lcd.write(byte(DOLU));
  }
  else if(nem>=21 && nem<=40)
  {
    lcd.setCursor(10,1);
    lcd.print("     ");
    for(int i=10;i<12;i++)
    {
      lcd.setCursor(i,1);
      lcd.write(byte(DOLU));
    }
  }
  else if(nem>=41 && nem<=60)
  {
    lcd.setCursor(10,1);
    lcd.print("     ");
    for(int i=10;i<13;i++)
    {
      lcd.setCursor(i,1);
      lcd.write(byte(DOLU));
    }
  }
  else if(nem>=61 && nem<=80)
  {
    lcd.setCursor(10,1);
    lcd.print("     ");
    for(int i=10;i<14;i++)
    {
      lcd.setCursor(i,1);
      lcd.write(byte(DOLU));
    }
  }
  else if(nem>=81 && nem<=100)
  {
    lcd.setCursor(10,1);
    lcd.print("     ");
    for(int i=10;i<15;i++)
    {
      lcd.setCursor(i,1);
      lcd.write(byte(DOLU));
    }
  }
 
  delay(yeniVeri);
  
}
