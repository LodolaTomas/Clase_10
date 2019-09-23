#include "funciones.h"










void harcodeoAlumnos(eAlumno listaDeAlumnos[],int cantidad)
{
    int i;

    int legajo[]= {1,5,9,10,88};
    int isEmpy[]= {1,1,1,1,1};
    char nombre[][20]= {"juan","pedro","maria","julieta","pepe"};
    int nota[]= {10,2,9,4,6};
    int idLocalidad[]={101,101,102,100,100};

    for(i=0; i<cantidad; i++)
    {
        strcpy(listaDeAlumnos[i].nombre,nombre[i]);
        listaDeAlumnos[i].legajo=legajo[i];
        listaDeAlumnos[i].isEmpy=isEmpy[i];
        listaDeAlumnos[i].promedio=nota[i];
        listaDeAlumnos[i].idLocalidad=idLocalidad[i];

    }
}
void mostrarAlumnos(eAlumno listaDeAlumnos[],int cantidad,eLocalidad listaDeLocalidad[])
{

    int i;
    int flag=0;
    printf("%5s %10s %10s %10s\n","legajo","nombre","nota","localidad");
    for(i=0; i<cantidad; i++)
    {
        if(listaDeAlumnos[i].isEmpy==OCUPADO)
        {
            flag=1;
            mostrarAlumno(listaDeAlumnos[i],listaDeLocalidad[i]);
            //printf("indice[%d],estaVacio[%d]\n",i,listaDeAlumnos[i].isEmpy);
        }
    }
    if(flag==0)
    {
        printf("\n No hay alumnos para mostrar\n");
    }

}
void mostrarAlumno(eAlumno alumno,eLocalidad localidad)
{
    char description[64];
    int cP;
    if(alumno.idLocalidad==localidad.id)
    {
        localidad.descripicion;
        cP=localidad.codPostal;
    }

    printf("%5d %10s %10d %10d %10s %10d\n",alumno.legajo,alumno.nombre,alumno.promedio,description,cP);

}


















/*int answersSysOp(void)
{
    int option;
    int sysOp;

    do
    {

        printf("\nAntes de comenzar me gustaria preguntarle\n en que systema operativo esta trabajando?\n\t1. En Linux\n\t2. En Windows\nSu respuesta:");
        scanf("%d",&option);

        switch(option){

        case 1:

            sysOp=1;

            break;
        case 2:

            sysOp=2;

            break;
        default:
            printf("\n\tERROR. Elija una opcion [1-2]\n");
            break;
        }

    }
    while(option!=2 && option !=1);

    return sysOp;
} Beta */
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
