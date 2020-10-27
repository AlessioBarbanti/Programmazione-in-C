
#include <stdio.h>


int main()

{
	int min, max, numero, i = 0;
	char direzione = 'a';
	int temp;

	printf("Inserisci l’intervallo di ricerca (min < max):");
	scanf("%d %d", &min, &max);
	getchar();
	printf("Pensa ad un numero compreso tra %d e %d. (Estremi esclusi) \n", min,max);

    while(direzione != '='){ //continuo a ciclare finchè l'utente non immette = ovvero "hai indovinato!"
        numero = (min + max) / 2; //ricomincio la ricerca dalla media dei valori
        printf("Il numero che hai pensato è maggiore (>) o minore (<) o uguale (=)di %d? \n", numero);
        printf("min = %d ; max = %d\n",min, max);
        scanf("%c", &direzione);


        if (direzione == '<') {
            max = numero;

        }
        if (direzione == '>') {
            min = numero;
        }

    }
    printf("Hai indovinato!");



return 0;
}
