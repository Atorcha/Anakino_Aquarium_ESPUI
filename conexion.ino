
 
  void connectWIFI(){  // Connect to Wi-Fi // try to connect to existing network
    
  int connect_timeout;  
 // WiFi.setHostname(hostname);
  Serial.println("Begin wifi...");
  ssid = nvs.getString("ssid", "");
  password = nvs.getString("password", "");
  
  if (ssid == "" || password == ""){
    
  modo_wifi_cliente = false;   
  Serial.println("No values saved for ssid or password");
  Serial.println("\nCreating access point...");
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(IPAddress(192, 168, 4, 1), IPAddress(192, 168, 4, 1), IPAddress(255, 255, 255, 0));
  WiFi.softAP("Anakino_control");

    connect_timeout = 20;
    do {
      delay(250);
      Serial.print(",");
      connect_timeout--;
    } 
    while(connect_timeout);
  }
  
////////// MODO CLIENTE . ///////
  
  else {
  modo_wifi_cliente= true;
  Serial.println("Modo Cliente");
  Serial.println("\nTry to connect to: ");
  WiFi.setHostname("ESP32 Anakino"); //define hostname
  WiFi.mode(WIFI_STA);
  delay(2000);
  WiFiMulti.addAP(ssid.c_str(), password.c_str());
  Serial.println(ssid.c_str());
  Serial.println(password.c_str());
  Serial.print("\nConnecting to WiFi ..");
  while (WiFiMulti.run() != WL_CONNECTED) {
      delay(500);   
      Serial.print('.');
      if (contador_2 == 60) {
          ESP.restart(); // Restart ESP
      }
   contador_2++; 
  delay(1000);
  }
    Serial.println("Connected to AP");
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
