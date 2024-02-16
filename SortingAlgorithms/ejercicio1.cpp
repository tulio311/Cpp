#include <iostream>


template <class T>
void MergeSort(T arr[], int p, int r, bool (*comparar)(T, T)){
    int q=(p+r)/2; 
    MergeSort<T>(arr, p, q, comparar);
    MergeSort<T>(arr, q+1, r, comparar);
    Merge(arr, p, q, r);
}

template <class T>
void Merge(T arr[], int p, int q, int r, bool (*comparar)(T, T)){
    T[] arrLeft = new T[q-p+1];
    T[] arrRight = new T[r-q];

    int i;

    for(i=0; i<q-p+1; i++) arrLeft[i] = arr[p+i];
    for(i=1; i<=r-q; i++) arrRight[i] = arr[q+i];

    int j=0, k=0;

    for(i=0; i<=r-p; i++){
        if(j>=q-p+1){
            arr[i] = arrRight[k];
            k++;
        }
        if(k>=r-q){
            arr[i] = arrLeft[j];
            j++;
        }

        if(comparar(arrLeft(j), arrRight(k))){
            arr[i] = arrLeft(j);
            j++;
        }else{
            arr[i] = arrRight(k);
            k++;
        }

    }
}


bool comparaInt(int a, int b){
    if(a<b) return 1;
    return 0;
}










