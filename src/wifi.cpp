#include <wifi.h>

void setupWifi()
{

  WiFiManager wm;

  WiFi.mode(WIFI_STA);

  bool res;

  res = wm.autoConnect("aquascape", "aquascape");

  if (!res)
  {
    Serial.print("Gagal terhubung koneksi");
  }
  else
  {
    Serial.print("Terhubung koneksi");
  }
}
