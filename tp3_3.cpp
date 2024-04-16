#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

int main()
{
    char buff[50];
    char **V;
    int long_char;
    V = (char **)malloc(sizeof(char *) * MAX);
    for (int i = 0; i < MAX; i++)
    {
        printf("\nIngrese su nombre: ");
        scanf("%s", buff);
        long_char = strlen(buff) + 1;
        V[i] = (char *)malloc(sizeof(char) * long_char);
        strcpy(V[i], buff);
    }
    for (int i = 0; i < 5; i++)
    {
        printf("\nSu nombre es: %s\n", V[i]);
    }
    for (int i = 0; i < MAX; i++)
    {
        free(V[i]);
    }
    free(V);
    return 0;
}