//**********************************************************************************************
//************************ Funciones Non Volatile Storage **************************************
//**********************************************************************************************

void SAVEparametrosNVS()
{
  nvs.putFloat("temp_agua_des", (temp_agua_des));
  nvs.putInt("modo_luz", modo_luz);
  nvs.putInt("luz_on_hora", luz_on_hora);
  nvs.putInt("luz_on_minuto", luz_on_minuto);
  nvs.putInt("luz_off_hora", luz_off_hora);
  nvs.putInt("luz_off_minuto", luz_off_minuto);
  nvs.putInt("modo_ai", modo_ai);
  nvs.putInt("ai_on_hora", ai_on_hora);
  nvs.putInt("ai_on_minuto", ai_on_minuto);
  nvs.putInt("ai_off_hora", ai_off_hora);
  nvs.putInt("ai_off_minuto", ai_off_minuto);
  nvs.end(); // Close the Preferences
  Serial.println("Graba parámetros en NVS");
}

void SAVEwifitoNVS(){
  nvs.putString("ssid", ssid);
  nvs.putString("password", password);
  nvs.end(); // Close the Preferences
}

void SAVElogintoNVS(){
  nvs.putString("user", userLogin);
  nvs.putString("pass", passLogin);
  nvs.end(); // Close the Preferences
}

void READfromNVS()
{
  temp_agua_des=nvs.getFloat("temp_agua_des", 0);
  luz_on_hora=nvs.getInt("luz_on_hora", 0);
  luz_on_minuto=nvs.getInt("luz_on_minuto", 0);
  luz_off_hora=nvs.getInt("luz_off_hora", 0);
  luz_off_minuto=nvs.getInt("luz_off_minuto", 0);
  modo_luz=nvs.getInt("modo_luz", 0);
  ai_on_hora=nvs.getInt("ai_on_hora", 0);
  ai_on_minuto=nvs.getInt("ai_on_minuto", 0);
  ai_off_hora=nvs.getInt("ai_off_hora", 0);
  ai_off_minuto=nvs.getInt("ai_off_minuto", 0);
  modo_ai=nvs.getInt("modo_ai", 0);
  MUST_UPDATE = nvs.getBool("must_update", MUST_UPDATE);
}

void READLoginfromNVS()
{
  userLogin = nvs.getString("user", "");
  passLogin = nvs.getString("pass", "");
  
  if (userLogin == "" || passLogin == ""){
    userLogin = "Anakin";
    passLogin = "1234";
  }
}
