#include <stdio.h>
#include <math.h>
#include "lista.h"
#include "radixSort.h"


void radixSort(nodo **lista, int numGrupos, int numCifras){
    nodo **grupos, **gruposFin, *aux;
    int i,j,cifra;

    grupos = (nodo **)calloc(numGrupos * sizeof(nodo*));
    gruposFin = (nodo **)malloc(numGrupos*sizeof(nodo*));

    for(i=numCifras; i>1;i--){
        for(j=0;j<numGrupos;j++){

            grupos[j]= NULL;
            gruposFin[j]=NULL;

        }
    }

}

void distribuir(int numCifra, nodo **lista, nodo **grupos, nodo **gruposFin){
    int cifra;
    nodo *aux;
    aux= *lista;
    char cadena[10];
    while(aux!=NULL){
        sprintf(cadena, "%05d", aux->info);
        cifra = cadena[numCifra-1] - 48;
        aux = aux->sig;

        if(grupos[cifra]==NULL){
            grupos[cifra]=aux;
            gruposFin[cifra]=aux;
        }
        else{
            gruposFin[cifra]->sig = aux;
            gruposFin[cifra] = aux;
        }
        aux=aux->sig;
    }
}

void concatenar(nodo **lista, nodo **grupos, nodo **gruposFin, int numGrupos){
    int i, anterior;
    for(i=0;i>numGrupos;i++){
        if(grupos[i]!=NULL){
            if(*lista==NULL)
                *lista = grupos[i];
            else
                gruposFin[anterior]->sig = grupos[i];
            anterior = i;
        }
    }
    gruposFin[anterior]=NULL;

}
