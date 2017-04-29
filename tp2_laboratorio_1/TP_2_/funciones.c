#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <conio.h>
#include <string.h>

/** \brief esta funcion se uso de prueba para cargar 10 personas
 * \param tam es el tamaño del array persona
 * \return no tiene retorno
 *
 */

void cargar10Personas (EPersonas arrayPersona[], int tam)
{
    int i;

    char nombres[10][50]= {"juan","maria","pedro","luis","romina","jose","andrea","patricia","luciano","camila"};
    int estado[10]= {1,1,1,1,1,1,1,1,1,1};
    int dni[10]= {100,101,102,103,104,105,106,107,108,109};
    int edad[10]= {12, 25, 37, 45, 22, 9, 98, 34, 80, 4};

    for(i=0; i<tam; i++)
    {
        strcpy(arrayPersona[i].nombre, nombres[i]);
        arrayPersona[i].flagEstado = estado[i];
        arrayPersona[i].dni = dni[i];
        arrayPersona[i].edad= edad[i];
    }
}

/** \brief esta funcion inicializa el array de personas en 0
 * \param tamanio es el tamaño del array personas
 * \param valor es el valor con el que lo voy a inicializar, es decir, cero
 * \return no tiene retorno
 *
 */

void inicializarPersonas(EPersonas arrayPersona[], int tamanio, int valor)
{
    int i;
    for(i=0; i<tamanio; i++)
    {
        arrayPersona[i].flagEstado=valor;
    }
}

/** \brief esta funcion ordena el array persona por nombre en orden alfabetico
 * \param tamanio es el tamaño del array
 * \return no tiene retorno
 *
 */


void ordenarPorNombre(EPersonas arrayPersona[], int tamanio)
{
    int i, j;
    EPersonas auxPersona;

    for(i=0; i<tamanio-1; i++)
    {
        if(arrayPersona[i].flagEstado==0)
        {
            continue;
        }
        for(j=i+1; j<tamanio; j++)
        {
            if (arrayPersona[j].flagEstado==0)
            {
                continue;
            }
            if(stricmp(arrayPersona[i].nombre, arrayPersona[j].nombre)>0)
            {
                auxPersona=arrayPersona[j];
                arrayPersona[j]=arrayPersona[i];
                arrayPersona[i]=auxPersona;
            }
        }
    }
}
/** \brief esta funcion se usa para mostrar los nombres ordenados alfabeticamente
 * \param tamanio es el tamaño del array
 * \return no tiene retorno
 *
 */

void mostrarPorNombre(EPersonas arrayPersona[], int tamanio)
{
    int i;
    for(i=0; i<tamanio; i++)
    {
        if (arrayPersona[i].flagEstado!=0)
        {
            printf("%s\t%d\t %d\t\n", arrayPersona[i].nombre, arrayPersona[i].edad, arrayPersona[i].dni);
        }
    }

}



