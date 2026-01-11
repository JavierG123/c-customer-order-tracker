#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define C 3  // Clientes
#define F 4  // Combos

int main()
{
    int i, k, acum3, mayor = 0;
    char nom[C][26], combo[F][20], nomb[26];
    int pedido[F][C];
    float precio[F], precio_cliente[C] = {0}, acum, acum2 = 0, total_producto[F] = {0};

    // Ingreso de nombres de clientes
    for(i = 0; i < C; i++)
    {
        printf("\nIngrese el nombre del cliente N.%d: ", i + 1);
        fflush(stdin);
        fgets(nom[i], sizeof(nom[i]), stdin);
        nom[i][strcspn(nom[i], "\n")] = 0; // eliminar salto de línea
        system("cls");
    }

    // Ingreso de nombres de combos
    for(i = 0; i < F; i++)
    {
        printf("\nIngrese el nombre del combo N.%d: ", i + 1);
        fflush(stdin);
        fgets(combo[i], sizeof(combo[i]), stdin);
        combo[i][strcspn(combo[i], "\n")] = 0;
        system("cls");
    }

    // Cantidades pedidas
    for(i = 0; i < F; i++)
    {
        for(k = 0; k < C; k++)
        {
            printf("\nIngrese la cantidad de %s que pidió el cliente %s: ", combo[i], nom[k]);
            scanf("%d", &pedido[i][k]);
            system("cls");
        }
    }

    // Precios de combos
    for(i = 0; i < F; i++)
    {
        printf("\nIngrese el precio de %s: ", combo[i]);
        scanf("%f", &precio[i]);
        system("cls");
    }

    // Calculo de pagos por cliente y total
    for(i = 0; i < C; i++)
    {
        acum = 0;
        for(k = 0; k < F; k++)
        {
            acum += pedido[k][i] * precio[k];
            acum2 += pedido[k][i] * precio[k];
        }
        precio_cliente[i] = acum;
    }

    // Mostrar ventas por cliente
    printf("\nVentas por cliente:\n");
    for(i = 0; i < C; i++)
    {
        printf("%s pagó: %.2f\n", nom[i], precio_cliente[i]);
    }
    getchar(); getchar(); // pausa
    system("cls");

    printf("\nTotal recaudado de ventas: %.2f\n", acum2);

    // Calculo del total vendido por combo
    for(i = 0; i < F; i++)
    {
        acum3 = 0;
        for(k = 0; k < C; k++)
        {
            acum3 += pedido[i][k];
        }
        total_producto[i] = acum3;
    }

    // Determinar combo más vendido
    for(i = 0; i < F; i++)
    {
        if(total_producto[i] > mayor)
            mayor = total_producto[i];
    }

    for(i = 0; i < F; i++)
    {
        if(total_producto[i] == mayor)
            strcpy(nomb, combo[i]);
    }

    printf("\nEl combo más vendido fue: %s\n", nomb);
    getchar();
    return 0;
}
