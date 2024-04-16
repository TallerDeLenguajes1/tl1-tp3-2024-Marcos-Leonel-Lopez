#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    srand(time_t(NULL));
    int historial_produccion[5][12];
    int suma,min,max,mesMAX,anioMAX,anioMIN,mesMIN ;
    float prom;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            historial_produccion[i][j] = 10000 + rand() % 40001;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("Ganancia del anio %d",i+1);
        suma = 0;
        for (int j = 0; j < 12; j++)
        {
            printf("Mes %d: %d\n", i + 1, j + 1, historial_produccion[i][j]);
            suma = suma + historial_produccion[i][j];
        }
        prom = suma / 12;
        printf("Promedio total: %.0f \n", prom);
        printf("----------\n");
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            if(i == 0 && j == 0){
                max = historial_produccion[i][j];
                min = historial_produccion[i][j];
            }
            if (historial_produccion[i][j] > max)
            {
                max = historial_produccion[i][j];
                anioMAX = i + 1;
                mesMAX = j + 1;
            }
             if (historial_produccion[i][j] < min)
            {
                min = historial_produccion[i][j];
                anioMIN = i + 1;
                mesMIN = j + 1;
            } 
        }
    }
    printf("Max: %d\n",max);
    printf("\tmes: %d\n",mesMAX+1);
    printf("\tanio: %d\n",anioMAX);
    printf("Min: %d\n",min);
    printf("\tmes: %d\n",mesMIN+1);
    printf("\tanio: %d\n",anioMIN);
    
    return 0;
}