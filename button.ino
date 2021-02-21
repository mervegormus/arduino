
void setup() {
  // put your setup code here, to run once:
 
  pinMode(9,OUTPUT);//sınav sorusu
  pinMode(19,INPUT_PULLUP);//YAVASLA
  pinMode(21,INPUT_PULLUP);//HIZLAN
  

 
}
int gecikme=1000;
void loop() {
  // put your main code here, to run repeatedly:
 int btnYavasla=digitalRead(19);
 int btnHizlan=digitalRead(21);

if(btnYavasla == 0){
  if(gecikme <= 1900)
   gecikme+=100;

}
if(btnHizlan == 0){
  
   gecikme-=100;
   gecikme=gecikme<500?500:gecikme;//koşul
   
}
 digitalWrite(9,1);
 delay(gecikme);
 digitalWrite(9,0);
 delay(gecikme);
}
