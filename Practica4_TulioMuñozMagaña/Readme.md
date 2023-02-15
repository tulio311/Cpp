# Práctica 4

## Tulio Muñoz Magaña

## Marco teórico

Los templates son una herramienta de C++ que sirve para ahorrar esfuerzo en la implementación de funciones en las que se realizan tareas muy similares, con la única diferencia de los tipos de datos usados. Cuando se llama a una función de este estilo, se indican los tipos de datos que se usarán, además de los parámetros propios de la función. 

## Descripción de los problemas

En el problema 1 se ha implementado un template en una función que realiza una búsqueda binaria, donde la comparación entre objetos se realiza con el operador '<'. El código de este problema se encuentra en el archivo `P1.hpp`.

En el problema 2 se han implementado con templates 2 algoritmos de ordenamiento, el algoritmo bubble sort y el algoritmo selection sort, ambos con complejidad O(n^2). La comparación entre elementos se realiza también con el operador '<'. El código de estos dos algoritmos se encuentra en el archivo `P2.hpp`

Tanto el archivo `P1.hpp` como el `P2.hpp` son incluidos con `#include` en el archivo fuente del problema 3, el cual tiene el nombre `main.cpp`. En este código se utilizan las funciones con templates creadas anteriormente para crear un programa que recibe un entero `n`, y posteriormente recibe `n` strings, ordena esos strings con alguno de los 2 algoritmos de ordenamiento implementados en el problema 2 (se llaman a las dos funciones y se comenta una de ellas), luego se van introduciendo strings al programa, y el algoritmo imprime 
> `[palabra] FOUND: [índice]` 

si el string obtenido está en el arreglo, donde `índice` es la posición que tiene el string en el arreglo ya ordenado. O imprime
> `[palabra] NOT FOUND :(`

si el string no está en el arreglo. 

Los siguientes son los comandos de compilación y ejecución respectivamente
> ```
> g++ -std=c++11 main.cpp 
> ./a.out
> ```

Se le han pasado los 3 casos de prueba, a continuación se ponen las entradas y salidas de los 3 casos. 

Entrada caso 1:

    5
    4D:ec
    nbFLNjG97
    uLl
    aUVXS6L]
    8
    4D:ec
    a5xLh
    s8a
    -1

Salida caso 1:

    4D:ec FOUND: 0
    a5xLh NOT FOUND :(
    s8a NOT FOUND :(

La captura de esta salida se llama `case1.png`.

Entrada caso 2:

    10
    0839S
    d>vl
    HlC
    h5N
    N>
    l9u
    2x
    taQfdCr
    wjEQNF
    abdP
    0839S
    d>vl
    Xna9Ijg@
    Na84
    Wh3O60r4
    -1

Salida caso 2:

    0839S FOUND: 0
    d>vl FOUND: 5
    Xna9Ijg@ NOT FOUND :(
    Na84 NOT FOUND :(
    Wh3O60r4 NOT FOUND :(

La captura de esta salida se llama `case2.png`.

Entrada caso 3:

    100
    mQM2
    m?U
    w
    2wHWD4
    <2bGgZ
    rkAC>Vi_
    k0Oc>w`a
    EbUY
    zf
    Kf>uT
    NN1]tjAV
    u^vlZ
    R
    ZnO
    B
    WdRB[M
    ITnJ6Pm
    v5
    BeQ
    y\2AO:
    bYCK
    ?w6^E[
    IJ[;
    ?udR_:C]fz
    ;9[VKn
    52VoJU
    Tn
    4
    W
    \
    f@
    bWSJ4G=_m
    ;czr?oAM
    e@OSr`P
    Y;M]Vt5
    xLP\raQZ
    HR>BX:`hC8
    sXmQL?
    \
    lo
    qD5Q^VexW
    ;iNFN
    Y@T:hz[
    sHO
    mC=M
    BnnhXlD
    w
    lv:`T
    n^kVs^N
    flfbz8r
    `fc=@`D<L5
    ?OEB
    ]2hUJpN5a
    hIBHD
    g`
    wy
    93k
    Bs?T:l@\FZ
    M_kW
    n
    7k2nPjkNU]
    zWMrf[f
    T0@
    Q^Ku::QEA
    G4J
    XRy:
    x
    cX6CwGgwWS
    no1xy;v
    MBwg2>>0
    kazTr
    Po5qkE
    r
    q\jXgfP9x6
    cDh
    EB2DO^2XR
    7B6Qm
    0Nb
    oM
    a
    h@Peb
    0]Ax
    odBF
    JY
    T4;TS
    f0]NaaorkC
    FwoW
    YLFT
    knt
    0
    s>nOtn
    0T
    Y4pl
    ;hWKJigaC8
    jeqT5R
    sqDf\E
    aWaV1aaR=
    lw;;swEKa
    oPGVHrkh<i
    mEGHF
    mQM2
    m?U
    w
    2wHWD4
    <2bGgZ
    rkAC>Vi_
    k0Oc>w`a
    EbUY
    zf
    Kf>uT
    NN1]tjAV
    u^vlZ
    R
    ZnO
    B
    WdRB[M
    ITnJ6Pm
    v5
    BeQ
    y\2AO:
    bYCK
    ?w6^E[
    IJ[;
    ?udR_:C]fz
    ;9[VKn
    52VoJU
    Tn
    4
    W
    \
    f@
    bWSJ4G=_m
    ;czr?oAM
    e@OSr`P
    Y;M]Vt5
    xLP\raQZ
    HR>BX:`hC8
    sXmQL?
    bhoLB
    W7LSLgn
    EwBkDmD1y2
    T0LUF2<g
    A
    3R
    8^op:j:6e
    4@
    5ru:KvVp
    XeK8vg;6?D
    3mXV`_@wc
    oQ0SD
    7j@
    1^im
    UxIMu
    QPEw5]
    2yzZ8d
    M4mpyXq\
    coU
    rr
    ^
    e\
    S
    A><ti
    ]T
    bG@IXkuW
    S
    VJ
    k
    ^>CyJQ?YG9
    EfT`6kYOH
    3pV?Z1
    <l?TcR;
    ]K\t=\r\5
    cZ
    kr8
    P^20_Dp:
    2VH>
    uBnW
    -1


Salida caso 3:

    mQM2 FOUND: 75
    m?U FOUND: 72
    w FOUND: 93
    2wHWD4 FOUND: 4
    <2bGgZ FOUND: 14
    rkAC>Vi_ FOUND: 85
    k0Oc>w`a FOUND: 66
    EbUY FOUND: 23
    zf FOUND: 99
    Kf>uT FOUND: 30
    NN1]tjAV FOUND: 33
    u^vlZ FOUND: 90
    R FOUND: 36
    ZnO FOUND: 47
    B FOUND: 18
    WdRB[M FOUND: 41
    ITnJ6Pm FOUND: 28
    v5 FOUND: 91
    BeQ FOUND: 19
    y\2AO: FOUND: 97
    bYCK FOUND: 55
    ?w6^E[ FOUND: 17
    IJ[; FOUND: 27
    ?udR_:C]fz FOUND: 16
    ;9[VKn FOUND: 10
    52VoJU FOUND: 6
    Tn FOUND: 39
    4 FOUND: 5
    W FOUND: 40
    \ FOUND: 49
    f@ FOUND: 60
    bWSJ4G=_m FOUND: 54
    ;czr?oAM FOUND: 11
    e@OSr`P FOUND: 58
    Y;M]Vt5 FOUND: 44
    xLP\raQZ FOUND: 96
    HR>BX:`hC8 FOUND: 26
    sXmQL? FOUND: 88
    bhoLB NOT FOUND :(
    W7LSLgn NOT FOUND :(
    EwBkDmD1y2 NOT FOUND :(
    T0LUF2<g NOT FOUND :(
    A NOT FOUND :(
    3R NOT FOUND :(
    8^op:j:6e NOT FOUND :(
    4@ NOT FOUND :(
    5ru:KvVp NOT FOUND :(
    XeK8vg;6?D NOT FOUND :(
    3mXV`_@wc NOT FOUND :(
    oQ0SD NOT FOUND :(
    7j@ NOT FOUND :(
    1^im NOT FOUND :(
    UxIMu NOT FOUND :(
    QPEw5] NOT FOUND :(
    2yzZ8d NOT FOUND :(
    M4mpyXq\ NOT FOUND :(
    coU NOT FOUND :(
    rr NOT FOUND :(
    ^ NOT FOUND :(
    e\ NOT FOUND :(
    S NOT FOUND :(
    A><ti NOT FOUND :(
    ]T NOT FOUND :(
    bG@IXkuW NOT FOUND :(
    S NOT FOUND :(
    VJ NOT FOUND :(
    k NOT FOUND :(
    ^>CyJQ?YG9 NOT FOUND :(
    EfT`6kYOH NOT FOUND :(
    3pV?Z1 NOT FOUND :(
    <l?TcR; NOT FOUND :(
    ]K\t=\r\5 NOT FOUND :(
    cZ NOT FOUND :(
    kr8 NOT FOUND :(
    P^20_Dp: NOT FOUND :(
    2VH> NOT FOUND :(
    uBnW NOT FOUND :(


Las capturas de esta salida se llaman `case3_1.png` y `case3_2.png`, se han dividido en 2 porque no cabía la salida en una sola captura. 

## Conclusión

Se ha logrado obtener el mismo resultado en los tres casos de prueba que el resultado dado, se ha optimizado lo más posible bubble sort y selection sort de manera que se realicen menos operaciones en cada iteración, tomando en cuenta los elementos que ya están ordenados.  

## Problemas encontrados

Se encontró un problema en el caso 3, en el cual la búsqueda binaria del programa encontraba el caracter `'/'` en la posición 48, donde el archivo de salida dado registraba que se encontraba en la posición 49. Esto ocurría porque existían dos caracteres iguales en ambas posiciones en el arreglo ya ordenado, y había una ligera variación en el algoritmo de búsqueda binaria que encontraba antes el `'/'` que se encontraba en la posición 48 que el que se encontraba en la posición 49. Se ha modificado para que la respuesta coincida. 

## Referencias

* Cormen, T. H. (2013). Algorithms unlocked. Cambridge, MA: MIT Press.
* Eckel, B. (2000). Thinking in C++. Upper Saddle River, NJ: Prentice Hall.
* https://softwareengineering.stackexchange.com/questions/358786/what-is-golden-files
* https://repl.it