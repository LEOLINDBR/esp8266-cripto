
/*
 *  ForbiddenBit.com
 *  
 *  NodeMCU and Display ST7735
 *
NodeMCU to Display

D8  -> CS
D7  -> SDA
D5   -> CSK
D4.  -> A0
D3   -> RESET
Vcc  -> 3.3V
Led  -> 3.3V
GND -> GND
funciona

*/


//  --------  Libraries required to use the Display  ---------------
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Fonts/FreeSerif9pt7b.h>

  #define TFT_CS         15      
  #define TFT_RST        0
  #define TFT_DC         2

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
// WiFi Parameters
const char* ssid = "Chupandinho"; //nome da sua rede entre as aspas
const char* password = "66266626"; // senha do wifi entre as aspas

#define LTBLUE    0xB6DF
#define LTTEAL    0xBF5F
#define LTGREEN   0xBFF7
#define LTCYAN    0xC7FF
#define LTRED     0xFD34
#define LTMAGENTA 0xFD5F
#define LTYELLOW  0xFFF8
#define LTORANGE  0xFE73
#define LTPINK    0xFDDF
#define LTPURPLE  0xCCFF
#define LTGREY    0xE71C

#define BLUE      0x001F
#define TEAL      0x0438
#define GREEN     0x07E0
#define CYAN      0x07FF
#define RED       0xF800
#define MAGENTA   0xF81F
#define YELLOW    0xFFE0
#define ORANGE    0xFC00
#define PINK      0xF81F
#define PURPLE    0x8010
#define GREY      0xC618
#define WHITE     0xFFFF
#define BLACK     0x0000

#define DKBLUE    0x000D
#define DKTEAL    0x020C
#define DKGREEN   0x03E0
#define DKCYAN    0x03EF
#define DKRED     0x6000
#define DKMAGENTA 0x8008
#define DKYELLOW  0x8400
#define DKORANGE  0x8200
#define DKPINK    0x9009
#define DKPURPLE  0x4010
#define DKGREY    0x4A49




#define CLGRAY    0xC618
#define CGREEN    0x07E0
#define CLIME     0x87E0
#define CAQUA     0x5D1C
#define CORANGE   0xFCA0
#define CBROWN    0x8200
#define CSILVER   0xA510
#define CGOLD     0xA508
#define CNAVY     0x000F
#define CMAROON   0x7800
#define CPURPLE   0x780F
#define COLIVE    0x7BE0


void setup() {
  
 
  tft.initR(INITR_BLACKTAB);
Serial.begin(115200);
  WiFi.begin(ssid, password);//iniciando wifi com seus dados ja setados 

  tft.fillScreen(ST77XX_BLACK);
  
  Serial.print("Connecting...");
  
  tft.setRotation(3);
  tft.setCursor(30, 80);
 tft.setFont(&FreeSerif9pt7b);
  tft.setTextColor(GREEN);
  tft.setTextSize(1);
  tft.print("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {
  delay(1000);
  tft.fillScreen(BLACK);
  }
}
 
void loop() {
 HTTPClient http;

    Serial.print("[HTTP] begin...BTC\n");  
    
http.begin("https://www.mercadobitcoin.net/api/BTC/ticker/", "32 59 93 CE 8E 10 B9 BF 34 1D 19 4F 71 1C 0A 53 60 7E 17 7D");
   int httpCode = http.GET();
   delay(800);
   if(httpCode > 0) {  
      if(httpCode == HTTP_CODE_OK) {
      const size_t bufferSize = JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(7) + 281;
      DynamicJsonBuffer jsonBuffer(bufferSize);
      JsonObject& root = jsonBuffer.parseObject(http.getString());
      JsonObject& ticker = root["ticker"];

const char* ticker_buy = ticker["buy"]; // "34820.08014000"
const char* ticker_sell = ticker["sell"]; // "35177.91968000"
const char* ticker_high = ticker["high"]; // "35800.00000000"
const char* ticker_low = ticker["low"]; // "34330.00000000"
const char* ticker_vol = ticker["vol"]; // "509.79745863"
const char* ticker_last = ticker["last"]; // "35177.91968000"
long ticker_date = ticker["date"]; // 1559245158
      Serial.print("low:");
      Serial.println(ticker_low);
      Serial.print("high:");
      Serial.println(ticker_high);
      Serial.print("last:"); 
      Serial.println(ticker_last);
      Serial.print("sell:"); 
      Serial.println(ticker_sell);
      Serial.print("vol:"); 
      Serial.println(ticker_buy);
      Serial.print("date:"); 
      Serial.println(ticker_date);


// tft.drawFastVLine(0, 0, 160, GREEN);
// tft.drawFastVLine(127, 0, 160, GREEN);

//tft.drawFastHLine(0, 0, 128, GREEN);
//tft.drawFastHLine(0, 22, 128, GREEN);
//tft.drawFastHLine(0, 36, 128, GREEN);
//tft.drawFastHLine(0, 50, 128, GREEN);
//tft.drawFastHLine(0, 159, 128, GREEN);
//tft.drawFastHLine(0, 158, 128, GREEN);


tft.setCursor(2,15);
 tft.setTextColor(YELLOW);
  tft.setTextSize(1);
  tft.print("B");
   tft.setCursor(18,15);
 tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.print(ticker_last);
        
       }
 http.end();
 delay(500);
  // iniciando leitura da api do mercado bitcoin
     Serial.print("[HTTP] begin...LTC\n");  
     
    
http.begin("https://www.mercadobitcoin.net/api/LTC/ticker/", "32 59 93 CE 8E 10 B9 BF 34 1D 19 4F 71 1C 0A 53 60 7E 17 7D");
   int httpCode = http.GET();
   delay(800);
   if(httpCode > 0) {  
      if(httpCode == HTTP_CODE_OK) {
          const size_t bufferSize = JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(7) + 281;
      DynamicJsonBuffer jsonBuffer(bufferSize);
      JsonObject& root = jsonBuffer.parseObject(http.getString());
      JsonObject& ticker = root["ticker"];

const char* ticker_buy = ticker["buy"]; // "34820.08014000"
const char* ticker_sell = ticker["sell"]; // "35177.91968000"
const char* ticker_high = ticker["high"]; // "35800.00000000"
const char* ticker_low = ticker["low"]; // "34330.00000000"
const char* ticker_vol = ticker["vol"]; // "509.79745863"
const char* ticker_last = ticker["last"]; // "35177.91968000"
long ticker_date = ticker["date"]; // 1559245158

      Serial.print("low:");
      Serial.println(ticker_low);
      Serial.print("high:");
      Serial.println(ticker_high);
      Serial.print("last:"); 
      Serial.println(ticker_last);
      Serial.print("sell:"); 
      Serial.println(ticker_sell);
      Serial.print("vol:"); 
      Serial.println(ticker_buy);
      Serial.print("date:"); 
      Serial.println(ticker_date);
           

  tft.setCursor(2, 30);
  tft.setTextColor(LTGREY);
  tft.setTextSize(1);
  tft.print("L");

  tft.setCursor(18, 30);
  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.print(ticker_last);

  
      }
 http.end();
 delay(500);
  // iniciando leitura da api do mercado bitcoin
       Serial.print("[HTTP] begin...BCH\n");  

http.begin("https://www.mercadobitcoin.net/api/BCH/ticker/", "32 59 93 CE 8E 10 B9 BF 34 1D 19 4F 71 1C 0A 53 60 7E 17 7D");
   int httpCode = http.GET();
   delay(800);
   if(httpCode > 0) {  
      if(httpCode == HTTP_CODE_OK) {
         const size_t bufferSize = JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(7) + 281;
      DynamicJsonBuffer jsonBuffer(bufferSize);
      JsonObject& root = jsonBuffer.parseObject(http.getString());
      JsonObject& ticker = root["ticker"];

const char* ticker_buy = ticker["buy"]; // "34820.08014000"
const char* ticker_sell = ticker["sell"]; // "35177.91968000"
const char* ticker_high = ticker["high"]; // "35800.00000000"
const char* ticker_low = ticker["low"]; // "34330.00000000"
const char* ticker_vol = ticker["vol"]; // "509.79745863"
const char* ticker_last = ticker["last"]; // "35177.91968000"
long ticker_date = ticker["date"]; // 1559245158

      Serial.print("low:");
      Serial.println(ticker_low);
      Serial.print("high:");
      Serial.println(ticker_high);
      Serial.print("last:"); 
      Serial.println(ticker_last);
      Serial.print("sell:"); 
      Serial.println(ticker_sell);
      Serial.print("vol:"); 
      Serial.println(ticker_buy);
      Serial.print("date:"); 
      Serial.println(ticker_date);

  tft.setCursor(2, 45);
  tft.setTextColor(GREEN);
  tft.setTextSize(1);
  tft.print("B");

  tft.setCursor(18, 45);
  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.print(ticker_last);


      }
 http.end();
 delay(500);
  // iniciando leitura da api do mercado bitcoin
      Serial.print("[HTTP] begin...ETH\n");  
    
http.begin("https://www.mercadobitcoin.net/api/ETH/ticker/", "32 59 93 CE 8E 10 B9 BF 34 1D 19 4F 71 1C 0A 53 60 7E 17 7D");
   int httpCode = http.GET();
   delay(800);
   if(httpCode > 0) {  
      if(httpCode == HTTP_CODE_OK) {
        const size_t bufferSize = JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(7) + 281;
      DynamicJsonBuffer jsonBuffer(bufferSize);
      JsonObject& root = jsonBuffer.parseObject(http.getString());
      JsonObject& ticker = root["ticker"];

const char* ticker_buy = ticker["buy"]; // "34820.08014000"
const char* ticker_sell = ticker["sell"]; // "35177.91968000"
const char* ticker_high = ticker["high"]; // "35800.00000000"
const char* ticker_low = ticker["low"]; // "34330.00000000"
const char* ticker_vol = ticker["vol"]; // "509.79745863"
const char* ticker_last = ticker["last"]; // "35177.91968000"
long ticker_date = ticker["date"]; // 1559245158

     Serial.print("low:");
      Serial.println(ticker_low);
      Serial.print("high:");
      Serial.println(ticker_high);
      Serial.print("last:"); 
      Serial.println(ticker_last);
      Serial.print("sell:"); 
      Serial.println(ticker_sell);
      Serial.print("vol:"); 
      Serial.println(ticker_buy);
      Serial.print("date:"); 
      Serial.println(ticker_date);

  tft.setCursor(2, 60);
  tft.setTextColor(LTRED);
  tft.setTextSize(1);
  tft.print("E");

  tft.setCursor(18, 60);
  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.print(ticker_last);

      }
    http.end();
    delay(500);
  // iniciando leitura da api do mercado bitcoin
    Serial.print("[HTTP] begin...XRP\n");  

 http.begin("https://www.mercadobitcoin.net/api/XRP/ticker/", "32 59 93 CE 8E 10 B9 BF 34 1D 19 4F 71 1C 0A 53 60 7E 17 7D");
   int httpCode = http.GET();
   delay(800);
   if(httpCode > 0) {  
      if(httpCode == HTTP_CODE_OK) {
          const size_t bufferSize = JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(7) + 281;
      DynamicJsonBuffer jsonBuffer(bufferSize);
      JsonObject& root = jsonBuffer.parseObject(http.getString());
      JsonObject& ticker = root["ticker"];

const char* ticker_buy = ticker["buy"]; // "34820.08014000"
const char* ticker_sell = ticker["sell"]; // "35177.91968000"
const char* ticker_high = ticker["high"]; // "35800.00000000"
const char* ticker_low = ticker["low"]; // "34330.00000000"
const char* ticker_vol = ticker["vol"]; // "509.79745863"
const char* ticker_last = ticker["last"]; // "35177.91968000"
long ticker_date = ticker["date"]; // 1559245158

      Serial.print("low:");
      Serial.println(ticker_low);
      Serial.print("high:");
      Serial.println(ticker_high);
      Serial.print("last:"); 
      Serial.println(ticker_last);
      Serial.print("sell:"); 
      Serial.println(ticker_sell);
      Serial.print("vol:"); 
      Serial.println(ticker_buy);
      Serial.print("date:"); 
      Serial.println(ticker_date);

  tft.setCursor(2, 75);
  tft.setTextColor(BLUE);
  tft.setTextSize(1);
  tft.print("X");

  tft.setCursor(18, 75);
  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.print(ticker_last);

}
 http.end();

delay(800);

  // iniciando leitura da api do mercado bitcoin
    Serial.print("[HTTP] begin...OGFT\n");  
http.begin("https://www.mercadobitcoin.net/api/OGFT/ticker/", "32 59 93 CE 8E 10 B9 BF 34 1D 19 4F 71 1C 0A 53 60 7E 17 7D");
   int httpCode = http.GET();
   delay(800);
   if(httpCode > 0) {  
      if(httpCode == HTTP_CODE_OK) {
          const size_t bufferSize = JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(7) + 281;
      DynamicJsonBuffer jsonBuffer(bufferSize);
      JsonObject& root = jsonBuffer.parseObject(http.getString());
      JsonObject& ticker = root["ticker"];

const char* ticker_buy = ticker["buy"]; // "34820.08014000"
const char* ticker_sell = ticker["sell"]; // "35177.91968000"
const char* ticker_high = ticker["high"]; // "35800.00000000"
const char* ticker_low = ticker["low"]; // "34330.00000000"
const char* ticker_vol = ticker["vol"]; // "509.79745863"
const char* ticker_last = ticker["last"]; // "35177.91968000"
long ticker_date = ticker["date"]; // 1559245158

      Serial.print("low:");
      Serial.println(ticker_low);
      Serial.print("high:");
      Serial.println(ticker_high);
      Serial.print("last:"); 
      Serial.println(ticker_last);
      Serial.print("sell:"); 
      Serial.println(ticker_sell);
      Serial.print("vol:"); 
      Serial.println(ticker_buy);
      Serial.print("date:"); 
      Serial.println(ticker_date);

  tft.setCursor(2, 90);
  tft.setTextColor(ORANGE);
  tft.setTextSize(1);
  tft.print("G");

  tft.setCursor(18, 90);
  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.print(ticker_last);
      }

delay(800);
 http.end();

  // iniciando leitura da api do mercado bitcoin
    Serial.print("[HTTP] begin...CHZ\n");  

 http.begin("https://www.mercadobitcoin.net/api/CHZ/ticker/", "32 59 93 CE 8E 10 B9 BF 34 1D 19 4F 71 1C 0A 53 60 7E 17 7D");
   int httpCode = http.GET();
   delay(800);
   if(httpCode > 0) {  
      if(httpCode == HTTP_CODE_OK) {
          const size_t bufferSize = JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(7) + 281;
      DynamicJsonBuffer jsonBuffer(bufferSize);
      JsonObject& root = jsonBuffer.parseObject(http.getString());
      JsonObject& ticker = root["ticker"];

const char* ticker_buy = ticker["buy"]; // "34820.08014000"
const char* ticker_sell = ticker["sell"]; // "35177.91968000"
const char* ticker_high = ticker["high"]; // "35800.00000000"
const char* ticker_low = ticker["low"]; // "34330.00000000"
const char* ticker_vol = ticker["vol"]; // "509.79745863"
const char* ticker_last = ticker["last"]; // "35177.91968000"
long ticker_date = ticker["date"]; // 1559245158

      Serial.print("low:");
      Serial.println(ticker_low);
      Serial.print("high:");
      Serial.println(ticker_high);
      Serial.print("last:"); 
      Serial.println(ticker_last);
      Serial.print("sell:"); 
      Serial.println(ticker_sell);
      Serial.print("vol:"); 
      Serial.println(ticker_buy);
      Serial.print("date:"); 
      Serial.println(ticker_date);

  tft.setCursor(2, 105);
  tft.setTextColor(RED);
  tft.setTextSize(1);
  tft.print("Y");

  tft.setCursor(18, 105);
  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.print(ticker_last);

      }  
 delay(500);
 http.end();



  // iniciando leitura da api do mercado bitcoin
    Serial.print("[HTTP] begin...PSGFT\n");  
http.begin("https://www.mercadobitcoin.net/api/PSGFT/ticker/", "32 59 93 CE 8E 10 B9 BF 34 1D 19 4F 71 1C 0A 53 60 7E 17 7D");
   int httpCode = http.GET();
   delay(800);
   if(httpCode > 0) {  
      if(httpCode == HTTP_CODE_OK) {
          const size_t bufferSize = JSON_OBJECT_SIZE(1) + JSON_OBJECT_SIZE(7) + 281;
      DynamicJsonBuffer jsonBuffer(bufferSize);
      JsonObject& root = jsonBuffer.parseObject(http.getString());
      JsonObject& ticker = root["ticker"];

const char* ticker_buy = ticker["buy"]; // "34820.08014000"
const char* ticker_sell = ticker["sell"]; // "35177.91968000"
const char* ticker_high = ticker["high"]; // "35800.00000000"
const char* ticker_low = ticker["low"]; // "34330.00000000"
const char* ticker_vol = ticker["vol"]; // "509.79745863"
const char* ticker_last = ticker["last"]; // "35177.91968000"
long ticker_date = ticker["date"]; // 1559245158

      Serial.print("low:");
      Serial.println(ticker_low);
      Serial.print("high:");
      Serial.println(ticker_high);
      Serial.print("last:"); 
      Serial.println(ticker_last);
      Serial.print("sell:"); 
      Serial.println(ticker_sell);
      Serial.print("vol:"); 
      Serial.println(ticker_buy);
      Serial.print("date:"); 
      Serial.println(ticker_date);

  tft.setCursor(2, 120);
  tft.setTextColor(BLUE);
  tft.setTextSize(1);
  tft.print("P");

  tft.setCursor(18, 120);
  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.print(ticker_last);
 
 http.end();

 delay(5500);



 
tft.fillScreen(BLACK);
}
   }
   }
   }
   }
}
   }
}
}
}
