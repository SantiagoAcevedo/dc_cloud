#include <ESP8266WiFi.h> //essa biblioteca já vem com a IDE. Portanto, não é preciso baixar nenhuma biblioteca adicional
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>

#define SSID_REDE "SUA REDE" /* coloque aqui o nome da rede que se deseja conectar */
#define SENHA_REDE "SUA SENHA" /* coloque aqui a senha da rede que se deseja conectar */
#define INTERVALO_ENVIO_THINGSPEAK 30000 /* intervalo entre envios de dados ao ThingSpeak (em ms) */
 
/* constantes e variáveis globais */
const char* serverName = "https://api.thingspeak.com/update";
String apiKey = "SUAKEYAPI";  /* Coloque aqui sua chave de escrita do seu canal */
unsigned long last_connection_time;
WiFiClient client; 
/* prototypes */
void init_wifi(void);
void conecta_wifi(void);
void verifica_conexao_wifi(void);
String message1;
String message2;
void init_wifi(void){
    Serial.println("------WI-FI -----");
    Serial.println("Conectando-se a rede: ");
    Serial.println(SSID_REDE);
    Serial.println("\nAguarde...");
    conecta_wifi();
}
void conecta_wifi(void){
    if (WiFi.status() == WL_CONNECTED){
        return;
    }
    WiFi.begin(SSID_REDE, SENHA_REDE);     
    while (WiFi.status() != WL_CONNECTED){
        delay(100);
    }
 
    Serial.println("Conectado com sucesso a rede wi-fi \n");
    Serial.println(SSID_REDE);
}
void verifica_conexao_wifi(void){
    conecta_wifi();
}
void setup() {
  Serial.begin(9600);
  last_connection_time = 0;
  init_wifi();
}
void loop() {   
      if (Serial.available() > 0) { 
        String fullMessage = Serial.readString(); 
        int commaIndex = fullMessage.indexOf(','); 
        if (commaIndex != -1) { 
          message1 = fullMessage.substring(0, commaIndex);
          message2 = fullMessage.substring(commaIndex + 1);
        }
        if( millis() - last_connection_time > INTERVALO_ENVIO_THINGSPEAK ){
              WiFiClientSecure client;
              client.setInsecure();
              HTTPClient http;
              http.begin(client, serverName);
              http.addHeader("Content-Type", "application/x-www-form-urlencoded");
              String httpRequestData = "api_key=" + apiKey + "&field1=" + String(message1) + "&field2="+ String(message2);
              int httpResponseCode = http.POST(httpRequestData);      
              if (httpResponseCode == 200) {                
                Serial.println("Dados enviados a ThingSpeak");
              } else {
                String response = http.getString();
                Serial.println("Response:");
                Serial.println(response);
                Serial.print("Error code: ");
                Serial.println(httpResponseCode);
              }
            last_connection_time = millis();  
            http.end();
        }
      }     
      verifica_conexao_wifi();     
}
