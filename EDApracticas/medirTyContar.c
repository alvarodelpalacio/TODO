/*
 * medirTiempos.c	Procedimiento general para medir tiempos de ejecución a diferetes algortimos en funcion
 * 			del "tamaño"
 *
 *  Created on: 29/09/2014
 *      Author: M.J. Polo
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algoritmos.h"
long int contadorInterno,contadorExterno, contadorMedio;
int main(int argc, char *argv[])
{
	// clock_t tiempoInicial , tiempoFinal ;
	double tiempo, tiempoInicial, tiempoFinal, tiempoMinimo = 10 * CLOCKS_PER_SEC;

	int n, i, repeticiones = 0;

	FILE *f;

	if (argc != 2)
	{
		printf("\n Uso: ./medirTiempos <nombre fichero resultados>\n\n");
		return -1;
	}

	f = fopen(argv[1], "w+");
	fprintf(f, "n;tiempoMedio\n");
	
	//for (n = 10; n <= 60; n+=10)
	for (n = 500; n <= 2500; n = 250 + n)
	//for (n = 5000; n <= 50000; n = 5000 + n)
	{
		repeticiones = contadorExterno=contadorInterno=0;
		tiempoInicial = tiempoFinal = (double)clock();
		//while ((tiempoFinal - tiempoInicial < MIN_T) || (repeticiones < MIN_REP))
		{
			fibonacciI(n);
			repeticiones++;
			tiempoFinal = (double)clock();
		}
		//contadorInterno/=repeticiones;
		tiempo = (tiempoFinal - tiempoInicial) / CLOCKS_PER_SEC / repeticiones;
		printf("n: %d tiempo: %g contador: %li \n", n, tiempo, contadorInterno);
		fprintf(f, "%d ; %g ; %li \n", n, tiempo, contadorInterno);
	}
	fclose(f);

	return 0;
}