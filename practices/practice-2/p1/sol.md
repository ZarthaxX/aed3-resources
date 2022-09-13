# Solucion
Resolvemos por induccion, tomando como HI:

> Dado un digrafo $D = (V, E)$ con $m = |E(D)|$ aristas, vale que:
> $\sum_{v \in V(D)} d_{in}(v)$ = $\sum_{v \in V(D)} d_{out}(v)$ = $|E(D)|$

# Caso base
Tomamos  $D = (V, H)$ con $m = |E(D)| = 1$. Como $m = 1$, tenemos una sola arista $(a,b)$, y por lo tanto vale que:
- $d_{out}(a) = 1$
- $d_{in}(b) = 1$

Y para todo otro $v \in V, v \neq a, v \neq b$ vale que:
- $d_{out}(a) = 0$
- $d_{in}(b) = 0$

Por lo tanto tenemos:
$\sum_{v \in V(D)} d_{in}(v)$ = $\sum_{v \in V(D)} d_{out}(v)$ = $|E(D)| = 1$

# Paso inductivo
Suponemos que vale la HI para $m - 1$, y queremos ver que un digrafo D con $m = |E(D)|$ tiene:

$\sum_{v \in V(D)} d_{in}(v)$ = $\sum_{v \in V(D)} d_{out}(v)$ = $|E(D)|$


Tomemos una arista $(a,b)\in E(D)$, y saquemosla de D, de tal manera que terminamos con un digrafo $D' = (V, E - (a,b))$.
Como $m - 1 = |E(D')|$, podemos aplicar la HI y tenemos que:

$\sum_{v \in V(D')} d_{in}(v)$ = $\sum_{v \in V(D')} d_{out}(v)$ = $|E(D')| = m-1$

Podemos reformular lo anterior para distinguir el grado de salida de $a$ y el de entrada de $b$:

$d_{in}(b) + \sum_{v \in V(D'), v \neq b } d_{in}(v) = d_{out}(a) + \sum_{v \in V(D'), v \neq a} d_{out}(v) = |E(D')| = m-1$

Ahora, si le agregamos a D' la arista (a,b) que le sacamos, volvemos a tener $D$, y el d_{out}(a) se incrementara en 1, asi como el d_{in}(b), y nos queda:

$d_{in}(b) + 1 + \sum_{v \in V(D), v \neq b } d_{in}(v) = d_{out}(a) + 1 + \sum_{v \in V(D), v \neq a} d_{out}(v) = |E(D)| = m$

Que es lo que queriamos probar.