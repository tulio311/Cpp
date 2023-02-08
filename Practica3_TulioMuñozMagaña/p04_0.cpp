#include<iostream>
#include<sstream>
#include <iomanip>

using namespace std; 

struct point{ 
  double * coords; 
  int d; 
  point(){
    this->coords = nullptr; 
    this->d = 0; 
  };
  point(int d){
    this->d = d; 
    this->coords = new double[d]; 
    for(int i=0; i < this->d; i+=1){ 
      this->coords[i] = 0;
    }; 
  }
  virtual ~point(){delete[] this->coords;}
  virtual string to_s(void){ 
    stringstream ss;
    ss << "pointNd:";
    for(int i=0; i < this->d-1; i+=1){ss << " " << fixed << setprecision(1) << this->coords[i];} 
    ss << " " << this->coords[this->d-1];
    return ss.str();
  } 
};

// Inicio <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// Estructura point2d
struct point2d : point{ 

  point2d(double x, double y){
    this->d = 2; 
    this->coords = new double[2];
    this->coords[0] = x;
    this->coords[1] = y;
  };

  virtual string to_s(void){ 
    stringstream ss;
    ss << "point2d:";
    ss << " x:" << fixed << setprecision(1) << this->coords[0]; 
    ss << " y:" << fixed << setprecision(1) << this->coords[1];
    return ss.str();
  } 
};

// Estructura point3d
struct point3d : point{ 
  
  point3d(double x, double y, double z){
    this->d = 3; 
    this->coords = new double[3]; 
    this->coords[0] = x;
    this->coords[1] = y;
    this->coords[2] = z;
  };
  
  virtual string to_s(void){ 
    stringstream ss;
    ss << "point3d:";
    ss << " x:" << fixed << setprecision(1) << this->coords[0]; 
    ss << " y:" << fixed << setprecision(1) << this->coords[1]; 
    ss << " z:" << fixed << setprecision(1) << this->coords[2];
    return ss.str();
  } 
};

// Estructura arreglo 
struct arreglo{
  point ** mem = nullptr; 
  int      tam = 0; 
  arreglo(int tam){
    this->tam = tam;
    this->mem = new point*[tam];
    for(int i = 0; i<tam; i++) this->mem[i] = new point;
  }
  ~arreglo(){
    int i; 
    for(i = 0; i < this->tam; i++){delete this->mem[i];} 
    delete[] this->mem;
    }
  void set(int i, point * p){ 
    delete mem[i];
    this->mem[i] = p;
  } 
  point * get(int i){
    return mem[i];
  } 
  void map(void (g)(point &p)){ 
    for(int i = 0; i<this->tam; i++){
      g(*mem[i]);
    }
  }; 
}; 

// Fin <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

int main(int num_args, char **args){ 
  
  arreglo arr(5); 
  arr.set(0,new point(5)); 
  arr.set(1,new point2d(3,3)); 
  arr.set(2,new point3d(3,3,3)); 
  arr.set(3,new point(5)); 
  arr.set(4,new point(5)); 
  arr.map([](point &p){p.coords[0] = 1;});
  for(int i=0; i < arr.tam; i+=1){ cout << arr.get(i)->to_s() << endl;} 

  return 0;
}
