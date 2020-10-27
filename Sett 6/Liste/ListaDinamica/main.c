
#define _CRT_SECURE_NO_WARNINGS


#include "listaDinamica.h"


/* Predisporre una libreria di gestione del tipo di dato astratto LISTA,
 implementato sia tramite allocazione indicizzata (vettore statico e
vettore dinamico) sia tramite strutture collegate. Le funzioni che,
come minimo, dovranno essere implementate sono:
inserisci in testa,
inserisci in coda,
inserisci dopo un certo elemento,
cancella dalla testa,
cancella dalla coda,
cancella la prima occorrenza dell’elemento.
   Il programma deve visualizzare lo stato della lista ad inizio esecuzione
    (vuota) e dopo ogni operazione scelta dall'utente. Consegnare un file
     .zip contente un progetto che comprenda tutti i file necessari per testare il programma.*/



int main()
{
    int scelta = 0;
    TipoLista l = list_create();
    l.last = 0;



    do {
        printList(l);
        list_extend(&l); //ad ogni ciclo controllo se la lista è piena, se lo è la funzione lo raddoppia
        printf("\n1. Visualizza lista \n");
        printf("2. Inserisci in testa \n");
        printf("3. inserisci in coda \n");
        printf("4. Inserire dopo un certo elemento \n");
        printf("5. Cancellare dalla testa \n");
        printf("6. Cancellare dalla coda \n");
        printf("7. Cancellare la prima occorrenza dell'elemento \n");
        printf("8. EXIT\n");
        scanf("%d", &scelta);

        fflush(stdin);


        switch (scelta) {



        case 1:
            printList(l); // & non necessario, non devo modificare nulla
            break;


        case 2:
            addHead(&l);
            break;
            
        case 3:
            addTail(&l);
            break;

        case 4:
            insertAfter(&l);
            break;

        case 5:
            delHead(&l);
            break;
        case 6:
            delTail(&l);
            break;
        case 7:
            delElem(&l);
            break;

        case 8:
            exit(0);
            break;

        default:
            printf("\nInserire una scelta tra quelle mostrate.");
            break;
      }
    } while (1);

    return 0;
}
