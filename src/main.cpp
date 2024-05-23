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

void send()
{
  if (mySerial.available() == 0)
  {
    if (botCondition)
    {
      mySerial.print("sudah");
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
        mySerial.print("belum");
        mySerial.print('\n');
      }
    }
  }
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
      errjson = false;
      suhuValue = doc["suhu"];
      phValue = doc["ph"];
      emptyAsam = doc["emptyAsam"];
      emptyBasa = doc["emptyBasa"];

      doc.clear();
    }
  }
}

void setup()
{
  // mySerial.begin(9600);
  Serial.begin(9600);
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
    /* code */

    // if (notifikasi)
    // {
    //   if (emptyAsam)
    //   {
    //     bot.sendMessage(chatID, "Segera isi ulang cairan asam.", "");
    //   }

    //   if (emptyBasa)
    //   {
    //     bot.sendMessage(chatID, "Segera isi ulang cairan basa.", "");
    //   }

    //   if (errjson)
    //   {
    //     bot.sendMessage(chatID, "Json error.", "");
    //   }
    // }
  }
  else
  {
    handleClient();
  }
  received();
}
