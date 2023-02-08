#include <iostream>
// Se quito el .h en iostream porque ya no forma parte del lenguaje

static const int N = 10000;

int main(){
	
	int i,j,p,q,id[N];
	// Se agrego la declaracion de la j
	
	for(i=0; i<N; i++) id[i] = i;
	
	// Tanto cin como cout y endl pertenecen al namespace std
	while(std::cin >> p >> q){
		
		for(i=p; i!=id[i]; i=id[i]);
			for(j=q; j!=id[j]; j=id[j]);
			
		if(i == j) continue;
		id[i] = j;
		
		std::cout << " " << p << " " << q << std::endl;
		
	}
	
	return 0;
}
