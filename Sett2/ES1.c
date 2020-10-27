

#include <stdio.h>
#include <ctype.h>
int main()
{

    int spaziBianchi=0;
    int alfabetici=0;
    int alfanumerici=0;
    int controllo=0;
    int cifre=0;
    int grafico=0;
    int minuscole=0;
    int maiuscole=0;
    int stampabile=0;
    int punteggiatura=0;
    int spaziatura=0;
    int esadecimale=0;
    int c=0;

while(1){

    c = getchar();

    if(c == 35){ //se è un carattere di ritorno (\n) stampo la lista, se non lo è incremento la varibile corrispondente
        printf("Spazi Bianchi: %d \n", spaziBianchi);
        printf("Caratteri Alfabetici: %d \n", alfabetici);
        printf("Caratteri Alfanumerici: %d \n", alfanumerici);
        printf("Caratteri di controllo: %d \n", controllo);
        printf("Cifre: %d \n",cifre);
        printf("Caratteri grafici: %d \n",grafico);
        printf("Minuscole: %d \n",minuscole);
        printf("Maiuscole: %d \n",maiuscole);
        printf("Caratteri stampabili: %d \n",stampabile);
        printf("Segni di punteggiatura: %d \n",punteggiatura);
        printf("Spaziature: %d \n",spaziatura);
        printf("Caratteri esadecimali: %d \n",esadecimale);
    }
    else {

    if (isalnum(c)){alfanumerici++;};
    if (isalpha(c)){alfabetici++;};
    if (isblank(c)){spaziBianchi++;};
    if (iscntrl(c)){controllo++;};
    if (isdigit(c)){cifre++;};
    if (isgraph(c)){grafico++;};
    if (islower(c)){minuscole++;};
    if (isprint(c)){stampabile++;};
    if (ispunct(c)){punteggiatura++;};
    if (isspace(c)){spaziatura++;};
    if (isupper(c)){maiuscole++;};
    if (isxdigit(c)){esadecimale++;};


    }
 }
}
