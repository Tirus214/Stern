#include <stdio.h>
#include <ctype.h>

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

int main()
{
    /*
    int resultado;
    do{
         resultado = menu_stern_brocot();
    }while(resultado==0); */

    int i;
    do
    {
        printf("Digite un indice: ");
        scanf("%i", &i);
        imprimirFraccion(i);
    } while (i != 0);

    int n;
    int d;
    do
    {
        printf("Digite un numerador: ");
        scanf("%i", &n);
        printf("Digite un denominador: ");
        scanf("%i", &d);
        imprimirIndice(n, d);
    } while (n != 0 && d != 0);

    return 0;
}
/*
int menu_stern_brocot(){

    int opcion;
    printf("------Stern Brocot------\n\n");
    printf("1. Ver la fraccion a traves de un indice\n2. Ver el indice a traves de una opcion\n");
    scanf("%opcion", &opcion );
    if(isdigit(opcion)){
        if (opcion == 1){
             printf("Digite un indice: ");
            scanf("%i", &i);
            imprimirFraccion(i);
        }else if(opcion == 2){
            printf("Digite un numerador: ");
            scanf("%i", &n);
            printf("Digite un denominador: ");
            scanf("%i", &d);
            imprimirIndice(n, d);0
        }else{

            return -1;//falla por no ingresar una de las opciones
        }
        return 0; //El menú se ejecuta con éxito
    }else{
        printf("Error, digite un numero entero");
        return -2; //Falla por no ingresar un número entero
    }
}
 */