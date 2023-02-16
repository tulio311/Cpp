#include <iostream>

class Nodo {

public:
    int dato; 
    Nodo* next;

    Nodo(int D){
        this -> dato = D;
        next = NULL;
    }
};


class lista_ligada_simple {

private:
    Nodo* cabeza;        

public:

    lista_ligada_simple(){
        cabeza = NULL;
    }
    ~lista_ligada_simple(){
        Nodo* ap = cabeza;
        Nodo* aux;  // Este apuntador es el que va a ir eliminando la memoria

        while(ap != NULL){
            aux = ap;
            ap = ap -> next;
            delete aux;  
        }
    }

    void insertar_inicio(int D){
        Nodo* N = new Nodo(D);
        N -> next = cabeza;
        cabeza = N;
    }

    void pop(){
        // Para evitar problemas si la lista es vacía
        if(cabeza == NULL) return;
        
        Nodo* aux = cabeza -> next;
        delete cabeza;
        cabeza = aux;
    }

    void imprime_lista(){
        Nodo* ap = this -> cabeza;
        while(ap != NULL){ // Si el apuntador es nulo, significa que ya terminó la lista

            std::cout << ap -> dato << " ";
            ap = ap -> next;
            
        }
        std::cout << std::endl;
    }

};


int main(){

    
    lista_ligada_simple L;

    std::cout << "Lista despues de ser creada: "; L.imprime_lista();

    L.insertar_inicio(1);

    std::cout << "Lista despues de agregar 1: "; L.imprime_lista();

    L.insertar_inicio(1);

    std::cout << "Lista despues de agregar 1: "; L.imprime_lista();

    L.insertar_inicio(2);

    std::cout << "Lista despues de agregar 2: "; L.imprime_lista();

    L.pop();

    std::cout << "Lista despues de hacer pop: "; L.imprime_lista();

    return 0;
}