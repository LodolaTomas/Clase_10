#include "Alumno.h"
#include <string.h>

int buscarLibre(eAlumno listadoDeAlumnos[], int tam)
{

    int indice = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(listadoDeAlumnos[i].estado!=OCUPADO)
        {
            indice = i;
            break;
        }
    }
    return indice;

}


void hardCodearAlumnos(eAlumno listadoDeAlumnos[], int tam)
{
    int i;
    int legajo[]= {101,102,105};
    float promedio[]= {6.66, 4,7.66};
    char nombre[][25]= {"Juan","Maria josefina","Maria"};
    int localidad[]= {1,1,3};
    for(i=0; i<3; i++)
    {
        listadoDeAlumnos[i].legajo = legajo[i];
        listadoDeAlumnos[i].promedio = promedio[i];
        strcpy(listadoDeAlumnos[i].nombre, nombre[i]);
        listadoDeAlumnos[i].estado = OCUPADO;
        listadoDeAlumnos[i].idLocalidad=localidad[i];

    }
}
void mostrarUnAlumno(eAlumno miAlumno,eLocalidad miLocalidad)
{

    printf("%4d %25s %8.2f %25s\n",miAlumno.legajo,miAlumno.nombre, miAlumno.promedio, miLocalidad.localidad);

}

void mostrarListadoAlumnos(eAlumno listadoDeAlumnos[], int tam,eLocalidad listaLocalidad[],int lenLocal)
{
    int i,j;
    int index;
    eLocalidad unaLocalidad;
    for(i=0; i<tam; i++)
    {

        if(listadoDeAlumnos[i].estado==OCUPADO)
        {
            index  = buscarLocalidadId(listaLocalidad,lenLocal,listadoDeAlumnos[i].idLocalidad);
            if(index!=-1)
            {
                mostrarUnAlumno(listadoDeAlumnos[i],listaLocalidad[index]);
            }
        }
    }
}


int buscarLocalidadId(eLocalidad listaLocalidad[],int lenLocal,int idLocalidad)
{
    int i;
    int index=-1;

    for(i=0; i<lenLocal; i++)
    {
        if(idLocalidad==listaLocalidad[i].idLocalidad)
        {
            index=i;
            break;
        }
    }

    return index;
}

void cargarListadoAlumnos(eAlumno listadoDeAlumnos[], int tam,eLocalidad listaLocalidad[],int lenLocal)
{

    int indice;

    indice = buscarLibre(listadoDeAlumnos, tam);
    printf("Indice: %d\n", indice);
    if(indice!=-1)
    {
        //hay lugar
        listadoDeAlumnos[indice] = cargarAlumno(listaLocalidad,lenLocal);
    }
    else
    {
        printf("No hay espacio disponible");
    }

}

eAlumno cargarAlumno(eLocalidad listaDeLocalidad[],int lenLocal)
{
    eAlumno miAlumno;

    printf("Ingrese legajo: ");
    scanf("%d", &miAlumno.legajo);
    printf("Ingrese nombre: ");
    fflush(stdin);
    scanf("%s", miAlumno.nombre);
    printf("Ingrese promedio: ");
    scanf("%f", &miAlumno.promedio);

    int i;
    for(i=0; i<lenLocal; i++)
    {
        printf("%d - %s - %d\n", listaDeLocalidad[i].idLocalidad,listaDeLocalidad[i].localidad,listaDeLocalidad[i].codigoPostal);
    }

    printf("En que localidad vive?");
    scanf("%d", &miAlumno.idLocalidad);


    miAlumno.estado = OCUPADO;

    return miAlumno;
}


void sortStudentsByNameAndAverage(eAlumno listadoDeAlumnos[], int tam)
{
    int i;
    int j;
    eAlumno auxAlumno;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(strcmp(listadoDeAlumnos[i].nombre,listadoDeAlumnos[j].nombre)>0)
            {
                auxAlumno = listadoDeAlumnos[i];
                listadoDeAlumnos[i] = listadoDeAlumnos[j];
                listadoDeAlumnos[j] = auxAlumno;
            }

            else
            {
                if(strcmp(listadoDeAlumnos[i].nombre,listadoDeAlumnos[j].nombre)==0)
                {
                    if(listadoDeAlumnos[i].promedio>listadoDeAlumnos[j].promedio)
                    {
                        auxAlumno = listadoDeAlumnos[i];
                        listadoDeAlumnos[i] = listadoDeAlumnos[j];
                        listadoDeAlumnos[j] = auxAlumno;
                    }
                }
            }
        }

    }
}


int buscarAlumnoPorLegajo(eAlumno* listaDeAlumnos, int cant, int legajo)
{
    int i;
    int retorno = -1;


    if(listaDeAlumnos!=NULL && cant>0)
    {

        for(i=0; i<cant; i++)
        {
            if(listaDeAlumnos[i].legajo==legajo && listaDeAlumnos[i].estado==OCUPADO)
            {
                retorno = i;
                break;
            }
        }
    }


    return retorno;
}

int modificarAlumno(eAlumno listaDeAlumnos[], int cant, int legajo)
{
    int index;
    char nombre[30];
    int quePaso = -1;
    char respuesta;
    eAlumno aux;

    index = buscarAlumnoPorLegajo(listaDeAlumnos,cant, legajo);
    if(index!=-1)
    {
        aux = listaDeAlumnos[index];
//        mostrarUnAlumno(aux);
        printf("Ingrese el nuevo nombre: ");
        fflush(stdin);
        scanf("%s",aux.nombre);
        printf("Esta seguro que desea modificar este alumno? :");
        //respuesta = get();
        if(respuesta=='s')
        {
            listaDeAlumnos[index] = aux;
            quePaso = 1;
        }
        else
        {
            quePaso = 0;
        }

    }
    return quePaso;
}
int eliminarAlumno(eAlumno listadoDeAlumnos[], int tam)
{
    int legajo;
    int i;
    int flag = 0 ;
    char respuesta;

    int quePaso = -1;

    //mostrarListadoAlumnos(listadoDeAlumnos,tam,);

    printf("Ingrese el legajo: ");
    scanf("%d", &legajo);

    for(i=0; i<tam; i++)
    {
        if(listadoDeAlumnos[i].legajo==legajo && listadoDeAlumnos[i].estado==OCUPADO)
        {
            //mostrarUnAlumno(listadoDeAlumnos[i]);
            printf("Esta seguro que desea eliminar este alumno? :");
            //respuesta = getche();
            if(respuesta=='s')
            {
                listadoDeAlumnos[i].estado = LIBRE;
                quePaso = 1;
            }
            else
            {
                quePaso = 0;
            }
            break;
        }

    }

    return quePaso;

}


