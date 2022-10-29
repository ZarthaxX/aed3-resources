# Solucion

## (a)
- Consideremos el grafo $D^{-1}$, con todas las direcciones de sus aristas invertidas:
- Definimos la funcion recursiva $d: V(D) \arrow Z$ tal que d(w):
- 0 si w = v
- por cada vecino z a w, calculo su d(z) + costo arista (w,z), y me quedo con la minima de todas estas
  - como el grafo es conexo, no necesito definir el caso donde no hay vecinos, porque siempre es alcanzable w desde v

## (b)
Puedo usar la definicion anterior, y lo que agrego como memoizacion es una tabla por cada estado $w$.
- Cada vez que en la funcion recursiva quiera calcular el $d(w)$, chequeo si lo calcule antes y evito hacerlo devuelta
- Como hay $n$ nodos, entonces la complejidad de la funcion recursiva va a ser $O(n + m)$, porque calculo las $n$ distancias a lo sumo y tengo que ver todas las aristas $m$.
- Notar que esta funcion eventualmente calculo camino minimo a todo nodo desde $v$ en la misma complejidad, cuando termino llamandola para todos los nodos.
