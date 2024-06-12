#include "website.h"

char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Aquascape</title>
  <link rel="icon" href="data:;base64,iVBORw0KGgo=">
  <style>
    * {
      margin: 0;
      padding: 0;
    }

    html,
    body {
      width: 100%;
      height: 100%;
    }

    body {
      background: #03151f;
      overflow: hidden;
    }

    #container {
      width: 100vw;
      height: 100vh;
      position: relative;
      left: 50%;
      top: 50%;
      transform: translate(-50%, -50%);
      border-radius: 10px;
      box-shadow: 0px 0px 20px #000;
      background: linear-gradient(#f9855d, #fdd288, white);
      overflow: hidden;
    }

    .sun {
      width: 100px;
      height: 100px;
      position: absolute;
      top: 20px;
      right: 40px;
      background-color: #f9cb5d;
      border-radius: 50%;
    }

    .wave-01 {
      position: absolute;
      width: 150%;
      height: 100%;
      left: -25%;
      top: 70%;
      background-color: rgba(0, 190, 255, 0.4);
      border-radius: 45%;
      animation: rotate 10s linear infinite;
    }

    .wave-02 {
      position: absolute;
      width: 150%;
      height: 100%;
      left: -25%;
      top: 77%;
      background-color: rgba(0, 70, 110, 0.4);
      border-radius: 43%;
      animation: rotate 7s linear infinite;
    }

    .wave-03 {
      position: absolute;
      width: 150%;
      height: 100%;
      left: -25%;
      top: 80%;
      background-color: rgba(0, 90, 110, 0.4);
      border-radius: 40%;
      animation: rotate 5s linear infinite;
    }

    .form-container {
      position: absolute;
      z-index: 10;
      top: 0;
      left: 0;
      right: 0;
      bottom: 0;
      display: flex;
      justify-content: center;
      align-items: center;
    }

    .input {
      margin-bottom: 10px;
      text-align: center;
    }

    .input1 {
      --input-focus: rgba(255, 255, 255, .1);
      --font-color: #323232;
      --font-color-sub: #666;
      --bg-color: rgba(50, 50, 50, .1);
      --main-color: #323232;
      width: 200px;
      height: 40px;
      border-radius: 5px;
      border: 2px solid var(--main-color);
      background-color: var(--bg-color);
      box-shadow: 4px 4px var(--main-color);
      font-size: 15px;
      font-weight: 600;
      color: var(--font-color);
      padding: 5px 10px;
      outline: none;
    }

    .input1::placeholder {
      color: var(--font-color-sub);
      opacity: 0.8;
    }

    .input1:focus {
      border: 2px solid var(--input-focus);
    }

    .button {
      --font-color: #323232;
      --bg-color: rgba(50, 50, 50, .1);
      --main-color: #323232;
      width: 120px;
      height: 40px;
      border-radius: 5px;
      border: 2px solid var(--main-color);
      background-color: var(--bg-color);
      box-shadow: 4px 4px var(--main-color);
      font-size: 17px;
      font-weight: 600;
      color: var(--font-color);
      cursor: pointer;
    }

    .button:active {
      box-shadow: 0px 0px var(--main-color);
      transform: translate(3px, 3px);
    }

    h2 {
      text-align: center;
      text-shadow: 1px 1px rgba(100, 100, 100, .3);
      margin-bottom: 20px;
      font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;
    }

    @keyframes rotate {
      120% {
        transform: rotate(360deg);
      }
    }

    #wrapper {
      display: none;
      width: 200px;
      height: 60px;
      position: relative;
      z-index: 1;
    }

    .circle {
      width: 20px;
      height: 20px;
      position: absolute;
      border-radius: 50%;
      background-color: #fff;
      left: 15%;
      transform-origin: 50%;
      animation: circle7124 .5s alternate infinite ease;
    }

    @keyframes circle7124 {
      0% {
        top: 60px;
        height: 5px;
        border-radius: 50px 50px 25px 25px;
        transform: scaleX(1.7);
      }

      40% {
        height: 20px;
        border-radius: 50%;
        transform: scaleX(1);
      }

      100% {
        top: 0%;
      }
    }

    .circle:nth-child(2) {
      left: 45%;
      animation-delay: .2s;
    }

    .circle:nth-child(3) {
      left: auto;
      right: 15%;
      animation-delay: .3s;
    }

    .shadow {
      width: 20px;
      height: 4px;
      border-radius: 50%;
      background-color: rgba(0, 0, 0, 0.9);
      position: absolute;
      top: 62px;
      transform-origin: 50%;
      z-index: -1;
      left: 15%;
      filter: blur(1px);
      animation: shadow046 .5s alternate infinite ease;
    }

    @keyframes shadow046 {
      0% {
        transform: scaleX(1.5);
      }

      40% {
        transform: scaleX(1);
        opacity: .7;
      }

      100% {
        transform: scaleX(.2);
        opacity: .4;
      }
    }

    .shadow:nth-child(4) {
      left: 45%;
      animation-delay: .2s
    }

    .shadow:nth-child(5) {
      left: auto;
      right: 15%;
      animation-delay: .3s;
    }

    .check {
      --borderWidth: 7px;
      --borderColor: black;
      display: none;
      transform: rotate(45deg);
      height: 36px;
      width: 24px;
      border-bottom: var(--borderWidth) solid var(--borderColor);
      border-right: var(--borderWidth) solid var(--borderColor);
    }
  </style>
</head>

<body>

  <div id="container">
    <div class="wave-01"></div>
    <div class="wave-02"></div>
    <div class="wave-03"></div>
    <div class="sun">
    </div>
    <div class="form-container">
      <div id="form">
        <h2>Aquascape</h2>
        <form id="myForm">
          <div class="input">
            <input type="text" placeholder="Token" name="token" class="input1" autocomplete="off" id="token" required>
          </div>
          <div class="input">
            <input type="text" name="chatid" placeholder="Chat ID" class="input1" autocomplete="off" id="chatid" required>
          </div>
          <div style="text-align: center;">
            <button class="button" type="submit" id="submitButton">Submit</button>
          </div>
        </form>
      </div>
      <div class="wrapper" id="wrapper">
        <div class="circle"></div>
        <div class="circle"></div>
        <div class="circle"></div>
        <div class="shadow"></div>
        <div class="shadow"></div>
        <div class="shadow"></div>
      </div>
      <div class="check"></div>
    </div>
  </div>

</body>

<script>
  document.getElementById("myForm").addEventListener("submit", async function (event) {
    event.preventDefault();

    let connect = "";
    document.getElementById("form").style.display = "none";
    document.getElementById("wrapper").style.display = "block";

    try {
      const tokenValue = document.getElementById("token").value;
      const chatidValue = document.getElementById("chatid").value;
      const response = await fetch(`http://${window.location.hostname}:90/token`,{
        method : 'POST',
        headers: {
            'Content-Type': 'application/x-www-form-urlencoded',
          },
          body: `token=${encodeURIComponent(tokenValue)}&chatid=${encodeURIComponent(chatidValue)}`,
      });
      const data = await response.json();
      connect = data.status;

      setTimeout(function () {
        document.getElementById("wrapper").style.display = "none";
        if (connect == "success") {
          document.querySelector(".check").style.display = "block";
        } else {
          document.getElementById("form").style.display = "block";
        }
      }, 3000);
    } catch (error) {
      console.error("Error:", error);
      document.getElementById("wrapper").style.display = "none";
      document.getElementById("form").style.display = "block";
    }
  });
</script>

</html>
)rawliteral";

ESP8266WebServer server(90);

void handleRoot()
{
  server.send(200, "text/html", index_html);
}

void handleTokenSubmit()
{

  String tokenValue, chatid;

  // Cek apakah request memiliki parameter "token" dan "chatid"
  if (server.hasArg("token") && server.hasArg("chatid"))
  {
    tokenValue = server.arg("token");
    chatid = server.arg("chatid");

    // Lakukan sesuatu dengan nilai token, misalnya menyimpannya atau mengirimkannya ke BotFather
    bot.updateToken(tokenValue);

    if (!bot.getMe())
    {
      // Kirim respons JSON jika token tidak valid
      const char *json = "{\"status\":\"failed\"}";
      server.send(400, "application/json", json);
    }

    // Kirim respons JSON berhasil
    const char *json = "{\"status\":\"success\"}";
    server.send(200, "application/json", json);

    // Kirim chat ke telegram
    chatID = chatid;
    // Menghentikan server
    botCondition = true;

    String welcome = "Selamat datang.\n";
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

    bot.sendMessage(chatID, welcome, "");
  }
  else
  {
    // Kirim respons JSON jika token tidak valid
    const char *json = "{\"status\":\"failed\"}";
    server.send(400, "application/json", json);
  }
}

void setupWebsite()
{
  server.on("/", HTTP_GET, handleRoot);
  server.on("/token", HTTP_POST, handleTokenSubmit);
  server.begin();
}

void handleClient()
{
  server.handleClient();
}