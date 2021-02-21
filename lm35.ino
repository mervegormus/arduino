void setup() {
  // put your setup code here, to run on
  Serial.begin(9600);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  int okunanDeger = analogRead(A15);
  float derece = (okunanDeger / 1024.0) * 500;
  int derece1 = (int)derece;
  Serial.println(okunanDeger);
  Serial.println(derece1);
 
  delay(1000);
}
