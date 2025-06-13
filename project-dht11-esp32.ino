#include "DHT.h"

#define DHTPIN 4        // Pin data DHT terhubung ke GPIO 4
#define DHTTYPE DHT11   // Tipe sensor DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  float suhu = dht.readTemperature();     // dalam °C
  float kelembaban = dht.readHumidity();  // dalam %

  if (isnan(suhu) || isnan(kelembaban)) {
    Serial.println("Gagal membaca dari sensor DHT!");
  } else {
    Serial.print("Suhu: ");
    Serial.print(suhu);
    Serial.print("°C  |  Kelembaban: ");
    Serial.print(kelembaban);
    Serial.println("%");
  }

  delay(2000);  // baca setiap 2 detik
}

