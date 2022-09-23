# Solucion

## c
Pasos de algoritmo:
- correr DFS desde un vertice para generar 2 listas:
  - lista donde para cada vertice nos dice el padre
  - lista donde para cada vertice nos dice la profundidad
- iterar todas las aristas:
  - chequeamos si los 2 extremos estan a profunidades distintas (seria par e impar)
- si en el paso anterior todas las aristas satisfacieron la condicion, podemos armar:
  - V: vertices a profundidad par
  - W: vertices a profundidad impar
- si en el paso anterior una arista no cumplio la condicion, encontramos ciclo impar:
  - tomamos los extremo v y w de esa arista que no cumplio (v,w)
  - subimos por cada uno hacia el padre y vamos guardando los vertices que recorremos
  - terminamos con la lista de vertices que empiezan en v y w respectivamente y terminan en la misma raiz
  - este seria el ciclo impar si unimos estos 2 caminos