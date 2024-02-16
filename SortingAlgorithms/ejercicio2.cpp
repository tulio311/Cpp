#include <iostream>


template <class T>
int Partition(T arr[], int inicio, int fin, bool (*comparar)(T, T)){
    T p = arr[fin];
    int i = inicio - 1, j;
    T aux; // Para el swap
    for(j=inicio; j<fin; j++){
        if(comparar(arr[j],p)){
            i=i+1;
            aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
        }
    }´
    // Metemos el pivote en medio de los dos subarreglos
    aux = arr[i+1];
    arr[i+1] = arr[fin];
    arr[fin] = aux;

    // Regresamos la posición donde quedó el pivote
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