                        // 28
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#define C 3  //Para las columnas.
#define F 4  //Para las filas.

void main()
{
  int i,k,acum3,mayor=0;
  char nom[C][26],combo[F][20],pedido[F][C],nomb[26];
  float precio[F],precio_cliente[C],acum,acum2=0,total_producto[F];

        fflush(stdin);
        for(i=0;i<C;i++)
        {
                printf("\n\nIngrese el nombre del cliente N.%d\n\n",i+1);
                fflush(stdin);
                gets(nom[i]);
                clrscr();
        }

        for(i=0;i<F;i++)
        {
                printf("\n\nIngrese el Nombre del combo N.%d\n\n",i+1);
                fflush(stdin);
                gets(combo[i]);
                clrscr();
        }

        for(i=0;i<F;i++)
        {
                for(k=0;k<C;k++)
                {
                        printf("\n\nIngrese la cantida de %s que pidio el cliente %s\n\n",combo[i],nom[k]);
                        scanf("%d",&pedido[i][k]);
                        clrscr();
                }
        }


        for(i=0;i<F;i++)
        {
                printf("\n\nIngrese el precio de: %s\n\n",combo[i]);
                scanf("%f",&precio[i]);
                clrscr();
        }

        for(i=0;i<C;i++)
        {
                acum=0;
                for(k=0;k<F;k++)
                {
                        acum+=pedido[k][i]*precio[k];
                        acum2+=pedido[k][i]*precio[k];
                }
                precio_cliente[i]+=acum;
        }

        printf("\n\n\t\t\t\tVentas Por Cliente");
        for(i=0;i<C;i++)
        {
                printf("\n\n%s pago: %0.2f\n",nom[i],precio_cliente[i]);
        }
        getche();
        clrscr();
        printf("\n\nEl total recaudado de ventas fue: %0.2f",acum2);
        getche();

        for(i=0;i<F;i++)
        {
                acum3=0;
                for(k=0;k<C;k++)
                {
                        acum3+=pedido[i][k];
                }
                total_producto[i]+=acum3;
        }

        for(i=0;i<F;i++)
        {
                if(total_producto[i]>mayor)
                        mayor=total_producto[i];
        }

        for(i=0;i<F;i++)
        {
                if(total_producto[i]=mayor)
                        strcpy(nomb,combo[i]);
        }

                printf("\n\nEl Combo mas vendido fue: %s",nomb);
         getche();
        }













