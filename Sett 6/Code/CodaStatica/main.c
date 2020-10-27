
#include "codaStatica.h"

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
    Tipocoda c;
    c.primo = 0;
    c.ultimo = 0;

    do {
        stampaCoda(c);
        int scelta = 0;
        printf("\n1.  Push - Aggiungi Elemento\n");
        printf("2.  Pop - Rimuovi il primo elemento\n");
        printf("3.  Ritorna il primo elemento senza eliminarlo \n");
        printf("4.  Controlla se sono presenti elementi in lista \n");
        printf("5. EXIT\n");
        scanf("%d", &scelta);
        fflush(stdin);





        switch (scelta) {



        case 1:
            push(&c);
            break;


       case 2:
            pop(&c);
            break;

        case 3:
            printf("primo elemento in coda: %d\n",first(&c));
            break;

        case 4:
            if (isEmpty(c)) printf("\ncoda vuota!\n");
            else printf("\nla coda non e' vuota!\n");
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
