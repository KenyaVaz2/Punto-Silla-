/*
Instituto Politécnico Nacional
Escuela Superior de Cómputo
Alumno: 
Vazquez Salto Kenya Marisol
Materia: Analisis y Diseno de Algoritmos 
Grupo: 3CM3
Práctica #1: Determinación experimental del análisis de un algoritmo
Resumen: Este programa consiste en encontrar un punto maximo
tal que es menor o igual a los numeros de su fila y mayor o igual
a los numeros de su columna analizando el mejor y peor caso. 
Fecha: 28/08/24
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 100

void principal();
void generarMatriz(int **M, int fil, int col);
void imprimirMatriz(int **M, int fil, int col);
void generarPuntoSilla(int **M,int a, int b,int fil, int col);
void puntoSilla(int **M, int fil, int col,int *ct);
void todoslospuntossilla(int **M, int fil, int col,int *ct);
int main()
{
    principal();
    return 0;
}

void principal()
{
    FILE *pf = fopen("puntoSilla.csv", "w");
    if (pf == NULL) 
    {
        printf("Error al abrir el archivo\n");
        return;
    }
    int ct;
    srand(time(NULL));
    int fil, col;
    fil=col=5;

    for(int i=0; i<100; i++)
    {
        ct=0;
        int **M = (int **)malloc(fil * sizeof(int*));  
        for(int i = 0; i < fil; i++)
            M[i] = (int *)malloc(col * sizeof(int));
        generarPuntoSilla(M,fil-1,col-1,fil,col);
       //generarMatriz(M, fil,col);
        imprimirMatriz(M,fil,col);
        puntoSilla(M,fil,col,&ct);
        //todoslospuntossilla(M,fil,col,&ct);
        fprintf(pf,"%d,%d\n",fil,ct);
         for (int i = 0; i < fil; i++)
            {
                free(M[i]);
            } 
    free(M);
        fil+=1;
        col+=1;
    }
    fclose(pf);
    
}
void generarMatriz(int **M, int fil, int col)
{
    srand(time(NULL));
    for(int i=0;i<fil;i++)
        for(int j=0;j<col;j++)
            M[i][j]=rand()%50;
}

void generarPuntoSilla(int **M,int a, int b,int fil, int col)
{
    srand(time(NULL));
    for(int i=0;i<fil;i++)
        for(int j=0;j<col;j++)
        {
            if(i==a)
                M[i][j]=rand()%25+25;
            else if(j==b)
                M[i][j]=rand()%25;
            else
                M[i][j]=rand()%50;
        }
    M[a][b]=25;
}

void imprimirMatriz(int **M, int fil, int col)
{
    for(int i=0;i<fil;i++)
    {
        for(int j=0;j<col;j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }
}

void puntoSilla(int **M, int fil, int col, int *ct)
{
    int silla = 1; (*ct)++;  (*ct)++;
    int i;  (*ct)++;
    int j;  (*ct)++;
    (*ct)++;
    for (i = 0; i < fil; i++)
    {
        (*ct)++;
        int fsilla = M[i][0]; (*ct)++; 
        int csilla = 0; (*ct)++;
        (*ct)++;
        for (j = 1; j < col; j++)
        {
            (*ct)++;
            if (M[i][j] < fsilla)
            {
                (*ct)++;
                 (*ct)++;
                fsilla = M[i][j]; 
                csilla = j;
            }
            (*ct)++;
            (*ct)++;
        }
        (*ct)++;

        silla = 1; (*ct)++;
        (*ct)++;
        for (int j = 0; j < fil; j++)
        {
            (*ct)++;
            if (M[j][csilla] > fsilla)
            {
                (*ct)++;
                (*ct)++;
                silla = 0;
                break;
            }
            (*ct)++;
            (*ct)++;
        }
        (*ct)++;

        if (silla == 1)
        {
            (*ct)++;
            (*ct)++;
            printf("\n------- M[%d][%d] = %d ----------\n", i, csilla, M[i][csilla]);
            return;
        }
        (*ct)++;
        (*ct)++;
    }
    (*ct)++; 
}

void todoslospuntossilla(int **M, int fil, int col, int *ct)
{
    int totalPuntosSilla = 0; (*ct)++;
    int i; (*ct)++;
	int j;(*ct)++;
    (*ct)++;
    for (i = 0; i < fil; i++)
    {
    	(*ct)++;
    	(*ct)++;
        int fsilla = M[i][0]; 
        int csilla = 0; 
        (*ct)++;
        for (j = 1; j < col; j++)
        {
        	(*ct)++;
            if (M[i][j] < fsilla)
            {
            	(*ct)++;
            	(*ct)++;
                fsilla = M[i][j]; 
                csilla = j; 
            }
            (*ct)++;
            (*ct)++;
        }
        (*ct)++;

        int silla = 1; (*ct)++;
        (*ct)++;
        for (int j = 0; j < fil; j++)
        {
        	(*ct)++;
            if (M[j][csilla] > fsilla)
            {
            	(*ct)++;
            	(*ct)++;
                silla = 0;
            }
            (*ct)++;
            (*ct)++;
        }
        (*ct)++;

        if (silla == 1)
        {
        	(*ct)++;
        	(*ct)++;
            printf("\nTODOS LOS PUNTOS SILLA SON M[%d][%d] = %d ----------\n", i, csilla, M[i][csilla]);
            totalPuntosSilla++;
        }
        (*ct)++;
        (*ct)++;
    }
    (*ct)++;
}
