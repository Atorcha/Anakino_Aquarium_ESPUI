/////////////////////////////////////////////////////////////////
//   TEMPERATURA DEL AGUA
/////////////////////////////////////////////////////////////////

void check_temp(){ // sensor de temp del agua
  
  contador_temp ++;
  sensors.requestTemperatures();   // call sensors.requestTemperatures() to issue a global 
  // temperature request to all devices on the bus
  
  temperatura_agua_temp += sensors.getTempCByIndex(0);       // lee temp del agua
  if(contador_temp == 10){
    temp_agua = temperatura_agua_temp / 10;
    contador_temp = 0;  
    temperatura_agua_temp = 0;
  }
 }
  
/////////////////////////////////////////////////////////////////
//   CALENTADOR
/////////////////////////////////////////////////////////////////

void check_calentador(){           // activa calentador
    
  #ifdef DEBUG
  Serial.println("check calentador");
  #endif
  
    if (temp_agua > temp_agua_des + 0.5 || temp_agua < temp_agua_des - 0.5)  {
      //alarma_activa =true;
      } 
      else { 
        //alarma_activa = false;
        }
  
    if (temp_agua != -127 && temp_agua != 85 && temp_agua != 0){
     
      if (temp_agua <= temp_agua_des-0.1){
        digitalWrite(calentador,HIGH); // Encendemos Calentador
        ESPUI.updateSwitcher(Switch_3, true);
        // Serial.print("Enciende calentador: "); Serial.print(temp_agua); Serial.print(" "); Serial.println(temp_agua_des-temperatura_margen); 
       }
       
      if (temp_agua >= temp_agua_des+0.1){
        digitalWrite(calentador,LOW); // Apagamos Calentador
        ESPUI.updateSwitcher(Switch_3, false);
       // Serial.print("Apaga calentador"+ String(temp_agua) +"Temp agua + margen= " + String(temp_agua_des+temperatura_margen));
      }
    }
    else
    {
      digitalWrite(calentador,LOW); // Apagamos Calentador
      ESPUI.updateSwitcher(Switch_3, false);
    } 
}


/////////////////////////////////////////////////////////////////
//   VENTILADOR
/////////////////////////////////////////////////////////////////
