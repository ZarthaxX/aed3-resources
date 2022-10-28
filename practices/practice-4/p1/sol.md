1
corro djikstra en 2 grafos, el G original desde s y el G-1, osea invirtiendo las flechas desde t
recorro cada arista (a,b) y si vale la propiedad de st-eficiente (que puedo chequearlo usando (a) en O(1)) entonces la vuelo de G
ahora que elimine todas las st eficiente corro djikstra devuelta sobre eso y me quedo con el camino minimo de s a t
si no existe el camino porque se desconecto el grafo cuando vole las aristas entonces no hay cm
r * tambien crece, porque multiplicamos por algo >= 1 FALLA si es < 1 pero > 0