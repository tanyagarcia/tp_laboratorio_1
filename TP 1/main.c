#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int num2;
    int num1;
    int flag1=0, flag2=0;
    int resultado;
    int flagPrimOperando=0, flagSegOperando=0;

    while(seguir=='s')
    {
        if(flag1==0)
        {
            printf("1- Ingresar 1er operando (A=x)\n");
        }
        else
        {
            printf("1- Ingresar 1er operando (A=%d)\n", num1);
        }

        if(flag2==0)
        {
            printf("2- Ingresar 2do operando (B=y)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B=%d)\n", num2);
        }


        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);
        while(opcion<1 || opcion>9)
        {
            printf("Ingrese una opcion de 1 a 9 por favor\n");
            scanf("%d", &opcion);
        }

        switch(opcion)
        {
        case 1:
            printf("1- Ingresar 1er operando (A=y)\n");
            scanf("%d", &num1);
            flag1=1;
            flagPrimOperando=1;
            break;
        case 2:
            if(flagPrimOperando==1)
            {
                printf("2- Ingresar 2do operando (B=y)\n");
                scanf("%d", &num2);
                flag2=1;
                flagSegOperando=1;
            }
            else
            {
                printf("Debe ingresar primer operando primero\n");
            }

            break;
        case 3:
            if(flagPrimOperando==0 || flagSegOperando==0)
            {
                printf("Se necesitan dos operandos para realizar la suma\n");
            }
            else
            {
                if(flagPrimOperando==1 && flagSegOperando==1)
                {
                    resultado= sumar(num1, num2);
                    printf("El resultado de la suma es %d\n", resultado);
                    num1=0;
                    num2=0;
                    flagPrimOperando=0;
                    flagSegOperando=0;
                }
            }

            break;
        case 4:
            if(flagPrimOperando==0 || flagSegOperando==0)
            {
                printf("Se necesitan dos operandos para realizar la resta\n");
            }
            else
            {
                if(flagPrimOperando==1 && flagSegOperando==1)
                {
                    resultado= restar(num1, num2);
                    printf("El resultado de la resta es %d\n", resultado);
                    num1=0;
                    num2=0;
                    flagPrimOperando=0;
                    flagSegOperando=0;
                }
            }
            break;
        case 5:
            if(flagPrimOperando==0 || flagSegOperando==0)
            {
                printf("Se necesitan dos operandos para realizar la division\n");
            }
            else
            {
                if(flagPrimOperando==1 && flagSegOperando==1)
                {
                    if(num2==0)
                    {
                        printf("No se puede realizar la division con divisor 0\n");
                        num1=0;
                        num2=0;
                    }
                    else
                    {
                        resultado= division(num1, num2);
                        printf("El resultado de la division es %d\n", resultado);
                        num1=0;
                        num2=0;
                        flagPrimOperando=0;
                        flagSegOperando=0;
                    }
                }
            }
            break;
        case 6:
            if(flagPrimOperando==0 || flagSegOperando==0)
            {
                printf("Se necesitan dos operandos para realizar la multiplicacion\n");
            }
            else
            {
                if(flagPrimOperando==1 && flagSegOperando==1)
                {
                    resultado= multiplicacion(num1, num2);
                    printf("El resultado de la multiplicacion es %d\n", resultado);
                    num1=0;
                    num2=0;
                    flagPrimOperando=0;
                    flagSegOperando=0;
                }
            }
            break;
        case 7:
            if(flagPrimOperando==1 && flagSegOperando==1)
            {
                printf("Solo es necesario un operando para realizar esta operacion\n");
                num1=0;
                num2=0;
                flagPrimOperando=0;
                flagSegOperando=0;
            }
            else
            {
                if(flagPrimOperando==1)
                {
                    if(num1>0)
                    {
                        resultado=factorial(num1);
                        printf("El factorial es %d\n", resultado);
                        num1=0;
                        flagPrimOperando=0;
                    }
                    else
                    {
                        printf("No se puede realizar el factorial de un numero negativo\n");
                    }

                }
            }
            break;
        case 8:
            if(flagPrimOperando==0 || flagSegOperando==0)
            {
                printf("Se necesitan dos operandos para realizar la suma\n");
            }
            else
            {
                if(flagPrimOperando==1 && flagSegOperando==1)
                {
                    resultado= sumar(num1, num2);
                    printf("El resultado de la suma es %d\n", resultado);

                    resultado= restar(num1, num2);
                    printf("El resultado de la resta es %d\n", resultado);

                    resultado= division(num1, num2);
                    printf("El resultado de la division es %d\n", resultado);

                    resultado= multiplicacion(num1, num2);
                    printf("El resultado de la multiplicacion es %d\n", resultado);

                    if(num1>0)
                    {
                        resultado=factorial(num1);
                        printf("El factorial del primer numero es %d\n", resultado);
                        num1=0;
                        flagPrimOperando=0;
                    }
                    else
                    {
                        printf("No se puede realizar el factorial de un numero negativo\n");
                    }
                    if(num2>0)
                    {
                        resultado=factorial(num2);
                        printf("El factorial del segundo numero es %d\n", resultado);
                        num2=0;
                        flagSegOperando=0;
                    }
                    else
                    {
                        printf("No se puede realizar el factorial de un numero negativo\n");
                    }
                }
            }
            num2=0;
            flagSegOperando=0;
            break;
        case 9:
            seguir = 'n';
            break;
        }

    }
    return 0;
}
