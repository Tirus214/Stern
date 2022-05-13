#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define DIGITOS 10

int fracIr(int n1, int n2)
{
    if (n1 == 1 || n2 == 1)
    {
        return 1;
    }

    else if (n1 % n2 == 0 || n2 % n1 == 0)
    {
        return 0;
    }

    int i = 2;
    while (n1 / 2 >= i && n2 / 2 >= i)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            return 0; // fraccion reducible
        }
        i++;
    }
    return 1; // fracción irreducible
}

int sucesionStern(int n)
{
    if (n < 2)
    {
        return n;
    }
    else if (n % 2 == 0) // si es par
    {
        return sucesionStern(n / 2); // la mitad de n
    }
    else // si es impar
    {
        return sucesionStern((n - 1) / 2) + sucesionStern((n - 1) / 2 + 1); // la mitad de (n-1) mas, lo anterior mas 1
    }
}

// para convertir indice a fraccion
void imprimirFraccion(int index)
{
    printf("Fraccion en ese indice: %i, %i\n\n", sucesionStern(index), sucesionStern(index + 1));
}

// para convertir fraccion a indice
int encontrarIndice_aux(int numerador, int denominador, int index)
{
    if (sucesionStern(index) == numerador && sucesionStern(index + 1) == denominador)
        return index;
    return encontrarIndice_aux(numerador, denominador, index + 1);
}

int encontrarIndice(int numerador, int denominador)
{
    return encontrarIndice_aux(numerador, denominador, 1);
}

void imprimirIndice(int numerador, int denominador)
{
    printf("Indice de fraccion: %i\n\n", encontrarIndice(numerador, denominador));
}

int isEnteroPositivo(char num[])
{ // ingresa una cadena, valida que sea entero y lo regresa
    int numValido;
    if (strlen(num) > DIGITOS)
    {
        printf("La longitud del entero sobrepasa el limite establecido");
        return -1;
    }
    for (int i = 0; i < strlen(num); i++)
    {
        if (!(isdigit(num[i])))
            return -2;
    }
    numValido = atoi(num);
    return numValido;
}

int input(char mensaje[])
{ // Ingresa un parametro para mostrar el mensaje y si es un número entero positivo, lo regresa
    char numero[DIGITOS];
    printf(mensaje);
    scanf("%s", numero);
    int validateNum = isEnteroPositivo(numero);
    if (validateNum > 0)
        return validateNum;
    else
        return -1;
}

int menu_stern_brocot()
{
    printf("\n------Stern Brocot------\n\n");

    int opcion = input("\n1. Ver la fraccion a traves de un indice\n2. Ver el indice a traves de una opcion\n3. Salir\n\nElija una opcion: ");
    int indice, numerador, denominador;
    switch (opcion)
    {
    case -1:
        printf("\nError, digite un numero entero\n");
        break;
    case 1:
        indice = input("\nDigite un indice: ");
        if (indice > 0)
            imprimirFraccion(indice);
        else
            printf("\nDigite un indice entero positivo");
        break;
    case 2:
        numerador = input("\nIngrese el numerador: ");
        denominador = input("Ingrese el denominador: ");
        if (numerador > 0 && denominador > 0)
        {
            if (fracIr(numerador, denominador) == 1)
                imprimirIndice(numerador, denominador);
            else
                printf("La fraccion ingresada no es irreducible\n");
        }
        else
            printf("Error, el numerador y denominador deben ser enteros positivos\n");
        break;
    case 3:
        printf("\nIntegrantes:\n-Jean Paul Rodriguez Flores 2020059156\n-\n-Esteban Leiva Montenegro 2020426227\n-\n José Mauricio Muñoz Morera");
        printf("\n\nGracias por usar nuestro programa\n\n");
        return 1;
    default:
        printf("Por favor digite una de las opciones");
    }
    return 0; // El menú se ejecuta con éxito
}

int main()
{
    int resultado;
    do
        resultado = menu_stern_brocot();
    while (resultado != 1);
    return 0;
}
