
#include "fileutil.h"

char** listarArchivos(char *cadena){

  DIR *dir;
  char** archivos;

  //numero archivos
  int n,i = 0;
  n = contarArchivos(cadena);

  archivos = malloc(n * sizeof(char));
  struct dirent *archivo;

  dir = opendir (cadena);
  

  if (dir == NULL){
	printf("error al abrir el directorio");
  }else{
	
	while ((archivo = readdir (dir)) != NULL) 
    {
     if (archivo->d_type != DT_DIR) 
    {
	archivos[i] = (char *)malloc(50 * sizeof(char *));
	strcpy(archivos[i],archivo->d_name);
       
	i++;

    }
    }
  closedir (dir);
  }

  return archivos;

}

int contarArchivos(char *cadena){

  DIR *dir;
  
  //numero archivos
  int n;

  struct dirent *archivo;

  dir = opendir (cadena);

  while ((archivo = readdir (dir)) != NULL) {
      if ( (strcmp(archivo->d_name, ".")!=0) && (strcmp(archivo->d_name, "..")!=0)){
      	n += 1;
      }
    }
  closedir (dir);
  return n;
}


int tamanoArchivo(char *archivo){
	FILE *fp;
        int count = 0;

        // Se abre el archivo y se contara caracter por caracter el numero 
        // de bytes del archivo
        fp = fopen(archivo,"r");
        if (fp == NULL) {
		return -1;
               
        }else
          while (fgetc(fp) != EOF) {
                count++;
           }
        fclose(fp);
  
	return count;
}
















