/*
 * radixSort.h 
 *
 *  Created on: 03/11/2014
 *      Author: M.J. Polo
 */
#include "lista.h"
#ifndef __RADIX_H
#define __RADIX_H

extern long int contadorExterno,contadorInterno;


void radixSort(nodo **lista,int numGrupos,int numCifras);
void distribuir(int numCifra, nodo **lista, nodo** grupos,nodo **gruposFin);
void concatenar(nodo **lista, nodo** grupos,nodo **gruposFin);
#endif // 



