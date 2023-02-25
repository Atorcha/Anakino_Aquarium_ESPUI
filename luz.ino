/////////////////////////////////////////////////////////////////
//LUZ
/////////////////////////////////////////////////////////////////

void check_luz(){

      if (modo_luz == 1){       // si esta configurado el modo automatico
        
       if (temp_luz == 1 ) // si en hora
       {
        digitalWrite(luz,HIGH); //activa rele
        ESPUI.updateSwitcher(Switch_4, true);
        //Serial.println("LUZ Auto ON");
      }
      if (temp_luz == 0 ) // si no en hora
      {
        digitalWrite(luz,LOW); //desactiva rele
        ESPUI.updateSwitcher(Switch_4, false);
       // Serial.println("LUZ Auto OFF");
      }
    }

   else if (modo_luz == 2) // Modo manual ON
    {
      
    digitalWrite(luz,HIGH); // Encendemos luz,
    ESPUI.updateSwitcher(Switch_4, true); 
   // Serial.println("LUZ Manual ON ");
    }
    else if   
      (modo_luz == 3)   // Modo manual OFF
      {  
      digitalWrite(luz,LOW); // Apagamos luz
      ESPUI.updateSwitcher(Switch_4, false);
    //  Serial.println("LUZ Manual OFF ");
    }
   }

/////////////////////////////////////////////////////////////////
// TEMPORIZADOR LUZ
/////////////////////////////////////////////////////////////////

void tempo_luz(){
              ///////////////////   temporizador 1 (LUZ)
       
    if(NumMins(luz_off_hora,luz_off_minuto) > NumMins(luz_on_hora,luz_on_minuto))
    {       
      if((NumMins(th,tm) >= NumMins(luz_on_hora,luz_on_minuto)) && (NumMins(th,tm) <= NumMins(luz_off_hora,luz_off_minuto)))
      {
          temp_luz = 1;
          
         // Serial.println(" Temp true");
        //SetRele(temporizador1, HIGH);        // activa rele
      }
      if (NumMins(th,tm) > NumMins(luz_off_hora,luz_off_minuto))
      {
         temp_luz = 0;
         //ESPUI.updateSwitcher(Switch_4, false);
        // Serial.println(" Temp false");
       //SetRele(temporizador1, LOW);       // desactiva rele
      }
    }
    if(NumMins(luz_off_hora,luz_off_minuto) < NumMins(luz_on_hora,luz_on_minuto))
    {
     // Serial.println(" Temp 2");                     
      if(NumMins(th,tm) >= NumMins(luz_on_hora,luz_on_minuto)) 
      {
         temp_luz = 1;
         //ESPUI.updateSwitcher(Switch_4, true);
       //  Serial.println(" Temp true");
       //SetRele(temporizador1, HIGH);          // activa rele
      }

      if (NumMins(th,tm) < NumMins(luz_off_hora,luz_off_minuto)) 
      {
          temp_luz = 1;
         // ESPUI.updateSwitcher(Switch_4, true);
        //  Serial.println(" Temp true");
        //SetRele(temporizador1, HIGH);          //  ACTIVA RELE
      }     
      if ((NumMins(th,tm) >= NumMins(luz_off_hora,luz_off_minuto)) && (NumMins(th,tm) < NumMins(luz_on_hora,luz_on_minuto)))
      {
          temp_luz = 0;
         // ESPUI.updateSwitcher(Switch_4, false);
          //Serial.println(" Temp false");
        //SetRele(temporizador1, LOW);         // desactiva rele
      } 
    }  
 }
