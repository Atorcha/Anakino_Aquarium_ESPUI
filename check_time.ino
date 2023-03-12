

void check_time()
{
    realtime = timeClient.getFormattedTime();
    ESPUI.updateLabel(realtime_LabelId, realtime);
    th = timeClient.getHours(); // asigna a th la hora
    tm = timeClient.getMinutes(); // asigna a tm el minuto
    
}
