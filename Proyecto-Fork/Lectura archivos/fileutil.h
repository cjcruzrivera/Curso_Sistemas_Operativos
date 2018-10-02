#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

char** listarArchivos(char *cadena);
int tamanoArchivo(char *archivo);
int contarArchivos(char *cadena);
