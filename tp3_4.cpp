#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *TiposProductos[] = {"Galletas", "Snacks", "Cigarrillos", "Caramelos", "Bebidas"};

struct
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;
struct
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos;         // El tamaño de este arreglo depende de la variable
} typedef Cliente;

void cargar(Cliente *cliente, int numClientes);

int main()
{
    srand(time_t(NULL));
    int numClientes, n = 0;
    Cliente *clientes;
    do
    {
        printf("Numero de clientes: ");
        scanf("%d", &numClientes);
        if (numClientes < 5)
        {
            n = 1;
            clientes = (Cliente *)malloc(sizeof(Cliente ) * numClientes);
            cargar(clientes,numClientes);

        }
        else
        {
            n = 0;
            printf("El numero de clientes no puede ser mayor a 5");
        }
    } while (n == 0);

    return 0;
}

void cargar(Cliente *cliente, int numClientes){
    char nombre[30];
    int long_nomb;
    for (int i = 0; i < numClientes; i++)
    {
       printf("\nCliente %d", i+1);
       cliente->ClienteID = i+1;
       printf("\nNombre: ");
       scanf("%s",nombre);
       long_nomb = strlen(nombre)+1;
       cliente->NombreCliente = (char *)malloc(sizeof(char) *long_nomb);
       strcpy(cliente->NombreCliente,nombre);
    

    }
    





}