#ifndef VARIABLE_H
#define VARIABLE_H

// library for website
#include <ESPAsyncWebServer.h>
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

// Checks for new messages every 1 second.
int botRequestDelay;
unsigned long lastTimeBotRan;

// make function for execute telegram bot
void excuteTelegramBot();

#endif