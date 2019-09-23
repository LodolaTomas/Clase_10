#include "funciones.h"
#define A 5
#define L 3

int main()
{


    int i;
    eAlumno listadodeAlumnos[A];
    eLocalidad listaLocalidades[L]={{100,"Avellaneda",1870},{101,"Wilde",1872},{102,"Lomas de Zamora",1840}};

    harcodeoAlumnos(listadodeAlumnos,A);



    /*
    do
    {



        printf("1. Cargar\n");
        printf("2. Mostrar\n");
        printf("3. Ordenar\n");
        printf("4. Borrar\n");
        //printf("5. Atras\n");
        printf("5. Salir\n\n");

        printf("Elija una opcion:");
        scanf("%d",&option);

        switch(option)
        {

        case 1:
            borrar();

            pausa();
            break;
        case 2:
            borrar();

            pausa();
            break;
        case 3:
            borrar();

            pausa();
            break;
        case 4:
            borrar();

            pausa();
            break;
        //case 5:
         //   printf("\nVolviendo atras\n");
          //  break;
        case 5:
            printf("\nHASTA LUEGO..");
            break;

        default:
            borrar();
            printf("ERROR. Elija una opcion del 1-5\n");
            pausa();
            break;

        }
        borrar();

    }
    while(option!=5);*/

    return 0;
}
























