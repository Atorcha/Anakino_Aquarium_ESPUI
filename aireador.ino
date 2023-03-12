/////////////////////////////////////////////////////////////////
// control funcionamiento del aireador
/////////////////////////////////////////////////////////////////

void check_ai(){

      if (modo_ai == 0)      // modo aireador en AUTO
      {       
        if (ai == true ) // si en hora
        {
          digitalWrite(aireador,HIGH); //activa rele
          ESPUI.updateSwitcher(Switch_2, true);      
          //Serial.println(" AI Auto ON"); 
                  
        }
      else if (ai == false) // si no en hora
      { 
        digitalWrite(aireador,LOW); //desactiva rele
        ESPUI.updateSwitcher(Switch_2, false);       
        //Serial.println("AI Auto OFF");
      }
    }
      
   else if (modo_ai == 1) // modo manual ON
    {
      digitalWrite(aireador,HIGH); //activa rele   
      ESPUI.updateSwitcher(Switch_2, true);
    //Serial.println("AI Manual ON");  
      }
    else if   
      (modo_ai == 2) // MODO MANUAL OFF
      {
      digitalWrite(aireador,LOW); // Apagamos  ai,
      ESPUI.updateSwitcher(Switch_2, false);
     // Serial.println("AI Manual OFF");  
         
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
          ai = true;
          
         // Serial.println(" ai true");
        //SetRele(temporizador1, HIGH);        // activa rele
      }
      if (NumMins(th,tm) > NumMins(ai_off_hora,ai_off_minuto))
      {
         ai = false;
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
         ai = true;
        // ESPUI.updateSwitcher(Switch_4, true);
       //  Serial.println(" ai true");
       //SetRele(temporizador1, HIGH);          // activa rele
      }

      if (NumMins(th,tm) < NumMins(ai_off_hora,ai_off_minuto)) 
      {
          ai = true;
        //  ESPUI.updateSwitcher(Switch_4, true);
        //  Serial.println(" ai true");
        //SetRele(temporizador1, HIGH);          //  ACTIVA RELE
      }     
      if ((NumMins(th,tm) >= NumMins(ai_off_hora,ai_off_minuto)) && (NumMins(th,tm) < NumMins(ai_on_hora,ai_on_minuto)))
      {
          ai = false;
         // ESPUI.updateSwitcher(Switch_4, false);
          //Serial.println(" ai false");
        //SetRele(temporizador1, LOW);         // desactiva rele
      } 
    }  
 }
