#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define OCUPADO 1
#define LIBRE 0
#define A 5
#define L 3

typedef struct
{
    int id;
    char descripicion[64];
    int codPostal;

}eLocalidad;

typedef struct
{

    int legajo;
    char nombre[32];
    int promedio;
    int idLocalidad;
    int isEmpy;

}eAlumno;



void inicializarAlumnos(eAlumno listaDeAlumnos[],int cantidad,int inicializo);
void harcodeoAlumnos(eAlumno listaDeAlumnos[],int cantidad);
void mostrarAlumnos(eAlumno listaDeAlumnos[],int cantidad,eLocalidad listaDeLocalidad[]);
void mostrarAlumno(eAlumno alumno,eLocalidad localidad);

//int answersSysOp(void); Beta
void pausa();
void borrar();
