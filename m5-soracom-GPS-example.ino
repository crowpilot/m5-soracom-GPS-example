#include <M5Stack.h>

#define TINY_GSM_MODEM_UBLOX
#include <TinyGsmClient.h>

TinyGsm modem(Serial2); /* 3G board modem */
TinyGsmClient ctx(modem);

void setup() {
  Serial.begin(115200);
  M5.begin();

  M5.Lcd.print(F("modem.restart()"));
  Serial2.begin(115200, SERIAL_8N1, 16, 17);
  modem.restart();
  M5.Lcd.println(F("done"));

  M5.Lcd.print(F("getModemInfo:"));
  String modemInfo = modem.getModemInfo();
  M5.Lcd.println(modemInfo);
  M5.Lcd.print("enable GPS");
  modem.enableGPS();
  M5.Lcd.println("ok");
  //M5.Lcd.println(modem.getGNSSMode());

  delay(1000);
  M5.Lcd.clear(TFT_BLACK);
}


void loop() {
  M5.update();

  //M5.Lcd.clear(BLACK);
  //M5.Lcd.println(F("World Clock from worldtimeapi.org"));
  Serial.println(modem.getGPSraw());
  //getGPSraw()  GPS-GSM loc
  //getGsmLocationRaw() GSM loc
  Serial.println("/nrefresh/n");
  float lat,lon,speed,alt,accuracy;
  int vsat,usat;
  int year,month,day,hour,minute,second;
  modem.getGPS(&lat,&lon,&speed,&alt,&vsat,&usat,&accuracy,&year,&month,&day,&hour,&minute,&second);

  M5.Lcd.setCursor(0,0);
  M5.Lcd.setTextSize(2);
  M5.Lcd.printf("%3.3f%3.3f",lat,lon);

  delay(1000 * 3);
}
