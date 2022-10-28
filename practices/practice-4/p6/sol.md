la idea es aplicar el logaritmo a todos los pesos de las aristas
de esta manera, nuestros caminos pasan de ser:
$$e_1 + e_2 + ... + e_n$$

a ser

$$log(e_1) + log(e_2) + ... + log(e_n)$$

notar que esta ultima suma se puede interpretar como:

$$e_1 * e_2 * ... * e_n$$

y esto es lo que queriamos hacer, expresar al camino como un producto de los pesos de las aristas del mismo

faltaria ver que este camino mantiene la propiedad de que es minimo

veamos que vale entonces el si solo si entre estos 2:

$$e_1 + e_2 + ... + e_n \iff log(e_1) + log(e_2) + ... + log(e_n)$$


la demo sale porque log es una funcion creciente si los e_i > 0 siempre, entonces basicamente:
- vale que para todo otro camino la suma de pesos es mayor igual al que tenemos minimo
  - al aplicar log sabemos que por ser funcion creciente se sigue respetando el mayor igual


