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
struct Pila {

    Nodo<T>* head;

    Pila(){
        this -> head = nullptr;
    }

    ~Pila(){
        Nodo<T>* aux;
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
        // Si head es un apuntador nulo, la pila tiene que estar vacía
        if(this -> head == nullptr) return true;
        return false;
    }


    // Se ha creado este método adicional para reutilizar la misma pila
    void vaciar(){
        while(this-> head != nullptr){
            pop();
        }
    }

};


int main(){

    // número de strings a evaluar
    int n;

    std::cin >> n;

    Pila<char> P;

    std::string str = "";

    int indicator;

    // Aquí se recibe la línea donde se escribe el número de strings para desecharla
    std::getline(std::cin, str);

    for(int i = 0; i<n; i++){
        
        std::getline(std::cin, str);

        // Esta variable vale 1 si es un string correcto hasta el momento y será 0 cuando se verifica que es un string incorrecto
        indicator = 1;
        
        for(int j = 0; j<str.length(); j++){

            if(str[j] == '(' || str[j] == '['){
                P.push(str[j]);
                continue;
            }
          
            if(str[j] == ')'){

                // Si la pila está vacía, se está cerrando un paréntesis que no se abrió
                if(P.isempty()){ 
                    indicator = 0;
                    continue;
                }

                if(P.top() != '('){
                    indicator = 0;
                } else{
                    P.pop();
                }
                continue;
            }

            // Lo siguiente es exactamente igual al caso de ')' pero con ']'
            if(str[j] == ']'){
                if(P.isempty()){ 
                    indicator = 0;
                    continue;
                }
                if(P.top() != '['){
                    indicator = 0;
                } else{
                    P.pop();
                }
                continue;
            }

        }

        // Si la pila no está vacía, entonces no se cerraron corchetes o paréntesis
        if(!P.isempty()) indicator = 0;
        
        if(indicator){
            std::cout << "Yes" << std::endl;
        }else{
            std::cout << "No" << std::endl;
        }
       
        P.vaciar();
       
    }

    return 0;
}

