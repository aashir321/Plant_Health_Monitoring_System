#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL6y0MPVDc-"
#define BLYNK_TEMPLATE_NAME "Plant Health Monitoring System"
#define BLYNK_AUTH_TOKEN "7t1PIAiFSK5-MHbQkVtYiRHauUCy2nEO"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include "esp_eap_client.h"
#include "esp_wifi.h"

const char* ssid = "eduroam";
const char* EAP_IDENTITY = "lab.two@smiu.edu.pk";
const char* EAP_USERNAME = "lab.two@smiu.edu.pk";
const char* EAP_PASSWORD = "$miu@1022";

#define SOIL_PIN 32
#define LDR_PIN  34

int DRY = 3900;
int WET = 1200;

#define VPIN_MOISTURE V0
#define VPIN_LIGHT    V1
#define VPIN_STATUS   V2

BlynkTimer timer;

void connectEduroam() {
  WiFi.disconnect(true);
  WiFi.mode(WIFI_STA);

  esp_eap_client_set_identity((uint8_t*)EAP_IDENTITY, strlen(EAP_IDENTITY));
  esp_eap_client_set_username((uint8_t*)EAP_USERNAME, strlen(EAP_USERNAME));
  esp_eap_client_set_password((uint8_t*)EAP_PASSWORD, strlen(EAP_PASSWORD));

  esp_wifi_sta_enterprise_enable();
  WiFi.begin(ssid);

  Serial.print("Connecting to eduroam");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP: ");
  Serial.println(WiFi.localIP());
}

void sendData() {
  int soilRaw = analogRead(SOIL_PIN);
  int ldrRaw  = analogRead(LDR_PIN);

  int moisturePercent = map(soilRaw, DRY, WET, 0, 100);
  moisturePercent = constrain(moisturePercent, 0, 100);

  String soilStatus = (moisturePercent >= 50) ? "Healthy" : "Needs Water";

  // Note: LDR wiring pe depend karta hai, threshold adjust kar lena
  String lightStatus = (ldrRaw < 2000) ? "Needs Sunlight" : "Healthy Light";

  String statusText = soilStatus + " | " + lightStatus;

  Serial.print("Moisture: ");
  Serial.print(moisturePercent);
  Serial.print("% (Raw ");
  Serial.print(soilRaw);
  Serial.print(") | LightRaw: ");
  Serial.print(ldrRaw);
  Serial.print(" | ");
  Serial.println(statusText);

  Blynk.virtualWrite(VPIN_MOISTURE, moisturePercent);
  Blynk.virtualWrite(VPIN_LIGHT, ldrRaw);
  Blynk.virtualWrite(VPIN_STATUS, statusText);
}

void setup() {
  Serial.begin(115200);
  delay(500);

  connectEduroam();

  // config + connect is required
  Blynk.config(BLYNK_AUTH_TOKEN);
  if (!Blynk.connect(8000)) {
    Serial.println("Blynk connect failed, check token or internet.");
  } else {
    Serial.println("Blynk connected!");
  }

  timer.setInterval(2000L, sendData);
}

void loop() {
  // keep wifi alive (optional safety)
  if (WiFi.status() != WL_CONNECTED) {
    connectEduroam();
  }

  Blynk.run();
  timer.run();
}
