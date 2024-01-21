
///////////////////////////////////////////////////////////

     /////////////////////////////////////
    ///////////////             /////////
   //////////////// PESTAÑAS    ////////
  /////////////////             ///////
 /////////////////////////////////////

void setupUI(){
  
  String clearLabelStyle = "background-color: unset; width: 100%;";
  
  /*
   * Tab: STATUS
   * This tab contains all the basic ESPUI controls, and shows how to read and update them at runtime.
   *-----------------------------------------------------------------------------------------------------------*/
   
    auto status_tab = ESPUI.addControl(Tab, "", "Status");

  String labelStyle = "background-color: unset; width: 20%;";
  String inputStyle = "width: 70%; text-align: center;";

  auto estado = ESPUI.addControl(Label, "Estado", "Agua ºC", Peterriver, status_tab);
   ESPUI.setElementStyle(estado, labelStyle);
   ESPUI.setElementStyle(aguatempId = ESPUI.addControl(Label, "", "", Peterriver, estado, generalCallback), inputStyle);

   ESPUI.setElementStyle(ESPUI.addControl(Label, "", "Hora", None, estado), labelStyle);
   ESPUI.setElementStyle(realtime_LabelId = ESPUI.addControl(Label, "", "", Peterriver, estado, generalCallback), inputStyle);

   ESPUI.setElementStyle(ESPUI.addControl(Label, "", "RSSI", None, estado), labelStyle);
   ESPUI.setElementStyle(RSSItempId = ESPUI.addControl(Label, "", "", Peterriver, estado, generalCallback), inputStyle);

    // group switchers. AQUI IRA EL ESTADO DE LOS RELES   
  auto gruposreles = 
   ESPUI.addControl(Switcher, "Estados RELES", "0", Peterriver, status_tab, generalCallback);
   Switch_2 = ESPUI.addControl(Switcher, "", "", Sunflower, gruposreles, generalCallback);// aireador
   Switch_3 = ESPUI.addControl(Switcher, "", "", Sunflower, gruposreles, generalCallback);//calentador
   Switch_4 = ESPUI.addControl(Switcher, "", "", Sunflower, gruposreles, generalCallback);//led
  
   ESPUI.setElementStyle(ESPUI.addControl(Label, "", "", None, gruposreles), clearLabelStyle);
   //We will now need another label style. This one sets its width to the same as a switcher (and turns off the background)
   String switcherLabelStyle = "width: 60px; margin-left: .3rem; margin-right: .3rem; background-color: unset;";
   //We can now just add the styled labels.
   ESPUI.setElementStyle(ESPUI.addControl(Label, "", "1", None, gruposreles), switcherLabelStyle);
   ESPUI.setElementStyle(ESPUI.addControl(Label, "", "AIR", None, gruposreles), switcherLabelStyle);
   ESPUI.setElementStyle(ESPUI.addControl(Label, "", "HEAT", None, gruposreles), switcherLabelStyle);
   ESPUI.setElementStyle(ESPUI.addControl(Label, "", "LED", None, gruposreles), switcherLabelStyle);
    
  /*
   * Tab: PARÁMETROS
   * This tab contains all the basic ESPUI controls, and shows how to read and update them at runtime.
   *-----------------------------------------------------------------------------------------------------------*/
    auto param_tab = ESPUI.addControl(Tab, "", "Parámetros");
    
    // ESPUI.separator("Configuracion agua"); 
    ESPUI.addControl(ControlType::Separator, "Configuracion agua", "", ControlColor::None, param_tab); //CONFIGURACION AGUA
    
    // INPUT para la temperatura del agua Number inputs also accept Min and Max components, but you should still validate the values.
    mainNumber = ESPUI.addControl(Number, "Temperatura agua deseada", "24.5", Peterriver, param_tab, temperatura_Callback);
    ESPUI.addControl(Step, "", "0.1", None, mainNumber);
    ESPUI.addControl(Min, "", "20", None, mainNumber);
    ESPUI.addControl(Max, "", "30", None, mainNumber);

   // ESPUI.separator("Configuracion luz"); 
    ESPUI.addControl(ControlType::Separator, "Configuracion luz", "", ControlColor::None, param_tab); //MODO FUNCIONAMIENTO LUZ
    
  auto select1 = ESPUI.addControl(ControlType::Label, "LUZ", "Modo", ControlColor::Peterriver, param_tab);
    ESPUI.setElementStyle(select1, labelStyle);
    auto select1b = ESPUI.addControl(ControlType::Select, "", "", ControlColor::Peterriver, select1, selectCall);
      ESPUI.setElementStyle(select1b, inputStyle);
      ESPUI.setElementStyle(ESPUI.addControl(ControlType::Option, "MODO AUTO", "MODO AUTO", ControlColor::Peterriver, select1b), inputStyle);
      ESPUI.setElementStyle(ESPUI.addControl(ControlType::Option, "MODO ON", "MODO ON", ControlColor::Peterriver, select1b), inputStyle);
      ESPUI.setElementStyle(ESPUI.addControl(ControlType::Option, "MODO OFF", "MODO OFF", ControlColor::Peterriver, select1b), inputStyle);
     
    ESPUI.setElementStyle(ESPUI.addControl(Label, "", "Hora ON", Peterriver, select1), labelStyle);   // INTRODUCCION HORA ENCENDIDA/APAGADA
    ESPUI.setElementStyle(text_time1 = ESPUI.addControl(Text, "", luz_on_temp, Peterriver, select1, luz_on_Callback), inputStyle); // INPUT ON DEL PRIMER TIMER
    ESPUI.setInputType(text_time1, "time");
    
    ESPUI.setElementStyle(ESPUI.addControl(Label, "", "Hora OFF", Peterriver, select1), labelStyle); 
    ESPUI.setElementStyle(text_time2 = ESPUI.addControl(Text,"", luz_off_temp, Peterriver, select1, luz_off_Callback), inputStyle); // INPUT OFF DEL PRIMER TIMER
    ESPUI.setInputType(text_time2, "time");

  //  ESPUI.separator("Configuracion aireador"); 
    ESPUI.addControl(Separator, "Configuracion aireador", "", None, param_tab); //MODO FUNCIONAMIENTO AIREADOR

    auto select2 = ESPUI.addControl(ControlType::Label, "AIREADOR", "Modo", ControlColor::Peterriver, param_tab);
      ESPUI.setElementStyle(select2, labelStyle);
      auto select2b = ESPUI.addControl(ControlType::Select, "", "", ControlColor::Peterriver, select2, selectCall_2);
        ESPUI.setElementStyle(select2b, inputStyle);
        ESPUI.setElementStyle(ESPUI.addControl(ControlType::Option, "MODO AUTO", "MODO AUTO", ControlColor::Peterriver, select2b), inputStyle);
        ESPUI.setElementStyle(ESPUI.addControl(ControlType::Option, "MODO ON", "MODO ON", ControlColor::Peterriver, select2b), inputStyle);  
        ESPUI.setElementStyle(ESPUI.addControl(ControlType::Option, "MODO OFF", "MODO OFF", ControlColor::Peterriver, select2b), inputStyle);
        
      ESPUI.setElementStyle(ESPUI.addControl(Label, "", "Hora ON", Peterriver, select2), labelStyle);   // INTRODUCCION HORA ENCENDIDA/APAGADA
      ESPUI.setElementStyle(text_time_ai1 = ESPUI.addControl(Text, "", ai_on_temp, Peterriver, select2, ai_on_Callback), inputStyle); // INPUT ON DEL PRIMER TIMER
      ESPUI.setInputType(text_time_ai1, "time");
      
      ESPUI.setElementStyle(ESPUI.addControl(Label, "", "Hora OFF", Peterriver, select2), labelStyle); 
      ESPUI.setElementStyle(text_time_ai2 = ESPUI.addControl(Text,"", ai_off_temp, Peterriver, select2, ai_off_Callback), inputStyle); // INPUT OFF DEL PRIMER TIMER
      ESPUI.setInputType(text_time_ai2, "time");

    // BOTON GRABAR EN EEPROM
    boton_param = ESPUI.addControl(ControlType::Button, "GRABAR", "Press", ControlColor::Alizarin, param_tab, &boton_param_Callback);

         
  /*
   * Tab: CONFIGURACION
   * You use this tab to enter the SSID and password of a wifi network to autoconnect to.
   *-----------------------------------------------------------------------------------------------------------*/
  ///////////////////////// UPDATE WIFI
  auto config_tab = ESPUI.addControl(Tab, "", "Configuracion");
  // WIFI
  ESPUI.addControl(ControlType::Separator, "Configurar WIFI", "", ControlColor::None, config_tab);
  wifi_ssid_text = ESPUI.addControl(Text, "SSID", "", Peterriver, config_tab, textCallback);
  //Note that adding a "Max" control to a text control sets the max length
  ESPUI.addControl(Max, "", "32", None, wifi_ssid_text);
  wifi_pass_text = ESPUI.addControl(Text, "Password", "", Peterriver, config_tab, textCallback);
  ESPUI.addControl(Max, "", "64", None, wifi_pass_text);
  ESPUI.addControl(Button, "Guardar", "Guardar", Alizarin, config_tab, enterWifiDetailsCallback);

  ////////////////////////// UPDATE LOGIN
  ESPUI.addControl(ControlType::Separator, "Configurar login", "", ControlColor::None, config_tab);
  userLogin_text = ESPUI.addControl(Text, "Usuario", "", Peterriver, config_tab, textCallback);
  //Note that adding a "Max" control to a text control sets the max length
  passLogin_text = ESPUI.addControl(Text, "Contraseña", "", Peterriver, config_tab, textCallback);
  ESPUI.addControl(Button, "Guardar", "Guardar", Alizarin, config_tab, enterLoginDetailsCallback);
  
  /////////////////////////// UPDATE FIRM
  ESPUI.addControl(ControlType::Separator, "Actualizar firmware", "", ControlColor::None, config_tab);

  // BOTON COMPROBAR VERSION
    boton_ver = ESPUI.addControl(ControlType::Button, "Actualizar Firmware", "Update", ControlColor::Alizarin, config_tab, &boton_ver_Callback);
    versionLabelId = ESPUI.addControl(Label, "Version Firmware ", "", ControlColor::Peterriver, config_tab); // version firmware

      /////////////////////////// RESET
  ESPUI.addControl(ControlType::Separator, "REINCIAR", "", ControlColor::None, config_tab);
    boton_restart = ESPUI.addControl(ControlType::Button, "REINICIAR ESP32", "Press", ControlColor::Alizarin, config_tab, &boton_restart_Callback);
   
    // Enable this option if you want sliders to be continuous (update during move) and not discrete (update on stop)
    // ESPUI.sliderContinuous = true;

    /*
     * Optionally you can use HTTP BasicAuth. Keep in mind that this is NOT a
     * SECURE way of limiting access.
     * Anyone who is able to sniff traffic will be able to intercept your password
     * since it is transmitted in cleartext. Just add a string as username and
     * password, for example begin("ESPUI Control", "username", "password")
     */   
}
