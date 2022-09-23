# Solucion

## Inciso A
Tenemos al grafo $D = (V,E)$, y tomamos un $v \in V$ cualquiera. 
Empezamos a recorrer $D$ a partir de $v$, tomando siempre un $w$ tal que $(v,w) \in E$.

Observemos que siempre va a existir por lo menos una de estas aristas, por la hipotesis que nos dice que todo vertice en $D$ tiene grado de salida mayor a 0.
Por otro lado, como la cantidad de vertices es a lo sumo $n = |V|$, necesariamente en un momento vamos a pasar por un vertice $v_i$ que ya visitamos.
Cuando ocurra esto, significa que vamos a haber visitado a $v_i$ 2 veces, y para que esto pase significa que hay un ciclo en $D$.

## Inciso B
El algoritmo es similar a la idea del A para probar que existe tal ciclo.

Tenemos al grafo $D = (V,E)$, y tomamos un $v \in V$ cualquiera inicialmente. 
Vamos a hacer un algoritmo iterativo, el cual mantiene en todo momento la lista de vertices que fueron visitados hasta ahora (inicialmente vacio).

En cada paso, vamos a seleccionar un vertice $w$ tal que para el ultimo $v$ que elegimos tenemos una arista que los conecta, osea $(v,w) \in E$, y vamos a guardar en la lista de visitados a este nuevo vertice $w$.
Necesariamente en un momento vamos a pasar por un vertice $v_i$ que ya visitamos (esta en la lista de visitados).

Vamos a tener en nuestra lista de visitados a los vertices $v_1, ..., v_i, ..., v_k, v_i$, donde $v_i$ denota al vertice que visitamos previamente y volvimos a visitar ahora.
Por lo tanto, podemos tomar el ciclo $v_i, ..., v_k, v_i$ como la respuesta que buscabamos.


## Inciso C
```pseudocode
// esta seria la informacion del grafo que asumimos que viene dada
listaAdyacencia = inicializar // O(n + m)
// en cada posicion i dice cual es el proximo vertice j, inicialmente con valor -1
sigVertice =  lista de n posiciones  // O(n)
// empezamos con el primer vertice de D pero podria ser cualquiera
verticeActual = 1 
// iteramos hasta pasar por un vertice que ya habiamos visto antes
mientras sigVertice[verticeActual] == -1 // O(n) porque a lo sumo veo todos los vertices
 // tomamos el primer vertice alcanzable de manera directa desde verticeActual
 verticeSiguiente = listaAdyacencia[verticeActual][1] // O(1)
 // marcamos para el vertice actual cual es el siguiente vertice a ser visitado
 sigVertice[verticeActual] = verticeSiguiente // O(1)
 verticeActual = verticeSiguiente // O(1)

// reconstruimos el ciclo, empezando desde verticeActual hasta pasar por todos los vertices y volver a ver a verticeActual
ciclo = lista vacia // O(1)
verticeCiclo = verticeActual // O(1)
mientras sigVertice[verticeCiclo] != verticeActual // O(n) porque a lo sumo el ciclo tiene a todos los vertices
 ciclo <- ciclo + [verticeCiclo] // O(1)
 verticeCiclo = sigVertice[verticeCiclo] // O(1)

// agregamos para cerrar el ciclo al vertice actual
ciclo <- ciclo + [verticeActual] // O(1)
```

En total tenemos la complejidad de:
- inicializar la lista de adyacencia que cuesta $O(n+m)$
- recorrer $D$ hasta encontrar un ciclo que cuesta $O(n)$
- reconstruir el ciclo que cuesta $O(n)$

La complejidad final seria $O(n+m)$

## Inciso D
Probamos las implicaciones para ambos lados.
### $\implies$) 
Tomamos un digrafo $D$ no trivial, porque si es trivial vale trivialmente la propiedad.
En este caso como $n > 1$ no puede ser el grafo trivial, asi que vamos a probar que D tiene un vértice con
$d_{out}(v) = 0$ tal que $D - {v}$ es acíclico. 

Por el contrarreciproco del inciso $A$, sabemos que vale que:
> D es aciclico $\implies$ existe al menos un vertice $v$ en $D$ tal que $d_{out}(v) = 0$.

Con esto vemos que tenemos el $v$ que queriamos. Cumple $d_{out}(v) = 0$ por un lado.
Si le sacamos a $D$ este vertice $v$ nos queda otro digrafo $D'$ que sigue siendo aciclico, porque si ya lo era $D$, al sacar un vertice lo sigue siendo tambien.

### $\impliedby$)
Ahora queremos probar que:
> $D$ es trivial, o $D$ tiene un vértice con $d_{out}(v) = 0$ tal que $D - {v}$ es acíclico $\implies$ $D$ es aciclico

Si $D$ es trivial, no tiene aristas, asi que no pueden existir ciclos.

Si $D$ no es trivial, entonces vale que $D$ tiene un vértice con $d_{out}(v) = 0$ tal que $D - {v}$ es acíclico.
Tomemos ese vertice $v$ y construyamos a $D' = D - {v}$. Por la hipotesis sabemos que $D'$ es aciclico.
Como $D'$ es aciclico, falta ver si se puede crear un ciclo al agregar $v$. 
Supongamos que si se crea un ciclo al agregar $v$, significa que $v$ forma parte del ciclo.
Definamos sin perdida de generalidad a ese ciclo como $C = v_1,...v_k,v,v_1$. 
Necesariamente como existe $C$ en $D$ existe tambien la arista $(v,v_1)$ que forma parte de ese ciclo.
Pero esto implicaria que $d_{out}(v) > 0$, y por hipotesis es 0.
Esto es un absurdo que vino de suponer que existia un ciclo en $D$, y por lo tanto no existe tal ciclo.

