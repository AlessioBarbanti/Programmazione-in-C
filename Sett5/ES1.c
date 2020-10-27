/* Si scriva un programma C, adeguatamente commentato, che gestisca un certo numero di studenti iscritti ad un corso di laurea.
 Il programma utilizza un vettore di strutture, ognuna delle quali memorizza le informazioni di uno studente (numero matricola,
  nome e cognome, anno di immatricolazione, piano di studi, …).

  Il programma utilizza inoltre un vettore di strutture, ognuna delle quali memorizza le informazioni di un insegnamento
  (codice, descrizione, anno di somministrazione, crediti, …).

  Il programma deve fornire la possibilità di:

aggiungere un nuovo studente, stampando un messaggio di errore se lo studente è già presente (individuato dalla matricola) o se il vettore è pieno; ok
la funzione deve inoltre assegnargli un piano di studi scegliendo fra gli insegnamenti disponibili. ok
dato il numero di matricola, stampare le informazioni dello studente oppure un messaggio di errore se la matricola non è presente nel vettore ok
dato un numero di matricola, modificare le informazioni del piano di studi aggiungendo un voto oppure stampando un messaggio di errore se la matricola non è presente nel vettore. ok
Calcolare la media dei voti di tutti gli studenti che hanno completato il piano di studi pesata sul numero di crediti di ogni insegnamento. ok

Il piano di studi all’interno della struttura studente è un vettore di NUM_ESAMI elementi ognuno di tipo struttura contenete il codice dell'insegnamento e il voto corrispondente (0 se non sostenuto).ok

Modificare il programma dell'esercizio 1 in modo che il vettore di studenti venga allocato dinamicamente e successivamente riallocato al suo riempimento. ok
Inizialmente usare la funzione malloc() per allocare lo spazio sufficiente per un vettore di 10 strutture studente, Quando il vettore non ha più spazio ok
per contenere nuovi studenti, utilizzare la funzione realloc() per raddoppiare la sua dimensione. Ripetere il raddoppio delle dimensioni ogni volta che il vettore si riempie. ok */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#define MAX_DIM 40
#define NUM_ESAMI 3
//creo la struttura materia che andrò poi a immettere in studente
typedef struct
{
    int id;
    char insegnamento[20];
    int crediti;
    int voto;
}
materia;
//creo la struttura studente
typedef struct
{
    int n_matricola;
    char nome[21];
    char cognome[31];
    int anno_immatr;
    materia piano_studi[NUM_ESAMI];
}
studente;

int main()
{
    int dim, i, scelta, ricerca, controllo,num,dimpunt=10; //num è una variabile che indica il numero di sudenti presenti nel vettore
    bool trovato;
    float media_studenti;


    studente* uni; //variabile puntatore di tipo studente
    uni = (studente *) malloc(dimpunt * sizeof(studente)); //considero uni come un gruppo di studenti (vettore)

    do
    {
        printf("quanti studenti si vogliono inserire? ");
        controllo = scanf("%d",&dim);
    }
    while(controllo != 1 || dim < 0 || dim > dimpunt);

    num = dim;// memorizzo il numero di studenti

    printf("\nInserisci le %d materie del piano di studi: \n", NUM_ESAMI); 
    for(int k = 0; k<NUM_ESAMI; k++){ //stampo e immetto i dati iniziali
    printf("Nome materia %d: ", k+1);
    scanf("%s",uni[0].piano_studi[k].insegnamento);
    printf("ID materia %d: ", k+1);
    scanf("%d",&uni[0].piano_studi[k].id);
    printf("Crediti materia %d: ", k+1);
    scanf("%d",&uni[0].piano_studi[k].crediti);
    }


//uso questo for per copiare ogni materia per ogni sudente
    for(i = 1; i < dim + MAX_DIM; i++)
    {
        //strcpy mi permette di copiare le materie
        for(int k = 0; k<NUM_ESAMI; k++)
        {
            strcpy(uni[i].piano_studi[k].insegnamento, uni[0].piano_studi[k].insegnamento);
        }
    }

    for(i = 0; i < dim; i++)
    {

        do
        {
            printf("numero di matricola (massimo 8 cifre): ");
            scanf("%d",&ricerca);



        for(int k = 0; k <= num && ricerca != -1; k++)  //scorro il vettore per cercare la matricola già presente, se la trovo, faccio riprovare
        {
            if(uni[k].n_matricola == ricerca)
            {
                printf("\nMatricola gia in elenco, riprovare \n\n");
                ricerca = -1;
            }
        }

        if (ricerca != -1){
            uni[i].n_matricola = ricerca;
        }


        } while(ricerca > 99999999 || ricerca < 0); //numero massimo matricola






        //continuo con l'immissione, è possibile avere due persone omonime, quindi non cerco doppioni
        printf("nome: ");
        scanf("%s",uni[i].nome);
        printf("cognome: ");
        scanf("%s",uni[i].cognome);
        printf("anno di immatricolazione: ");
        scanf("%d",&uni[i].anno_immatr);
        for(int k =0; k<NUM_ESAMI; k++) //immetto i dati dello stundente alla posizione k
        {
            printf("\ninserire un voto per %s: ",uni[i].piano_studi[k].insegnamento);
            scanf("%d",&uni[i].piano_studi[k].voto);

        }
    }

    do
    { //menu
        printf("1. Aggiungere un nuovo studente\n");
        printf("2. Conoscere le informazioni di uno studente\n");
        printf("3. Modificare i voti di uno studente\n");
        printf("4. Visualizzare media pesata dei voti per ogni materia\n");

        trovato = false;
        scanf("%d",&scelta);
        switch(scelta)
        {
        case 1: //aggiunta studente
            if(num== dimpunt) // se il vettore è pieno
            {
                dimpunt *= 2;
                uni = (studente *) realloc(uni,dimpunt * sizeof(studente));
                //inserisco nomi delle materie per la nuova dimensione
                for(i = dimpunt/2; i < dimpunt; i++)
                {
                    for(int k =0; k<NUM_ESAMI; k++)
                    {
                        strcpy(uni[i].piano_studi[k].insegnamento, uni[0].piano_studi[k].insegnamento);
                    }
                }
                break;
            }

            do
            {
                printf("numero di matricola (massimo 8 cifre : ");
                scanf("%d",&ricerca);
                trovato = false;
            }
            while(ricerca > 99999999 || ricerca < 0);

            for(i = 0; i <= num && !trovato; i++) //vedi sopra
            {
                if(uni[i].n_matricola == ricerca)
                {
                    printf("\nmatricola gia in elenco, impossibile proseguire \n\n");
                    trovato = true;
                }
            }
            if(trovato)

                break;

            printf("inserire i dati della nuova matricola \n\n");

            printf("nome: ");
            scanf("%s",uni[num].nome);
            printf("cognome: ");
            scanf("%s",uni[num].cognome);
            printf("anno di immatricolazione: ");
            scanf("%d",&uni[num].anno_immatr);

            for(int k = 0; k<NUM_ESAMI; k++)
            {
                printf("\ninserire un voto per %s: ",uni[i].piano_studi[k].insegnamento);
                scanf("%d",&uni[num].piano_studi[k].voto);
            }
            num++;
            break;

        case 2: //informazioni
            do
            {
                printf("numero di matricola da cercare (massimo 8 cifre) : ");
                scanf("%d",&ricerca);
                trovato = false;
            }
            while(ricerca > 99999999 || !ricerca);

            for(i = 0; i < num && !trovato; i++)
            {
                if(uni[i].n_matricola == ricerca)
                {
                    printf("matricola: %.8d\n",uni[i].n_matricola);
                    printf("nome: %s\n",uni[i].nome);
                    printf("cognome: %s\n",uni[i].cognome);
                    printf("anno di immatricolazione: %d\n\n",uni[i].anno_immatr);

                    if(uni[i].piano_studi[0].voto == 0)
                    {
                        printf(" l'esame di %s non e' ancora sostenuto", uni[i].piano_studi[0].insegnamento);
                    }
                    else
                    {
                        printf("\ni voti sono:\n %s: %d\n", uni[i].piano_studi[0].insegnamento, uni[i].piano_studi[0].voto);
                    }
                    if(uni[i].piano_studi[1].voto == 0)
                    {
                        printf(" l'esame di %s non e' ancora sostenuto", uni[i].piano_studi[1].insegnamento);
                    }
                    else
                    {
                        printf(" %s: %d\n", uni[i].piano_studi[1].insegnamento, uni[i].piano_studi[1].voto);
                    }
                    if(uni[i].piano_studi[2].voto == 0)
                    {
                        printf(" l'esame di %s non e' ancora sostenuto", uni[i].piano_studi[2].insegnamento);
                    }
                    else
                    {
                        printf(" %s: %d\n", uni[i].piano_studi[2].insegnamento, uni[i].piano_studi[2].voto);
                    }
                    trovato = true;
                }
            }
            if(!trovato)
            {
                printf("\nla matricola non e' stata trovata!\n");
                break;
            }
            break;

        case 3: //mod voti
            do
            {
                printf("numero di matricola da cercare (max 8 cifre, int): ");
                scanf("%d",&ricerca);
                trovato = false;
            }
            while(ricerca > 99999999);

            for(i = 0; i < num && !trovato; i++)
            {
                if(uni[i].n_matricola == ricerca)
                {
                    printf("i voti sono:\n %s: %d\n", uni[i].piano_studi[0].insegnamento, uni[i].piano_studi[0].voto);
                    printf(" %s: %d\n", uni[i].piano_studi[1].insegnamento, uni[i].piano_studi[1].voto);
                    printf(" %s: %d\n", uni[i].piano_studi[2].insegnamento, uni[i].piano_studi[2].voto);
                    trovato = true;
                }
            }
            if(!trovato)
            {
                printf("la matricola non e' stata trovata!\n");
                break;
            }
            i--;
            printf("inserire il numero della materia da modificare ");
            scanf("%d",&ricerca);

            printf("\ninserire il voto di %s: ",uni[i].piano_studi[ricerca-1].insegnamento); //se trovo la matricola inserisco i nuovi voti e aggiorno i campi

            switch (ricerca)
            {
            case 1:
                scanf ("%d", &uni[i].piano_studi[0].voto);
                break;
            case 2:
                scanf ("%d", &uni[i].piano_studi[1].voto);
                break;
            case 3:
                scanf ("%d", &uni[i].piano_studi[2].voto);
                break;
            default:
                printf("inserimento sbagliato!");
                break;
            }

            break;

        case 4:
            printf("DEBUG voto studente %d = %d\n", 0, uni[0].piano_studi[0].voto);

            for(media_studenti = 0, i = 0; i < NUM_ESAMI; i++) //sccorro i voti dei vari studenti con 2 cicli e faccio la media per ogni insegnamento
            {


                for(int k = 0; k<num; k++)
                {
                    //   printf("DEBUG k = %d ---- i= %d\n", k, i);
                    //   printf("DEBUG uni[k].piano_studi[i].voto = %d \n", uni[k].piano_studi[i].voto);
                    media_studenti += uni[k].piano_studi[i].voto;

                }

                media_studenti = media_studenti / num;

                printf("Media degli studenti per %s = %5.2f\n", uni[i].piano_studi[i].insegnamento, media_studenti);
                media_studenti = 0;
            }


            break;

            break;

        } //fine switch
    } //fine do
    while(scelta > 0 && scelta < 5);


    return 0;
}
