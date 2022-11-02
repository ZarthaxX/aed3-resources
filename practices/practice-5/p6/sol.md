# Solucion

## (a)
Tomamos los vertices de $G$ y los duplicamos, teniendo asi por cada $v$ un $v_{in}$ y $v_{out}$. Las aristas seran las siguientes:
- Para cada $v_{in}$ sale una arista a su respectivo $v_{out}$ con capacidad 1, exceptuando a $s$ y $t$, estas se mantienen igual.
- Para cada $v_{out}$ sale una arista al $w_{in}$ con capacidad infinito si y solo si en $G$ existia la arista $(v,w)$.

El flujo maximo en este modelo nos da la maxima cantidad de caminos disjuntos en aristas.

## (b)
Cada unidad de flujo representa un camino de $s$ a $t$.

Cada capacidad representa:
- En el caso de las aristas $(v_{in},v_{out})$ la maxima cantidad de caminos que pueden compartir ese vertice $v$
- En el caso de las demas aristas la capacidad representa que se puede usar esa arista todas las veces que se quiera (por eso infinito). Aunque por la restriccion anterior solo va a poder pasar 1 de flujo por ellas de cualquier forma.

## (c)

El modelo es correcto porque es facil ver que 2 caminos no pueden compartir ningun vertice, ya que si lo hicieran en $G$, entonces en nuestro modelo pasarian por la arista $(v_{in},v_{out})$ 2 veces, osea que tendria 2 de flujo minimo. Esto no puede pasar porque la capacidad de ellas es 1.

## (d)

Tenemos $O(2*n)$ vertices, y $m$ aristas, por lo que la complejidad queda $O(nm^2)$
