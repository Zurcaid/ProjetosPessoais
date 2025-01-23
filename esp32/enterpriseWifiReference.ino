// Codigo para conectar em redes WPA2 

#define EAP_IDENTITY "user"  // Nome de usuario
#define EAP_PASSWORD "senha"  // Senha do usuario
const char *ssid = "nomeDoWifi";    // Nome da rede wifi

#include <WiFi.h>
#include "esp_eap_client.h"

void getSite(String url){ // Função para usar o metodo GET em sites
  if (WiFi.status() == WL_CONNECTED) { // Caso a internet esteja conectada
    HTTPClient http;

    http.begin(url.c_str()); // Inicia a conexão com o site
   
    int httpCode = http.GET(); // GET no site (retorna a estrutura html do site)

    if (httpCode > 0) {
      Serial.print("Codigo de status HTTP: ");
      Serial.println(httpCode);
      String payload = http.getString(); 
      Serial.println(payload);
    } else { // Quando há um erro, o código de resposta é -1
      Serial.print("Código de erro: ");
      Serial.println(httpResponseCode);
    }

    http.end(); // Encerra a conexão
  } else {
    Serial.println("WiFi Disconnected"); // Caso a internet não esteja conectada
  }
}

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
