#include <MakerKit.h>

#define BLYNK_TEMPLATE_ID           "TMPL6kNNddxVE"
#define BLYNK_DEVICE_NAME           "IOT"
#define BLYNK_AUTH_TOKEN            "bcXII5c0-ffAoPf4mUWtROlQ1CYwnrbN"


#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "Macna";
char pass[] = "911";
#include <Adafruit_NeoPixel.h>
 Adafruit_NeoPixel pixels = Adafruit_NeoPixel(5, 4, NEO_GRB + NEO_KHZ800);

BLYNK_WRITE(V0)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    pixels.setPixelColor(0, 0xff0000);
    pixels.setPixelColor(1, 0xff0000);
    pixels.setPixelColor(2, 0xff0000);
    pixels.setPixelColor(3, 0xff0000);
    pixels.setPixelColor(4, 0xff0000);
    pixels.show();
    pixels.show();

  }
}

BLYNK_WRITE(V1)
{
int pinValue = param.asInt();
  if (pinValue == 1) {
    pixels.setPixelColor(0, 0x3333ff);
    pixels.setPixelColor(1, 0x3333ff);
    pixels.setPixelColor(2, 0x3333ff);
    pixels.setPixelColor(3, 0x3333ff);
    pixels.setPixelColor(4, 0x3333ff);
    pixels.show();
    pixels.show();

  }
}

BLYNK_WRITE(V3)
{
int pinValue = param.asInt();
  if (pinValue == 1) {

  } else if (false) {
  }
}

BlynkTimer Timer1;

void Timer1_TimerEvent()
{
  Blynk.virtualWrite(V20, ultrasonic(12,27));
  Blynk.virtualWrite(V7, analogRead(36));
}


void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pixels.begin();

  pinMode(36, INPUT);
  Timer1.setInterval(200, Timer1_TimerEvent);

}

void loop() {
  Blynk.run();
  Timer1.run();
}