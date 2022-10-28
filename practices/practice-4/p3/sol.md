
3
hago un G’ que tenga 3 capas:
Primer capa G1 identico a G pero que en cada nodo donde sale una arista de peso negativo traiciona al nodo equivalente pero en la capa 2 G2
Segunda capa G2 que hace lo mismo que la anterior, pero transiciona a la capa G3
La capa G3 es como G, no tiene transiciones a ningun lado

corremos djikstra sobre esto, y vemos si existe un camino desde:
s a t en G1 o s a t en G2
Si no existe en ninguno de estos, entonces seguro existe en G3 y no es valido, porque para estar en G3 hizo 2 saltos por aristas negativas si o si

