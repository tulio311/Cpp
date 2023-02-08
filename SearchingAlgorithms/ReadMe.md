# Práctica 1

## Tulio Muñoz Magaña

### Quick Find

Copiar y ejecutar el algoritmo Quick Find.

El código de éste algoritmo se llama `Quick_Find.cpp`

Comando de compilación:

> `g++ Quick_Find.cpp -o QuickFind`

Comando de ejecución:

> `QuickFind.exe`

La captura de pantalla de este algoritmo corriendo se llama `Quick_Find.png` 

### Resultados

```
3 4  
 3 4  
4 9  
 4 9
8 0  
 8 0  
2 3 
 2 3 
5 6
 5 6  
2 9  
5 9  
 5 9
7 3
 7 3  
4 8 
 4 8 
5 6  
0 2  
6 1 
 6 1 
```

---

### Quick Union

Copiar y ejecutar el algoritmo Quick Union.

El código del algoritmo Quick-Union se llama `Quick_Union.cpp`

Comando de compilación:

> `g++ Quick_Union.cpp -o QuickUnion`

Comando de ejecución:

> `QuickUnion.exe`

La captura de pantalla de este algoritmo corriendo se llama `Quick_Union.png`

### Resultados

```
3 4  
 3 4  
4 9  
 4 9
8 0  
 8 0  
2 3 
 2 3 
5 6
 5 6  
2 9  
5 9  
 5 9
7 3
 7 3  
4 8 
 4 8 
5 6  
0 2  
6 1 
 6 1 
```


---
### Weighted Quick Union

Copiar y ejecutar el código de la captura de pantalla de Weighted Quick-union, verificar que funcione y dar una breve explicación sobre su funcionamiento y su tiempo de ejecución.

El código del algoritmo Weighted-Quick-Union se llama `Weighted_Quick_Union.cpp`

Comando de compilación:

> `g++ Weighted_Quick_Union.cpp -o WeightedQuickUnion`

Comando de ejecución:

> `WeightedQuickUnion.exe`

La captura de pantalla de este algoritmo corriendo se llama `Weighted_Quick_Union.png`

### Resultados

```
0 1 2 3 4 5 6 7 8 9
3 4  
0 1 2 3 4 5 6 7 8 9
Pair 3, 4 gives a new connection 
4 9
0 1 2 3 4 5 6 7 8 9  
Pair 4, 9 gives a new connection
8 0  
0 1 2 3 4 5 6 7 8 9
Pair 8, 0 gives a new connection  
2 3 
0 1 2 3 4 5 6 7 8 9
Pair 2, 3 gives a new connection 
5 6
0 1 2 3 4 5 6 7 8 9
Pair 5, 6 gives a new connection  
2 9  
5 9  
0 1 2 3 4 5 6 7 8 9
Pair 5, 9 gives a new connection
7 3
0 1 2 3 4 5 6 7 8 9
Pair 7, 3 gives a new connection 
4 8 
0 1 2 3 4 5 6 7 8 9
Pair 4, 8 gives a new connection 
5 6  
0 2  
6 1 
0 1 2 3 4 5 6 7 8 9
Pair 6, 1 gives a new connection

```

En este algoritmo se ha inicializado el arreglo `sz[N]` de manera que `sz[i] = 1` para todo `i`, que representa el tamaño del bloque en el que se encuentra el elemento, al principio todos los elementos están en un bloque diferente donde solo están ellos mismos, y por eso todos los tamaños son 1.  

Cuando a lo largo del algoritmo se identifica que los elementos líderes de un par de números son diferentes, se pregunta cuál de ellos está en un conjunto de tamaño mayor, finalmente se pega el líder del conjunto de tamaño menor al líder del conjunto de tamaño mayor.  

De esta forma se busca que los elementos se organicen de una manera más centralizada y evita FIND's excesivamente largos.   

Si procedemos de esta forma, en un conjunto de tamaño `i`, tendremos que todos los elementos están a distancia del líder, de a lo más, la parte entera de `log_2 (n)`. Esto lo podemos probar por inducción fuerte, veo que funciona para los primeros casos, luego supongo que es verdad para todos los casos hasta `n`, y veo que si `n+1` no es potencia de `2`, entonces todas las formas que tengo de formar un conjunto de `n+1` elementos juntando dos conjuntos y pegando el más pequeño al más grande, la mayor distancia al líder sigue siendo a lo más la mayor distancia al líder en un conjunto de `n` elementos, lo cual es la parte entera de `log_2 (n)`, que es igual a la parte entera de `log_2 (n+1)`, porque `n+1` no es potencia de `2`. Y si `n+1` es potencia de `2`, vemos que la mayor distancia al líder va a ser la mayor distancia al líder de un conjunto de `n` elementos, mas 1, lo que es justamente la parte entera de `log_2 (n+1)`.  

Como vamos a realizar la operación FIND `n` veces y en cada vez, el mayor conjunto posible es `1` más, la complejidad de las operaciones FIND en la totalidad del algoritmo es
> `log_2 (1) + ... + log_2 (n) = log_2 (n!)`

Por otro lado, la complejidad de la operación UNION es lineal porque solamente se realizarán `n-1` operaciones.

Entonces la complejidad del algoritmo es `log_2 (n!)`, ya que la parte lineal del UNION la podemos despreciar.





## Referencias

* R. Sedgewick. "Algorithms in C++"

* T.H. Cormen, C.E. Leiserson, R.L. Riverst, C. Stein. "Introduction to Algorithms". 3rd. edition

* Videos de clase

