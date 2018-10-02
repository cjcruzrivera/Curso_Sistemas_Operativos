
#include "fileutil.h"



int main(int argc, char** argv) {
	char ** archivos;
        char *dir;
	dir = (char *)malloc (100 * sizeof(char *));
	dir = argv[1];	
		
	archivos = (char **)malloc(sizeof(char)*1000); 
	
	int i = 0, j = 0, tamanoTotal, numeroArc = contarArchivos(dir);

	for(i;i<numeroArc;i++){
		archivos[i] = (char *)malloc (100 * sizeof(char *));
	}
	archivos = listarArchivos(dir);

	for(j; j<numeroArc;j++){
		tamanoTotal =+ tamanoArchivo(archivos[j]);
	}
	
	printf("Estudiante 1: 201428907\n");
	printf("Total archivos: %d\n", numeroArc);
	printf("Total bytes: %d\n",tamanoTotal);
}



