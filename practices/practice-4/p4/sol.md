
4
parece similar a 1 y 2:
corro djikstra en 2 grafos, el G original desde s y el G-1, osea invirtiendo las flechas desde t
recorro cada arista (a,b)que no esta en G y la agrego al conjunto de las que mejoran el cm si:
el camino d(s,a) + c(a,b) + d(b,t) <= d(s,t), donde d(s,t) es sin usar esa arista. Osea, si yo uso la arista (a,b) para ir de s a t, el camino mas corto usandola (que seria camino minimo de s a a en G, pasar por esta arista, y de ahi de b a t en G') es mejor que el camino minimo de s a t en G
