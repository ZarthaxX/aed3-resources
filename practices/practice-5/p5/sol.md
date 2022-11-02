# Solucion

## (a)
Tomas el digrafo origina l $G$, y le asignas capacidad 1 a las aristas. Luego el maximo flujo va a representar la maxima cantidad de caminos disjuntos en aristas.

## (b)
La unidad de flujo representa un camino de s a t. La restriccion de capacidad representa que 2 caminos no pueden compartir ninguna arista.

## (c)
Esto se puede ver rapidamente por induccion:
- Caso base con flujo 1, simplemente sigo el camino de la unidad de flujo y llego de s a t, asi que tengo 1 camino.
- Paso inductivo con n de flujo: Puedo sacar igual que antes un camino de s a t que se forma siguiendo aristas con flujo 1 asignado. Al sacarlo me queda flujo n-1, por las propiedades del flujo. Luego por HI esto tiene n-1 caminos disjuntos. Como el camino que saque no comparte aristas con estos tengo n caminos disjuntos.

## (d)
Complejidad = $O(nm^2)$
