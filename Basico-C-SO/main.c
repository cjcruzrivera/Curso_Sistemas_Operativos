#include <stdio.h>
#include <stdlib.h>
#include "fibo.h"
#include <stdbool.h>

int main(int argc, char** argv){
	bool resp = true;
	
	while(resp){		

		int num,fibonacci;
		char res;
		
		printf("Ingrese el numero al cual desea calcular el fibonacci:\n"); //le pedimos al usuario un dato
 		scanf("%i", &num);
		fibonacci = fibo(num);			

		printf("El fibonaci de %d es: %d", num,fibonacci);
		printf("\n¿Desea calcular otro fibonacci? S / N\n");
		scanf("%s", &res);		

		if(res == 'N'){
			resp = false;		
		}else{
			resp = true;			
		}
		
			
	}
	return 0;
}
