#include "variable.h"

// make object bot
WiFiClientSecure client;
UniversalTelegramBot bot("update token", client);

// variable chatid for bot
String chatID = "";

// terhubung wifi
bool connectedWifi = false;

// bot condition variable for ensure that have connected with telegram
bool botCondition = false;

// Checks for new messages every 1 second.
int botRequestDelay = 1000;
unsigned long lastTimeBotRan;

// Handle what happens when you receive new messages
void handleNewMessages(int numNewMessages)
{
  Serial.println("handleNewMessages");
  Serial.println(String(numNewMessages));

  for (int i = 0; i < numNewMessages; i++)
  {
    // Chat id of the requester
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != chatID)
    {
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }

    // Print the received message
    String text = bot.messages[i].text;
    Serial.println(text);

    String from_name = bot.messages[i].from_name;

    if (text == "/mulai")
    {
      String welcome = "Welcome, " + from_name + ".\n";
      welcome += "Gunakan perintah yang ada dibawah ini.\n\n";
      welcome += "/beri-makan untuk memberi pakan ikan \n";
      welcome += "/keadaan untuk mengetahui keadaan aquascape\n";
      bot.sendMessage(chat_id, welcome, "");
    }

    if (text == "/beri-makan")
    {
      bot.sendMessage(chat_id, "Sudah memberi makan", "");
    }

    if (text == "/keadaan")
    {
      bot.sendMessage(chat_id, "LED state set to OFF", "");
    }
  }
}

void excuteTelegramBot()
{
  // put your main code here, to run repeatedly:
  if (millis() > lastTimeBotRan + botRequestDelay)
  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while (numNewMessages)
    {
      Serial.println("got response");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    lastTimeBotRan = millis();
  }
}
