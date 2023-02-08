#include <iostream>
// Se quitó el .h en iostream porque ya no forma parte del lenguaje

static const int N = 10000;

int main(){
	
	int i,p,q,id[N];
	
	for(i=0; i<N; i++) id[i] = i;
	
	// Tanto cin como cout y endl pertenecen al namespace std
	while(std::cin >> p >> q){
		
		int t = id[p];
		
		if(t == id[q]) continue;
		
		for(i=0; i<N; i++)
			if(id[i] == t) id[i] = id[q];
		std::cout << " " << p << " " << q << std::endl;
		
	}
	
	return 0;
}
