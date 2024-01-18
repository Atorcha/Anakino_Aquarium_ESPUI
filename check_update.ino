
//////////////////////////////////////////////////
//////////////   UPDATE     //////////////////////
/////////////////////////////////////////////////

void firmwareUpdate(void) 
    {
  nvs.putBool("must_update", false);
  esp32FOTA.execOTA();
  ESPUI.updateLabel(estadoId, String ("REINICIANDO..."));
  delay (3000);
}

//////////////////////////////////////////////////
//////////////   NECESITA ACTUALIZAR    //////////////////////
/////////////////////////////////////////////////

void necesita_update()
    {
        nvs.putBool("must_update", true);
        ESPUI.updateLabel(estadoId, String ("Necesita actualizar..."));
        Serial.println("Necesita actualizar...");
        delay (3000);
        ESP.restart(); // Restart ESP32 
    }


//////////////////////////////////////////////////
///////   NO NECESITA ACTUALIZAR    /////////////
/////////////////////////////////////////////////

void no_necesita_update()
    {
        Serial.println("NO necesita actualizar...");
        ESPUI.updateLabel(estadoId, String ("NO UPDATE"));
        delay (3000); 
        //ESPUI.updateLabel(estadoId, String ("Running...")); 
    }
