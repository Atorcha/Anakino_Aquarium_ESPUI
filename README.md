# Anakino_Aquarium_ESPUI

## Componentes utilizados

- ESP32 y la placa de expansion ( ESP32 TYPE-C, USB, CH340C, WiFi + Bluetooth https://a.aliexpress.com/_EuOpbz7 )
- DES18B20 y módulo sensor (  https://a.aliexpress.com/_EvZ7Wb7 )
- Reles Solidos ( estos reles no hace ruido cuando abren o cierran: https://a.aliexpress.com/_EJaN06h )





## Instrucciones de utilización.

Seleccionar la placa ESP32 DEVMODULE
## Configuración

La primera vez, el esp32 crea un red wifi. Nos conectamos a ella e introducimos 192.168.4.1 en un navegador web. Ahi debemos introducir el nombre de la red y la contraseña de la misma (SSID y PASS) ES IMPORTANTE PULSAR ENTER CUANDO SE INTRODUCEN LOS DATOS, PARA QUE SE GUARDEN.
Posteriormente reiniciará y se conectará a la red configurada. En el monitor serial podemos ver la IP que le ha asignado el router. Es recomendable asignarle una IP fija.

Desde monitor serial podemos confirmar los parámetros guardados en la NVS 

## UPDATE
Se se ha activado la actualizacion via desde internet del firmware. Solamente hay que pulsar el botón UPDATE y esperar. Estoy pendiente de mostrar la version en el web del controlador para saber cual es la que tenemos instalada en ése momento.

## TO DO

- 


## VERSIONS
- 24.01.17 Añadida la opción de modificar el user y el pass del login al panel. Por defecto es Anakin y 1234
- 24.01.18 Reparada actualizacion y modificacion codigo update
- 24.02.00 mejora de los paneles de info y configuracion revisado codigo para limpieza 
  
## Contacto
Hay un grupo de telegram sobre el proyecto para aclarar dudas: https://t.me/Anakino_aquarium
