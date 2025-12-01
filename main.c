#include <stdio.h>
#include <stdlib.h>

void help(void);
void menu(void);

int main(int arg, char* argv[]){
    char archivo[30];
    int eleccion;
    if(arg != 2){ //Si no recibe el nombre del archivo
        fprintf(stdout,"No hay sufucientes argumentos\n");
        help();
        exit(1);
    }
    do{
        menu();
        fscanf(stdin, "%d", &eleccion);
        if(eleccion == 1){
            fprintf(stdout,"Agregar alumno\n");
        }
        if(eleccion == 2){
            fprintf(stdout,"Eliminar alumno\n");
        }
        if(eleccion == 3){
            fprintf(stdout,"Editar alumno\n");
        }
        if(eleccion < 1 || eleccion > 4){
            fprintf(stderr,"No es una opcion valida\n");
        }
    }while(eleccion != 4);
}

void menu(void){
    fprintf(stdout,"1. Agregar alumnos\n");
    fprintf(stdout,"2. Eliminar alumno\n");
    fprintf(stdout,"3. Editar alumno\n");
    fprintf(stdout,"4. Salir\n");
    fprintf(stdout,"Ingresar: ");
}

void help(void){
    fprintf(stdout,"Faltaron o sobraron argumentos\n");
    fprintf(stdout,"Ingreselos de esta forma ./prueba <Nombre_del_archivo>\n");
}