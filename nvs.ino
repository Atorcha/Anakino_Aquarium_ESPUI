//**********************************************************************************************
//************************ Funciones Non Volatile Storage **************************************
//**********************************************************************************************

void SAVEtoNVS()
{
  nvs.putInt("temp_agua_des", (temp_agua_des*10));
  nvs.putInt("luz_on_hora", luz_on_hora);
  nvs.putInt("luz_on_minuto", luz_on_minuto);
  nvs.putInt("luz_off_hora", luz_off_hora);
  nvs.putInt("luz_off_minuto", luz_off_minuto);
  nvs.putInt("modo_luz", modo_luz);
 //  nvs.putInt("")=int (amanecer_anochecer);
 // nvs.putInt("")=int (pwm_absoluto);
 // nvs.putInt("")=int (pwm_percent);
  nvs.end(); // Close the Preferences
  Serial.println("Graba  en NVS");    
}

void SAVEwifitoNVS(){
  nvs.putString("ssid", ssid);
  nvs.putString("password", password);
}

void READwififromNVS(){
  
}

void READfromNVS()
{
  temp_agua_des=nvs.getInt("temp_agua_des", 0);
  temp_agua_des /=10;
  luz_on_hora=nvs.getInt("luz_on_hora", 0);
  luz_on_minuto=nvs.getInt("luz_on_minuto", 0);
  luz_off_hora=nvs.getInt("luz_off_hora", 0);
  luz_off_minuto=nvs.getInt("luz_off_minuto", 0);
  modo_luz=nvs.getInt("modo_luz", 0);
}
