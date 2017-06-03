#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "funciones.h"

/** \brief funcion para mostrar titulo de programa
 *
 * \param void
 * \return void
 *
 */

void muestraTitulo()
{
    printf("*** MENU DE OPCIONES ***\n");
}

/** \brief funcion para ver el estado del archivo
 *
 * \param movie puntero a Emovie
 * \return void
 *
 */

void verEstadoDeArchivo(EMovie* movie)
{
    FILE* bin;
    int cant;

    bin = fopen ("bin.dat", "rb");
    if(bin==NULL)
    {
        printf(" Archivo vacio \n");
        system("pause");
    }
    else
    {
        while(!feof(bin))
        {
            cant=fread(movie,sizeof(EMovie),1,bin);
            if(cant!=1)
            {
                if(feof(bin))
                {
                    break;
                }
                else
                {
                    printf("No leyo el ultimo registro");
                    break;
                }
            }
            if(movie->estado==1)
            {
                printf("%s--%d--%s--%s--%d--%s--%d\t", movie->titulo, movie->duracion, movie->genero, movie->descripcion, movie->puntaje, movie->linkImagen, movie->estado);
            }

        }

    }

    fclose(bin);
}

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie puntero a EMovie
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
void agregarPelicula(EMovie* movie)
{

    char buffer[100];

    printf("Ingrese titulo de pelicula: \n");
    fflush(stdin);
    gets(buffer);
    while(strlen(buffer)>50)
    {
        printf("Reingrese titulo mas corta");
        fflush(stdin);
        gets(buffer);
    }
    strcpy(movie->titulo, buffer);
    printf("Ingrese duracion: \n");
    scanf("%d", &movie->duracion);
    while(movie->duracion>100 || movie->duracion<0)
    {
        printf("Reingrese duracion valida\n");
        scanf("%d", &movie->duracion);
    }
    printf("Ingrese genero: \n");
    fflush(stdin);
    gets(buffer);
    while(strlen(buffer)>50)
    {
        printf("Reingrese genero");
        fflush(stdin);
        gets(buffer);
    }
    strcpy(movie->genero, buffer);

    printf("Ingrese puntaje de 1 a 10: \n");
    scanf("%d", &movie->puntaje);
    while(movie->puntaje>10 || movie->puntaje<0)
    {
        printf("Reingrese puntaje de 1 a 10\n");
        scanf("%d", &movie->puntaje);
    }

    printf("Ingrese descripcion\n");
    fflush(stdin);
    gets(buffer);
    while(strlen(buffer)>50)
    {
        printf("Reingrese descripcion mas corta");
        fflush(stdin);
        gets(buffer);
    }
    strcpy(movie->descripcion, buffer);
    printf("Ingrese link de imagen\n");
    fflush(stdin);
    gets(buffer);
    while(strlen(buffer)>100)
    {
        printf("Reingrese link mas corto");
        fflush(stdin);
        gets(buffer);
    }
    strcpy(movie->linkImagen, buffer);
    movie->estado=1;
    system("pause");

    guardarEnArchivo(movie);

    if(1)
    {
        printf("Pelicula cargada correctamente\n");
        printf("%s--%s--%s--%d--%d--%s",movie->linkImagen,movie->titulo,movie->genero,movie->puntaje, movie->duracion,movie->descripcion);
    }

}
/** \brief funcion para guardar pelicula en archivo
 *
 * \param movie puntero a la estructura EMovie
 * \return 0 error, 1 ok
 *
 */


int guardarEnArchivo(EMovie* movie)
{
    FILE* bin;
    bin=fopen("bin.dat", "ab+");
    if(bin==NULL)
    {
        printf("Error al abrir archivo");
        return 0;
    }

    fwrite(movie, sizeof(EMovie), 1, bin);

    fclose(bin);

    return 1;

}


/**
 *  Borra una pelicula del archivo binario
 *  @param movie puntero a Emovie
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie* movie)
{
    FILE* bin;
    char nombre[50];
    int i=0;

    printf("Ingrese titulo de pelicula que desea borrar\n");
    fflush(stdin);
    gets(nombre);

    bin = fopen ("bin.dat", "rb");
    while(!feof(bin))
    {
        while(fread(movie,sizeof(EMovie),1,bin) !=0)
        {
            if(strcmp(movie->titulo,nombre)==0)
            {
                movie->estado=0;
                i=1;
                break;
            }
        }
    }
    fclose(bin);
    return i;
}

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param movie puntero a EMovie
 *  return void
 */
void generarPagina(EMovie* movie)
{
    FILE *archivo;
    FILE* bin;

    archivo = fopen("arch.html","wb");
    bin= fopen("bin.dat", "rb");

    if(archivo != NULL)
    {
        if(bin != NULL)
        {
            fprintf(archivo, "<!DOCTYPE html> <html lang='en'> <head> <meta charset='utf-8'><meta http-equiv='X-UA-Compatible'"
                    "content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title>"
                    "<link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'><!--[if lt IE 9]>"
                    "<script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'>"
                    "</script><![endif]--></head><body><div class='container'><div class='row'>");

            while((fread(movie,sizeof(EMovie),1,bin))!=0)
            {
                fprintf(archivo, "<article class='col-md-4 article-intro'>\n"
                        "<a href='#'>\n"
                        "<img class='img-responsive img-rounded' src='%s' alt=''>\n"
                        "</a>\n"
                        "<h3>\n"
                        "<a href='#'>%s</a>\n"
                        "</h3>\n"
                        "<ul>\n"
                        "<li>Genero:%s</li>\n"
                        "<li>Puntaje:%d</li>\n"
                        "<li>Duracion:%d minutos</li>\n"
                        "</ul>\n"
                        "<p>%s</p>\n"
                        " </article>\n",movie->linkImagen,movie->titulo,movie->genero,movie->puntaje, movie->duracion,movie->descripcion);
            }

            fprintf(archivo, "</div>"
                    "<!-- /.row -->"
                    "</div>"
                    "<!-- /.container -->"
                    "<!-- jQuery -->"
                    "<script src='js/jquery-1.11.3.min.js'></script>"
                    "<script src='js/bootstrap.min.js'></script>"
                    "<!-- IE10 viewport bug workaround -->"
                    "<script src='js/ie10-viewport-bug-workaround.js'></script>"
                    "<script src='js/holder.min.js'></script>"
                    "</body>"
                    "</html>");
        }
    }

    fclose(archivo);
    fclose(bin);
    system("pause");
}





