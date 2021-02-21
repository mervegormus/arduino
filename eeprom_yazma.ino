#include<EEPROM.h>

int kayitAdresi = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
//float f = 123.456f;
void loop() {
  struct BenimVeriTipim {
    char isim[12];
  };
  int kayitAdresi = 0;
  BenimVeriTipim isim = {
    "MERVE GORMUS"
  };

  EEPROM.put(kayitAdresi , isim);
  kayitAdresi += sizeof(BenimVeriTipim);


  if (kayitAdresi == EEPROM.length()) {
  kayitAdresi = 0;

}
delay(1000);
}
