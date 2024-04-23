#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define MAX 5

int main()
{
    char buff[50];
    char **V;
    int long_char;
    int num_nombres;
    printf("Numero de nombres: ");
    scanf("%d", &num_nombres);




    V = (char **)malloc(sizeof(char *) * num_nombres);
    for (int i = 0; i < num_nombres; i++)
    {
        printf("\nIngrese su nombre: ");
        scanf("%s", buff);
        long_char = strlen(buff) + 1;
        V[i] = (char *)malloc(sizeof(char) * long_char);
        strcpy(V[i], buff);
    }
    for (int i = 0; i < num_nombres; i++)
    {
        printf("\nNombres: %s\n", V[i]);
    }
    for (int i = 0; i < num_nombres; i++)
    {
        free(V[i]);
    }
    free(V);
    return 0;
}