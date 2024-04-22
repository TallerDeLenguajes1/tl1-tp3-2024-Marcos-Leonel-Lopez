#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char TiposProductos[5][12] = {"Galletas", "Snacks", "Cigarrillos", "Caramelos", "Bebidas"};

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
void mostrar(Cliente *cliente, int numClientes);
void costoTotalDeUnProducto(Cliente *cliente, int numClientes);
void mostrarNombres(Cliente *cliente, int numClientes);
void mostrarProductos(Cliente *cliente, int clienteIndex);
float costoDeUnProucto(Cliente *cliente, int clienteIndex, int productoIndex);
void montoPorCliente(Cliente *cliente, int numClientes);
int main()
{
    srand(time_t(NULL));
    int numClientes, n = 0, Z;
    Cliente *clientes;
    do
    {
        printf("Numero de clientes: ");
        scanf("%d", &numClientes);
        if (numClientes < 5)
        {
            n = 1;
            clientes = (Cliente *)malloc(sizeof(Cliente) * numClientes);
            cargar(clientes, numClientes);
        }
        else
        {
            n = 0;
            printf("El numero de clientes no puede ser mayor a 5");
        }
    } while (n == 0);

    mostrar(clientes, numClientes);

    // mostrar costo de un producto
    costoTotalDeUnProducto(clientes, numClientes);

    scanf("%d", &Z);
    free(clientes);
    for (int i = 0; i < numClientes; i++)
    {
        free(clientes[i].Productos);
    }

    return 0;
}

void cargar(Cliente *cliente, int numClientes)
{
    char nombre[30];
    int long_nomb;
    for (int i = 0; i < numClientes; i++)
    {
        printf("\nCliente %d", i + 1);
        (cliente + i)->ClienteID = i + 1;
        printf("\nNombre: ");
        scanf("%s", nombre);
        long_nomb = strlen(nombre) + 1;
        (cliente + i)->NombreCliente = (char *)malloc(sizeof(char) * long_nomb);
        strcpy((cliente + i)->NombreCliente, nombre);
        (cliente + i)->CantidadProductosAPedir = 1 + rand() % 5;
        (cliente + i)->Productos = (Producto *)malloc(sizeof(Producto) * (cliente + i)->CantidadProductosAPedir);
        for (int j = 0; j < (cliente + i)->CantidadProductosAPedir; j++)
        {
            (cliente + i)->Productos[j].ProductoID = j + 1;
            (cliente + i)->Productos[j].Cantidad = 1 + rand() % 10;
            (cliente + i)->Productos[j].TipoProducto = TiposProductos[rand() % 5];
            (cliente + i)->Productos[j].PrecioUnitario = 10 + rand() % 100;
        }
    }
}

void mostrar(Cliente *cliente, int numClientes)
{
    for (int i = 0; i < numClientes; i++)
    {
        printf("\nCliente %d", i + 1);
        printf("\nNombre: %s", (cliente + i)->NombreCliente);
        printf("\nNumero de productos a pedir: %d", (cliente + i)->CantidadProductosAPedir);
        for (int j = 0; j < (cliente + i)->CantidadProductosAPedir; j++)
        {
            printf("\nProducto %d: %s", (cliente + i)->Productos[j].ProductoID, (cliente + i)->Productos[j].TipoProducto);
            printf("\nCantidad: %d", (cliente + i)->Productos[j].Cantidad);
            printf("\nPrecio unitario: %.2f", (cliente + i)->Productos[j].PrecioUnitario);
        }
        printf("\n\n");
    }
}

void costoTotalDeUnProducto(Cliente *cliente, int numClientes)
{
    int clienteIndex, productIndex;
    float costoTotal = 0;
    mostrarNombres(cliente, numClientes);
    scanf("%d", &clienteIndex);
    printf("index: %d\n", clienteIndex);
    mostrarProductos(cliente, (clienteIndex - 1));
    scanf("%d", &productIndex);
    printf("index: %d\n", productIndex);
    costoTotal = costoDeUnProucto(cliente, (clienteIndex - 1), (productIndex - 1));
    printf("El costo total del producto %d es %.2f\n", productIndex, costoTotal);
}

void mostrarNombres(Cliente *cliente, int numClientes)
{
    for (int i = 0; i < numClientes; i++)
    {
        printf("\nCliente %d", i + 1);
        printf("\n\tNombre: %s", (cliente + i)->NombreCliente);
    }
    printf("\n\n");
}

void mostrarProductos(Cliente *cliente, int clienteIndex)
{
    for (int i = 0; i < cliente[clienteIndex].CantidadProductosAPedir; i++)
    {
        printf("\nProducto %d: %s", cliente[clienteIndex].Productos[i].ProductoID, cliente[clienteIndex].Productos[i].TipoProducto);
    }
    printf("\n\n");
}

float costoDeUnProucto(Cliente *cliente, int clienteIndex, int productoIndex)
{
    printf("Producto: %s\n", cliente[clienteIndex].Productos[productoIndex].TipoProducto);
    printf("Cantidad: %d\n", cliente[clienteIndex].Productos[productoIndex].Cantidad);
    printf("Precio Unitario: %.2f\n", cliente[clienteIndex].Productos[productoIndex].PrecioUnitario);
    return cliente[clienteIndex].Productos[productoIndex].Cantidad * cliente[clienteIndex].Productos[productoIndex].PrecioUnitario;
}
