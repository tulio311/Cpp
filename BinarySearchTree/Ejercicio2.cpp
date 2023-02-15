#include <iostream>
#include <chrono>
#include <random>

using namespace std;

class Nodo;

class Nodo{
public:
    Nodo *der, *izq;

    // Para poder almacenar enteros hasta 10^{18}
    unsigned long long val;

    Nodo(){
        this -> der = nullptr;
        this -> izq = nullptr;
    }

    Nodo(unsigned long long n){
        this -> val = n;
        this -> der = nullptr;
        this -> izq = nullptr;
    }

    ~Nodo(){}

};


class BST{

public:

    ~BST(){   Destroy(root);   }
    
    void Destroy(Nodo * nodo){   
        if (nodo!=nullptr){   
            Destroy(nodo->izq);
            Destroy(nodo->der);
            delete(nodo);
        }
    }

    Nodo* root = nullptr;

    unsigned long insertar(unsigned long long a){

        // Este entero almacena el número de comparaciones realizadas en la inserción
        unsigned long n = 0;

        if(root == nullptr){
            Nodo* N = new Nodo(a);
            root = N;
            return n; // n va a ser 0
        }

        // *last almacena el último nodo visitado y *ptr el actual
        Nodo* ptr = root, *last;

        // direccion es 1 si se va hacia la derecha y 0 si se va hacia la izquierda
        bool direccion;

        while(ptr != nullptr){

            // Cada vez que *ptr es vacío se debe realizar una nueva comparación con el nodo actual 
            n++;

            if(ptr -> val == a){
                // Este caso ocurre cuando el elemento ya había sido insertado
                return n;
            }else if(ptr -> val < a){
                direccion = 1;
                last = ptr;
                ptr = ptr -> der;
            }else{
                direccion = 0;
                last = ptr;
                ptr = ptr -> izq;
            }

            // A pesar de que se puedan realizar 2 comparaciones en cada iteración,
            // solo la hemos contado como 1 (es una comparación humana), 
            // la constante 2 no altera la complejidad

        }

        // Al llegar al final, incluimos el nuevo nodo
        Nodo* N = new Nodo(a);
        if(direccion == 0){
            last -> izq = N;
        }else{
            last -> der = N;
        }


        return n;
    }




};

// Esta función realiza un árbol con N números aleatorios entre 0 y 10E18,
// regresa el número de comparaciones realizadas
unsigned long Arbolar(unsigned long N){

    BST Tree;

    // El sistema de números aleatorios
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine rgen(seed);
    uniform_int_distribution<unsigned long long> rdist(0,1E18);

    // Número de comparaciones totales
    unsigned long suma = 0;

    for(unsigned long i = 0; i<N; i++){
        suma += Tree.insertar(rdist(rgen));
    }

    return suma;
}


int main(){

    // Se calculan 51 casos entre 0 y 5E7 
    for(int i=0; i<=5E7; i+=1E6){
    
        cout << i << ", " << Arbolar(i) << endl;

    }

    return 0;
}


