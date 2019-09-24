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

    printf("%4d %20s %15.2f %25s\n",miAlumno.legajo,miAlumno.nombre, miAlumno.promedio, miLocalidad.localidad);

}

void mostrarListadoAlumnos(eAlumno listadoDeAlumnos[], int tam,eLocalidad listaLocalidad[],int lenLocal)
{
    int i,j;
    int index;
    eLocalidad unaLocalidad;
    printf("\n%4s %20s %15s %25s\n","Id","Nombre","Promedio","Localidad");
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
    printf("\n");
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

    mostrar_localidades(listaDeLocalidad,lenLocal);

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

submenu_Mostrar(eAlumno listadoDeAlumnos[],int lenAl,eLocalidad listadoLocalidad[],int lenLocalidad)
{
    int opcion;

    //
    do
    {
        printf("%30s\n","SUB MENU MOSTRAR");
        printf("1. Mostrar todos los alumnos con la descripcion de su localidad\n2.Mostrar todas las localidades\n3.Mostrar por cada localidad, todos los alumnos que viven en ella\n4.Mostrar los alumnos que viven en Avellaneda\n5.Mostrar la localidad con menos habitantes\n7.Salir al menu\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            borrar();
                mostrarListadoAlumnos(listadoDeAlumnos, lenAl,listadoLocalidad,lenLocalidad);
            pausa();
            break;
        case 2:
            borrar();
                mostrar_localidades(listadoLocalidad,lenLocalidad);
            pausa();
            break;
        case 3:
            borrar();
                mostrar_porLocalidad(listadoDeAlumnos, lenAl,listadoLocalidad,lenLocalidad);
            pausa();
            break;
        case 4:
            borrar();
            pausa();
            break;
        case 5:
            borrar();
            pausa();
            break;
        }
        borrar();
    }
    while(opcion!=7);



}
void mostrar_porLocalidad(eAlumno listadoDeAlumnos[],int lenAl,eLocalidad listadoLocalidad[],int lenLocalidad)
{

    int i,j;

    for(i=0;i<lenLocalidad;i++)
    {
        printf("%30s\n",listadoLocalidad[i].localidad);
        for(j=0;j<lenAl;j++)
        {

            if(listadoLocalidad[i].idLocalidad==listadoDeAlumnos[j].idLocalidad)
            {
                mostrarUnAlumno(listadoDeAlumnos[j],listadoLocalidad[i]);

            }
        }

        printf("\n");
    }

}
void mostrar_Unalocalidad(eLocalidad listadoLocalidad)
{
    printf("%5d %20s %15d\n\n", listadoLocalidad.idLocalidad,listadoLocalidad.localidad,listadoLocalidad.codigoPostal);

}

void mostrar_localidades(eLocalidad listadoLocalidad[],int len)
{
    int i;
    printf("\n%5s %20s %20s\n","ID","Descripcion","CodigoPostal");
    for(i=0; i<len; i++)
    {
        mostrar_Unalocalidad(listadoLocalidad[i]);
    }


}
void pausa()
{
    //if(sysOp==1)
    //
        system("read -p 'Press Enter to continue...' var");
    //}
    //if (sysOp==2)
    //{
    //    system("pause");
    //}
}
void borrar()
{
    //if(sysOp==1)
    //{
        system("clear");
    //}
    //if (sysOp==2)
    //{
    //    system("cls");
    //}
}









