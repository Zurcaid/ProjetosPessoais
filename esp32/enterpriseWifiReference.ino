// Codigo para conectar em redes WPA2 

#define EAP_IDENTITY "user"  // Nome de usuario
#define EAP_PASSWORD "senha"  // Senha do usuario
const char *ssid = "nomeDoWifi";    // Nome da rede wifi

#include <WiFi.h>
#include "esp_eap_client.h"



void setup() {
  Serial.begin(115200);
  delay(10);

  Serial.println();
  Serial.print("Connecting to network: ");
  Serial.println(ssid);

  WiFi.disconnect(true);  // Disconecta da internet
  // esp_eap_client_set_identity((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY));  //provide identity
  // esp_eap_client_set_username((uint8_t *)EAP_IDENTITY, strlen(EAP_IDENTITY));  //provide username
  // esp_eap_client_set_password((uint8_t *)EAP_PASSWORD, strlen(EAP_PASSWORD));  //provide password
  // esp_wifi_sta_enterprise_enable();

  WiFi.begin(ssid, WPA2_AUTH_PEAP, EAP_IDENTITY, EAP_IDENTITY, EAP_PASSWORD);  // Conecta a internet
   while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.print(".");
   }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address set: ");
  Serial.println(WiFi.localIP());  // Imprime o IP privado

}

void loop() {
}
