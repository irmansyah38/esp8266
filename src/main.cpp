#include <Arduino.h>
#include "variable.h"
#include "website.h"
#include "wifi.h"

X509List cert(TELEGRAM_CERTIFICATE_ROOT);

void setup()
{
  Serial.begin(115200);
  configTime(0, 0, "pool.ntp.org"); // get UTC time via NTP
  client.setTrustAnchors(&cert);    // Add root
  setupWifi();
  setupWebsite();
}

void loop()
{
  handleClient();
  excuteTelegramBot();
}
