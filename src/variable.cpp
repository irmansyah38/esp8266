#include "variable.h"

// make object bot
WiFiClientSecure client;
UniversalTelegramBot bot("update token", client);

// make object wifi
WiFiManager wm;

// variable chatid for bot
String chatID = "";

// terhubung wifi
bool connectedWifi = false;

// sensors value
float phValue;
float suhuValue;

// notifikasi
bool notifikasi = true;
bool emptyAsam;
bool emptyBasa;

// bot condition variable for ensure that have connected with telegram
bool botCondition = false;

// servo
Servo myservo;

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
      String welcome = "Selamat datang, " + from_name + ".\n";
      welcome += "Gunakan perintah yang ada di bawah ini.\n\n";
      welcome += "/beri_pakan untuk memberi pakan  \n";
      welcome += "/status untuk mengetahui keadaan aquascape \n";

      if (notifikasi)
      {
        welcome += "/matikan_notifikasi untuk menghentikan notfikasi \n";
      }
      else
      {
        welcome += "/nyalakan_notifikasi untuk menyalakan notfikasi \n";
      }

      bot.sendMessage(chat_id, welcome, "");
    }

    if (text == "/beri_pakan")
    {

      // int pos = 0; // variable to store the servo position
      // for (pos = 0; pos <= 180; pos += 1)
      // { // goes from 0 degrees to 180 degrees
      //   // in steps of 1 degree
      //   myservo.write(pos); // tell servo to go to position in variable 'pos'
      //   delay(3);           // waits 15 ms for the servo to reach the position
      // }
      // for (pos = 180; pos >= 0; pos -= 1)
      // {                     // goes from 180 degrees to 0 degrees
      //   myservo.write(pos); // tell servo to go to position in variable 'pos'
      //   delay(3);           // waits 15 ms for the servo to reach the position
      // }
      myservo.write(60);
      delay(1000);
      myservo.write(0);
      bot.sendMessage(chat_id, "Sudah memberi pakan", "");
    }

    if (text == "/status")
    {
      String message = "Suhu: " + String(suhuValue) + "\n";
      message += "PH  : " + String(phValue) + "\n";
      bot.sendMessage(chat_id, message, "");
    }

    if (text == "/matikan_notifikasi" || text == "/nyalakan_notifikasi")
    {
      notifikasi = !notifikasi;
      bot.sendMessage(chat_id, "OK!", "");
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
