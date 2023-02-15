#include <iostream>
#include <string>
#include "P1.hpp"
#include "P2.hpp"

int main(){

    int n;
    std::cin >> n;
    std::string* S = new std::string [n];

    for(int i = 0; i<n; i++){
        std::cin >> S[i];
    }

    // A continuación se ponen los dos algoritmos de ordenamiento,
    // se puede descomentar uno y comentar el otro para verificar el 
    // funcionamiento de cada uno

    //bubbleSort<std::string>(S,n);
    selectionSort<std::string>(S,n);

    std::string palabra;

    std::cin >> palabra;

    while(palabra != "-1"){

        if(binarySearch<std::string>(S,n,palabra) == -1){
            std::cout << palabra + " NOT FOUND :(" << std::endl;
        }else{
            std::cout << palabra + " FOUND: " << binarySearch<std::string>(S,n,palabra) << std::endl;
        }

        std::cin >> palabra;

    }

    delete []S;

    return 0;
}