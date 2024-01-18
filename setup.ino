////////////////////////////////////////////////////////////////
// VOID SETUP
///////////////////////////////////////////////////////////////

void setup(void)
{
    Serial.begin(115200);
    Serial.setDebugOutput(true);
    esp32FOTA.setManifestURL( manifest_url );
    esp32FOTA.printConfig();  
    sensors.begin();
    nvs.begin("datos",false); // use "datos" namespace
    READfromNVS();
    READLoginfromNVS();  
    WiFi.onEvent(WiFiStationDisconnected, WiFiEvent_t::ARDUINO_EVENT_WIFI_STA_DISCONNECTED);  
    connectWIFI();          
    if (MUST_UPDATE == true) {
        nvs.putBool("must_update", false);
        Serial.println("Ha reiniciado ...y empieza actualizacion");
        esp32FOTA.execHTTPcheck();       
        esp32FOTA.execOTA();
        delay (2000);
    }
    
  //  ESPUI.setVerbosity(Verbosity::Verbose); //Turn ON verbose debugging
    timeClient.begin(); // Initialize a NTPClient to get time
    timeClient.setTimeOffset(3600); // Set offset time in seconds to adjust for your timezone, for example:
    // GMT +1 = 3600
    timeClient.update();

///////////////////////////////////////
    //Asignamos los distintos PINES

  pinMode(calentador, OUTPUT); // Calentador     
  pinMode(luz, OUTPUT);
  pinMode(aireador, OUTPUT);
  pinMode(rele, OUTPUT);

  
/////////////////////////////////////////////////

    check_time();
    
    
    Serial.print("\nHora actual:");
    Serial.println(timeClient.getFormattedTime());
    Serial.print("Temp deseada: ");
    Serial.println(temp_agua_des);
    //Serial.println(NumMins(th,tm));
    Serial.print("Hora LUZ ON: ");
    //Serial.println(NumMins(luz_on_hora,luz_on_minuto));
    luz_on_temp = String() + (luz_on_hora < 10 ? "0" : "") + luz_on_hora + ':' + (luz_on_minuto < 10 ? "0" : "") + luz_on_minuto;
    Serial.println(luz_on_temp);
    Serial.print("Hora LUZ OFF: ");
    //Serial.println(NumMins(luz_off_hora,luz_off_minuto));
    luz_off_temp = String() + (luz_off_hora < 10 ? "0" : "") + luz_off_hora + ':' + (luz_off_minuto < 10 ? "0" : "") + luz_off_minuto;
    Serial.println(luz_off_temp);
    Serial.print("Modo Luz: ");
    Serial.println(modo_luz);

    Serial.print("Hora Aireador ON: ");
    //Serial.println(NumMins(luz_on_hora,luz_on_minuto));
    ai_on_temp = String() + (ai_on_hora < 10 ? "0" : "") + ai_on_hora + ':' + (ai_on_minuto < 10 ? "0" : "") + ai_on_minuto;
    Serial.println(ai_on_temp);
    Serial.print("Hora Aireador OFF: ");
    //Serial.println(NumMins(luz_off_hora,luz_off_minuto));
    ai_off_temp = String() + (ai_off_hora < 10 ? "0" : "") + ai_off_hora + ':' + (ai_off_minuto < 10 ? "0" : "") + ai_off_minuto;
    Serial.println(ai_off_temp);
    Serial.print("Modo Aireador: ");
    Serial.println(modo_ai);
    Serial.println(userLogin.c_str()); 
    Serial.println(passLogin.c_str());
    
    
  setupUI();
  ESPUI.begin("Anakino Aquarium", userLogin.c_str(), passLogin.c_str());
  ESPUI.updateLabel(versionLabelId, String (SemV));
  //ESPUI.updateLabel(estadotempId, String (estado));
}
