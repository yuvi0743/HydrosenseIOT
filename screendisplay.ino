#include "headers.h"
int drop=0;
int frameweather1 = 0;
int frameweather2 = 0;
int frameweather3 = 0;
int frameweather4 = 0;
int frameweather5 = 0;
int frameweather6=0;
int frametemp = 0;
int framewifi = 0;
int framecloud = 0;
int screen =0;
int _moisture,sensor_analog;
const int sensor_pin = A0;
const int wet=966;
const int dry =2845;
float tempreading;
int weatherchoose;
const char* weathertype;
const char* weatherConditions[] = {
    "clear sky", "few clouds", "scattered clouds", "broken clouds",
    "shower rain", "rain", "thunderstorm", "snow", "mist"
};
int getWeatherCode(const char* weather) {
    for (int i = 0; i < 9; i++) {
        if (strcmp(weather, weatherConditions[i]) == 0) {
            return i;
        }
    }
    return -1; // Return -1 if no match is found
}
WiFiClientSecure net = WiFiClientSecure();
PubSubClient client(net);
void connectAWS()
{
WiFi.mode(WIFI_STA);
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.println("Connecting to Wi-Fi");

while (WiFi.status() != WL_CONNECTED)
{
 wifianimation();
}
display.clearDisplay();
Serial.println(WiFi.localIP());
wifisymbol(1);
net.setCACert(AWS_CERT_CA);
net.setCertificate(AWS_CERT_CRT);
net.setPrivateKey(AWS_CERT_PRIVATE);

Serial.print("Certificates done");
digitalWrite(LED_BUILTIN, HIGH);
client.setServer(AWS_IOT_ENDPOINT, 8883);

client.setCallback(messageHandler);

Serial.println("Connecting to AWS IOT");

while(!client.connect(THINGNAME))//!client.connect(THINGNAME)
{
cloudanim();
}

if (!client.connected())
{
Serial.println("AWS IoT Timeout!");
return;
}
client.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);
client.subscribe(temp_topic);

Serial.println("AWS IoT Connected!");

}

void publishMessage(int per)
{
StaticJsonDocument<200> doc;
doc["Moisture"] = per;
char jsonBuffer[512];
serializeJson(doc, jsonBuffer);
client.publish(AWS_IOT_PUBLISH_TOPIC, jsonBuffer);
}

void messageHandler(char* topic, byte* payload, unsigned int length)
{
Serial.print("incoming: ");
Serial.println(topic);
String payloadStr;
    for (int i = 0; i < length; i++) {
        payloadStr += (char)payload[i];
    }

    // Check the topic and take appropriate actions
    if (strcmp(topic, "esp32/weathertemp") == 0) {
        StaticJsonDocument<200> doc;
        deserializeJson(doc, payloadStr);
        const char* temperature = doc["Temperature"];
        const char* weather = doc["Weather"];
        
        Serial.print("Temperature: ");
        Serial.println(temperature);
        tempreading=atof(temperature);
        Serial.print("Weather: ");
        Serial.println(weather);
        weathertype=weather;
        weatherchoose = getWeatherCode(weather);
        //tempreading=message;
        delay(2000);
    }
    else if (strcmp(topic, "your/second/topic") == 0) {
        // Handle messages for the second topic
        // Extract information from payloadStr as needed
        Serial.println("Received message on your/second/topic");
    }
    // Add more conditions for other topics as needed
    else {
        // Handle messages for unknown topics
        Serial.println("Received message on an unknown topic");
    }
}
void invertBitmap(unsigned char* bitmap, int size) {
    for (int i = 0; i < size; ++i) {
        bitmap[i] = ~bitmap[i];
    }
}

void setup() {
  Serial1.begin(9600, SERIAL_8N1, RXp2, TXp2);
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  int bitmapSize = sizeof(dropsign) / sizeof(dropsign[0]);
  invertBitmap(dropsign, bitmapSize);
  int bitmapSize1 = sizeof(tap) / sizeof(tap[0]);
  invertBitmap(tap,bitmapSize1);
  splashscreen();
  connectAWS();
}

void loop() {
  if(screen<14)
  { 
    displaymoisture();
    client.loop();
    delay(100);
    screen=screen+1;
  }
  else if (screen==14)
  { 
    display.fillRect(0, 16, 128, 48, SSD1306_BLACK);
    screen=screen+1;
    client.loop();
  }
  else if(screen>14 && screen< 60)
  {
    
  displaytemp();
  displaytemperature();
  delay(100);
  screen=screen+1;
  client.loop();
  }
  else if(screen>=60&&screen<95)
  { 
    display.fillRect(0, 16, 128, 48, SSD1306_BLACK);
    screen=screen+1;
    weatheranimation(weatherchoose);
    delay(100);
  }
  else if(screen==95)
  { 
    display.fillRect(0, 16, 128, 48, SSD1306_BLACK);
    screen=0;
    client.loop();
  }
}

void splashscreen(void) 
{
  display.clearDisplay();
  int bitmapSize2 = sizeof(splashlogo) / sizeof(splashlogo[0]);
  int bitmapSize3 = sizeof(splashlogo2) / sizeof(splashlogo2[0]);
  invertBitmap(splashlogo, bitmapSize2);
  invertBitmap(splashlogo2, bitmapSize3);
  display.clearDisplay();
  display.drawBitmap(0,0,splashlogo,64,48,1);
  display.drawBitmap(65,0,splashlogo2,64,48,1);
  display.display();
  delay(4000);
  display.clearDisplay();
}

void dropblink(int val)
{ if(val==0)
{ 
  display.drawBitmap(0,(display.height() - LOGO_HEIGHT1)/2+15,dropsign,LOGO_WIDTH1, LOGO_HEIGHT1,1);
  display.display();
  drop=1;
}
else{
  if(drop==0)
  {
   display.drawBitmap(0,(display.height() - LOGO_HEIGHT1)/2+15,dropsign,LOGO_WIDTH1, LOGO_HEIGHT1,drop);
   display.display();
   drop=1;
  }
  else
  {
   display.drawBitmap(0,(display.height() - LOGO_HEIGHT1)/2+15,dropsign,LOGO_WIDTH1, LOGO_HEIGHT1,drop);
   display.display();
   drop=0;  
  }
  }
}

void weatheranimation(int val)
{ if(val==0)
{ display.setCursor(50, 18);
  display.setTextSize(2);
  display.println(weathertype);
  display.fillRect(0, 16, FRAME_WIDTHweather1, FRAME_HEIGHTweather1, SSD1306_BLACK);
  display.drawBitmap(0, 16, framesweather1[frameweather1], FRAME_WIDTHweather1, FRAME_HEIGHTweather1, 1);
  display.display();
  frameweather1 = (frameweather1 + 1) % FRAME_COUNTweather1;
  delay(FRAME_DELAYweather1);
}
else if(val==1)
{ display.setCursor(50, 18);
  display.setTextSize(2);
  display.print(weathertype);
  display.fillRect(0, 16, FRAME_WIDTHweather3, FRAME_HEIGHTweather3, SSD1306_BLACK);
  display.drawBitmap(0, 16, framesweather3[frameweather3], FRAME_WIDTHweather3, FRAME_HEIGHTweather3, 1);
  display.display();
  frameweather3 = (frameweather3 + 1) % FRAME_COUNTweather3;
  delay(FRAME_DELAYweather3);
}
else if(val==2||val==3)
{ display.setCursor(50, 18);
  display.setTextSize(2);
  display.print(weathertype);
  display.fillRect(0, 16, FRAME_WIDTHweather5, FRAME_HEIGHTweather5, SSD1306_BLACK);
  display.drawBitmap(0, 16, framesweather5[frameweather5], FRAME_WIDTHweather5, FRAME_HEIGHTweather5, 1);
  display.display();
  frameweather5 = (frameweather5 + 1) % FRAME_COUNTweather5;
  delay(FRAME_DELAYweather5);
}
else if(val==4||val==5)
{ display.setCursor(50, 18);
  display.setTextSize(2);
  display.print(weathertype);
  display.fillRect(0, 16, FRAME_WIDTHweather2, FRAME_HEIGHTweather2, SSD1306_BLACK);
  display.drawBitmap(0, 16, framesweather2[frameweather2], FRAME_WIDTHweather2, FRAME_HEIGHTweather2, 1);
  display.display();
  frameweather2 = (frameweather2 + 1) % FRAME_COUNTweather2;
  delay(FRAME_DELAYweather2);
}
else if(val==6)
{ display.setCursor(50, 18);
  display.setTextSize(2);
  display.print(weathertype);
  display.fillRect(0, 16, FRAME_WIDTHweather4, FRAME_HEIGHTweather4, SSD1306_BLACK);
  display.drawBitmap(0, 16, framesweather4[frameweather4], FRAME_WIDTHweather4, FRAME_HEIGHTweather4, 1);
  display.display();
  frameweather4 = (frameweather4 + 1) % FRAME_COUNTweather4;
  delay(FRAME_DELAYweather4);
}
else if(val==7)
{ display.setCursor(50, 18);
  display.setTextSize(2);
  display.print(weathertype);
  display.fillRect(0, 16, FRAME_WIDTHweather6, FRAME_HEIGHTweather6, SSD1306_BLACK);
  display.drawBitmap(0, 16, framesweather6[frameweather6], FRAME_WIDTHweather6, FRAME_HEIGHTweather6, 1);
  display.display();
  frameweather6 = (frameweather6 + 1) % FRAME_COUNTweather6;
  delay(FRAME_DELAYweather6);
}
}

void wifisymbol(int val)
{ if(val==1)
  {
  display.drawBitmap(
    (display.width()  - LOGO_WIDTH )  ,
    0,
    logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
    display.display();
  }
  else
  {
  display.fillRect((display.width()  - LOGO_WIDTH), 0, LOGO_WIDTH, LOGO_HEIGHT, SSD1306_BLACK);
  }
}

void tapsign(bool val)
{
  if (val==true)
  {
    display.drawBitmap(0,0,tap,16, 14,1);
  }
  else
  {
    display.fillRect(0,0, 16, 14, SSD1306_BLACK);
  }
}

void displaymoisture()
{
   if (Serial1.available()) {
    int receivedValue = Serial1.parseInt(); // Read the incoming value as an integer
    Serial.println(Serial1.parseInt());
    _moisture = receivedValue;
  }
  //sensor_analog = analogRead(sensor_pin);
 //_moisture=map(sensor_analog,wet,dry,100,0);
  /*display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(50,display.height()/2+10);
  display.fillRect(50,display.height()/2+10,78,22,SSD1306_BLACK);
  display.print(_moisture);
  display.println("%");
  display.display();*/
  publishMessage(_moisture);
  //delay(400);
   display.fillRect(0, 16, 128, 48, SSD1306_BLACK);
   int value=_moisture;
  // Draw gauge background
  display.drawCircle(GAUGE_CENTER_X, GAUGE_CENTER_Y, GAUGE_RADIUS, WHITE);
  display.drawCircle(GAUGE_CENTER_X, GAUGE_CENTER_Y, GAUGE_RADIUS + 1, WHITE);
  display.drawCircle(GAUGE_CENTER_X, GAUGE_CENTER_Y, 5, WHITE);
  display.fillRect(0 , 42, 128 , 64 , SSD1306_BLACK);
  // Draw the needle
  float angleRad = (value - 50.0) * PI / 100.0;
  int x2 = GAUGE_CENTER_X + sin(angleRad) * NEEDLE_LENGTH;
  int y2 = GAUGE_CENTER_Y - cos(angleRad) * NEEDLE_LENGTH;
  display.drawLine(GAUGE_CENTER_X, GAUGE_CENTER_Y, x2, y2, WHITE);
  
  // Add arrowhead at the end of the needle
  float arrowAngle1 = angleRad + PI / 8;
  float arrowAngle2 = angleRad - PI / 8;
  int arrowX1 = x2 - sin(arrowAngle1) * 5;
  int arrowY1 = y2 + cos(arrowAngle1) * 5;
  int arrowX2 = x2 - sin(arrowAngle2) * 5;
  int arrowY2 = y2 + cos(arrowAngle2) * 5;
  display.drawLine(x2, y2, arrowX1, arrowY1, WHITE);
  display.drawLine(x2, y2, arrowX2, arrowY2, WHITE);
  display.setTextSize(0.6);
  display.setTextColor(WHITE);
  display.setCursor(26,48);
  display.print("Moisture: ");
  display.print(value);
  display.display();
}

void displaytemp()
{
  display.fillRect(0, 0, 112 , 16 , SSD1306_BLACK);
  display.fillRect(0, 16, FRAME_WIDTHtemp, FRAME_HEIGHTtemp, SSD1306_BLACK);
  display.drawBitmap(0, 16, framestemp[frametemp], FRAME_WIDTHtemp, FRAME_HEIGHTtemp, 1);
  display.display();
  frametemp = (frametemp + 1) % FRAME_COUNTtemp;
  delay(FRAME_DELAYtemp);
}

void displaytemperature()
{
   display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(50,display.height()/2-10);
  if(tempreading!=NULL){
  display.print(tempreading);
   display.setCursor(50,display.height()/2+10);
  display.setTextSize(2);
    display.println("deg C");
  }
  else{
    display.setCursor(50,display.height()/2-10);
    display.println("--");
    display.setCursor(50,display.height()/2+10);
    display.setTextSize(2);
    display.println("deg C");
  }
  display.display();
}


void wifianimation()
{
  display.clearDisplay();
  display.drawBitmap(32, 0, frameswifi[framewifi], FRAME_WIDTHwifi, FRAME_HEIGHTwifi, 1);
  display.display();
  framewifi = (framewifi + 1) % FRAME_COUNTwifi;
  delay(FRAME_DELAYwifi);
}
void cloudanim()
{
  display.clearDisplay();
  display.drawBitmap(32, 0, framescloud[framecloud], FRAME_WIDTHcloud, FRAME_HEIGHTcloud, 1);
  display.display();
  framecloud = (framecloud + 1) % FRAME_COUNTcloud;
  delay(FRAME_DELAYcloud);
}