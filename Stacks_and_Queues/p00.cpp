#include <iostream>

template<class T>
struct Nodo {
    T val;
    Nodo<T>* next;
    Nodo(T val){
        this -> val = val;
        this -> next = nullptr;
    }
};


template<class T>
struct Pila {

    Nodo<T>* head;

    Pila(){
        this -> head = nullptr;
    }

    ~Pila(){
        Nodo<T>* aux;
        // Vamos eliminando de uno en uno hasta que la pila esté vacía
        while(this -> head != nullptr){
            aux = this -> head;
            this -> head = (this -> head) -> next;
            delete aux;
        }
    }

    void push(T val){
        Nodo<T>* N = new Nodo<T>(val);
        N -> next = this -> head;
        this -> head = N;
    }

    void pop(){
        if(this -> head == nullptr) return;
        Nodo<T>* aux = this -> head;
        this -> head = (this -> head) -> next;
        delete aux;
    }

    T top(){
        return head -> val;
    }

    bool isempty(){
        if(this -> head == nullptr) return true;
        return false;
    }

};