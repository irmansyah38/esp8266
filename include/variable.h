#ifndef VARIABLE_H
#define VARIABLE_H

// library for website
#include <ESP8266WebServer.h>
// library for telegram
#include <UniversalTelegramBot.h>
// wifiClientSecure
#include <WiFiClientSecure.h>

// make object client
extern WiFiClientSecure client;

// make object telegram bot
extern UniversalTelegramBot bot;
// make variable chatid for bot
extern String chatID;
// make variable bot condition
extern bool botCondition;

// make function for execute telegram bot
void excuteTelegramBot();

#endif