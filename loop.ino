
////////////////////////////////////////////////////////////////
// VOID LOOP
///////////////////////////////////////////////////////////////

void loop()
{    
   TIMERG0.wdt_wprotect=TIMG_WDT_WKEY_VALUE;
   TIMERG0.wdt_feed=1;
   TIMERG0.wdt_wprotect=0;
   
   // static long oldTime = 0;
   // static bool testSwitchState = false;
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
     timeClient.update();
     break;
   }
   #endif
   
   if (modo_wifi_cliente == true){
   unsigned long currentMillis = millis();
  // if WiFi is down, try reconnecting every CHECK_WIFI_TIME seconds
  if ((WiFi.status() != WL_CONNECTED) && (currentMillis - previousMillis >=interval)) {
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
