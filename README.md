# Anakino_Aquarium_ESPUI

## Instrucciones de utilización.

Seleccionar la placa ESP32 DEVMODULE
## Configuración

La primera vez, el esp32 crea un red wifi. Nos conectamos a ella e introducimos 192.168.4.1 en un navegador web. Ahi debemos introducir el nombre de la red y la contraseña de la misma (SSID y PASS) ES IMPORTANTE PULSAR ENTER CUANDO SE INTRODUCEN LOS DATOS, PARA QUE SE GUARDEN.
Posteriormente reiniciará y se conectará a la red configurada. En el monitor serial podemos ver la IP que le ha asignado el router. Es recomendable asignarle una IP fija.

El usuario es Anakin y la contraseña es 123456 Se puede cambiar el el código en la última linea del archivo SETUP. Hay que tener en cuenta que de momento cada vez que actualice el firm se volverá a poner el usuario y la contraseña por defecto. 

## UPDATE
Se se ha activado la actualizacion via desde internet del firmware. Solamente hay que pulsar el botón UPDATE y esperar. Estoy pendiente de mostrar la version en el web del controlador para saber cual es la que tenemos instalada en ése momento.

## TO DO

- modificar el usuario y la contraseña de acceso desde el panel.
  

