void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13,OUTPUT);
pinMode(12,OUTPUT);
pinMode(11,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
int okunanDeger = analogRead(A0);
float derece=(okunanDeger/1024.0)*500;
Serial.println(okunanDeger);
Serial.println(derece);

digitalWrite(11,0);
digitalWrite(12,0);
digitalWrite(11,0);
if(derece>=25){
  digitalWrite(13,1);
}else if(derece<25 && derece>18){
  digitalWrite(12,1);
  }
else(derece<=18){
  digitalWrite(11,1);
  }
}
