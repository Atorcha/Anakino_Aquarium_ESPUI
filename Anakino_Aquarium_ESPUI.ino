
///////////////////////////////////////////////////////////////
//
//
//     CONTROLADOR DE ACUARIO C 
//     
//     V. 23.02
//
//     PLACA ESP32
//               
//
///////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////
//Librerias necesarias
///////////////////////////////////////////////////////////////

//#include <DNSServer.h>
#include <ESPUI.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <Preferences.h>
#include <WiFi.h>
#include "time.h"

////////////////////////////////////////////////////////////////

  //#define DEBUG
    #define CONTADOR
    int contador_1 = 0;   // variable contador del loop
    int contador_2 = 0; // contador para restart en caso de no wifi
////////////////////////////////////////////////////////////////
// Definimos los pines y variables
////////////////////////////////////////////////////////////////
// mejores pines OUTPUT 32,33,25,26,27,14,23,22,21,19,18,5,17
// mejores pines INPUT 36,39,34,35,32,33,25,26,27,14,23,22,21,19,18
#define sensores_temp  13  //  Sensores de temp de agua y pantalla leds
#define calentador 17      // Calentador    * RELE 1         
#define luz   19           // luz      * luz
#define aireador 29

//*********************** Variables de control de temperatura del agua ********************

float temp_agua;             //Temperatura del agua
unsigned char temp_agua_des;         //temperatura agua deseada
int contador_temp = 0;
float temperatura_agua_temp;       // Temperatura temporal del agua
///////////////////////////////////////////////////////////

int modo_luz;      // modo de funcionamiento luz
bool temp_luz;    // Variable para indicar si activa o no la luz
int luz_on_hora;       // Horario para encender leds.
int luz_on_minuto;
int luz_off_hora;      // Horario para apagar leds.
int luz_off_minuto;
////////////////////////////////////////////////////////////
int modo_ai;      // modo de funcionamiento ai
bool temp_ai;    // Variable para indicar si activa o no la ai
int ai_on_hora;       // Horario para encender ai.
int ai_on_minuto;
int ai_off_hora;      // Horario para apagar ai.
int ai_off_minuto;


uint16_t tempHBLabelId, humedadHBLabelId, aguatempId; //statusLabelId;
uint16_t realtime_LabelId;
uint16_t button1, button2;
uint16_t text_time1, text_time2;
char timeString[9];

//UI handles
uint16_t wifi_ssid_text, wifi_pass_text;
uint16_t mainLabel, Switch_4, Switch_3, Switch_2, Switch_1, mainSlider, mainText, mainNumber, mainScrambleButton, mainTime;
uint16_t styleButton, styleLabel, styleSwitcher, styleSlider, styleButton2, styleLabel2, styleSlider2;
uint16_t graph;

// Variables to save date and time
String realtime;
String luz_on_temp;
String luz_off_temp;

unsigned char th; // tiempo en hora
unsigned char tm; // tiempo en minuto

int on1_hora; /// temporizador 1 hora ON
int on1_minuto; //// temporizador 1 minuto ON
int off1_hora; /// temporizador 1 hora OFF
int off1_minuto; //// temporizador 1 minuto OFF
int on2_hora; /// temporizador 2 hora ON
int on2_minuto; //// temporizador 2 minuto ON
int off2_hora; /// temporizador 2 hora OFF
int off2_minuto; //// temporizador 2 minuto OFF

////////////////////////////////////////////////////////////////

Preferences nvs;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org");

String ssid;
String password;

unsigned long previousMillis = 0;
unsigned long interval = 30000; 

const char* hostname = "Anakino Aquarium";


////////////////////////////////////////////////////////////////
//ARRANCA  EL SENSOR DE TEMP DEL AGUA 
///////////////////////////////////////////////////////////////

OneWire oneWire(sensores_temp);      //Sensores de temperatura conectados al pin 22.
DallasTemperature sensors(&oneWire);
//DeviceAddress sensor_agua;


///////////////////////////////////////////////////////////
//
//              CARDS
//
/////////////////////////////////////////////////////////////

/////////////////   BOTON 1   ///////////////////////////////
void boton1_Callback(Control* sender, int type)
{
    switch (type)
    {
    case B_DOWN:
        Serial.println("Button DOWN");
        //SaveLEDToEEPROM();
        SAVEtoNVS();
        break;

    case B_UP:
        Serial.println("Button UP");
        break;
    }
}

void boton2_Callback(Control* sender, int type)
{
    switch (type)
    {
    case B_DOWN:
        Serial.println("Button DOWN");
        break;

    case B_UP:
        Serial.println("Button UP");
        ESP.restart(); // Restart ESP
        break;
    }
}

//Most elements in this test UI are assigned this generic callback which prints some
//basic information. Event types are defined in ESPUI.h
void generalCallback(Control *sender, int type) {
  Serial.print("CB: id(");
  Serial.print(sender->id);
  Serial.print(") Type(");
  Serial.print(type);
  Serial.print(") '");
  Serial.print(sender->label);
  Serial.print("' = ");
  Serial.println(sender->value);
  
  switch (sender->id)
  {
    case 4:
     Serial.println("rele 1");
    break;
    
    case 5:
     Serial.println("rele 2");
    break;
    
    case 14:    // MODO LUZ
     if (String(sender->value)==("MODO AUTO")) {(modo_luz = 1);}
     if (String(sender->value)==("MODO ON")) {(modo_luz = 2);}
     if (String(sender->value)==("MODO OFF")) {(modo_luz = 3);}
     Serial.print("Modo Luz: ");
     Serial.println(modo_luz);
    break;
    
    case 18: // caso de hora luz ON
    {
    //Convert the hours. Rely on the fact that it will stop converting when it hits the :
    luz_on_hora = sender->value.toInt();
    //Look for the : 
   char *mins_str = strstr(sender->value.c_str(), ":");
   //strstr returns a pointer to where the : was found. Increment past it.
   mins_str += 1;
   //And finally convert the rest of the string.
   luz_on_minuto = String(mins_str).toInt();
   Serial.print("Luz ON numMins: ");
   Serial.println(NumMins(luz_on_hora,luz_on_minuto));
    break;
    }
    
    case 19:  // caso de hora Luz OFF
    {
    //Convert the hours. Rely on the fact that it will stop converting when it hits the :
    luz_off_hora = sender->value.toInt();
    //Look for the : 
   char *mins_str = strstr(sender->value.c_str(), ":");
   //strstr returns a pointer to where the : was found. Increment past it.
   mins_str += 1;
   //And finally convert the rest of the string.
   luz_off_minuto = String(mins_str).toInt();
   Serial.print("Luz OFF NumMins: ");
   Serial.println(NumMins(luz_off_hora,luz_off_minuto));
   break;
  }
    case 20:  // caso de temperatura del agua deseada
    {
    temp_agua_des = sender->value.toInt();
    Serial.print("Temp agua deseada: ");
    Serial.println(temp_agua_des);
    break;
    }
  }
}

void numberCall(Control* sender, int type)
{
    Serial.println(sender->value);
}

void padExample(Control* sender, int value)
{
    switch (value)
    {
    case P_LEFT_DOWN:
        Serial.print("left down");
        break;

    case P_LEFT_UP:
        Serial.print("left up");
        break;

    case P_RIGHT_DOWN:
        Serial.print("right down");
        break;

    case P_RIGHT_UP:
        Serial.print("right up");
        break;

    case P_FOR_DOWN:
        Serial.print("for down");
        break;

    case P_FOR_UP:
        Serial.print("for up");
        break;

    case P_BACK_DOWN:
        Serial.print("back down");
        break;

    case P_BACK_UP:
        Serial.print("back up");
        break;

    case P_CENTER_DOWN:
        Serial.print("center down");
        break;

    case P_CENTER_UP:
        Serial.print("center up");
        break;
    }

    Serial.print(" ");
    Serial.println(sender->id);
}

void enterWifiDetailsCallback(Control *sender, int type) {
  if(type == B_UP) {
    Serial.println("Saving credentials to NVS...");
    Serial.println(ESPUI.getControl(wifi_ssid_text)->value);
    Serial.println(ESPUI.getControl(wifi_pass_text)->value);

    nvs.putString("ssid", (ESPUI.getControl(wifi_ssid_text)->value)); 
    nvs.putString("password", (ESPUI.getControl(wifi_pass_text)->value));
    Serial.println("Network Credentials Saved using Preferences");
    nvs.end();
  }
}

void textCallback(Control *sender, int type) {
  //This callback is needed to handle the changed values, even though it doesn't do anything itself.
}
///////////////////////////////////////////////////////////////////////
// FUNCION PARA PASAR LAS HORAS A MINUTOS Y ASI PODER GESTIONAR MEJOR LOS TEMPORIZADORES
int NumMins(uint8_t ScheduleHour, uint8_t ScheduleMinute)
{
  return (ScheduleHour*60) + ScheduleMinute;
}
