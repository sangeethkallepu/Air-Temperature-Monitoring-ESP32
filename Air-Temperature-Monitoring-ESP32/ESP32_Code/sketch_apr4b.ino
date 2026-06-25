#define BLYNK_TEMPLATE_ID "TMPL3siTBgIVT"
#define BLYNK_TEMPLATE_NAME "Air and Temperature Monitoring"
#define BLYNK_AUTH_TOKEN "fujAd3uKG3tP0RJs2PcJrDJHgKlnQRDV"

#define BLYNK_PRINT Serial

#define GREEN_LED 25
#define RED_LED 26
#define BUZZER 27

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "MQ135.h"

const char *ssid = "12345678";
const char *pass = "12345678";

LiquidCrystal_I2C lcd(0x27, 16, 2);

byte degree_symbol[8] = {
  0b00111,
  0b00101,
  0b00111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

char auth[] = BLYNK_AUTH_TOKEN;
BlynkTimer timer;

int gas = 32;

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);


float temperature = 0;
float humidity = 0;
int gasValue = 0;

void sendSensor()
{
  
  humidity = dht.readHumidity();
  temperature = dht.readTemperature();
  gasValue = analogRead(gas);

  float f = (temperature * 9.0 / 5.0) + 32.0;

  
  Blynk.virtualWrite(V0, f);
  Blynk.virtualWrite(V1, humidity);
  Blynk.virtualWrite(V2, gasValue);

  
  Serial.println("===== SENSOR DATA =====");
  Serial.print("Temperature: ");
  Serial.print(f);
  Serial.print(" F  Humidity: ");
  Serial.println(humidity);

  Serial.print("Air Value: ");
  Serial.println(gasValue);
}

void setup()
{
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.begin(115200);
  dht.begin();

  lcd.init();
  lcd.backlight();
  lcd.createChar(1, degree_symbol);

  lcd.setCursor(0, 0);
  lcd.print("Air & Temperature");
  lcd.setCursor(3, 1);
  lcd.print("Monitoring");
  delay(3000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Connecting WiFi");

  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED)
  {
    lcd.setCursor(0, 1);
    lcd.print("Please wait...");
    delay(500);
  }

  Blynk.begin(auth, ssid, pass);
  timer.setInterval(2000L, sendSensor);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WiFi Connected");
  delay(2000);
  lcd.clear();
}

void loop()
{
  Blynk.run();
  timer.run();

  float f = (temperature * 9.0 / 5.0) + 32.0;

  lcd.setCursor(0, 0);
  lcd.print("Temperature ");
  lcd.setCursor(0, 1);
  lcd.print(f);
  lcd.setCursor(6, 1);
  lcd.write(1);
  lcd.setCursor(7, 1);
  lcd.print("F   ");
  delay(1000);
  lcd.clear();

  
  lcd.setCursor(0, 0);
  lcd.print("Humidity ");
  lcd.print(humidity);
  lcd.print("%   ");
  delay(1000);
  lcd.clear();

  
  lcd.setCursor(0, 0);
  lcd.print("Air Value: ");
  lcd.print(gasValue);
  lcd.print("   ");

  lcd.setCursor(0, 1);
  lcd.print("                "); 

  if (gasValue < 800)
  {
    lcd.setCursor(0, 1);
    lcd.print("Fresh Air");
    Serial.println("Fresh Air");

    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BUZZER, LOW);
  }
  else
  {
    lcd.setCursor(0, 1);
    lcd.print("Bad Air");
    Serial.println("Bad Air");

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BUZZER, HIGH);

    Blynk.logEvent("pollution_alert", "Bad Air");
  }

  Serial.println("======================\n");

  delay(1000);
  lcd.clear();
}