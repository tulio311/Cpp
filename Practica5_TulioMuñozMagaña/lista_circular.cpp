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


class lista_ligada_circular {

private:
    Nodo* cabeza;        

public:

    lista_ligada_circular(){
        cabeza = NULL;
    }
    ~lista_ligada_circular(){
        Nodo* ap = cabeza;
        Nodo* aux;

        while(ap -> next != cabeza){ // Si esto se cumple, significa que ya se ha dado la vuelta
            // La variable ap va a ir avanzando mientras
            // aux borra lo que va quedando atrás
            aux = ap;
            ap = ap -> next;
            delete aux;  
        }
        delete ap; // Borra la memoria del último elemento
    }

    void insertar_inicio(int D){

        if(cabeza == NULL){
            Nodo* N = new Nodo(D);
            cabeza = N;
            N -> next = N; // Se apunta a sí mismo
            return;
        }

        Nodo* N = new Nodo(D);
        N -> next = cabeza;

        Nodo* ap = cabeza;

        // Este while es para llegar al último elemento antes de dar la vuelta,
        // y apuntar este último elemento a la nueva cabeza
        while(ap -> next != cabeza){
            ap = ap -> next; 
        }

        ap -> next = N;
        cabeza = N;

    }

    void pop(){
        if(cabeza == NULL) return;
        
        Nodo* aux = cabeza -> next;
        Nodo* ap = cabeza;

        // Igual, nos vamos hasta el último elemento para
        // apuntar a la nueva cabeza
        while(ap -> next != cabeza){
            ap = ap -> next; 
        }
        ap -> next = aux;

        delete cabeza;
        cabeza = aux;
    }

    void imprime_lista(){
        // Si la lista es vacía imprimimos solo un salto de línea
        if(cabeza == NULL){
            std::cout << std::endl;
            return;
        }

        Nodo* ap = this -> cabeza;
        while(ap -> next != cabeza){ // Si esto ocurre, significa que ya dimos la vuelta

            std::cout << ap -> dato << " ";
            ap = ap -> next;
            
        }
        std::cout << ap -> dato << " "; // Imprime el último elemento

        std::cout << std::endl;
    }

};


int main(){

    
    lista_ligada_circular L;

    std::cout << "Lista despues de ser creada: "; L.imprime_lista();

    L.insertar_inicio(1);

    std::cout << "Lista despues de agregar 1: "; L.imprime_lista();

    L.insertar_inicio(2);

    std::cout << "Lista despues de agregar 2: "; L.imprime_lista();

    L.insertar_inicio(6);

    std::cout << "Lista despues de agregar 6: "; L.imprime_lista();

    L.insertar_inicio(24);

    std::cout << "Lista despues de agregar 24: "; L.imprime_lista();

    L.pop();

    std::cout << "Lista despues de hacer pop: "; L.imprime_lista();

    return 0;
}