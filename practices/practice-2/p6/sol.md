# Solucion

Supongamos que esto no ocurre y que los 2 caminos, llamemoslos $P$ y $Q$, son disjuntos en vertices.

Como sabemos que el grafo es conexo, podemos definir un camino minimo en el grafo $R = (p, r_1, ..., r_n, q)$ tal que $p$ esta en $P$, y $q$ en $Q$. 
Este camino $R$ contiene vertices que no estan en ninguno de los 2 caminos, exceptuando los extremos.
Por lo tanto, podemos definirnos un nuevo camino $S$, tal que:
- $S$ tenga la porcion del camino $P = $(v_1, ..., p, ..., v_n)$ que termine en $p$ mas larga, ya sea $(v_1, ..., p)$ o $(p, ..., v_n)$.
- Repito el mismo argumento para $Q = $(w_1, ..., q, ..., w_n)$, quedandome con el camino mas largo de $(w_1, ..., q)$ o $(q, ..., w_n)$.
- $S$ tiene el camino minimo $R$ que une a $p$ y $q$

Sin perdida de generalidad supongamos que $S$ queda definido como $S = (v_1, ..., p, r_1, ..., r_n, q, ..., w_n)$.
Resta ver que este nuevo camino $S$ es mas largo que $P$ y $Q$.
En efecto, como $S$ tiene el subcamino mas grande de $P$ y de $Q$, necesariamente es al menos igual en largo que $P$ y $Q$. 
Pero ademas, como se le agrega el camino minimo entre $p$ y $q$, es un camino mas largo que estos dos.
Por lo tanto, $P$ y $Q$ no son caminos maximos, lo cual contradice la hipotesis, un absurdo. Esto surgio de suponer que los 2 caminos $P$ y $Q$ no compartian un vertice.
Entonces $P$ y $Q$ comparten al menos un vertice.