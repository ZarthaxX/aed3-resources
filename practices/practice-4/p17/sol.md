# Solucion

Planteas grafo dirigido $G$:
- Los vertices son todos los montos posibles de $1,\dots,v$
- Las aristas son las transiciones de un $v$ a un $w$ tal que puedo llegar a el sumando uno de los $w_i$. Le pongo costo 1 siempre.

Me queda un DAG, y puedo correr el algoritmo del ej 16 que me computa el camino minimo desde 1 hasta $v$ en $O(n+m) = O(v+vk) = O(vk)$
¿Por que queda un DAG? Si no quedara un DAG entonces tendria un ciclo, y eso significaria que empece en un cierto monto $w$ y volvi al mismo luego de sumarle algunas monedas, lo cual no tiene sentido.