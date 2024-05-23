#include <wifi.h>

void setupWifi()
{

  WiFi.mode(WIFI_STA);

  bool res;

  res = wm.autoConnect("aquascape", "aquascape");

  if (res == true)
  {
    connectedWifi = true;
  }
}
