
/*
 * Program ini digunakan untuk project IoT dasar menggunakan app Blynk
 * Project date : 15 April 2020
 * Author : IDNmakerspace Algorithm Factory (https://idnmakerspace.wordpress.com/)
 */

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHTesp.h>

#define BLYNK_PRINT Serial

//kode token yang dikirmkan ke email sobat
char konfirmasi[] = "S_0w3o5JRQTOGNW02EgjWmnjJsyAU6Xg"; 

//nama wifi/Hotspot sobat
char ssid[] = "Linux@ITERA"; 

//password wifi
char password[] = "namasayamadeagusandigunawan"; 

    
DHTesp dht;
BlynkTimer waktu;

void KIRIM()
{
  float kelembaban = dht.getHumidity();
  float suhu = dht.getTemperature();
  if (isnan(kelembaban) || isnan(suhu)) {
    Serial.println("gagal ketika membaca dari sensor DHT11!");
    return;
  }
  Blynk.virtualWrite(V5, suhu);
  Blynk.virtualWrite(V6, kelembaban);
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(konfirmasi, ssid, password);
  dht.setup(0, DHTesp::DHT11);
  waktu.setInterval(1000L, KIRIM);
}
 
void loop()
{
  Blynk.run();
  waktu.run();
}
