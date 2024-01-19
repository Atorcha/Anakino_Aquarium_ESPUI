# Anakino_Aquarium_ESPUI

## Instrucciones de utilización.

Seleccionar la placa ESP32 DEVMODULE
## Configuración

La primera vez, el esp32 crea un red wifi. Nos conectamos a ella e introducimos 192.168.4.1 en un navegador web. Ahi debemos introducir el nombre de la red y la contraseña de la misma (SSID y PASS) ES IMPORTANTE PULSAR ENTER CUANDO SE INTRODUCEN LOS DATOS, PARA QUE SE GUARDEN.
Posteriormente reiniciará y se conectará a la red configurada. En el monitor serial podemos ver la IP que le ha asignado el router. Es recomendable asignarle una IP fija.

Desde monitor serial podemos confirmar los parámetros guardados en la NVS 

## UPDATE
Se se ha activado la actualizacion via desde internet del firmware. Solamente hay que pulsar el botón UPDATE y esperar. Estoy pendiente de mostrar la version en el web del controlador para saber cual es la que tenemos instalada en ése momento.

## TO DO

- Ajuste temperatura con un decimal.


## VERSIONS
- 24.01.17 Añadida la opción de modificar el user y el pass del login al panel. Por defecto es Anakin y 1234
- 24.01.18 Reparada actualizacion y modificacion codigo update
  

