/*
 * Por partes... 
 * La versión del xbee es la VERSION:2.0-20100601
 * Nombre del dispositivo XBEE
 * 
 * Qué había pasado? 
 * Pues el dispositivo estaba como master, y como tal, no permitía que se le pudiera conectar nadie, 
 * ya que sólo podía conectarse él con otro dispositivo. Se ha pasado a slave y ya es reconocible. 
 * 
 * 
 * 
 * 
 * ¿Como se configura?
 * 
 * Lanzar el sketch
 * 
 * conectar los pines 
 *   RX (USB Esplorer ) -> D10 (arduino)
 *   TX (USB Esplorer ) -> D11 (arduino)
 * 
 * Una vez conectados, hay que entrar en modo AT, para ello, lo que he hecho ha sido juntar las dos puntas
 * de un mismo cable en el pin de voltaje durante 1 segundo y ha cambiado a modo AT
 * 
 * Probar comandos AT
 * 
 * AT -> OK (Está conectado) 
 * 
 * Aquí es con la ayuda del documento word de los comandos AT donde podemos cambiar la configuración.
 * 
 * Cuando hayamos acabado lanzamos AT+STATE para ver en que estado estamos, normalmente “INITIALIZED”
 * 
 * Entonces, para poder arrancar y empezar a trabajar con el XBEE sólo hay que lanzar el comando 
 * 
 * AT+INIT
 * 
 * Habrá pasado de parpadear una vez cada dos segundos a un parpadeo rápido.
 * 
 * Ya lo podremos encontrar con el móvil.
 * 
 * 
 * PDF de la configuración
 * https://cdn.instructables.com/ORIG/FKY/Z0UT/HX7OYY7I/FKYZ0UTHX7OYY7I.pdf
 * 
*/

#include <SoftwareSerial.h>

SoftwareSerial mySerial(2,3); // RX, TX

void setup() {

Serial.begin(9600);

pinMode(9,OUTPUT); digitalWrite(9,HIGH);

Serial.println("Enter AT commands:");

mySerial.begin(38400);

}

void loop()

{

if (mySerial.available())

Serial.write(mySerial.read());

if (Serial.available())

mySerial.write(Serial.read());

}
