#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#define P 20

int main()
{
    EPersonas arrayPersona[P];
    inicializarPersonas(arrayPersona, P, 0);

    char seguir='s';
    int opcion=0;
    char respuesta;
    int i;
    int flagCapacidad;
    char auxNombre[50];
    int menoresA18=0, de19a36=0, mayoresA36=0;


    while(seguir=='s')
    {
        printf("\n1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            flagCapacidad=0;
            for(i=0; i<P; i++)
            {
                if(arrayPersona[i].flagEstado==0)
                {
                    printf("Ingrese nombre: ");
                    fflush(stdin);
                    gets(arrayPersona[i].nombre);
                    printf("Ingrese edad: ");
                    scanf("%d", &arrayPersona[i].edad);
                    printf("Ingrese dni: ");
                    scanf("%d", &arrayPersona[i].dni);
                    arrayPersona[i].flagEstado=1;
                    flagCapacidad=1;
                    break;
                }
            }
            if(flagCapacidad==0)
            {
                printf("No hay mas espacio disponible\n");
            }
            //cargar10Personas(arrayPersona, 10);
            system("pause");
            system("cls");
            break;
        case 2:
            flagCapacidad=0;
            printf("Ingrese nombre de la persona que desea borrar: ");
            fflush(stdin);
            gets(auxNombre);
            for(i=0; i<P; i++)
            {
                if(stricmp(arrayPersona[i].nombre,auxNombre)==0 && arrayPersona[i].flagEstado==1)
                {
                    printf("Esta seguro que desea borrarla? s/n\n");
                    respuesta=getche();
                    if(respuesta=='s')
                    {
                        arrayPersona[i].flagEstado=0;
                        printf("\nLa persona ha sido borrada ");
                    }
                    else
                    {
                        printf("Opcion cancelada");
                    }
                    flagCapacidad=1;
                    break;
                }
            }
            if(flagCapacidad==0)
            {
                printf("Persona no encontrada");
            }
            break;
        case 3:
            ordenarPorNombre(arrayPersona, P);
            mostrarPorNombre(arrayPersona, P);
            break;
        case 4:
            for(i=0; i<P; i++)
            {
                if(arrayPersona[i].flagEstado==1)
                {
                    if(arrayPersona[i].edad<18)
                    {
                        menoresA18++;
                    }
                    else if(arrayPersona[i].edad>18 && arrayPersona[i].edad<36)
                    {
                        de19a36++;
                    }
                    else
                    {
                        mayoresA36++;
                    }
                }

            }


            for(i=0; i<menoresA18; i++)
            {
                if(arrayPersona[i].flagEstado==1)
                {
                    printf("\n * ");
                    printf("\n ");
                }
                else
                {
                    printf(" ");
                }

            }

            for(i=0; i<de19a36; i++)
            {
                if(arrayPersona[i].flagEstado==1)
                {
                    printf("\n\t * ");
                    printf("\n ");
                }
                else
                {
                    printf(" ");
                }

            }

            for(i=0; i<mayoresA36; i++)
            {
                if(arrayPersona[i].flagEstado==1)
                {
                    printf("\n\t\t * ");
                    printf("\n ");
                }
                else
                {
                    printf(" ");
                }

            }
            printf("<18--de19a36-->36");
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("Ingreso una opcion invalida. Reingrese opcion de 1 a 5");
        }

    }
    return 0;
}
