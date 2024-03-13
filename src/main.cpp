#include <Arduino.h>
#include <wifi.h>
#include "variable.h"
#include "website.h"

// put function declarations here:

void setup()
{
  X509List cert(TELEGRAM_CERTIFICATE_ROOT);
  configTime(0, 0, "pool.ntp.org"); // get UTC time via NTP
  // client.setTrustAnchors(&cer);
  Serial.begin(9600);
  setupWifi();
  setupWebsite();
  // put your setup code here, to run once:
}

void loop()
{
  if (botCondition == true)
  {
    excuteTelegramBot();
  }
}
