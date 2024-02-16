#include <iostream>

template<class T>
struct Nodo {
    T val;
    T* next;
    Nodo(T val){
        this -> val = val;
        this -> next = nullptr;
    }
};


template<class T>
struct Cola {

    Nodo<T>* head;
    Nodo<T>* tail;

    Cola(){
        this -> head = nullptr;
        this -> tail = nullptr;
    }

    ~Cola(){
        while(this -> head = (this -> head) -> next)
            delete head;
    }

    enqueue(T val){
        if(this -> head == nullptr){
            Nodo<T>* N(val);
            this -> tail = N;
            this -> head = N;
            N.next = nullptr;
        }
        Nodo<T>* N(val);
        (this -> tail) -> next = N;
        N -> next = nullptr;
    }

    dequeue(){
        if(this -> head = nullptr) return;
        Nodo* aux = this -> head;
        this -> head = (this -> head) -> next;
        delete aux;
    }

    next(){
        return (this -> head) -> val;
    }

    last(){
        return (this -> tail) -> val;
    }

    isempty(){
        if(head = nullptr) return true;
        return false;
    }

};