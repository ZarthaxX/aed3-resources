# Solucion

Tenemos 2 caminos distintos, que no necesariamente son disjuntos completamente en vertices:
- $P = v_0, ..., v_p$
- $Q = w_0, ..., w_q$

Donde $v_0 = w_0 = v$ y $v_p = w_q = w$.

Si ambos caminos $P$ y $Q$ no comparten vertices (ademas de $v$ y $w$), entonces podemos definir al ciclo como:

$C = v_0, ..., v_p, w_{q-1}, ..., w_0$

Si comparten al menos un vertice, lo que podemos hacer es:

- Tomar el minimo $i$ tal que en $P$ tenemos que $v_i \not\in Q$. Sabemos que existe porque $P$ y $Q$ son caminos distintos. A su vez sabemos que $v_{i-1}$ esta bien definido, porque el primer vertice de $P$ y $Q$ es el mismo, asi que como minimo puede pasar que $v_{i-1} = v$ si $i = 1$. 
- Luego tomamos el minimo $j$ tal que $i < j$ y en $P$ vale $v_j \in Q$. Esto tambien existe ya que $P$ y $Q$ comparten $w$, asi que a lo sumo $j = p$.

Tenemos entonces el siguiente subcamino $v_{i-1}, ..., v_{j}$ en $P$, donde el primer y ultimo vertice estan en $Q$, y los vertices intermedios no, por como lo construimos.

Ahora podemos tomar un subcamino de $Q$, a partir de este subcamino, partiendo desde $w_a = v_j$  hasta $w_b = v_{i-1}$. El subcamino $w_b, ..., w_a$ no contiene ningun vertice $w_k$ (si no consideramos a $w_b$ y $w_a$) tal que esta en el subcamino de $P$ que encontramos previamente. 
Esto es asi porque $P$ fue construido especialmente para no compartir vertices con $Q$, mas alla de los extremos.

Por lo tanto, si consideramos el camino $v_{i-1}, ..., v_{j}, w_{a+1}, ..., w_b$ obtenemos el circuito que queriamos, ya que $v_{i-1} = w_b$.

> Nota: Probablemente este argumento funcionaba para el caso donde los caminos eran disjuntos tambien, y no era necesario argumentarlo aparte ese caso.