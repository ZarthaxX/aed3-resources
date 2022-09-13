# Solucion

Demostremos por un lado que se puede construir al menos un grafo orientado que cumpla esto, y luego que es unico para cada $n$.

## Construccion
Podemos pensarlo inductivamente, planteando que sabemos que existe un grafo orientado para $n$, y lo extendemos a $n+1$.

### Caso base
Tenemos $n = 1$, entonces podemos poner un nodo $v$ sin aristas a si mismo. Esto cumple que es un grafo orientado porque no hay aristas directamente, y todos sus vertices tienen $d_{out}$ distinto, en particular solo $v$ que tiene $0$.

### Paso inductivo
Supongamos que vale que tenemos un grafo orientado $G = (V, E)$ con $n$ vertices que cumple nuestra HI. 
Veamos como extenderlo a $n+1$ y que siga siendo un grafo orientado con todos sus vertices con grado de salida distintos.

Tomamos $G$ y nos construimos un $G' = (V', E')$ tal que $V' = V + v$, donde $v$ es el nuevo vertice que agregamos, y $E'$ es $E$ mas algunas aristas que agregamos.
Las nuevas aristas que agregamos son de la forma $(a, v)$, con $a \in V$ y $v$ el vertice nuevo.

Como $G$ cumplia nuestra HI, sabemos que todos los grados de salida de los vertices en V eran distintos. Lo que hicimos ahora es agregar una nueva arista que sale de cada uno de estos a $v$, entonces le sumamos a todos 1 en su grado de salida, por lo que siguen siendo todos distintos.
A su vez, como sumamos un nuevo vertice, y ninguna arista comienza de el, este tiene grado de salida 0, y como los demas tienen 1 arista mas, necesariamente tienen $d_out(a) > 0$.

Faltaria ver que queda un grafo orientado, pero eso ocurre ya que $G$ era orientado, y solo agregamos aristas entre los vertices de $G$ y $v$, y como $v$ no tiene aristas que salen de el, no puede existir a su vez:
$(a, v)$ y $(v, a)$. 