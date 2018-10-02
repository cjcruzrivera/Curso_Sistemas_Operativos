#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

void fileSize(char *archivo){
	
// Definicion e inicializacion de variables
        FILE *fp;
        int count = 0;

        // Se abre el archivo y se contara caracter por caracter el numero 
        // de bytes del archivo
        fp = fopen(archivo,"r");
        if (fp == NULL) {
                perror("filesize - No se pudo abrir archivo\n");
               
        }
        while (fgetc(fp) != EOF) {
                count++;
        }
        fclose(fp);
  
 
      printf ("file: %s size: %d bytes\n", archivo, count);
   
}

int main(int argc, 
         char** argv) {
	
	DIR *dir;

  	struct dirent *arch;
	struct stat tipo;
  	
  	dir = opendir(".");

	if (dir != NULL){
		while((arch = readdir(dir)) != NULL){
			stat(arch->d_name,&tipo);
			if(!S_ISDIR(tipo.st_mode)) {
            			fileSize(arch->d_name);
        		}
		}
	}
	else{
	   printf("Error al leer el directorio");
	}
	closedir (dir);
	 
}

	


