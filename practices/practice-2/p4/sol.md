# Solucion

Lo hacemos por induccion, planteando como HI que:
> Si tenemos un grafo $G = (V,E)$ tal que $n = |V(G)|$ y $(n − 1)(n − 2)/2 < |E(G)|$, entonces $G$ es conexo.

## Caso base
Lo hacemos para  $G = (V,E)$ tal que $n = |V(G)| = 2$, ya que para n = 1 no funciona, porque nos queda:

$(1 - 1)(1 - 2)/2 < |E(G)| \iff 0 < 0$

Que es falso.

Entonces tenemos que vale:

$(2 - 1)(2 - 2)/2 < |E(G)| \iff 0 < |E(G)|$

Como tenemos 2 vertices, necesariamente hay una arista entre ellos, y por lo tanto $G$ es conexo.

## Paso inductivo

Supongamos que vale que para todo grafo $G = (V,E)$ con $n = |V(G)|$ y $(n − 1)(n − 2)/2 < |E(G)|$, entonces $G$ es conexo.

Queremos probar que esto vale para grafos con $n+1$ vertices. Tomemos entonces un grafo $G = (V,E)$ con $n + 1 = |V(G)|$ tal que vale:

$n(n − 1)/2 < |E(G)|$

Ahora saquemosle a $G$ el vertice $v$ de menor grado, y  obtenemos el grafo $G'$. Veamos que grado maximo podia llegar a tener $v$ en $G$:
- $d(v) = n$: Si era $n$, entonces todos los vertices de $G$ tienen $n$, y $G$ es un grafo completo, y por ende conexo.
- $d(v) < n$: En este caso estariamos sacando a lo sumo $n-1$ aristas. Veamos que pasa al hacer esto.

Sabemos que para $G$ valia:

$n(n − 1)/2 < |E(G)|$

Si restamos $n-1$ que son todas las aristas que podriamos haber sacado tenemos:

$n(n − 1)/2 - (n-1) < |E(G)| - (n-1) \iff (n(n − 1) - 2(n-1))/2 < |E(G')| \iff (n^2-3n+2)/2 < |E(G')|$

Para aplicar HI sobre $G'$ que tiene $n$ vertices necesitabamos justamente que valiera:

$(n − 1)(n − 2)/2 < |E(G')| \iff (n^2-3n+2)/2 < |E(G')|$

Que es justamente lo que nos quedo. Por lo tanto, por HI vale que G' es conexo. 

Al agregar el vertice $v$ devuelta junto con todas sus aristas volvemos a $G$, y como todos los vertices de $G'$ eran alcanzables en $G'$, podemos decir que $v$ tambien lo sera. 
Esto es porque simplemente cualquier camino para llegar de un nodo $a$ a un $b$ en $G'$ donde $a$ es esta conectado a $v$, le sirve como camino a $v$ tambien para alcanzar a $b$.

# Alternativa

Suponer que no es conexo $G$, pensar en la particion de vertices en 2 grupos de $G$, $V$ y $V'$, tal que son disconexos entre si estos 2.

Cada uno tiene $i$ y $n - i$ respectivamente. A lo sumo cada uno puede tener estas aristas:
- $i(i-1)/2$
- $(n-i)(n-i-1)/2$

Si sumamos estos 2 para ver la maxima cantidad de aristas nos queda:

$(i^2-i+n^2-ni-n-in+i^2+i)/2 = (2i^2+n^2-2ni-n)/2$

Derivo para analizar el valor de i donde llega al maximo:

$(4i-2n)/2 = 2i-n$

Igualo a 0 para ver cuando alcanza el maximo la funcion:

$2i-n = 0 \iff 2i = n \iff i = n/2$

Reemplazo el i en la funcion original:

$(n^2/2+n^2-n^2-n)/2 = (n^2/2-n)/2$

Ahora quiero ver que esta cantidad de aristas maxima es menor a la cota de aristas que tenia al principio. Si muestro que esto es asi, llegamos a un absurdo por suponer que era disconexo el grafo:

$(n^2/2-n)/2 < (n-1)(n-2)/2 \iff(n^2/2-n)/2 < (n^2-3n+2)/2 \iff 0 < n^2/2-2n+2$

Como esta funcion es creciente positiva a partir de $n = -2$, y a partir de $n = 1$ es mayor estricto a 0, podemos decir que se cumple lo que queriamos.
Por lo tanto llegamos al absurdo y G es conexo.