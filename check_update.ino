
//////////////////////////////////////////////////
//////////////   UPDATE     //////////////////////
/////////////////////////////////////////////////

void firmwareUpdate(void) 
    {
  nvs.putBool("must_update", false);
  esp32FOTA.execOTA();
  estado = "REINICIANDO...";
  ESPUI.updateLabel(estadotempId, String (estado));
  delay (3000);
  ESP.restart(); // Restart ESP32
}
