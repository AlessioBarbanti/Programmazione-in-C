#include<stdio.h>

long calcolaFattoriale(int numero)
{
	long rit;
	static int contatore=0; // uso una variabile statica che non viene reinizializzata durante la ricorsione
	int i=0;

	if (numero == 0)
		return 1;
	else
	{
		contatore++;

		for(i=0;i<contatore;i++) //uso un for per stampare gli spazi per il livello di rientro
			printf(" ");

		printf("%d*fattoriale(%d)= %d*%d! \n",numero,numero-1,numero,numero-1);

		rit=(numero * calcolaFattoriale(numero-1)); //RICORSIONE!

		contatore--;

		for(i=0;i<contatore;i++) //uso un for per stampare gli spazi per il livello di rientro
			printf(" ");

		printf("%d*fattoriale(%d)= %d*%d! \n",numero,numero-1,numero,numero-1);
	}
	return rit;
}

int main()
{
    int numero;
	long f;

	do
	{
		printf("Inserisci il numero da fattorializzare(compreso fra 1 e 10): ");
		scanf("%d", &numero);
	}
	while(numero<1 || numero<10);

	if (numero < 0)
		printf("I numeri negativi non sono permessi.\n");
	else
	{
		f = calcolaFattoriale(numero); //chiamo la funzione ricorsiva
		printf("\n%d! = %ld\n", numero, f);
	}

	return 0;
}
