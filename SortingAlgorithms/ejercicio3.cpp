#include <iostream>


template <class T>
class pareja{
    public:
    T x,y;
};


// El siguiente código es el mismo que está en los ejercicios 1 y 2

template <class T>
void Merge(T arr[], int p, int q, int r, bool (*comparar)(T, T)){
    T arrLeft[q-p+1];
    T arrRight[r-q];

    int i;

    for(i=0; i<q-p+1; i++) arrLeft[i] = arr[p+i];
    for(i=0; i<r-q; i++) arrRight[i] = arr[q+i+1];

    int j=0, k=0;

    for(i=0; i<=r-p; i++){
        if(j>=q-p+1){
            arr[p+i] = arrRight[k];
            k++;
            continue;
        }
        if(k>=r-q){
            arr[p+i] = arrLeft[j];
            j++;
            continue;
        }

        if(comparar(arrLeft[j], arrRight[k])){
            arr[p+i] = arrLeft[j];
            j++;
        }else{
            arr[p+i] = arrRight[k];
            k++;
        }

    } 
}


template <class T>
void MergeSort(T arr[], int p, int r, bool (*comparar)(T, T)){
    if(r<=p) return;
    int q=(p+r)/2; 
    MergeSort<T>(arr, p, q, comparar);
    MergeSort<T>(arr, q+1, r, comparar);
    Merge<T>(arr, p, q, r, comparar);
}


template <class T>
int Partition(T arr[], int inicio, int fin, bool (*comparar)(T, T)){
    T p = arr[fin];
    int i = inicio - 1, j;
    T aux;
    for(j=inicio; j<fin; j++){
        if(comparar(arr[j],p)){
            i=i+1;
            aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
        }
    }
    aux = arr[i+1];
    arr[i+1] = arr[fin];
    arr[fin] = aux;

    return i+1;
}

template <class T>
void QuickSort(T arr[], int inicio, int fin, bool (*comparar)(T, T)){
    if(inicio < fin){
        int q = Partition<T>(arr, inicio, fin, comparar);
        QuickSort<T>(arr, inicio, q-1, comparar);
        QuickSort<T>(arr, q+1, fin, comparar);
    }
}

// --------------------------


// Las siguientes son las funciones para comparar


// Estas dos funciones funcionan para coasas para las cuales
// estén definidos los operadores '<' y '>'  

template <class T>
bool comparaNumAsc(T a, T b){
    if(a<b) return 1;
    return 0;
}


template <class T>
bool comparaNumDesc(T a, T b){
    if(a>b) return 1;
    return 0;
}

//-----------------

// Compara por primera coordenada
template <class T>
bool comparaParejasPrimera(pareja<T> a, pareja<T> b){
    if(a.x<b.x) return 1;
    return 0;
}

// Compara por segunda
template <class T>
bool comparaParejasSegunda(pareja<T> a, pareja<T> b){
    if(a.y<b.y) return 1;
    return 0;
}




template <class T>
void copiarArreglo(T* A, T* B, int tam){
    int i;
    for(i=0; i<tam; i++) A[i] = B[i];
}



int main(){

    int i;

    int arrInt[] = {1,5,-4,7,-23,25,76,2,4,-9,0};
    double arrDouble[] = {2.54,7.68,-2.3,12,-67.8,34.9,3,-5.3};

    // Tamaño del arreglo
    int tam = sizeof(arrInt) / sizeof(arrInt[0]);

    int aux1[tam];


    // Guardamos el arreglo en aux1 para poder recuperarlo y probar
    // los distintos algoritmos de ordenamiento
    copiarArreglo<int>(aux1,arrInt,tam);


    std::cout << "El arreglo de enteros original:" << std::endl;
    for(i=0; i<tam; i++) std::cout << arrInt[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;



    MergeSort<int>(arrInt,0,tam-1,&comparaNumAsc<int>);
    std::cout << "El arreglo de enteros ordenado ascendentemente por Merge Sort:" << std::endl;
    for(i=0; i<tam; i++) std::cout << arrInt[i] << " ";
    std::cout << std::endl;


    // Recuperamos el arreglo original
    copiarArreglo<int>(arrInt,aux1,tam);
    QuickSort<int>(arrInt,0,tam-1,&comparaNumAsc<int>);
    std::cout << "El arreglo de enteros ordenado ascendentemente por Quick Sort:" << std::endl;
    for(i=0; i<tam; i++) std::cout << arrInt[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;


    copiarArreglo<int>(arrInt,aux1,tam);
    MergeSort<int>(arrInt,0,tam-1,&comparaNumDesc<int>);
    std::cout << "El arreglo de enteros ordenado descendentemente por Merge Sort:" << std::endl;
    for(i=0; i<tam; i++) std::cout << arrInt[i] << " ";
    std::cout << std::endl;


    copiarArreglo<int>(arrInt,aux1,tam);
    QuickSort<int>(arrInt,0,tam-1,&comparaNumDesc<int>);
    std::cout << "El arreglo de enteros ordenado descendentemente por Quick Sort:" << std::endl;
    for(i=0; i<tam; i++) std::cout << arrInt[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;





    tam = sizeof(arrDouble) / sizeof(arrDouble[0]);
    double aux2[tam];


    copiarArreglo<double>(aux2,arrDouble,tam);


    std::cout << "El arreglo de doubles original:" << std::endl;
    for(i=0; i<tam; i++) std::cout << arrDouble[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;


    MergeSort<double>(arrDouble,0,tam-1,&comparaNumAsc<double>);
    std::cout << "El arreglo de doubles ordenado ascendentemente por Merge Sort:" << std::endl;
    for(i=0; i<tam; i++) std::cout << arrDouble[i] << " ";
    std::cout << std::endl;


    copiarArreglo<double>(arrDouble,aux2,tam);
    QuickSort<double>(arrDouble,0,tam-1,&comparaNumAsc<double>);
    std::cout << "El arreglo de doubles ordenado ascendentemente por Quick Sort:" << std::endl;
    for(i=0; i<tam; i++) std::cout << arrDouble[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;


    copiarArreglo<double>(arrDouble,aux2,tam);
    MergeSort<double>(arrDouble,0,tam-1,&comparaNumDesc<double>);
    std::cout << "El arreglo de doubles ordenado descendentemente por Merge Sort:" << std::endl;
    for(i=0; i<tam; i++) std::cout << arrDouble[i] << " ";
    std::cout << std::endl;


    copiarArreglo<double>(arrDouble,aux2,tam);
    QuickSort<double>(arrDouble,0,tam-1,&comparaNumDesc<double>);
    std::cout << "El arreglo de doubles ordenado descendentemente por Quick Sort:" << std::endl;
    for(i=0; i<tam; i++) std::cout << arrDouble[i] << " ";
    std::cout << std::endl;
    std::cout << std::endl;


    // Creación de un arreglo de la estructura pareja

    pareja<int> A[5];
    A[0].x = 4;
    A[0].y = 2;
    A[1].x = 23;
    A[1].y = 8;
    A[2].x = -2;
    A[2].y = 9;
    A[3].x = 3;
    A[3].y = 0;
    A[4].x = -12;
    A[4].y = -7;

    tam = sizeof(A) / sizeof(A[0]);
    pareja<int> aux3[5];


    copiarArreglo<pareja<int>>(aux3,A,tam);


    std::cout << "El arreglo de parejas original:" << std::endl;
    for(i=0; i<tam; i++) std::cout << "(" << A[i].x << "," << A[i].y << ") ";
    std::cout << std::endl;
    std::cout << std::endl;

    QuickSort<pareja<int>>(A,0,4,&comparaParejasPrimera);
    std::cout << "El arreglo de parejas ordenado por la primera coordenada por Quick Sort:" << std::endl;
    for(i=0; i<tam; i++) std::cout << "(" << A[i].x << "," << A[i].y << ") ";
    std::cout << std::endl;


    copiarArreglo<pareja<int>>(A,aux3,tam);
    MergeSort<pareja<int>>(A,0,4,&comparaParejasPrimera);
    std::cout << "El arreglo de parejas ordenado por la primera coordenada por Merge Sort:" << std::endl;
    for(i=0; i<tam; i++) std::cout << "(" << A[i].x << "," << A[i].y << ") ";
    std::cout << std::endl;
    std::cout << std::endl;


    copiarArreglo<pareja<int>>(A,aux3,tam);
    QuickSort<pareja<int>>(A,0,4,&comparaParejasSegunda);
    std::cout << "El arreglo de parejas ordenado por la segunda coordenada por Quick Sort:" << std::endl;
    for(i=0; i<tam; i++) std::cout << "(" << A[i].x << "," << A[i].y << ") ";
    std::cout << std::endl;


    copiarArreglo<pareja<int>>(A,aux3,tam);
    MergeSort<pareja<int>>(A,0,4,&comparaParejasSegunda);
    std::cout << "El arreglo de parejas ordenado por la segunda coordenada por Merge Sort:" << std::endl;
    for(i=0; i<tam; i++) std::cout << "(" << A[i].x << "," << A[i].y << ") ";
    std::cout << std::endl;
    std::cout << std::endl;


    return 0;
}