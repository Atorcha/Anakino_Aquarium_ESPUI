////////////////////////////////////////////////////////////////
// VOID SETUP
///////////////////////////////////////////////////////////////

void setup(void)
{
    Serial.begin(115200);
    Serial.setDebugOutput(true);
    sensors.begin();
    nvs.begin("datos",false); // use "datos" namespace
    READfromNVS();
    ESPUI.setVerbosity(Verbosity::Verbose); //Turn ON verbose debugging
    connectWIFI();
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
    Serial.print("Active Firmware Version:");
    Serial.println(FirmwareVer);
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

  setupUI();
  ESPUI.begin("Anakino Aquarium 23.12", "Anakin", "123456");
}
