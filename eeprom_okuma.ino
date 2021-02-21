#include <EEPROM.h>

int kayitAdresi = 0;
void setup() {
  Serial.begin(9600);
}


void loop() {

  int okunanDeger = analogRead(A15);
  int derece = int(okunanDeger);
  Serial.println(derece);
  struct BenimVeriTipim {
    char isim[12];
  };

  BenimVeriTipim isim;

  EEPROM.get(kayitAdresi, isim);
  kayitAdresi += sizeof(BenimVeriTipim);

  //Serial.println("deneme");
  Serial.println(isim.isim);


  if (kayitAdresi == EEPROM.length()) {
    kayitAdresi = 0;
  }
  delay(1000);
}
