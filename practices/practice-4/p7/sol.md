a)

Modelamos un grafo que tiene 2n nodos, 2 por cada cabina. 
- El nodo $v_{i}^{in}$ que representa la entrada a la cabina $i$.
- El nodo $v_{i}^{out}$ que representa pasar por la cabina $i$ y estar del otro lado.

Ahora lo que hacemos es poner los pesos:
- Si tenemos costo $c_{ij}$ de viajar de forma directa, entonces ponemos la arista con ese peso desde $v_{i}^{out}$ a $v_{j}^{in}$. Osea, desde la salida de la cabina i a la entrada de la cabina j.
- Si tenemos el costo $c_i$ para transitar por una cabina, ponemos la arista con ese peso desde $v_{i}^{in}$ a $v_{i}^{out}$.

b)

Corres bellman ford y estas, detectas un ciclo negativo y tenes las cabinas involucradas.

c)

Cambias el modelo, ya que ahora depende si estas en una cabina despues de haber pasado por otra que pagaste o te pagaron.

La idea es tomar el modelo anterior, y cambiar los nodos asociados a cabinas inversas.

Seria basicamente otro indice mas sumado al que agregamos antes. Las aristas ahora se definen casi igual al anterior, pero con esta diferencia:
- La arista que simboliza pagar el peaje se mantiene igual yendo desde la entrada de un nodo (cabina) a la salida del mismo, sin hacer una transicion entre la entrada de una cabina que pago antes y despues no o viceversa, deberia ser el in y out que haya pagado / que no haya pagado. El peso de la arista va a ser positivo si el tipo de cabina es en la que se paga, o negativo si es la version donde no se paga.
- La arista que va entre 2 cabinas esa si cambia. Ahora ponemos esa arista entre todo par de cabina out y cabina in si estas difieren en el nuevo indice. Osea, solo puedo viajar de una salida de cabina que se pago a una que no se pago o viceversa.