#include <iostream>
#include <string>

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
struct Cola {

    Nodo<T>* head;
    Nodo<T>* tail;

    Cola(){
        this -> head = nullptr;
        this -> tail = nullptr;
    }

    ~Cola(){
        Nodo<T>* aux;
        while(this -> head != nullptr){
            aux = this -> head;
            this -> head = (this -> head) -> next;
            delete aux;
        }
    }

    void enqueue(T val){
        if(this -> head == nullptr){
            Nodo<T>* N = new Nodo<T>(val);
            this -> tail = N;
            this -> head = N;
            N -> next = nullptr;
            return;
        }
        Nodo<T>* N = new Nodo<T>(val);
        (this -> tail) -> next = N;
        this -> tail = N;
        (this -> tail ) -> next = nullptr;
    }

    void dequeue(){
        if(this -> head == nullptr) return;
        Nodo<T>* aux = this -> head;
        this -> head = (this -> head) -> next;
        delete aux;
    }

    T next(){
        return (this -> head) -> val;
    }

    T last(){
        return (this -> tail) -> val;
    }

    bool isempty(){
        if(this -> head == nullptr) return true;
        return false;
    }

};

int main(){

    Cola<int> LadoIzq;
    Cola<int> LadoDer;

    int c; // Número de casos
    int l; // Largo del barco en metros
    int m; // Número de carros
    int largo; // Largo de cada carro
    int barco; // Esta variable es 0 si el barco está en el lado izquierdo y 1 si está en el lado derecho
    int contador = 0; // Cuenta el número de cruces del barco hasta el momento
    int suma = 0; // Esta variable nos ayudará a saber cuándo el barco está lleno

    std::string lado; // Guarda si un carro está en "left" o "right"

    std::cin >> c;

    for(int i=0; i<c; i++){

        std::cin >> l;
        l = 100*l; // Convertimos la longitud del barco a cm

        std::cin >> m;

        // Creamos las colas de los dos lados
        for(int j=0; j<m; j++){

            std::cin >> largo;
            std::cin >> lado;

            if(lado == "left"){
                LadoIzq.enqueue(largo);
            }
            if(lado == "right"){
                LadoDer.enqueue(largo);
            }

        }

        // El barco comienza en el lado izquierdo
        barco = 0;
        
        while(!LadoIzq.isempty() || !LadoDer.isempty()){

            if(barco == 0){
                
                // Si no hay carros en este lado, tenemos que ir al otro porque del otro lado si hay,
                // ya que entramos al while
                if(LadoIzq.isempty()){
                    barco = 1;
                    contador++;
                    suma=0;
                    continue;
                }

                // este bucle llena el barco de carros hasta su máxima capacidad
                // o hasta que se acaben los carros en ese lado
                while(suma + LadoIzq.next() <= l){
                    
                    suma += LadoIzq.next();
                    LadoIzq.dequeue();
                    
                    if(LadoIzq.isempty()){
                        break;
                    }
                }

                barco = 1;
    
            }else if(barco == 1){
                
                // Este bloque es análogo al anterior, pero del otro lado

                if(LadoDer.isempty()){
                    barco = 0;
                    contador++;
                    suma=0;
                    continue;
                }

                while(suma + LadoDer.next() <= l){
                    
                    suma += LadoDer.next();
                    LadoDer.dequeue();
                    
                    if(LadoDer.isempty()){
                        break;
                    }
                }

                barco = 0;
                
            }

            contador++;
            suma=0;
        }
        
        std::cout << contador << std::endl;
        contador = 0;

    }

    return 0;
}

