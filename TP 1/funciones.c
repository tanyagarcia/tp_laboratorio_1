#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/**
 *\brief esta función realiza la operación suma y devuelve el resultado
 * \param int x es el operando 1
 * \param int y es el operando 2
 * \return el resultado de la operación
 *
 */
int sumar(int x, int y)
{
    int resultado;
    resultado=x + y;
    return resultado;
}
/**
 *\brief esta función realiza la operación resta y devuelve el resultado
 * \param int x es el operando 1
 * \param int y es el operando 2
 * \return el resultado de la operación
 *
 */
int restar(int x, int y)
{
    int resultado;
    resultado=x - y;
    return resultado;
}
/**
 *\brief esta función realiza la operación division y devuelve el resultado
 * \param int x es el operando 1
 * \param int y es el operando 2
 * \return el resultado de la operación
 *
 */
int division(int x, int y)
{
    int resultado;
    resultado=x/y;
    return resultado;
}
/**
 *\brief esta función realiza la operación multiplicación y devuelve el resultado
 * \param int x es el operando 1
 * \param int y es el operando 2
 * \return el resultado de la operación
 *
 */
int multiplicacion(int x, int y)
{
    int resultado;
    resultado=x*y;
    return resultado;
}
/**
 *\brief esta función realiza la operación de factorial y devuelve el resultado
 * \param int x es el operando 1
 * \return el resultado de la operación
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
