#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

int main(){

    int operaciones;
	std::cin >> operaciones;
	
	int num1,num2,len;
	float base,exp;
	std::string str, palabra;
    
	for(int i=0; i<operaciones; i++){
		std::cin >> str;
		
		if( str.compare("suma") == 0 ) {
			
			std::cin >> num1 >> num2; 
            std::cout << num1+num2 << std::endl;

        }else if ( str.compare("pow") == 0 ){

            std::cin >> base >> exp; 
            std::cout << std::fixed << std::setprecision(1) << pow(base,exp) << std::endl;
        }else if ( str.compare("concat") == 0 ){
            
			std::cin >> len;
            for(int j=0; j<len ; j++){
				std::cin >> palabra;
				std::cout << palabra;
			}
            
			std::cout << std::endl;

        }else{
            std::cout << "Entrada no válida";
        }
		
	}
    
    return 0;
}