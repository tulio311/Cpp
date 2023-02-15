#pragma once
#include <string>

template <class T>
void bubbleSort(T* arr, int n){
    T aux; 

    for(int i = 0; i<n; i++){
        for(int j=1; j< n - i; j++){ // Se pone n-i para ya no modificar los elementos que ya están ordenados hasta el final
            if(arr[j] < arr[j-1]){

                // Aquí realizamos el swap
                aux = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = aux;
            }
        }
    }

}


template <class T>
void selectionSort(T* arr, int n){
    T aux;
    int indice; // Guarda la posición del elemento más chico encontrado hasta el momento

    for(int i = 0; i<n; i++){

        indice = i;

        for(int j=i; j<n; j++){
            
            // Vamos buscando por el arreglo el elemento más chico que no esté ordenado ya
            if(arr[j] < arr[indice]){
                indice = j;
            }

        }

        aux = arr[i];
        arr[i] = arr[indice];
        arr[indice] = aux;

    }

}