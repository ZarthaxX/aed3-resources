# Solucion

Supongamos por el absurdo que esto no pasa, sino que tienen todos sus vertices de distinto grado.

Tomemos a un grafo que cumple esto y llamemoslo $G = (V,E)$. Sin perdida de generalidad, tomemos al $a \in V$ tal que $d(a) = n-1$, y a $b \in V$ tal que $d(b) = 0$.
Esto ocurre porque como todos tienen grado distinto, y hay n vertices, uno tiene $n-1$ y otro $0$. 

Ahora, como el vertice $a$ tiene grado $n-1$, necesariamente esta conectado a todos los demas vertices en $G$, en particular, a $b$. Por lo tanto, $d(b) > 0$ necesariamente, pero habiamos supuesto que era 0, porque el grado de todos los vertices era distinto.
Esto es un absurdo que provino de suponer que todos los grados de los verticed de $G$ eran distintos. Por lo tanto esto es falso y vale que deben existir al menos 2 vertices en $G$ que tengan el mismo grado.
