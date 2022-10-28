uno quiere definir un numero para cada $x_i$, tal que se respete despues la forma de S.
La forma de S basicamente implica que si uno tiene el i-esimo (, entonces entre este y el i-esimo ), los numeros que representen a los ( encerrados dentro de ese intervalo tienen que cumplir esto para cada ( en la posicion j:
$$|x_i - x_j| <= l - 1$$

Esto termina siendo 2 ecuaciones:

$$ x_i - x_j <= l - 1$$

$$ x_j - x_i <= l - 1$$

Notar que si hacemos esta cantidad de ecuaciones, seria en el orden $O(n^2)$ ecuaciones. La clave aca es que si ya forzamos a que los ( que estan en el medio de el i-esimo ( y el i-esimo ) se encuentren contenidos, entonces al plantear las restricciones para los ( internos, no es necesario incluir las ecuaciones de los ( que estan entre este y el i-esimo ), porque ya se fuerza la distancia necesaria.

De esta manera tenemos $O(n)$ ecuaciones, porque hay aproximadamente 2n ecuaciones, 2 por cada parentesis (, excepto por el primero.