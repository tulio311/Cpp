#include <iostream>

class Nodo {

public:
    int dato; 
    Nodo* next;
    Nodo* prev;

    Nodo(int D){
        this -> dato = D;
        this -> next = NULL;
        this -> prev = NULL;
    }
};


class lista_ligada_doble {

private:
    

public:

    Nodo* cabeza;
    Nodo* final;

    lista_ligada_doble(){
        this -> cabeza = NULL;
        this -> final = NULL;
    }
    ~lista_ligada_doble(){
        Nodo* ap = cabeza;
        Nodo* aux;

        // Se destruye igual que una lista ligada simple
        while(ap != NULL){
            aux = ap;
            ap = ap -> next;
            delete aux;  
        }
    }

    void insertar_final(int D){
        
        // Caso de lista vacía, tanto final como cabeza apuntan al único elemento
        if(this -> cabeza == NULL){
            Nodo* N = new Nodo(D);
            this -> cabeza = N;
            this -> final = this -> cabeza;
            return;
        }

        Nodo* N = new Nodo(D);
        (this -> final) -> next = N;
        N -> prev = this -> final;
        N -> next = NULL;
        this -> final = N;
    }

    void pop(){
        // Evitar problemas si la lista es vacía
        if(cabeza == NULL) return;

        Nodo* aux = cabeza;
        cabeza = cabeza -> next;
        cabeza -> prev = NULL;
        delete aux;
    }

    void imprime_lista(){
        Nodo* ap = this -> final;
        while(ap != NULL){ // Si esto ocurre, entonces ya terminó la lista

            std::cout << ap -> dato << " ";
            ap = ap -> prev;
            
        }
        std::cout << std::endl;
    }

};


int main(){

    
    lista_ligada_doble L;

    std::cout << "Lista despues de ser creada: "; L.imprime_lista();

    L.insertar_final(1);
    
    std::cout << "Lista despues de agregar 1: "; L.imprime_lista();

    L.insertar_final(3);

    std::cout << "Lista despues de agregar 3: "; L.imprime_lista();

    L.insertar_final(4);

    std::cout << "Lista despues de agregar 4: "; L.imprime_lista();

    L.pop();

    std::cout << "Lista despues de hacer pop: "; L.imprime_lista();

    return 0;
}