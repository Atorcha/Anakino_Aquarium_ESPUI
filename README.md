# Anakino_Aquarium_ESPUI

## Instrucciones de instalacion.

Seleccionar la placa ESP32 DEVMODULE

## MODO AP
La primera vez que se instale el software, el esp32 crea un red wifi. Nos conectamos a ella e introducimos la IP 192.168.4.1 en el navefador y nos dará la opcion de añadir el nombre SSID y la contraseña de la red a la que queremos conectar el controlador. Importante pulsar ENTER despues de introducir cada valor y luego darle a GRABAR.
## MODO CLIENTE
En el monitor serial podemos ver la IP que le ha asignado el router. Puede ser conveniente dejarla fija para poder acceder a ella desde fuera de casa mediante algun servicio DDNS gratuito.

El usuario por defecto para el login es Anakin y la contraseña es 123456 Se puede cambiar en el código en la última linea del archivo SETUP. De todos modos estoy trabajando en la posibilidad de cambiarlo y que se grabe en la memoria interna.


## Actualizacion

Se ha añadido la opción de actualizar el codigo sin necesidad de tener que conectar el PC al ESP32. Directamente dándole al botón UPDATE de la pestaña CONFIGURACION, automáticamente descargará el nuevo FIRMWARE y mantendrá todas las configuraciones.
