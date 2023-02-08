#include <iostream>
// Se quitó el .h en iostream porque ya no forma parte del standard de c++ y genera error

static const int N = 10;

int main(){
	
	int i,j,p,q,id[N],sz[N];
	// Se agregó la declaración de la j
	
	for(i=0; i<N; i++) id[i] = i;
    for(i=0; i<N; i++) sz[i] = 1;
    // Esta ultima linea se agrego para inicializar el arreglo sz 

    // Print the content of the array at the beginning

    for(i=0; i<N; i++){
        std::cout << id[i] << " ";
    } std::cout << std::endl;
	
	// Tanto cin como cout y endl pertenecen al namespace std
	while(std::cin >> p >> q){
		
		for(i=p; i!=id[i]; i=id[i]);
		for(j=q; j!=id[j]; j=id[j]);
			
		if(i == j) continue;
        if(sz[i] < sz[j]){
            id[i] = j;
            sz[j] += sz[i]; }
        else{
            id[j] = i;
            sz[i] += sz[j]; }
		// Print the content of the array at the end of the current iteration

        for(i=0; i<N; i++){
            std::cout << id[i] << " ";
        } std::cout << std::endl;
		
		std::cout << "Pair " << p << ", " << q << " gives a new connection " << std::endl;
		
	}
	
	return 0;
}