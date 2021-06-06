// FUNCIONA D1 240X240


#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <Fonts/FreeSerifBold12pt7b.h>
 
// ST7789 TFT module connections
#define TFT_DC    D1     // TFT DC  pin is connected to NodeMCU pin D1 (GPIO5)
#define TFT_RST   D2     // TFT RST pin is connected to NodeMCU pin D2 (GPIO4)
#define TFT_CS    D8     // TFT CS  pin is connected to NodeMCU pin D8 (GPIO15)
// initialize ST7789 TFT library with hardware SPI module
// SCK (CLK) ---> NodeMCU pin D5 (GPIO14)
// MOSI(DIN) ---> NodeMCU pin D7 (GPIO13)
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_RST);


#define ARDUINOJSON_ENABLE_STD_STRING 0
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
  

Serial.begin(115200);
  Serial.print(F("Hello! ST77xx TFT Test"));
 
  // if the display has CS pin try with SPI_MODE0
  tft.init(240, 240, SPI_MODE2);    // Init ST7789 display 240x240 pixel
 
  // if the screen is flipped, remove this command
  tft.setRotation(1);
 
  Serial.println(F("Initialized"));
 

 
  //tft.initR(INITR_GREENTAB);

  WiFi.begin(ssid, password);//iniciando wifi com seus dados ja setados 

  //tft.fillScreen(ST77XX_BLACK);
  Serial.print("Connecting...");
  tft.setCursor(30, 80);
tft.setFont(&FreeSerifBold12pt7b);
  tft.setTextColor(LTGREEN);
  tft.setTextSize(1);
  tft.print("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {
  delay(800);
  tft.fillScreen(BLACK);

delay(200);
tft.drawFastVLine(0, 0, 240, DKGREEN);
tft.drawFastHLine(0, 0, 240, DKGREEN);
tft.drawFastHLine(0, 23, 240, DKGREEN);
tft.drawFastHLine(0, 46, 240, DKGREEN);
tft.drawFastHLine(0, 69, 240, DKGREEN);
tft.drawFastHLine(0, 92, 240, DKGREEN);
tft.drawFastHLine(0,115, 240, DKGREEN);
tft.drawFastHLine(0, 138, 240, DKGREEN); 
tft.drawFastHLine(0, 161, 240, DKGREEN); 
tft.drawFastHLine(0, 184, 240, DKGREEN); 
tft.drawFastHLine(0, 207, 240, DKGREEN); 
tft.drawFastHLine(0, 230, 240, DKGREEN);
tft.drawFastHLine(0, 239, 240, DKGREEN);
tft.drawFastVLine(239, 0, 240, DKGREEN);

  tft.setCursor(10, 19);
  tft.setTextColor(YELLOW);
  tft.setTextSize(1);
  tft.print("B");


  tft.setCursor(10, 42);
  tft.setTextColor(LTGREY);
  tft.print("L");



  tft.setCursor(10, 65);
  tft.setTextColor(GREEN);
  tft.print("B");


  tft.setCursor(10, 88);
  tft.setTextColor(LTRED);
  tft.print("E");

  tft.setCursor(10, 111);
  tft.setTextColor(BLUE);
  tft.print("X");

  tft.setCursor(10, 134);
  tft.setTextColor(RED);
  tft.print("Y");

  tft.setCursor(10, 157);
  tft.setTextColor(ORANGE);
  tft.print("D");

  tft.setCursor(10, 180);
  tft.setTextColor(WHITE);
  tft.print("G");


  tft.setCursor(10, 203);
  tft.setTextColor(LTPURPLE);
  tft.print("W");

  tft.setCursor(10, 226);
  tft.setTextColor(BLUE);
  tft.print("M");
 
    }
}

void loop() {
 HTTPClient http;

    Serial.print("[HTTP] begin...BTC\n"); 
     
    delay(200);
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

 tft.drawRect(30, 2, 200, 20, BLACK);
 tft.fillRect(30, 2, 200, 20, BLACK);

delay(100);
  tft.setCursor(50,19);
  tft.setTextColor(YELLOW);
  tft.setTextSize(1);
  tft.print(ticker_last);

       }
 http.end();
 delay(800);
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
  
 tft.drawRect(30, 24, 200, 20, BLACK);
 tft.fillRect(30, 24, 200, 20, BLACK);        

delay(100);
  tft.setCursor(50, 42);
  tft.setTextColor(LTGREY);
  tft.setTextSize(1);
  tft.print(ticker_last);

  
      }
 http.end();
 delay(800);
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

 tft.drawRect(30, 47, 200, 20, BLACK);
 tft.fillRect(30, 47, 200, 20, BLACK);        

delay(100);
  tft.setCursor(50, 65);
  tft.setTextColor(GREEN);
  tft.setTextSize(1);
  tft.print(ticker_last);


      }
 http.end();
 delay(800);
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

 tft.drawRect(30, 70, 200, 20, BLACK);
 tft.fillRect(30, 70, 200, 20, BLACK);        

delay(100);
  tft.setCursor(50, 88);
  tft.setTextColor(LTRED);
  tft.setTextSize(1);
  tft.print(ticker_last);


      }
    http.end();
    delay(800);
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

 tft.drawRect(30, 93, 200, 20, BLACK);
 tft.fillRect(30, 93, 200, 20, BLACK);        

delay(100);
  tft.setCursor(50, 111);
  tft.setTextColor(LTBLUE);
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

 tft.drawRect(30, 116, 200, 20, BLACK);
 tft.fillRect(30, 116, 200, 20, BLACK);        

delay(100);
  tft.setCursor(50, 134);
  tft.setTextColor(RED);
  tft.setTextSize(1);
  tft.print(ticker_last);


 http.end();
delay(800);

  // iniciando leitura da api do mercado bitcoin
    Serial.print("[HTTP] begin...LINK\n");  
http.begin("https://www.mercadobitcoin.net/api/DAI/ticker/", "32 59 93 CE 8E 10 B9 BF 34 1D 19 4F 71 1C 0A 53 60 7E 17 7D");
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

 tft.drawRect(30, 139, 200, 20, BLACK);
 tft.fillRect(30, 139, 200, 20, BLACK);        

delay(100);
  tft.setCursor(50, 157);
  tft.setTextColor(ORANGE);
  tft.setTextSize(1);
  tft.print(ticker_last);

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

 tft.drawRect(30, 162, 200, 20, BLACK);
 tft.fillRect(30, 162, 200, 20, BLACK);        

delay(100);
  tft.setCursor(50, 180);
  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.print(ticker_last);
 
 http.end();

delay(800);


  // iniciando leitura da api do mercado bitcoin
    Serial.print("[HTTP] begin...WBX\n");  
http.begin("https://www.mercadobitcoin.net/api/WBX/ticker/", "32 59 93 CE 8E 10 B9 BF 34 1D 19 4F 71 1C 0A 53 60 7E 17 7D");
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

 tft.drawRect(35, 185, 200, 20, BLACK);
 tft.fillRect(35, 185, 200, 20, BLACK);        

delay(100);
 tft.setCursor(50, 203);
 tft.setTextColor(LTPURPLE);
 tft.setTextSize(1);
 tft.print(ticker_last);
 
 http.end();

delay(800);


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

 tft.drawRect(35, 208, 200, 20, BLACK);
 tft.fillRect(35, 208 , 200, 20, BLACK);        

delay(100);
  tft.setCursor(50, 226);
  tft.setTextColor(BLUE);
  tft.setTextSize(1);
  tft.print(ticker_last);
 
 http.end();

delay(500);
tft.drawFastHLine(2, 233, 25, RED);
tft.drawFastHLine(2, 234, 25, RED);
tft.drawFastHLine(2, 235, 25, RED); 
tft.drawFastHLine(2, 236, 25, RED);  

delay(500);
tft.drawFastHLine(2, 233, 50, RED);
tft.drawFastHLine(2, 234, 50, RED);
tft.drawFastHLine(2, 235, 50, RED); 
tft.drawFastHLine(2, 236, 50, RED); 

delay(500);
tft.drawFastHLine(2, 233, 75, RED);
tft.drawFastHLine(2, 234, 75, RED);
tft.drawFastHLine(2, 235, 75, RED); 
tft.drawFastHLine(2, 236, 75, RED); 

delay(500);
tft.drawFastHLine(2, 233, 100, RED);
tft.drawFastHLine(2, 234, 100, RED);
tft.drawFastHLine(2, 235, 100, RED);
tft.drawFastHLine(2, 236, 100, RED);
delay(500);
tft.drawFastHLine(2, 233, 125, RED);
tft.drawFastHLine(2, 234, 125, RED);
tft.drawFastHLine(2, 235, 125, RED);
tft.drawFastHLine(2, 236, 125, RED);

delay(500);
tft.drawFastHLine(2, 233, 150, RED);
tft.drawFastHLine(2, 234, 150, RED);
tft.drawFastHLine(2, 235, 150, RED);
tft.drawFastHLine(2, 236, 150, RED);

delay(500);
tft.drawFastHLine(2, 233, 175, RED);
tft.drawFastHLine(2, 234, 175, RED);
tft.drawFastHLine(2, 235, 175, RED);
tft.drawFastHLine(2, 236, 175, RED);

delay(500);
tft.drawFastHLine(2, 233, 200, RED);
tft.drawFastHLine(2, 234, 200, RED);
tft.drawFastHLine(2, 235, 200, RED);
tft.drawFastHLine(2, 236, 200, RED);

delay(500);
tft.drawFastHLine(2, 233, 225, RED);
tft.drawFastHLine(2, 234, 225, RED);
tft.drawFastHLine(2, 235, 225, RED);
tft.drawFastHLine(2, 236, 225, RED);

delay(500);
tft.drawFastHLine(2, 233, 236, RED);
tft.drawFastHLine(2, 234, 236, RED);
tft.drawFastHLine(2, 235, 236, RED);
tft.drawFastHLine(2, 236, 236, RED);

delay(500);
tft.drawRect(2, 233, 236, 4, BLACK);
tft.fillRect(2, 233, 236, 4, BLACK);
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
   }
   }
   }
}
   }
}


   
