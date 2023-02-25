

void check_time()
{
    //timeClient.update();

    realtime = timeClient.getFormattedTime();
    th = timeClient.getHours(); // asigna a th la hora
    tm = timeClient.getMinutes(); // asigna a tm el minuto
    ESPUI.updateLabel(realtime_LabelId, realtime);
}
