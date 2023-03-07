# Proyecto Integrador
# Qt + QML

Los comandos AT son un protocolo de comunicación ampliamente utilizado en comunicación serial, principalmente por módems.
Consisten en cadenas de caracteres (ASCII), que tienen varias formas:

AT+COMANDO
ATCOMANDO
AT?COMANDO
etc.

Usted debe implementar en C++, utilizando el Framework Qt, un software que se comunique mediante comandos AT, a través de un puerto serie, con una aplicación que genera señales.

El protocolo que debe implementar tiene los siguientes comandos:<br>
<b>AT+SIGNALS=?   	</b>: Devuelve una lista con las señales disponibles, en el formato AT+señal.<br>
<b>AT+CURR		      </b>: Informa la señal actual que se está enviando, en el formato AT+señal.<br>
<b>AT+SIGNAL=señal	</b>: Establece la señal a enviar. Responde AT+OK.<br>
<b>AT+START		      </b>: Inicia el envío de datos. Responde AT+OK.<br>
vAT+STOP		        </b>: Detiene el envío de datos. Responde AT+OK.<br>
<b>AT+MAX	        	</b>: Informa el valor numérico máximo que tienen los datos con el formato AT+VALUE=valor.<br>
<b>AT+MIN		        </b>: Informa el valor numérico mínimo que tienen los datos con el formato AT+VALUE=valor.<br>
Si el comando es incorrecto, responde AT+ERROR.
Los datos se reciben con el formato AT+VALUE=valor.

La aplicación se encuentra disponible para su descarga en Glodu.

El software que desarrolle debe:
a) Pedir a la aplicación la lista con las señales disponibles, y presentárselas al usuario, generando dinámicamente un botón para cada señal.

b) Haciendo uso de los botones generados en a), debe solicitar a la aplicación que comience el envío de datos para la señal correspondiente.

c) Debe existir un botón que le permita al usuario preguntarle a la aplicación qué señal se está enviando.

d) Graficar la señal recibida, online.

e) Debe existir un botón para frenar el envío de datos.

1- Implementar una interfaz basada en Widgets y C++, graficando la señal con OpenGL.
2- Haciendo la menor cantidad de cambios posibles, reimplementar la interfaz, esta vez con QML.

El software debe estar bien diseñado, con una clara división entre frontend y backend, que permita cambiar la interfaz de manera más sencilla.
