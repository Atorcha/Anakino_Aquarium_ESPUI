/////////////////////////////////////////////////////////////////
//LUZ
/////////////////////////////////////////////////////////////////

void check_luz(){

      if (modo_luz == 0){       // si esta configurado el modo automatico
        
       if (luz == true ) // si en hora
       {
        digitalWrite(leds,HIGH); //activa rele
        ESPUI.updateSwitcher(Switch_4, true);
        //Serial.println("LUZ Auto ON");
      }
      if (luz == false ) // si no en hora
      {
        digitalWrite(leds,LOW); //desactiva rele
        ESPUI.updateSwitcher(Switch_4, false);
       // Serial.println("LUZ Auto OFF");
      }
    }

   else if (modo_luz == 1) // Modo manual ON
    {
    digitalWrite(leds,HIGH); // Encendemos luz,
    ESPUI.updateSwitcher(Switch_4, true); 
   // Serial.println("LUZ Manual ON ");
    }
    else if   
      (modo_luz == 2)   // Modo manual OFF
      {  
      digitalWrite(leds,LOW); // Apagamos luz
      ESPUI.updateSwitcher(Switch_4, false);
    //  Serial.println("LUZ Manual OFF ");
    }
   }

/////////////////////////////////////////////////////////////////
// TEMPORIZADOR LUZ
/////////////////////////////////////////////////////////////////

void tempo_luz(){               ///////////////////   temporizador 1 (LUZ)
       
    if(NumMins(luz_off_hora,luz_off_minuto) > NumMins(luz_on_hora,luz_on_minuto))
    {       
      if((NumMins(th,tm) >= NumMins(luz_on_hora,luz_on_minuto)) && (NumMins(th,tm) <= NumMins(luz_off_hora,luz_off_minuto)))
      {
          luz = true; // activa rele
      }
      if (NumMins(th,tm) > NumMins(luz_off_hora,luz_off_minuto))
      {
         luz = false; // desactiva rele
      }
    }
    if(NumMins(luz_off_hora,luz_off_minuto) < NumMins(luz_on_hora,luz_on_minuto))
    {
     // Serial.println(" Temp 2");                     
      if(NumMins(th,tm) >= NumMins(luz_on_hora,luz_on_minuto)) 
      {
         luz = true;  // activa rele       
      }

      if (NumMins(th,tm) < NumMins(luz_off_hora,luz_off_minuto)) 
      {
          luz = true;  //  ACTIVA RELE         
      }     
      if ((NumMins(th,tm) >= NumMins(luz_off_hora,luz_off_minuto)) && (NumMins(th,tm) < NumMins(luz_on_hora,luz_on_minuto)))
      {
          luz = false; // desactiva rele
      } 
    }  
 }
