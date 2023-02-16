# Práctica 5

## Tulio Muñoz Magaña

## Marco teórico

Las listas ligadas son estructuras de datos que nos permiten almacenar una serie de datos, de manera que las operaciones de inserción y eliminado de datos se realiza en tiempo constante, sin embargo, es una estructura donde es más lento acceder a un elemento específico de la lista. 



## Descripción de los programas

Programa `lista_simple.cpp`: 

Este código implementa una lista ligada simple, la lista contiene los métodos `insertar_inicio()`, que inserta un elemento al inicio de la lista y redirecciona el apuntador de la cabeza, `pop()`, que elimina el primer elemento de la lista y redirecciona el apuntador de la cabeza e `imprime_lista()`, que imprime los valores en orden desde la cabeza. En el main se crea una instancia de la lista, y se van agregando valores, para después hacer un pop. El programa va imprimiendo la lista con `imprime_lista()` después de hacer cada modificación.

Los comandos de compilación y ejecución son los siguientes respectivamente:

    g++ -std=c++11 lista_simple.cpp
    ./a.out

El programa no recibe ninguna entrada


Salida:

    Lista despues de ser creada:
    Lista despues de agregar 1: 1 
    Lista despues de agregar 1: 1 1 
    Lista despues de agregar 2: 2 1 1 
    Lista despues de hacer pop: 1 1 

Programa `lista_doble.cpp`: 

Este código implementa una lista ligada doble, la lista contiene los métodos `insertar_final()`, que inserta un elemento al final de la lista y redirecciona los apuntadores respectivos, `pop()`, que elimina el primer elemento de la lista y redirecciona el apuntador de la cabeza e `imprime_lista()`, que imprime los valores en orden inverso, es decir, desde el final hasta la cabeza. En el main se crea una instancia de la lista, y se van agregando valores, para después hacer un pop. El programa va imprimiendo la lista con `imprime_lista()` después de hacer cada modificación.

Los comandos de compilación y ejecución son los siguientes respectivamente:

    g++ -std=c++11 lista_simple.cpp
    ./a.out

El programa no recibe ninguna entrada

Salida:

    Lista despues de ser creada:
    Lista despues de agregar 1: 1
    Lista despues de agregar 3: 3 1
    Lista despues de agregar 4: 4 3 1
    Lista despues de hacer pop: 4 3


Programa `lista_circular.cpp`: 

Este código implementa una lista ligada simple circular, la lista contiene los métodos `insertar_inicio()`, que inserta un elemento al inicio de la lista y redirecciona los apuntadores respectivos (esto incluye recorrer toda la lista para buscar el último elemento y conectarlo con el nuevo primer elemento), `pop()`, que elimina el primer elemento de la lista y redirecciona el apuntador de la cabeza (así como también el del último elemento) e `imprime_lista()`, que imprime los valores en orden, desde la cabeza hasta que se cierre el círculo. En el main se crea una instancia de la lista, y se van agregando valores, para después hacer un pop. El programa va imprimiendo la lista con `imprime_lista()` después de hacer cada modificación.

Los comandos de compilación y ejecución son los siguientes respectivamente:

    g++ -std=c++11 lista_simple.cpp
    ./a.out

El programa no recibe ninguna entrada

Salida:

    Lista despues de ser creada:
    Lista despues de agregar 1: 1
    Lista despues de agregar 2: 2 1
    Lista despues de agregar 6: 6 2 1
    Lista despues de agregar 24: 24 6 2 1
    Lista despues de hacer pop: 6 2 1

Las capturas de los programas corriendo son `lista_simple.png`, `lista_doble.png` y `lista_circular.png` respectivamente. 

# Conclusión 

Se ha logrado solucionar los problemas satisfactoriamente. La inserción de elementos al principio en una lista ligada simple circular es un poco lenta, ya que requiere recorrer toda la lista para encontrar el último elemento y conectarlo con el primero. 

## Problemas encontrados

Hubo una complicación teórica al intentar definir un Nodo de la siguiente forma: `Nodo N(D);`. Ya que ha causado problemas al gestionar el apuntador `next` del nodo. Finalmente se ha optado por la declaración: `Nodo* N = new Nodo(D)`.

## Referencias