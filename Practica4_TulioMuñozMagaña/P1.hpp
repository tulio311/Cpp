#pragma once
#include <string>

template <class T>
int binarySearch(T* arr, int n, T t){
    int p=0, f=n-1; //principio, final
    int mitad = (p+f) / 2;
    
    do{

        if(arr[mitad] > t){
            f = mitad;
            mitad = (p+f) / 2;

        }else if(arr[mitad] < t){
            p = mitad + 1;  // Esto se hace para poder llegar al último elemento
            mitad = (p+f) / 2;
            
        }

        if(arr[mitad] == t) return mitad;

    }while( p < f ); // Si esto llega a ocurrir, significa que no se encontró el elemento

    return -1;
}