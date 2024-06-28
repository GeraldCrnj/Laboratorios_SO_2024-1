#include <stdio.h>
#include <sys/stat.h>
#include <ctype.h>
#include <stdlib.h>

void contar_alfabeticos(){
    FILE *registro = fopen("RegistroPokemon.txt", "w");
    fprintf(registro,"Alfabético\n");
    int cantidad;
    struct dirent *read;
    char info[1024];
    for (char a ='A'; a <= 'Z'; a++){
        cantidad = 0;
        char path[256];
        snprintf(path, sizeof path,"./Alfabetico/%c",a);
        DIR *dir;
        dir = opendir(path);
        while ((read = readdir(dir)) != NULL){
            cantidad ++;
        }
        snprintf(info, sizeof(info), "%c - %i\n", a, cantidad);
        fprintf(registro,"%s",info);
    }
    fclose(registro);
}
