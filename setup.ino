////////////////////////////////////////////////////////////////
// VOID SETUP
///////////////////////////////////////////////////////////////

void setup(void)
{
    Serial.begin(115200);
    sensors.begin();
    nvs.begin("datos",false); // use "datos" namespace
    READfromNVS();
//   ESPUI.setVerbosity(Verbosity::VerboseJSON); //Turn ON verbose debugging
    connectWIFI();
    timeClient.begin(); // Initialize a NTPClient to get time
    timeClient.setTimeOffset(3600); // Set offset time in seconds to adjust for your timezone, for example:
    // GMT +1 = 3600
    timeClient.update();

///////////////////////////////////////
    //Asignamos los distintos PINES

  pinMode(calentador, OUTPUT); // Calentador     
  pinMode(luz, OUTPUT);

  
/////////////////////////////////////////////////

    check_time();
    Serial.print("\nHora actual:");
    Serial.println(timeClient.getFormattedTime());
    //Serial.println(NumMins(th,tm));
    Serial.print("Hora LUZ ON: ");
    //Serial.println(NumMins(luz_on_hora,luz_on_minuto));
    luz_on_temp = String() + (luz_on_hora < 10 ? "0" : "") + luz_on_hora + ':' + (luz_on_minuto < 10 ? "0" : "") + luz_on_minuto;
    Serial.println(luz_on_temp);
    Serial.print("Hora LUZ OFF: ");
    //Serial.println(NumMins(luz_off_hora,luz_off_minuto));
    luz_off_temp = String() + (luz_off_hora < 10 ? "0" : "") + luz_off_hora + ':' + (luz_off_minuto < 10 ? "0" : "") + luz_off_minuto;
    Serial.println(luz_off_temp);
    Serial.print("Temp deseada: ");
    Serial.println(temp_agua_des);
    Serial.print("Modo Luz: ");
    Serial.println(modo_luz);

  setupUI();
  ESPUI.begin("Anakino Control v23.2", "Anakin", "123456");
}
