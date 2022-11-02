# Solucion

## (a)
Planteamos el siguiente modelo:

[Dibujo del flujo](flow.png)

Donde tenemos:
- Aristas que salen de $s$ y van a un $f_i$ con capacidad $f_i$, que representan la cantidad de solteros de la familia $i$ a asignar.
- Aristas que salen de una familia $f_i$ y van a una mesa $m_j$ con capacidad $c_{ij}$, que representan la cantidad maxima de solteros de la familia $i$ que pueden asignarse en la mesa $j$
- Aristas que salen de una mesa $m_j$ y van a $t$, que representan la cantidad de solteros maxima que puede asignarse a esa mesa $j$.

Con esto, decimos que existe una asignacion si el flujo maximo es igual a la sumatoria de todos los solteros de todas las familias.

## (b)
- La unidad de flujo representa una asignacion de un soltero a una mesa
- La restriccion de capacidad en cada caso representa:
  - La cantidad de solteros disponibles para asignar para una familia
  - La cantidad de solteros maxima que puede asignarse de una familia a una cierta mesa
  - La cantidad de solteros maxima asignable a una mesa

