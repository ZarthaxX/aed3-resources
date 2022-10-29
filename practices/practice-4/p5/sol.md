# Solucion

Nos armamos el grafo $P$ tal que:
- Tiene todos los vertices de $P$
- Tiene todas las aristas st-eficientes de $G$

Por construccion, $P$ tiene todos los caminos minimos de $s$ a $t$, ya que tiene todas las aristas que forman parte de algun camino minimo.
Ahora, podemos encontrar las aristas puentes de este grafo $P$ y esas van a ser las criticas de $G$. Veamos que esto vale en este grafo como un si solo si

# $\implies$)
Si $(v,w)$ es puente en $P$, entonces no existe un camino minimo que llegue de $s$ a $t$ al sacarla. Seguro me aumenta el costo (o desconecta el grafo original), entonces es critica en $G$.

# $\impliedby$)
Si una arista es critica en $G$, significa que si la saco el costo minimo aumenta. Eso significa que los caminos minimos que iban de $s$ a $t$ pasaban siempre por esta arista, porque sino podria pasar por otro lado y seguir siendo minimo, pero el costo sabemos que aumento por ser critica.

Luego, como nuestro $P$ tiene los caminos minimos unicamente de $s$ a $t$, seguro que si saco esta arista critica desconecto el grafo $P$, por lo dicho previamente. Entonces esta arista es puente en $P$, y terminamos.