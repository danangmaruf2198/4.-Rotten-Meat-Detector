#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int s0 = 8;
const int s1 = 9;
const int s2 = 12;
const int s3 = 11;
const int out = 10;
// values
int red = 0;
int green = 0;
int blue = 0;
int sapi = 0;
int menu = 0;
bool scan = 0;
bool kalibrasi = 0;
bool submenu1 = 0;
bool submenu2 = 0;
bool submenu3 = 0;

int sapiR1 = 0;
int sapiG1 = 0;
int sapiB1 = 0;
int sapiK1 = 0;
int babiR1 = 0;
int babiG1 = 0;
int babiB1 = 0;
int babiK1 = 0;
int sapiR1 = 0;
int sapiG1 = 0;
int sapiB1 = 0;
int sapiK1 = 0;
int sapiR2 = 0;
int sapiG2 = 0;
int sapiB2 = 0;
int sapiK2 = 0;
int babiR2 = 0;
int babiG2 = 0;
int babiB2 = 0;
int babiK2 = 0;
int sapiR2 = 0;
int sapiG2 = 0;
int sapiB2 = 0;
int sapiK2 = 0;
int sapiRbawah;
int sapiRatas;
int sapiGbawah;
int sapiGatas;
int sapiBbawah;
int sapiBatas;
int sapiRbawah;
int sapiRatas;
int sapiGbawah;
int sapiGatas;
int sapiBbawah;
int sapiBatas;
int babiRbawah;
int babiRatas;
int babiGbawah;
int babiGatas;
int babiBbawah;
int babiBatas;

void setup()
{
  lcd.init();                      // initialize the lcd
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print("hello, world!");
  for (int c = 2; c < 8; c++) {
    pinMode(c, INPUT);
  }
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
  pinMode(13, OUTPUT);
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
}

void loop() {
  int t1 = digitalRead(2);
  int t2 = digitalRead(3);
  int t3 = digitalRead(4);
  int t4 = digitalRead(5);
  int t5 = digitalRead(6);
  int t6 = digitalRead(7);

  //if(Serial.available())
  //{
  //char a = Serial.read();

  if (t1 == 1) {
    menu++;
    //smenu++;
  }
  if (t4 == 1) {
    menu--;
    //smenu--;
  }



  if (menu > 3) {
    menu =  0;
    //    smenu = 0;
  }
  if (menu < 0) {
    menu =  3;
    //  smenu=2;
  }
  //}
  if (kalibrasi == 0 && scan == 0)
  { //Serial.println(scan);
    lcd.clear();
    lcd.print("PENA VERSI 2.0");
    lcd.setCursor(0, 1);
    lcd.print("||||||||||||||||||||||||||||||||||");

    menu = 0;
    if (t6 == 1) {
      kalibrasi = 1;
    }
    if (t3 == 1) {
      scan = 1;
    }
  }





  if (menu == 0 && submenu1 == 0 && submenu2 == 0 && submenu3 == 0 && kalibrasi == 1)
  {
    lcd.clear();
    lcd.print(" kalibrasi sapi");
    lcd.setCursor(0, 1);
    lcd.print("<<");
    lcd.setCursor(14, 1);
    lcd.print(">>");
    lcd.setCursor(0, 1);
    lcd.print("<<");
    lcd.setCursor(3, 1);
    lcd.print("Menu lain2");

    if (t2 == 1) {
      submenu1 = 1;

    }
  }
  if (menu == 1 && submenu1 == 0 && submenu2 == 0 && submenu3 == 0 && kalibrasi == 1)
  {
    lcd.clear();
    lcd.print("kalibrasi sapi");
    lcd.setCursor(0, 1);
    lcd.print("<<");
    lcd.setCursor(14, 1);
    lcd.print(">>");
    lcd.setCursor(0, 1);
    lcd.print("<<");
    lcd.setCursor(3, 1);
    lcd.print("Menu lain2");

    if (t2 == 1) {
      submenu2 = 1;

    }
  }
  if (menu == 2 && submenu1 == 0 && submenu2 == 0 && submenu3 == 0 && kalibrasi == 1)
  {
    lcd.clear();
    lcd.print("kalibrasi babi");
    lcd.setCursor(0, 1);
    lcd.print("<<");
    lcd.setCursor(14, 1);
    lcd.print(">>");
    lcd.setCursor(0, 1);
    lcd.print("<<");
    lcd.setCursor(3, 1);
    lcd.print("Menu lain2");
    if (t2 == 1) {
      submenu3 = 1;

    }
  }
  if (menu == 3 && submenu1 == 0 && submenu2 == 0 && submenu3 == 0 && kalibrasi == 1)
  {
    lcd.clear();
    lcd.print("Keluar");
    lcd.setCursor(0, 1);
    lcd.print("tekan bek 4 Back");
    if (t5 == 1) {
      kalibrasi = 0;
    }


  }






  if (menu == 0 && submenu1 == 1 && kalibrasi == 1)
  {
    lcd.clear();
    lcd.print("tekan tombol KAL");
    lcd.setCursor(0, 1);
    lcd.print("untuk kalibrasi");

    if (t5 == 1) {
      submenu1 = 0;
    }
    if (t6 == 1) {
      color();
      int red1 = red;
      int green1 = green;
      int blue1 = blue;
      delay(1000);
      color();
      int red2 = red;
      int green2 = green;
      int blue2 = blue;
      delay(1000);
      sapiR1 = red1;
      sapiG1 = green1;
      sapiB1 = blue1;
      sapiR2 = red2;
      sapiG2 = green2;
      sapiB2 = blue2;
      Serial.print(sapiR1);
      Serial.print("===");
      Serial.print(sapiG1);
      Serial.print("===");
      Serial.print(sapiB1);
      Serial.print("===");
      Serial.println(analogRead(A3));
/*      Serial.print(babiR1);
      Serial.print("===");
      Serial.print(babiG1);
      Serial.print("===");
      Serial.print(babiB1);
      Serial.print("===");
      //Serial.println(babiK);
      Serial.print(sapiR1);
      Serial.print("===");
      Serial.print(sapiG1);
      Serial.print("===");
      Serial.print(sapiB1);
      Serial.println("===");
      //Serial.println(sapiK);

//     sapiK = analogRead(A3);
      lcd.clear();
      lcd.print (f);
      lcd.setCursor(8, 0);
      lcd.print (g);
      lcd.setCursor(0, 1);
      lcd.print (h);
      lcd.setCursor(8, 1);
      lcd.print ("K");
      lcd.setCursor(9, 1);
      lcd.print (analogRead(A3));
      delay(1000);
      digitalWrite(13, LOW);
  */  }
  }
  /*
    if(menu == 1 && submenu1 == 1&& kalibrasi == 1)
    {
      lcd.clear();
      lcd.print("smenu1 2");
      if(t5 == 1){
        submenu1=0;
      }
    }

    if(menu == 2 && submenu1 == 1&& kalibrasi == 1)
    {
      lcd.clear();
      lcd.print("smenu1 3");
      if(t5 == 1){
        submenu1=0;
      }
    }*/





  if (menu == 1 && submenu2 == 1 && kalibrasi == 1)
  {
    lcd.clear();
    lcd.print("tekan tombol KAL");
    lcd.setCursor(0, 1);
    lcd.print("untuk kalibrasi");

    if (t5 == 1) {
      submenu2 = 0;
    }
    if (t6 == 1) {
      color();
      int red1 = red;
      int green1 = green;
      int blue1 = blue;
      delay(1000);
      color();
      int red2 = red;
      int green2 = green;
      int blue2 = blue;
      delay(1000);
      sapiR1 = red1;
      sapiG1 = green1;
      sapiB1 = blue1;
      sapiR2 = red2;
      sapiG2 = green2;
      sapiB2 = blue2;
  /*   Serial.print(sapiR);
      Serial.print("===");
      Serial.print(sapiG);
      Serial.print("===");
      Serial.print(sapiB);
      Serial.print("===");
      Serial.println(sapiK);
      Serial.print(babiR);
      Serial.print("===");
      Serial.print(babiG);
      Serial.print("===");
      Serial.print(babiB);
      Serial.print("===");
      Serial.println(babiK);
      Serial.print(sapiR);
      Serial.print("===");
      Serial.print(sapiG);
      Serial.print("===");
      Serial.print(sapiB);
      Serial.print("===");
      Serial.println(sapiK);

      lcd.clear();
      lcd.print (f);
      lcd.setCursor(8, 0);
      lcd.print (g);
      lcd.setCursor(0, 1);
      lcd.print (h);
      lcd.setCursor(8, 1);
      lcd.print ("K");
      lcd.setCursor(9, 1);
      lcd.print (analogRead(A3));
      delay(1000);
      digitalWrite(13, LOW);
*/    }
  }
  /*
    if(menu == 1 && submenu2 == 1&& kalibrasi == 1)
    {
      lcd.clear();
      lcd.print("smenu2 2");
      if(t5 == 1){
        submenu2=0;
      }
    }

    if(menu == 2 && submenu2 == 1&& kalibrasi == 1)
    {
      lcd.clear();
      lcd.print("smenu2 3");
      if(t5 == 1){
        submenu2=0;
      }
    }
  */







  if (menu == 2 && submenu3 == 1 && kalibrasi == 1)
  {
    lcd.clear();

    lcd.print("tekan tombol KAL");
    lcd.setCursor(0, 1);
    lcd.print("untuk kalibrasi");
    if (t5 == 1) {
      submenu3 = 0;
    }
    if (t6 == 1) {
      color();
      int red1 = red;
      int green1 = green;
      int blue1 = blue;
      delay(1000);
      color();
      int red2 = red;
      int green2 = green;
      int blue2 = blue;
      delay(1000);
      babiR1 = red1;
      babiG1 = green1;
      babiB1 = blue1;
      babiR2 = red2;
      babiG2 = green2;
      babiB2 = blue2;

  /*    Serial.print(sapiR);
      Serial.print("===");
      Serial.print(sapiG);
      Serial.print("===");
      Serial.print(sapiB);
      Serial.print("===");
      Serial.println(sapiK);
      Serial.print(babiR);
      Serial.print("===");
      Serial.print(babiG);
      Serial.print("===");
      Serial.print(babiB);
      Serial.print("===");
      Serial.println(babiK);
      Serial.print(sapiR);
      Serial.print("===");
      Serial.print(sapiG);
      Serial.print("===");
      Serial.print(sapiB);
      Serial.print("===");
      Serial.println(sapiK);
*/

    }
  }
  /*
    if(menu == 1 && submenu3 == 1&& kalibrasi == 1)
    {
      lcd.clear();
      lcd.print("smenu3 2");
      if(t5 == 1){
        submenu3=0;
      }
    }

    if(menu == 2 && submenu3 == 1 && kalibrasi == 1)
    {
      lcd.clear();
      lcd.print("smenu3 3");
      if(t5 == 1){
        submenu3=0;
      }
    }*/
  //============================================================

  if (menu == 0 && scan == 1)
  {
    lcd.clear();
    lcd.print("Tekan ok 1x");
    if (t2 == 1) {
      submenu1 = 1;

    }
  }
  if (menu == 1 && scan == 1)
  {
    lcd.clear();
    lcd.print("Keluar");
    lcd.setCursor(0, 1);
    lcd.print("tekan bek 4 Back");
    if (t5 == 1) {
      scan = 0;
    }

  }




  if (menu == 0 && submenu1 == 1 && scan == 1)
  { lcd.clear();
    lcd.print("tekan skan");
    if (t5 == 1) {
      submenu1 = 0;
    }
    if (t3 == 1) {
      color();
     
      String f = 'R' + String(red);
      String g = 'B' + String(blue);
      String h = 'G' + String (green);
      Serial.print(red);
      Serial.print("===");
      Serial.print(green);
      Serial.print("===");
      Serial.println(blue);
      Serial.print(red);
      Serial.print("===");
      Serial.print(green);
      Serial.print("===");
      Serial.println(blue);
      delay(1000);
      digitalWrite(13, LOW);
      if(sapiR1>=sapiR2){
        sapiRbawah= sapiR2;
        sapiRatas= sapiR1;
      }
      else if(sapiR1<sapiR2){
        sapiRbawah= sapiR1;
        sapiRatas= sapiR2;
      }
      
      if(sapiG1>=sapiG2){
        sapiGbawah= sapiG2;
        sapiGatas= sapiG1;
      }
      else if(sapiG1<sapiG2){
        sapiGbawah= sapiG1;
        sapiGatas= sapiG2;
      }
      
      if(sapiB1>=sapiB2){
        sapiBbawah= sapiB2;
        sapiBatas= sapiB1;
      }
      else if(sapiB1<sapiB2){
       sapiBbawah= sapiB1;
       sapiBatas= sapiB2;
      }
      //======================
      if(sapiR1>=sapiR2){
         sapiRbawah= sapiR2;
        sapiRatas= sapiR1;
      }
      else if(sapiR1<sapiR2){
        sapiRbawah= sapiR1;
        sapiRatas= sapiR2;
      }
      
      if(sapiG1>=sapiG2){
        sapiGbawah= sapiG2;
        sapiGatas= sapiG1;
      }
      else if(sapiG1<sapiG2){
        sapiGbawah= sapiG1;
        sapiGatas= sapiG2;
      }
      
      if(sapiB1>=sapiB2){
        sapiBbawah= sapiB2;
        sapiBatas= sapiB1;
      }
      else if(sapiB1<sapiB2){
        sapiBbawah= sapiB1;
        sapiBatas= sapiB2;
      }
      //============================
      if(babiR1>=babiR2){
        babiRbawah= babiR2;
        babiRatas= babiR1;
      }
      else if(babiR1<babiR2){
        babiRbawah= babiR1;
        babiRatas= babiR2;
      }
      
      if(babiG1>=babiG2){
        babiGbawah= babiG2;
        babiGatas= babiG1;
a    }
      else if(babiG1<babiG2){
        babiGbawah= babiG1;
        babiGatas= babiG2;
      }
      
      if(babiB1>=babiB2){
        babiBbawah= babiB2;
        babiBatas= babiB1;
      }
      else if(babiB1<babiB2){
        babiBbawah= babiB1;
        babiBatas= babiB2;
      }
      
      if ((red >= (sapiRbawah-10) && red <= (sapiRatas+10)) || (green >= (sapiGbawah-10)  && green <= (sapiGatas+10) ) || (blue >= (sapiBbawah-10)  && blue <= (sapiBatas + 10))) {
        lcd.clear();
        lcd.print ("sapi DETECTED");
        delay(1000);
      }
      else if ((red >= (babiRbawah - 10) && red <= (babiRatas + 10)) || (green >= (babiGbawah - 10) && green <= (babiGatas + 10)) || (blue >= (babiBbawah - 10) && blue <= (babiBatas + 10))) {
        lcd.clear();
        lcd.print ("babi DETECTED");
        delay(1000);
      }
      else if ((red >= (sapiRbawah - 10) && red <= (sapiRatas + 10)) || (green >= (sapiGbawah - 10) && green <= (sapiGatas + 10)) || (blue >= (sapiBbawah - 10) && blue <= (sapiBatas + 10))) {
        lcd.clear();
        lcd.print ("SAPI DETECTED");
        delay(1000);
      }
      else {
        lcd.clear();
        lcd.print("daging celeng");
        delay(1000);
      }
    }
  }


  delay(100);

}
void color()
{

  digitalWrite(13, HIGH);
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);
  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s3, HIGH);
  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  digitalWrite(s2, HIGH);
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);
  String f = 'R' + String(red);
  String g = 'B' + String(blue);
  String h = 'G' + String (green);
  lcd.clear();
  lcd.print (f);
  lcd.setCursor(8, 0);
  lcd.print (g);
  lcd.setCursor(0, 1);
  lcd.print (h);
  lcd.setCursor(8, 1);
  lcd.print ("K");
  lcd.setCursor(9, 1);
  lcd.print (analogRead(A3));
  delay(1000);
  digitalWrite(13, LOW);

}








