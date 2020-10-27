/* Scrivere un programma C che riceva in ingresso due parole inserite da tastiera. Si consideri che ciascuna parola
 può contenere al massimo 30 caratteri. Il programma deve essere case sensitive, cioè deve distinguere lettere
  minuscole da lettere maiuscole e deve essere in grado anche di analizzare numeri, simboli e segni di punteggiatura.
   Il programma deve sostituire ogni occorrenza della seconda parola nella prima parola con il carattere ’*’. Ad esempio,
   inserite le parole

abchdfffchdchdtlchd

e

chd

il programma deve visualizzare la parola

ab*fff**tl*

Scrivere due versioni:
la prima deve ignorare la presenza della libreria string.h e quindi dovete lavorare esplicitamente su ogni singolo carattere delle stringhe.
La seconda deve usare le funzioni della libreria string.h per determinare la lunghezza e per ricercare sotto-stringhe all'interno di una stringa
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

    char stringa1[31] = {0}; //30 più carattere terminatore
    char stringa2[31] = {0};

    int l_str1, l_str2 ; /* lunghezza delle due stringhe inserite */

    int match ; /* flag per la ricerca */
    int i, j ; /* indici dei cicli */

    /*  //VERSIONE SENZA USARE STRING.H
        printf ("Inserisci una parola (Max 30 caratteri): ") ;
        gets(stringa1) ;


        for(i=0; i<30; i++)
        {
            if (stringa1[i] != '\0')
                l_str1++;
        }




        // LEGGI LA SECONDA PAROLA INSERITA DA TASTIERA
        printf ("Inserisci una parola di al massimo 30 caratteri: ") ;
        gets(stringa2) ;

        // CALCOLA LA LUNGHEZZA DELLA PAROLA
        l_str2 = strlen(stringa2);




        //CICLO PER
        for ( i=0; i+(l_str2-1)<l_str1; i++ )
        {

            match = 1 ;
            for ( j=0; j<l_str2 && match==1; j++ )
            {
                if ( stringa1[i+j] != stringa2[j] )
                    match = 0 ;
            }


            if ( match==1 )
            {
                stringa1[i] = '*';
                for ( j=1; j<l_str1-i; j++ )
                {
                    stringa1[i+j] = stringa1[i+j+l_str2-1];
                }
            }
        }
         //STAMPA IL RISULTATO
        printf("%s \n", stringa1) ;*/


    //-------------------------------------------------------------------------------------------------------------------------


    printf ("** Sto usando String.h **\n");


    printf ("Inserisci una parola (Max 30 caratteri): ") ;
    gets(stringa1) ;
    l_str1 = strlen(stringa1);


    /* LEGGI LA SECONDA PAROLA INSERITA DA TASTIERA */
    printf ("Inserisci una parola di al massimo 30 caratteri: ") ;
    gets(stringa2) ;

    /* CALCOLA LA LUNGHEZZA DELLA PAROLA */
    l_str2 = strlen(stringa2);

    char *pch = NULL;
for(i=0; i<l_str1;i++){ //PARTENDO DA OGNI LETTERA CONTROLLO SE C'è UN MATCH CON LA SECONDA STRINGA
    pch = strstr (stringa1,stringa2);
    if(pch != NULL){ //SE TROVO UN'OCCORRENZA (OVVERO SE STRSTR NON RITORNA 0)
        strncpy (pch,"*",1); //COPIO L'ASTERISCO
        strncpy ( pch+sizeof(char), pch+(sizeof(char)*l_str2), l_str1-i ); //PUNTANDO ALLA CELLA SUCCESSIVA DELL'ARRAY COPIO IL RESTO DELLA STRINGA
        pch = NULL; //PREPARO IL PUNTATORE PER UNA NUOVA RICERCA
        puts (stringa1); //DEBUG, STAMPO LA PAROLA AD OGNI OCCORRENZA PER VEDERE COME LAVORA IL PROGRAMMA

 }







}












return(0);
}
