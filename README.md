
**Tiempo estimado y empleado:**
Estimaba todo el proceso en 20h, y ha sido realizado en 9h.
La gran mayoría (~7h) ha sido aprendizaje con tutoriales y búsqueda de información.
El resto análisis de código, documentación y crear/compartir el sketch final.


**Problemas y dificultades:**
 * Determinar si con la librería de Adafruit podía obtener el resultado deseado.
 * Comprender el funcionamiento de los waypoints y navegación por GPS, y si eran la mejor solución.


**Pasos seguidos:**

1.- Recopilar información. 

Leída la documentación y el tutorial oficial.

En el tutorial oficial encuentro un enlace para comprender mejor los tipos de mensaje NMEA.
( http://aprs.gids.nl/nmea/ )

En la guía de referencia NMEA leo sobre “waypoints” y realizo una búsqueda en Google sobre “gps waypoints”, donde encuentro como respuesta “a single specific location".
( http://www.gpsreview.net/waypoints/ )

Volviendo al tutorial oficial, veo que la librería oficial de Adafruit solo analiza mensajes GGA y RMC, y no hay referencia a los relacionados con waypoints.

Reviso el código de la librería, buscando la implementación del parser, para una posible extensión.

Detecto que toda la librería esta contenida en un único cpp con su archivo de cabeceras, y que el parser esta lejos de una implementación ideal (cadena de if-else buscando match con los strings pertinentes) en lugar de una alternativa más flexible (Strategy + Factory patterns).



2.- Evaluar la situación y opciones posibles.

No tengo claro si un waypoint es la solución que busco. Tampoco sé como establecerlo.

En cuanto a la implementación, tengo 3 alternativas:

1) Refactorizar y extender la librería oficial de Adafruit -> dado el escaso tiempo y mi falta de conocimiento en la materia, descarto esta posibilidad.
2) Buscar una librería más extensa.
3) Ignorar la existencia de waypoints y, usando la librería oficial, determinar si la posición que detecta el GPS es cercana a una latitud y longitud establecidos manualmente en constantes, realizando la pertinente conversión a metros.

Intento la opción 2 de momento, dejando la opción 3 como fallback si no consigo encontrar nada.




3.- Búsqueda de tutoriales, librerías e información sobre el caso concreto.

Busco en google: "adafruit gps set waypoint" donde veo de nuevo el tutorial oficial en formato PDF
( https://cdn-learn.adafruit.com/downloads/pdf/adafruit-ultimate-gps.pdf )
Este PDF contiene enlaces a tutoriales, uno de ellos habla de la relación entre waypoints y navegación/rutas.
( https://www.trimble.com/gps_tutorial/gpswork-nav.aspx )

La búsqueda también me lleva hasta un tutorial sobre programar un rover con posicionamiento GPS
( https://sites.google.com/site/wayneholder/self-driving-rc-car/getting-from-point-a-to-point-b )
donde leo más acerca de calcular la distancia entre 2 puntos GPS.


Vuelvo a repasar el concepto de waypoint tras caer en la cuenta de que para decirle al GPS un punto especifico, necesito saber las coordenadas de ese punto, por lo que quizá la opción 3 no es tan descabellada.

Realizo una batería de búsquedas: “adafruit ultimate gps library”, “arduino gps navigation”, “adafruit ultimate gps set waypoint” y encuentro en la última un tutorial de Make.
( https://makezine.com/projects/make-37/gps/ )

En este tutorial de utilizan la librería TinyGPS++ 
( https://github.com/mikalhart/TinyGPSPlus/releases )

Encuentro en la parte "Sketch 3: Finding Your Way" del tutorial un ejemplo muy cercano a lo que intento conseguir, y se parece realmente al objetivo de la opción 3.

Finalmente opto por este tutorial y la opción 3, implementándola en un sketch de arduino.






