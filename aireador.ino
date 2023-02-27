/////////////////////////////////////////////////////////////////
// control funcionamiento del aireador
/////////////////////////////////////////////////////////////////

void check_ai(){

      if (modo_ai == 1)      // modo aireador en AUTO
      {       
        if (temp_ai == 1 ) // si en hora
        {
          ESPUI.updateSwitcher(Switch_2, true);      
        //Serial.println(" AI Auto ON"); 
          digitalWrite(aireador,HIGH); //activa rele        
        }
      else if (temp_ai == 0)
      { 
        ESPUI.updateSwitcher(Switch_2, false);       
        //Serial.println("AI Auto OFF");
        digitalWrite(aireador,LOW); //desactiva rele
      }
    }
      
   else if (modo_ai == 2)
    {
      ESPUI.updateSwitcher(Switch_2, true);
    //Serial.println("AI Manual ON");  
      digitalWrite(aireador,HIGH); //activa rele    
      }
    else if   
      (modo_ai == 3){
      ESPUI.updateSwitcher(Switch_2, false);
     // Serial.println("AI Manual OFF");  
      digitalWrite(aireador,LOW); // Apagamos  ai,   
    }    
   }
/////////////////////////////////////////////////////////////////
// TEMPORIZADOR AIREADOR
/////////////////////////////////////////////////////////////////

void tempo_ai(){
       
    if(NumMins(luz_off_hora,luz_off_minuto) > NumMins(ai_on_hora,ai_on_minuto))
    {       
      if((NumMins(th,tm) >= NumMins(ai_on_hora,ai_on_minuto)) && (NumMins(th,tm) <= NumMins(ai_off_hora,ai_off_minuto)))
      {
          temp_ai = 1;
          
         // Serial.println(" ai true");
        //SetRele(temporizador1, HIGH);        // activa rele
      }
      if (NumMins(th,tm) > NumMins(ai_off_hora,ai_off_minuto))
      {
         temp_ai = 0;
        // ESPUI.updateSwitcher(Switch_4, false);
        // Serial.println(" ai false");
       //SetRele(temporizador1, LOW);       // desactiva rele
      }
    }
    if(NumMins(ai_off_hora,ai_off_minuto) < NumMins(ai_on_hora,ai_on_minuto))
    {
     // Serial.println(" ai 2");                     
      if(NumMins(th,tm) >= NumMins(ai_on_hora,ai_on_minuto)) 
      {
         temp_ai = 1;
        // ESPUI.updateSwitcher(Switch_4, true);
       //  Serial.println(" ai true");
       //SetRele(temporizador1, HIGH);          // activa rele
      }

      if (NumMins(th,tm) < NumMins(ai_off_hora,ai_off_minuto)) 
      {
          temp_ai = 1;
        //  ESPUI.updateSwitcher(Switch_4, true);
        //  Serial.println(" ai true");
        //SetRele(temporizador1, HIGH);          //  ACTIVA RELE
      }     
      if ((NumMins(th,tm) >= NumMins(ai_off_hora,ai_off_minuto)) && (NumMins(th,tm) < NumMins(ai_on_hora,ai_on_minuto)))
      {
          temp_ai = 0;
         // ESPUI.updateSwitcher(Switch_4, false);
          //Serial.println(" ai false");
        //SetRele(temporizador1, LOW);         // desactiva rele
      } 
    }  
 }
