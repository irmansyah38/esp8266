#ifndef VARIABLE_H
#define VARIABLE_H

// library for website
#include <ESP8266WebServer.h>
// library for telegram
#include <UniversalTelegramBot.h>
// wifiClientSecure
#include <WiFiClientSecure.h>

// servo
#include <Servo.h>

// wifi
#include <WiFiManager.h>
#include <ESP8266WiFi.h>

// terhubung wifi
extern bool connectedWifi;

// make object client
extern WiFiClientSecure client;

// make object wifi
extern WiFiManager wm;

// terhubung wifi
extern bool connectedWifi;

// make object telegram bot
extern UniversalTelegramBot bot;
// make variable chatid for bot
extern String chatID;
// make variable bot condition
extern bool botCondition;

// sensors value
extern float phValue;
extern float suhuValue;

// notifikasi
extern bool notifikasi;
extern bool emptyAsam;
extern bool emptyBasa;

// object servo
extern Servo myservo;

// make function for execute telegram bot
void excuteTelegramBot();

#endif