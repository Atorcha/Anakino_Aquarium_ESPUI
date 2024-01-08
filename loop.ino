
////////////////////////////////////////////////////////////////
// VOID LOOP
///////////////////////////////////////////////////////////////

void loop()
{     
   reinicio = millis();
   if (reinicio/1000/60/60 == 24 ){
    Serial.print("Reinicio diario");}

   check_time();
   
   #ifdef CONTADOR 
   contador_1 ++;
   switch (contador_1){

     case 100:
    // #ifdef DEBUG Serial.println("contador 100"); #endif  
    check_temp();        // Comprueba valores temperatura  
    check_calentador();  // Comprueba si activa el calentador
    ESPUI.updateLabel(aguatempId, String (temp_agua));      
    break;
     
     case 200:
     tempo_luz(); // comprueba temporizadores
     check_luz();
     break;

     case 300:
     tempo_ai();
     check_ai();
     contador_1 = 0;
     ESPUI.updateLabel(RSSItempId, String (WiFi.RSSI()));
//     ESPUI.updateLabel(versionLabelId, String (SemverClass( firmware_version )));
     timeClient.update();
     break;
   }
   #endif
   
   if (modo_wifi_cliente == true){
   unsigned long currentMillis = millis();
  // if WiFi is down, try reconnecting every CHECK_WIFI_TIME seconds
  if ((WiFiMulti.run() != WL_CONNECTED) && (currentMillis - previousMillis >=interval)) {
    Serial.print(millis());
    Serial.println("Reconnecting to WiFi...");
    WiFi.disconnect();
    WiFi.reconnect();
    contador_2++;
    if (contador_2 == 5) {   
    ESP.restart(); // Restart ESP
    previousMillis = currentMillis;
    }
   }
  }
}
