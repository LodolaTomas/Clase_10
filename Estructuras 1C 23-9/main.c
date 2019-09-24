#include <stdio.h>
#include <stdlib.h>
#include "Alumno.h"
#define A 5
#define L 3

int main()
{
    eAlumno listaDeAlumnos[A];
    eLocalidad listaLocalidades[L]= {{1,"Avellaneda",1870},{2,"Wilde",1872},{3,"Lomas de Zamora",1700}};
    int i;
    /*for(i=0;i<3;i++)
    {
        printf("%d - %s - %d\n", listaLocalidades[i].idLocalidad,listaLocalidades[i].localidad,listaLocalidades[i].codigoPostal);
    }*/


    int respuesta;
    int opcion;
    for(i=0; i<A; i++)
    {
        listaDeAlumnos[i].estado=LIBRE;
    }

    hardCodearAlumnos(listaDeAlumnos,A);

    do
    {
        printf("1.Cargar\n2.Mostrar\n3.Ordenar\n4.Eliminar\n5.Modificar\n7.Salir\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
        borrar();
            cargarListadoAlumnos(listaDeAlumnos,A,listaLocalidades,L);
        pausa();
            break;
        case 2:
        borrar();
            submenu_Mostrar(listaDeAlumnos,A,listaLocalidades,L);
        pausa();
            break;
        case 3:
        borrar();
            sortStudentsByNameAndAverage(listaDeAlumnos,A);
        pausa();
            break;
        case 4:
            respuesta = eliminarAlumno(listaDeAlumnos,A);
            switch(respuesta)
            {
            case 0:
                printf("Accion cancelada por el usuario\n");
                break;
            case 1:
                printf("Alumno eliminado\n");
                break;
            case -1:
                printf("Dato no encontrado\n");
                break;
            }

            break;
        case 5:

            respuesta = modificarAlumno(listaDeAlumnos,A,102);
            switch(respuesta)
            {
            case 0:
                printf("Accion cancelada por el usuario\n");
                break;
            case 1:
                printf("Alumno modificado\n");
                break;
            case -1:
                printf("Dato no encontrado\n");
                break;
            }
            break;
        }
        borrar();
    }
    while(opcion!=7);
    return 0;
}


