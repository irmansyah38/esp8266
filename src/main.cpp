#include <Arduino.h>
#include <ArduinoJson.h>
#include <SoftwareSerial.h>
#include "variable.h"
#include "website.h"
#include "wifi.h"

SoftwareSerial mySerial(12, 16);
StaticJsonDocument<200> doc;
X509List cert(TELEGRAM_CERTIFICATE_ROOT);
bool errjson;
bool interval1 = 1000;
unsigned long previousMillis1 = 0;

void send()
{
  if (botCondition)
  {
    mySerial.print("s");
    mySerial.print('\n');
  }
  else
  {
    if (connectedWifi)
    {
      IPAddress ip = WiFi.localIP();
      mySerial.print(ip.toString());
      mySerial.print('\n');
    }
    else
    {
      mySerial.print("b");
      mySerial.print('\n');
    }
  }
  delay(500);
}

void received()
{
  if (Serial.available())
  {

    String data = Serial.readStringUntil('\n');

    DeserializationError error = deserializeJson(doc, data);

    if (error)
    {
      errjson = true;
      return;
    }
    else
    {
      suhuValue = doc["suhu"];
      phValue = doc["ph"];
      emptyAsam = doc["emptyAsam"];
      emptyBasa = doc["emptyBasa"];

      doc.clear();
    }
  }
  delay(100);
}

void setup()
{
  Serial.begin(9600);
  mySerial.begin(9600);
  configTime(0, 0, "pool.ntp.org"); // get UTC time via NTP
  client.setTrustAnchors(&cert);    // Add root
  setupWifi();
  setupWebsite();

  // Servo
  myservo.attach(2);
  myservo.write(0);
}

void loop()
{

  if (botCondition)
  {
    excuteTelegramBot();

    if (notifikasi)
    {
      unsigned long currentMillis = millis();
      if (currentMillis - previousMillis1 >= interval1 * 120)
      {
        previousMillis1 = currentMillis;
        if (emptyAsam)
        {
          bot.sendMessage(chatID, "Segera isi ulang cairan asam.", "");
        }

        if (emptyBasa)
        {
          bot.sendMessage(chatID, "Segera isi ulang cairan basa.", "");
        }
      }
    }
  }
  else
  {
    handleClient();
  }
  received();
  send();
}
