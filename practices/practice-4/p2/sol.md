
2
corro djikstra en 2 grafos, el G original desde s y el G-1, osea invirtiendo las flechas desde t
recorro cada arista (a,b) y me quedo con la mas pesada que cumpla que:
el camino d(s,a) + c(a,b) + d(b,t) <= c. Osea, si yo uso la arista (a,b) para ir de s a t, el camino mas corto usandola (que seria camino minimo de s a a en G, pasar por esta arista, y de ahi de b a t en G') no excede c.
l aplicar * tambien crece, porque multiplicamos por algo >= 1 FALLA si es < 1 pero > 0