#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "funciones.h"

int main()
{
    EMovie* movie;
    char seguir='s';
    int opcion=0;

    movie=(EMovie*) malloc(sizeof(EMovie));

    while(seguir=='s')
    {
        muestraTitulo();
        printf("1- Contenido de archivo\n");
        printf("2- Agregar pelicula\n");
        printf("3- Borrar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");
        printf("\nElija una opcion\n");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            verEstadoDeArchivo(movie);
            break;
        case 2:
            if(movie != NULL)
            {
                agregarPelicula(movie);
            }
            break;
        case 3:
            borrarPelicula(movie);
            if(1)
            {
                printf("Pelicula borrada exitosamente\n");
            }
            else
            {
                printf("Error al borrar pelicula\n");
            }
            break;
        case 4:
            generarPagina(movie);
            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("Ingrese una opcion valida\n");
            break;
        }
    }

    return 0;
}
