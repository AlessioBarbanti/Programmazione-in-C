/* Scrivere un programma C che calcoli, memorizzi in un array, e visualizzi tutti
 i numeri primi entro un valore massimo specificato dall'utente (questo vuol dire
  che non sappiamo a priori quanti possano essere). Il programma deve allocare uno
   spazio iniziale di memoria per contenerli, trovare il successivo numero primo
    richiesto e memorizzarlo, ma se lo spazio non è più sufficiente, ampliarlo. */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main()
{
    int n, div=2, conta=0;
    int limite;
    int i=1;
    int k=0;

    printf("inserisci il limite superiore: ");
    scanf("%d", &limite);
    int* array = malloc(sizeof(int)); //riservo lo spazio per l'array

    for(n=1; n<=limite; n++) //scorro tutti i valori da 0 al limite inserito dall'utente
    {
        while(conta==0 && div<=n/2) //incremento div fino a metà del limite (dopo non ci sono più divisori)
        {
            if(n%div==0)
                conta++;
            div++;
        }

        if (conta==0){ //se non ha trovato divisori 

         array[i-1]=n;
         i++;
         array = realloc (array, sizeof(int)*i); //rialloco la memoria in funzione dei numeri primi trovati
        }

        div=2;
        conta=0;
    }
    for(k=0; k<i-1; k++) //stampo l'array
        printf("%d  ",array[k]);
}
