/*
 * pruebaRadix.c  Prueba el algoritmo de ordenación por distribuciń Raidx Sort
 *
 *  Created on: 07/11/2016
 *      Author: MJ Polo
 */

#include <stdlib.h>
#include <stdio.h>
#include "lista.h"
#include "radixSort.h"

long int contadorInterno,contadorExterno;
int main(int argc, char *argv[])
{ nodo *lista;

 
  // Se crea una lista enlazada de 20 enteros comprendidos entre 0 y 99.999
  lista = creaLista(10,100000); 
  verLista(lista);

  printf("\nOrdenada por Radixsort\n");
  radixSort(&lista,10,5);
   verLista(lista);



 
   liberarLista(lista);


return 0;
}
