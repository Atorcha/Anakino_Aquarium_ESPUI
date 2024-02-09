

#include <esp32fota.h>
#include <WiFi.h>
#include <Preferences.h>

String ssid = "XXXX"; // Change this to your WiFi SSID
String password = "XXX"; // Change this to your WiFi password

Preferences nvs;
esp32FOTA esp32FOTA("esp32-fota-http", 1, false, true);
const char* manifest_url = "https://raw.githubusercontent.com/Atorcha/Anakino_Aquarium_ESPUI/main/OTA/fota.json";

void setup_wifi()
{
  delay(10);
  Serial.print("Connecting to WiFi");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println(WiFi.localIP());
}

void setup()
{
  Serial.begin(115200);
  nvs.begin("datos",false); // use "datos" namespace
  SAVEwifitoNVS();
  esp32FOTA.setManifestURL( manifest_url );
  esp32FOTA.printConfig();
  setup_wifi();
}

void SAVEwifitoNVS(){
  nvs.putString("ssid", ssid);
  nvs.putString("password", password);
  nvs.end(); // Close the Preferences
  Serial.println("Graba datos wifi a nvs");
}

void loop()
{
  delay(2000);
  esp32FOTA.forceUpdate("https://raw.githubusercontent.com/Atorcha/Anakino_Aquarium_ESPUI/main/OTA/firm.bin", false ); 
}
