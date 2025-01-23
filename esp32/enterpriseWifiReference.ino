// Codigo para conectar em redes WPA2
// Funcao getSite para demonstrar a conexão com a internet com o metodo GET HTTP

#define EAP_IDENTITY "user"  // Nome de usuario
#define EAP_PASSWORD "senha"  // Senha do usuario
const char *ssid = "nomeDoWifi";    // Nome da rede wifi

#include <WiFi.h>
#include <HTTPClient.h>

void setup() {
  Serial.begin(115200);
  delay(10);

  Serial.println();
  Serial.print("Connecting to network: ");
  Serial.println(ssid);

  WiFi.disconnect(true);  // Disconecta da internet

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

void getSite(String url){ // Função para usar o metodo GET em sites
  // O parametro url deve ser a url completa do site. (Exemplo: "http://site.com/")
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
      Serial.println(httpCode);
    }

    http.end(); // Encerra a conexão
  } else {
    Serial.println("WiFi Disconnected"); // Caso a internet não esteja conectada
  }
}
