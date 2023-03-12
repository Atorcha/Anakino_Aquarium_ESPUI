
//////////////////////////////////////////////////
//////////////////////VERSION CHECK//////////////
/////////////////////////////////////////////////

int FirmwareVersionCheck(void) {
    String payload;
    int httpCode;
    String FirmwareURL = "";
    FirmwareURL += URL_fw_Version;
    FirmwareURL += "?";
    FirmwareURL += String(rand());
    Serial.println(FirmwareURL);
    WiFiClientSecure * client = new WiFiClientSecure;

    if (client) {
        client -> setCACert(rootCACertificate);
        HTTPClient https;

        if (https.begin( * client, FirmwareURL)) {
            Serial.print("[HTTPS] GET...\n");
            // start connection and send HTTP header
            delay(100);
            httpCode = https.GET();
            delay(100);
            if (httpCode == HTTP_CODE_OK) // if version received
            {
                payload = https.getString(); // save received version
            } else {
                Serial.print("Error Occured During Version Check: ");
                Serial.println(httpCode);
            }
            https.end();
        }
        delete client;
    }

    if (httpCode == HTTP_CODE_OK) // if version received
    {
        payload.trim();
        if (payload.equals(FirmwareVer)) {
            Serial.printf("\nDevice  IS Already on Latest Firmware Version:%s\n", FirmwareVer);
            return 0;
        } else {
            Serial.println(payload);
            Serial.println("New Firmware Detected");
            OTA = true;      
            return 1;
        }
    }
    return 0;
}

//////////////////////////////////////////////////
//////////////////////UPDATE//////////////////////
/////////////////////////////////////////////////

void firmwareUpdate(void) {
    Serial.println("paro server");
    WiFiClientSecure client;
    client.setCACert(rootCACertificate);
  //  WiFiClient client;
    Serial.println("FIRMWARE UPDATE");
    t_httpUpdate_return ret = httpUpdate.updateSpiffs(client, URL_fw_Bin);
    
    Serial.println("1");
    switch (ret) {
    case HTTP_UPDATE_FAILED:
    Serial.println("2");
        Serial.printf("HTTP_UPDATE_FAILD Error (%d): %s\n", httpUpdate.getLastError(), httpUpdate.getLastErrorString().c_str());
        break;

    case HTTP_UPDATE_NO_UPDATES:
        Serial.println("HTTP_UPDATE_NO_UPDATES");
        break;

    case HTTP_UPDATE_OK:
        Serial.println("HTTP_UPDATE_OK vvv");
        break;
    }
}
