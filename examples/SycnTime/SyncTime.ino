#include "Quectel_LTE.h"

Quectel_LTE LTE;
tm _time;

void setup() {
  delay(200);
  Serial.begin(115200);  
  Serial.println("## Demo AT Bypass");
  
  LTE.initialize();
  if(LTE.isAlive(20000))
  {
    Serial.println("### Module not alived");
    return;
  }
}

void loop() {
  /* Debug */
  // LTE._AtSerial.AT_Bypass();
  if(LTE.SyncTime("cn.ntp.org.cn"))
  {
    if(LTE.GetTime(&_time))
    {
      Serial.print("Get time: ");
      Serial.print(_time.tm_year);
      Serial.print("-");
      Serial.print(_time.tm_mon);
      Serial.print("-");
      Serial.print(_time.tm_mday);
      Serial.print(" ");
      Serial.print(_time.tm_hour);
      Serial.print(":");
      Serial.print(_time.tm_min);
      Serial.print(":");
      Serial.println(_time.tm_sec);
    }
  }

  delay(1000);
}
