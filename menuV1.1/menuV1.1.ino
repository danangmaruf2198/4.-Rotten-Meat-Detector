#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);
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
int sapiR2 = 0;
int sapiG2 = 0;
int sapiB2 = 0;
int sapiK2 = 0;
int babiR2 = 0;
int babiG2 = 0;
int babiB2 = 0;
int babiK2 = 0;
int sapiRSegarbawah;
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
  int t3 = 0;
  int t4 = digitalRead(5);
  int t5 = digitalRead(6);
  int t6 = digitalRead(7);
Serial.print(t1);
Serial.print("-----");
Serial.print(t2);
Serial.print("-----");
Serial.print(t3);
Serial.print("-----");
Serial.print(t4);
Serial.print("-----");
Serial.print(t5);
Serial.print("-----");
Serial.println(t6);
delay(100);

  //if(Serial.available())
  //{
  //char a = Serial.read();

  if (t1 == 1) {
    menu++;
    //ketika tombol 1 ditekan maka menu akan bergeser dan menambah variable menu menjadi +1
  }
  if (t4 == 1) {
    menu--;
    //ketika tombol 4 ditekan maka menu akan bergeser dan mengurangi variable menu menjadi -1;

  }



  if (menu > 2) {
    menu =  0;
    //    apabila menu ditekan lebih dari tiga kali maka menu akan kembali pada posisi awal. atau pana menu 1

  }
  if (menu < 0) {
    menu =  2;
    //  apablia lmenu dikurangi lebih dari 3 maka menu akan direset ke menu ketiga dan kembali pada posisi awal
  }
  //}
  if (kalibrasi == 0 && scan == 0)
  { //apabila variabel kalibrasi dan scan nol maka menu utama akan ditampilkan dengan syarat ini
    lcd.setCursor(0, 0);
    lcd.print("MEAT DETECTOR");
    lcd.setCursor(0, 1);
    lcd.print("<CALIB     SCAN>");

    menu = 0;
    if (t6 == 1) {
      kalibrasi = 1;
      //memilih menu kalibrasi dan menambahkan variable kalibrasi dengan nilai 1;

    }
  //  if (t3 == 1) {
    //  scan = 1;
      //memilih menu scan dan menambahkan variable scan dengan nilai 1;

    //}
  }





  if (menu == 0 && submenu1 == 0 && submenu2 == 0 && submenu3 == 0 && kalibrasi == 1)
  { //apabila setelah kalibrasi bernilai satu maka akan ditampilkan menu , saat menu pada kondisi 0 maka kalibrasi sapi ditampilkan;

    lcd.clear();
    lcd.print("Beef Calib");
    lcd.setCursor(0, 1);
    lcd.print("<<");
    lcd.setCursor(14, 1);
    lcd.print(">>");
    lcd.setCursor(0, 1);
    lcd.print("<<");
    lcd.setCursor(3, 1);
    lcd.print("Other Menu");

    if (t2 == 1) {
      submenu1 = 1;

    }
  }
  if (menu == 1 && submenu1 == 0 && submenu2 == 0 && submenu3 == 0 && kalibrasi == 1)
  { //apabila setelah kalibrasi bernilai satu maka akan ditampilkan menu , saat menu pada kondisi 1 maka kalibrasi babi ditampilkan;

    lcd.clear();
    lcd.print("Pork Calib");
    lcd.setCursor(0, 1);
    lcd.print("<<");
    lcd.setCursor(14, 1);
    lcd.print(">>");
    lcd.setCursor(0, 1);
    lcd.print("<<");
    lcd.setCursor(3, 1);
    lcd.print("Other Menu");
    if (t2 == 1) {
      // apabila di tekan enter pada tombol 1 maka submenu akan menambahkan nilai satu pada variable tersebut
      submenu2 = 1;

    }
  }
  if (menu == 2 && submenu1 == 0 && submenu2 == 0 && submenu3 == 0 && kalibrasi == 1)
  { // //apabila setelah kalibrasi bernilai satu maka akan ditampilkan menu , saat menu pada kondisi 2 maka ditampilkan emnu untuk keluar;


    lcd.clear();
    lcd.print("Back Home");
    lcd.setCursor(0, 1);
    lcd.print("Press bek 4 Back");
    if (t5 == 1) {
      // apabila tombol 5 ditekan maka menu akan keluar ke posisi sebelumnya atau home. karena nilai variable kalibrasi kembali dibuat 0

      kalibrasi = 0;
    }


  }






  if (menu == 0 && submenu1 == 1 && kalibrasi == 1)
  { // apabila menu bernilai 0 dan submenu 1 berniali 1 yakni ketika tombol kalibrasi sapi maka akan ditampilan menu kalibrasi sapi
    lcd.clear();
    lcd.print("tekan tombol KAL");
    lcd.setCursor(0, 1);
    lcd.print("untuk kalibrasi");

    if (t5 == 1) {
      // apabila tombol 5 ditekan maka sistem akan kembali ke posisi sebelumnya atau menu pelihian kalibrasi antara daging sapi atau daging babi
      submenu1 = 0;
    }
    if (t6 == 1) {
      //apabila tombol 6 ditekan maka akan membuat sistem mengeksekusi program pada void color() yakni program penjalanan sensor dan mengambil beberapa datanya
      color();
      int red1 = red;
      int green1 = green;
      int blue1 = blue;
      delay(1000);
      sapiR1 = red1;
      sapiG1 = green1;
      sapiB1 = blue1;
      Serial.print(babiR1);
      Serial.print("===");
      Serial.print(babiG1);
      Serial.print("===");
      Serial.print(babiB1);
      Serial.print("===");
      //  Serial.println(babiK);
      Serial.print(sapiR1);
      Serial.print("===");
      Serial.print(sapiG1);
      Serial.print("===");
      Serial.print(sapiB1);
      Serial.println("===");
      //Serial.println(sapiK);

      //     sapiK = analogRead(A3);
      lcd.clear();
    }
  }




  if (menu == 1 && submenu2 == 1 && kalibrasi == 1)
  { // menu kalibrasi sub menu 2 akan di tampilkan apabila menu berniali 1 dan submenu2 berniali 1 dan akan menampilkan tekan tombol kal.
    lcd.clear();
    lcd.print("tekan tombol KAL");
    lcd.setCursor(0, 1);
    lcd.print("untuk kalibrasi");

    if (t5 == 1) {
      // apabila ditekan tombol 5 atau tombol back maka menu akan kembali pada menu pemilihan sapi atau babi
      submenu2 = 0;
    }
    if (t6 == 1) {
      // apabila ditekan tombol 6 atau tombol kalibrasi maka akan mengeksekusi program dengan menjalankan void color()

      color();
      int red1 = red;
      int green1 = green;
      int blue1 = blue;
      delay(1000);
      sapiR1 = red1;
      sapiG1 = green1;
      sapiB1 = blue1;

    }
  }
  //============================================================

  if (menu == 0 && scan == 1)
  { // apabila pada menu home dipilih menu scan maka nilai scan adalah 1 dan menampilkan tulisan tekan oke
    lcd.clear();
    lcd.print("Tekan ok 1x");
    if (t2 == 1) {
      submenu1 = 1;
      //  apabila ditekan tombol 2 maka nilai menambahkan nilai submenu1 adalah 1
    }
  }
  if (menu == 1 && scan == 1)
  { // apabila menu adalalah 1 dan pada saat kondisi scan 1 maka akan ditampilkan menu keluar untuk keluar dari menu scan
    lcd.clear();
    lcd.print("Keluar");
    lcd.setCursor(0, 1);
    lcd.print("tekan bek 4 Back");
    if (t5 == 1) {
      // apabila tombol 5 ditekan maka anak membuat nilai scan menjadi 0 dan kembali ke home utama
      scan = 0;
    }

  }




  if (menu == 0 && submenu1 == 1 && scan == 1)
  { //apabila menu=0 dan submenu1 adalah 1 serta scan 1 maka akan menampilkan program deteksi
    lcd.clear();
    lcd.print("tekan skan");
    if (t5 == 1) {
      // apabila tombol 5 ditekan maka akan mengembalikan nilai submenu menjadi 0 kembali dan kembali ke menu pemilihan scan
      submenu1 = 0;
    }
    if (t3 == 1) {
      //  apabila tombol scan ditekan kembali maka akan mengeksekusi program di void color() serta mengambi data pembacaan serta dibandingkan dengan nilai konstanta hasil kalibrasi untuk mendeteksi daging apa
      color();
      String f = 'R' + String(red);
      String g = 'B' + String(blue);
      String h = 'G' + String (green);
      Serial.print(red);
      Serial.print("====");
      Serial.print(green);
      Serial.print("====");
      Serial.println(blue);
      Serial.print(red);
      Serial.print("====");
      Serial.print(green);
      Serial.print("====");
      Serial.println(blue);
      delay(1000);
      digitalWrite(13, LOW);
      if (119.67 <= red && red <= 133.47 && 170.6 <= green && green <= 184.73 && 149.27 <= blue && blue <= 159.33) {
        lcd.clear();
        lcd.print("sapi TIDAK SEGAR");
        delay(1000);
      }
      else if (113 <= red&& red <= 114.47 && 105 <= green && green <= 149.33 && 128.8 <=blue && blue <= 130) {
        lcd.clear();
        lcd.print("babi TIDAK SEGAR");
        delay(1000);
      }

      if (118 <= red && red <= 124 && 161.2 <= green && green <= 178 && 134.87 <= blue && blue <= 144.6) {
        lcd.clear();
        lcd.print("sapi KRG SEGER");
        delay(1000);
      }
      else if (105.93 <= red && red <= 115 && 129.73 <= green && green <= 142.47 && 108 <= blue && blue <= 115) {
        lcd.clear();
        lcd.print("babi KRG SEGER");
        delay(1000);
      }
      if (red <= 58 && green <= 104.13 && blue <= 86.267) {
        lcd.clear();
        lcd.print("sapi SEGER");
        delay(1000);

      }
      else if (58 < red && red < 69 && 104.13 < green && green < 139.87 && 86.267 < blue && blue < 113.93)
        lcd.clear();
      lcd.print("babi SEGAR");
      delay(1000);


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

//==========================================
/*
   PEMBAGIAN KATEGORI DAGING : HARI 1-2 = SEGAR
                               HARI 3-5 = KURANG SEGAR
                               HARI 6-7 = BUSUK
   RANGE SEGAR = DAGING BABI BERADA DI ANTARA DAGING SAPI. JADI SULIT DIDETEKSI. DIGUNAKAN PEMBAGIAN RANGE UNTUK BABI
                 DATA SEBAGAI BERIKUT:
                          S     B
                 DATA R :58.8   69

                 DATA G :104.13 139.87

                 DATA B :86.267 113.93

  if(red<=58&&green<=104.13&&blue<=86.267){
  daging sapi segar
   }
  else if (58<red<69&&104.13<green<139.87&&86.267<blue<113.93)

  ////      dagingsapi segar
    }
  RANGE KURANG SEGAR = DATA R:124.4   115
                              118.6   112.47
                              121.13  105.93
                              122     110.13
                            G:178.53  142.47
                              162     137.4
                              163.26  129.733
                              161.2   136.93
                            B:144.6  114.93
                              136.73  112.73
                              134.87  108.6
                              135.8   113.8

    if(118<=red<=124&&161.2<=green<=178&&134.87<=blue<=144.6){
    }
    else if(105.93<=red<=115&&129.73<=green<=142.47&&108<=blue<=115){

               }

  RANGE BUSUK : R: 119.67  114.47
                   133.47  113.6














  58.8  69
  124.4 115
  118.6 112.47
  121.13  105.93
  122 110.13
  119.67  114.47
  133.47  113.6



  104.13  139.87
  178.53  142.47
  162 137.4
  163.267 129.733
  161.2 136.93
  170.6 149.33
  184.73  105.67




  86.267  113.93
  144.6 114.93
  136.73  112.73
  134.87  108.6
  135.8 113.8
  149.27  128.8
  159.33  129.67
*/
