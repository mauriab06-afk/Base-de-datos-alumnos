#include <stdio.h>
#include <stdlib.h>
#include "alumnos.h"

ALUMNO* leerArchivo(char archivo[30], int* alumnos){
    FILE* fr;
    ALUMNO* lista;
    long tam; //Tamaño del archivo en bits
    if((fr = fopen(archivo, "rb")) == NULL){
        fprintf(stdout,"No se pudo abrir el archivo\n");
        exit(1);
    }
    fseek(fr,0,SEEK_END); //Vamos al final del archivo
    tam = ftell(fr); //Leemos en donde estamos
    rewind(fr);
    *alumnos = tam / sizeof(ALUMNO); // Asi sabemos cuantos alumnos hay
    lista = calloc(*alumnos,sizeof(ALUMNO));
    fread(lista, sizeof(ALUMNO), *alumnos, fr); //Leemos y guardamos en lista
    fclose(fr);
    return lista; //Numero de alumnos
}

void agregarAlumno(char archivo[30]){
    FILE* fa;
    ALUMNO nuevo;
    if((fa = fopen(archivo, "ab")) == NULL){
        fprintf(stdout,"No se pudo abrir el archivo\n");
        exit(1);
    }
    fprintf(stdout, "Ingrese el numero del alumno: ");
    fscanf(stdin,"%d", &nuevo.numero);
    fprintf(stdout, "Ingrese el nombre del alumno: ");
    fscanf(stdin,"%s", nuevo.nombre);
    fprintf(stdout, "Ingrese el promedio del alumno: ");
    fscanf(stdin,"%f", &nuevo.promedio);
    fwrite(&nuevo,sizeof(ALUMNO),1,fa);
    fclose(fa);
}

void imprimirAlumnos(ALUMNO* lista, int numAlumnos){
    int i;
    for(i = 0; i < numAlumnos; i++){
        fprintf(stdout,"%d. %d %s %.2f\n",i + 1, lista[i].numero, lista[i].nombre, lista[i].promedio);
    }
}

