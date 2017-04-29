#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nombre[50];
    int edad;
    int dni;
    int flagEstado;

} EPersonas;

void inicializarPersonas(EPersonas arrayPersona[], int, int); //para inicializar el campo estado de las estructuras en -1. Paso como parametro la esctructura y el define
void ordenarPorNombre(EPersonas arrayPersona[], int);
void mostrarPorNombre(EPersonas arrayPersona[], int);
void cargar10Personas (EPersonas arrayPersona[], int);
void grafico(EPersonas arrayPersona[], int);

#endif // FUNCIONES_H_INCLUDED
