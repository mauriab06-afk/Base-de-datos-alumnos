#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumnos.h"

void help(void);
void menu(void);

int main(int arg, char* argv[]){
    char archivo[30];
    int eleccion;
    ALUMNO* lista;
    int numAlumnos;
    if(arg != 2){ //Si no recibe el nombre del archivo
        fprintf(stdout,"No hay sufucientes argumentos\n");
        help();
        exit(1);
    }
    strcpy(archivo,argv[1]);
    do{
        lista = leerArchivo(archivo, &numAlumnos);
        fprintf(stdout,"Numero de alumnos: %d\n", numAlumnos);
        menu();
        fscanf(stdin, "%d", &eleccion);
        if(eleccion == 1){
            fprintf(stdout,"Agregar alumno\n");
            agregarAlumno(archivo);
        }
        if(eleccion == 2){
            fprintf(stdout,"Eliminar alumno\n");
        }
        if(eleccion == 3){
            fprintf(stdout,"Editar alumno\n");
        }
        if(eleccion == 4){
            fprintf(stdout,"Lista de alumnos\n");
            imprimirAlumnos(lista,numAlumnos);
        }
        if(eleccion < 1 || eleccion > 5){
            fprintf(stderr,"No es una opcion valida\n");
        }
    }while(eleccion != 5);
}

void menu(void){
    fprintf(stdout,"1. Agregar alumnos\n");
    fprintf(stdout,"2. Eliminar alumno\n");
    fprintf(stdout,"3. Editar alumno\n");
    fprintf(stdout,"4. Imprimir lista de alumnos\n");
    fprintf(stdout,"5. Salir\n");
    fprintf(stdout,"Ingresar: ");
}

void help(void){
    fprintf(stdout,"Faltaron o sobraron argumentos\n");
    fprintf(stdout,"Ingreselos de esta forma ./prueba <Nombre_del_archivo>\n");
}