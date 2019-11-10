#include<stdio.h>
#include<math.h>
#define SIZE 13

void display(int a[],int n);
void ordenamiento_burbuja(int *a, int n);
void ordenamiento_seleccion(int *a, int n);
void ordemamiento_insercion(int *a, int n);
void quicksort(int arreglo[SIZE],int primer,int ultimo, int n);
int ordenamientoModeloSecuencial(int n, int arreglo[SIZE]);
int ordenamientoBusquedaBinaria (int buscar, const int arreglo[SIZE]);

//-----------------Main Function----------------------

int main()
{
    int opcion;
    char ch[20];
    int arreglo[SIZE] = {8, 13, 6, 16, 2, 11, 9,  5, 1, 7, 15, 4, 10};

    printf("Por favor seleciona una opcion para el odenamiento del arreglo: \n");

    while(1)
    {
        printf("\n1. Ordenamiento Burbuja\n2. Ordemamiento Seleccion\n3. Ordenamiento Insercion\n4. QuickSort\n5. Busqueda Secuencial\n6. Busqueda Binaria\n7. Mostrar Arreglo.\n8. Salir del programa.\n");
        printf("\nSelecciona tu opcion : ");
        scanf_s("%d",&opcion);

        switch(opcion)
        {
            case 1:
                ordenamiento_burbuja(arreglo, SIZE);
                break;
            case 2:
                ordenamiento_seleccion(arreglo, SIZE);
                break;
            case 3:
                ordemamiento_insercion(arreglo, SIZE);
                break;
            case 4:
                quicksort(arreglo,0,SIZE-1, SIZE);
                break;
            case 5:
                ordenamientoModeloSecuencial(10, arreglo);
                ordenamientoModeloSecuencial(16, arreglo);
                ordenamientoModeloSecuencial(9, arreglo);
                break;
            case 6:
                ordenamientoBusquedaBinaria(15,arreglo);
                break;
            case 7:
                display(arreglo, SIZE);
                break;
            case 8:
                return 0;
            default:
                printf("\n ¨Por favor selecciona una opcion entre 1-8 ----\n");
        }
    }
    return 0;
}

//-----------End of main function---------------------

//-------------------Imprimir Function-----------------

void display(int a[], const int size)
{
    int i;
    for(i=0; i<size; i++)
        printf("%d ",a[i]);
    printf("\n");
}

//---------------------Burbuja-----------

void ordenamiento_burbuja(int *a, int n)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j] > a[j + 1])
            {
                temp=a[j];
                a[j]=a[j + 1];
                a[j + 1]=temp;
            }
        }
    }
    printf("Despues del odenamiento de Burbuja los elementos ordenados son: ");
    display(a, n);
}

//------------------Seleccion---------

void ordenamiento_seleccion(int *a, int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i] > a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("Despues del odenamiento de Seleccion los elementos ordenados son: ");
    display(a, n);
}

//---------------Insercion -------------------

void ordemamiento_insercion(int *a, int n)
{
    int i,j,min;
    for(i=1;i<n;i++)
    {
        min=a[i];
        j=i-1;
        while(min < a[j] && j >= 0)
        {
            a[j + 1]=a[j];
            j=j-1;
        }
        a[j + 1]=min;
    }
    printf("Despues del odenamiento de Insersion los elementos ordenados son: ");
    display(a, n);
}

//---------------Quick Sort -------------------

void quicksort(int arreglo[SIZE],int primer,int ultimo, int n)
{
    int i, j, pivot, temp;

    if(primer<ultimo){
        pivot=primer;
        i=primer;
        j=ultimo;
        while(i<j){
            while(arreglo[i]<=arreglo[pivot]&&i<ultimo)
                i++;
            while(arreglo[j]>arreglo[pivot])
                j--;
            if(i<j){
                temp=arreglo[i];
                arreglo[i]=arreglo[j];
                arreglo[j]=temp;
            }
        }
        temp=arreglo[pivot];
        arreglo[pivot]=arreglo[j];
        arreglo[j]=temp;
        quicksort(arreglo,primer,j-1,n);
        quicksort(arreglo,j+1,ultimo,n);
    }
    printf("\nDespues del ordenamiento QuickSort los elementos ordenados son: ");
    display(arreglo, SIZE);
}

//--------- Busqueda Secuencial

int ordenamientoModeloSecuencial(int n, int arreglo[SIZE])
{
    char band = 'F';
    int i;
    i=0;
    while(band=='F'&&i<SIZE) {
        if(arreglo[i]== n) {
            band ='V';
        }
        i++;
    }
    printf("\nValidando que el numero: %d exista en el arreglo... ", n);
    if (band == 'F') {
        printf("El numero %d no existe en el array", n);
        printf("\n");
    }
    else if (band == 'V') {
        printf("El numero %d si existe en la posicion: %i", n, i-1 );
        printf("\n");
    }
    return 0;
}

//--------- Busqueda Binaria

int ordenamientoBusquedaBinaria (int buscar, const int arreglo[SIZE]) {
    int izquierda = 0;
    int derecha = SIZE -1;
    int bandera = 0;
    int mitad;

    printf("====================================================\n");
    while (izquierda <= derecha){
        mitad = floor(izquierda + derecha) / 2;

        if(buscar == arreglo[mitad]){
            bandera=1;
            break;
        }
        else
        if(buscar > arreglo[mitad])
            izquierda = mitad -1;
        else
            derecha = mitad +1;
    }
    if (bandera == 1)
        printf("Numero %d encontrado en posicion %d\n", buscar, mitad);
    else
        printf("Numero no encontrado\n");
    return 0;
}
