# Solucion

Podemos definir los siguientes pasos para construir la lista de adyacencia, suponiendo que como entrada tenemos:
- $n$: La cantidad de vertices.
- $m$: La cantidad de aristas.
- $m$ pares $(a,b)$: Cada arista del grafo $G$, con sus 2 extremos $a$ y $b$.

Algoritmo:
- Inicializar la lista de $n$ posiciones donde vamos a guardar cada lista de adyacencia para cada vertice. Esto tiene complejidad $O(n)$.
- Por cada arista $(a,b)$ vamos a la lista de adyacencia de $a$ y de $b$, y guardamos en cada caso el otro vertice con el que conecta, que seria $b$ y $a$ respectivamente.
  - Buscar la posicion de cada lista es $O(1)$.
  - Insertar en cada lista tiene costo $O(1)$.
  
  En total tenemos costo $O(m)$.

Entre ambos pasos tenemos un costo total de $O(n + m)$.