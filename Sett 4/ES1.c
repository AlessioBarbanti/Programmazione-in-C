/*
Scrivere un programma C che chieda all’utente quante parole vuole inserire, successivamente
 le faccia inserire e poi le visualizzi. Le parole vanno memorizzate tramite un vettore
  dinamico di puntatori dimensionato al numero di parole, contenente puntatori a vettori
   dinamici di caratteri contenenti le parole.
    Il programma deve poi convertire tutti i caratteri minuscoli in maiuscolo e visualizzare
    le parole così modificate.*/
/*
  Array dinamico definito come una struttura.
*/





#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>


#define MAX_LENGTH 50

int main()
{ /*definisco e inizializzo le variabili*/
    char **array_puntatori;
    char *parola = malloc(sizeof(char));
    int nparole;
    printf("Inserisci il numero di parole da inserire: ");
    scanf("%d", &nparole);
    getchar();
    int i= 0;
    int k = 0;
    int finito;
    char carattere;
    array_puntatori = malloc(nparole * sizeof(char *));

    for(i=1; i<=nparole; i++)
    {   
        printf("Scrivi la parola numero %d: ",i);
        parola = malloc(sizeof(char));
        k=0;

        finito = 0;
        while(finito == 0)
        {
            carattere = getchar();
            if (carattere == '\n'){ //se incontro un \n vuol dire che è finita la parola ed esco dal while
                finito =1;
            }

            //printf("Carattere 1: %c \n",carattere);
            parola = realloc(parola,sizeof(char)*i); //rialloco memoria in funzione del numero di parole
            parola[k] = toupper(carattere); //passaggio a MAIUSCOLO
            k++;

        }
        array_puntatori[i-1]=parola; //salvo la parola nell'array
    }

    for(i=0; i<nparole; i++){
        printf("%s\n", array_puntatori[i]); //stampo le stringhe nell'array di puntatori
    }



    return 0;
}
