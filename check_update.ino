
//////////////////////////////////////////////////
//////////////   UPDATE     //////////////////////
/////////////////////////////////////////////////

void firmwareUpdate(void) {

  bool updatedNeeded = esp32FOTA.execHTTPcheck();
  if (updatedNeeded)
  {
    esp32FOTA.execOTA();
  }
  delay(3000);
}
