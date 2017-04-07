#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/**
 *\brief esta funci�n realiza la operaci�n suma y devuelve el resultado
 * \param int x es el operando 1
 * \param int y es el operando 2
 * \return el resultado de la operaci�n
 *
 */
int sumar(int x, int y)
{
    int resultado;
    resultado=x + y;
    return resultado;
}
/**
 *\brief esta funci�n realiza la operaci�n resta y devuelve el resultado
 * \param int x es el operando 1
 * \param int y es el operando 2
 * \return el resultado de la operaci�n
 *
 */
int restar(int x, int y)
{
    int resultado;
    resultado=x - y;
    return resultado;
}
/**
 *\brief esta funci�n realiza la operaci�n division y devuelve el resultado
 * \param int x es el operando 1
 * \param int y es el operando 2
 * \return el resultado de la operaci�n
 *
 */
int division(int x, int y)
{
    int resultado;
    resultado=x/y;
    return resultado;
}
/**
 *\brief esta funci�n realiza la operaci�n multiplicaci�n y devuelve el resultado
 * \param int x es el operando 1
 * \param int y es el operando 2
 * \return el resultado de la operaci�n
 *
 */
int multiplicacion(int x, int y)
{
    int resultado;
    resultado=x*y;
    return resultado;
}
/**
 *\brief esta funci�n realiza la operaci�n de factorial y devuelve el resultado
 * \param int x es el operando 1
 * \return el resultado de la operaci�n
 *
 */
int factorial (int x)
{
    int valor;
    if(x==0)
    {
        return 1;
    }
    else
    {
        valor= x*factorial(x-1);
        return valor;
    }
}
