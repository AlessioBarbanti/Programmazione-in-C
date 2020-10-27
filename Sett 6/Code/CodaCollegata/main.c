
#include "struttureCollegate.h"



TipoLista tmp;
TipoLista testa;
TipoLista paux;
TipoLista canc;





int main()
{
    /*Le code sfruttano una gestione dei dati di tipo FIFO,
    ovvero il primo dato inserito è anche il primo ad essere processato.
    Ho quindi deciso di implementare le 4 funzioni chiave per usare e gestire una Coda:

    -Aggiungi elemento (push)
    -Rimuovi elemento  (pop)
    -Visualizza il primo elemento (first)
    -controlla se la coda è vuota (isEmpty)

    Altre funzioni, nonostante siano possibili, andrebbero
    a snaturare il concetto di coda e di conseguenza non sono state implementate

    */
  
    testa = NULL;
    int scelta = 0;
    printf("Inserisci la grandezza iniziale della lista\n");
    scanf("%d", &scelta);
    fflush(stdin);


    for (int i = 1; i <= scelta; i++) {
        paux = (TipoLista)malloc(sizeof(TipoNodoLista));
        paux->info = i;
        paux->next = testa;
        testa = paux;
    }

    do {
        printList(testa);
        int scelta = 0;
        printf("\n1.  Push - Aggiungi Elemento\n"); //addTail
        printf("2.  Pop - Rimuovi il primo elemento\n"); //delHead
        printf("3.  Ritorna il primo elemento senza eliminarlo \n"); //printhead TODO
        printf("4.  Controlla se sono presenti elementi in lista \n");
        printf("5. EXIT\n");
        scanf("%d", &scelta);
        fflush(stdin);





        switch (scelta) {



        case 1:
            addTail(); //push
            break;


        case 2:
            delHead(); //pop
            break;

        case 3:
            if (testa != NULL){
                printf("Primo elemento in coda: %d\n", testa->info);
            }
            else {
                printf("Coda Vuota!");
            }
            break;

        case 4:
            if (testa == NULL){ 
                printf("\nla coda e' vuota!\n");
            }
            else {
                printf("\nla coda NON e' vuota!\n");
            }
            break;



        case 5:
            exit(0);
            break;

        default:
            printf("\nInserire una scelta tra quelle mostrate.");
            break;
        }
    } while (1);

    return 0;
}
