
 
  void connectWIFI(){  // Connect to Wi-Fi // try to connect to existing network
    
  int connect_timeout;  
  WiFi.setHostname(hostname);
  Serial.println("Begin wifi...");
  ssid = nvs.getString("ssid", "");
  password = nvs.getString("password", "");
  
  if (ssid == "" || password == ""){
  modo_wifi_cliente = false;   
  Serial.println("No values saved for ssid or password");
  Serial.println("\nCreating access point...");
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(IPAddress(192, 168, 1, 1), IPAddress(192, 168, 1, 1), IPAddress(255, 255, 255, 0));
  WiFi.softAP("Anakino_control");

    connect_timeout = 20;
    do {
      delay(250);
      Serial.print(",");
      connect_timeout--;
    } while(connect_timeout);
  }
  else {
  modo_wifi_cliente= true;  
  Serial.println("Modo Cliente");
  Serial.println("\n\nTry to connect to: ");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid.c_str(), password.c_str());
  Serial.println(ssid.c_str());
  Serial.println(password.c_str());
  Serial.print("\nConnecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
  Serial.print('.');
  contador_2++;
  if (contador_2 == 30) {   
  ESP.restart(); // Restart ESP
  } 
  delay(1000);
  }
    Serial.print("RRSI: ");
    Serial.println(WiFi.RSSI());  
}
    Serial.println("\nWiFi parameters:");
    Serial.print("Mode: ");
    Serial.println(WiFi.getMode() == WIFI_AP ? "Station" : "Client");
    Serial.print("IP address: ");
    Serial.println(WiFi.getMode() == WIFI_AP ? WiFi.softAPIP() : WiFi.localIP());
    delay(1000);
  
}
