#ifndef ALUMNOS_H
#define ALUMNOS_H

typedef struct{
    int numero;
    char nombre[30];
    float promedio;
}ALUMNO;

ALUMNO* leerArchivo(char archivo[30], int* alumnos);
void agregarAlumno(char archivo[30]);
void imprimirAlumnos(ALUMNO* lista, int numAlumnos);

#endif