#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define DIGITOS 10
int fracIr(int n1, int n2){
    int i = 2;
    if(n1 == 0 || n2 == 0)
        return 0;
    while(n1/2 >= i && n2/2 >= i){
        if(n1%i == 0 && n2%i == 0){
            return 0; //fraccion reducible
        }
        i++;
    }
    return 1;//fracción irreducible
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
int isEnteroPositivo(char num[]){//ingresa una cadena, valida que sea entero y lo regresa
    int numValido;
    if(strlen(num)>DIGITOS){
        printf("La longitud del entero sobrepasa el limite establecido");
        return -1;
    }
    for(int i = 0; i<strlen(num);i++){
        if(!(isdigit(num[i])))
            return -2;
    }
    numValido = atoi(num);
    return numValido;
}
int input(char mensaje[]){//Ingresa un parametro para mostrar el mensaje y si es un número entero positivo, lo regresa
    char numero[DIGITOS];
    printf(mensaje);
    scanf("%s",numero);
    int validateNum = isEnteroPositivo(numero);
    if(validateNum>0)
        return validateNum;
    else
        return -1;
}
int menu_stern_brocot(){
    printf("\n\n------Stern Brocot------\n\n");

    int opcion = input("\n1. Ver la fraccion a traves de un indice\n2. Ver el indice a traves de una opcion\n3. Salir\n");
    if(opcion!=-1){
        if (opcion == 1)
        {
            int indice = input("Digite un indice: ");
            if (indice>0)
                imprimirFraccion(indice);
            else
                printf("Digite un indice entero positivo");
        }else if(opcion == 2)
        {
            int numerador = input("Ingrese el numerador: ");
            int denominador = input("Ingrese el denominador: ");
            if(numerador>0 && denominador>0)
            {
                if(fracIr(numerador, denominador)==1)
                    imprimirIndice(numerador,denominador);
                else
                    printf("La fraccion ingresada no es irreducible");
            }else
                printf("Error, el numerador y denominador deben ser enteros positivos");
        }else if (opcion==3){
            printf("\nIntegrantes:\n-\n-\n-Esteban Leiva Montenegro 2020426227");
            printf("\n\nGracias por usar nuestro programa");
            return 1;
        }else
            printf("Por favor digite una de las opciones");
    }else
        printf("Error, digite un numero entero");
    return 0; //El menú se ejecuta con éxito
}

int main()
{
    int resultado;
    do
        resultado = menu_stern_brocot();
    while(resultado!=1);
    return 0;
}
