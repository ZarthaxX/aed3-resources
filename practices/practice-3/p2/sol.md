# Solucion

## Inciso A
Demostramos ambas implicaciones

### $\implies$)
Tenemos que vale que $vw$ es puente en $G$, y queremos probar que esto implica que no pertenece a ningun ciclo de $G$.

Vamos por el absurdo y supongamos que $vw$ pertenece a un ciclo $C$. Este ciclo es de la forma $k_1,...,v,w,...,k_n,k_1$.

Saquesmosle ahora a $G$ la arista $(v,w)$, y observemos que podemos definir el camino $w,...,k_n,k_1,...,v$ que existe porque teniamos a $C$ en $G$. Por lo tanto, $v$ y $w$ son alcanzables entre ellos.

Ahora, como $vw$ es puente de $G$, necesariamente $G - (v,w)$ no es conexo, y eso implica que $v$ y $w$ no tienen un camino que los une. Pero vimos que pudimos definir un camino entre ellos anteriormente, entonces esto es un absurdo. 

El absurdo vino de suponer que $vw$ pertenecia a algun ciclo $C$, y por lo tanto, no pertenece.

### $\impliedby$)

Ahora tenemos que $vw$ no pertenece a ningun ciclo de $G$, y queremos ver que $vw$ es un puente de $G$.

De manera similar, procedemos por el absurdo. Supongamos que $vw$ no es un puente, entonces si hago $G - (v,w)$ sigo teniendo un grafo $G$ con la misma cantidad de componentes conexas. 

Esto implica que $v$ y $w$ siguen siendo alcanzables entre ellos. Por lo tanto existe un camino C definido como $w,k_1,...,k_n,v$ que los une. 

Pero ahora si vuelvo a agregar la arista al grafo, entonces ahora puedo formar un ciclo con ese camino y cerrandolo con la arista $(v,w)$. Por lo tanto llegue a un ciclo en $G$ que involucra a $vw$, y habiamos supuesto que no pertenecia a ningun ciclo.

Este absurdo vino de suponer que $vw$ no era puente, y por lo tanto, si lo es.


## Inciso B
Para esto vamos a pensar en el orden que exploro DFS a los nodos. 

Necesariamente el algoritmo DFS pasa por $v$ o $w$ primero. Sin perdida de generalidad digamos que pasa por $v$ primero, es analogo para $w$.

Ahora, como pasa primero por $v$, lo que ocurre es que todos los descendientes de $v$ se visitan antes de finalizar de recorrer $v$. 

Lo importante en esta parte es que, como existe la arista $(v,w)$, necesariamente el algoritmo va a visitar a $w$ antes de finalizar con $v$. Puede pasar que:
- $w$ es visitado antes de terminar con $v$ pero sin usar esa arista, en cuyo caso $v$ seria ancestro de $w$.
- DFS explora todos los nodos hijos de $v$ y eventualmente visita $w$ con la arista que los une, y por lo tanto $v$ tambien termina siendo ancestro de $w$.

## Inciso C
