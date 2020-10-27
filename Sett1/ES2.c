/*



Scrivere un programma C che mostri l’utilizzo di tutti gli operatori studiati. ok

Il programma deve inoltre mostrare il comportamento scorretto che si ottiene utilizzando tipi non appropriati
alla dimensione delle variabili, ok

quello che si ottiene usando più operatori con side effects all’interno della stessa istruzione,

 quello che si ottiene quando le regole di conversione implicita sono applicate e ok

 quando si supera il range dei valori disponibili per un tipo di dato. ok

Il programma deve poi mostrare l’utilizzo di tutte le funzioni matematiche della libreria math.h.

*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

//dichiaro le variabili



int main()
{
    int ris = 0;
	int num1 = 6;
	int num2 = 2;
	printf("num1 = %d \nnum2 = %d \n\n",num1,num2);

	//stampo le varie operazioni con gli operandi interi

	printf("6+2=%d \n",num1+num2);
	printf("6-2=%d \n",num1-num2);
	printf("6*2=%d \n",num1*num2);
	printf("6/2=%d \n",num1/num2);
	printf("6%%2=%d \n\n",num1%num2);

	//ora uso gli operatori compatti

	printf("operatori compatti \n\n");

	num1=6;
	num1+=3;
	printf("num1 con addizione compatta : %d\n",num1);

	num1=6;
	num1-=3;
	printf("num1 con sottrazione compatta : %d\n",num1);

	num1=6;
	num1*=3;
	printf("num1 con moltiplicazione compatta : %d\n",num1);

	num1=6;
	num1/=3;
	printf("num1 con divisione compatta : %d\n",num1);

	num1=6;
	num1%=3;
	printf("num1 con resto modulo compatto : %d\n",num1);

	//Es. tipi non appropriati alla dimensione delle variabili
	num1 = INT_MAX + 1;
	num2 = INT_MAX + 6;
	ris = num1+num2;
	printf("Dichiarazione errata delle variabili e relativa somma: %d + %d = %d\n\n",num1, num2, ris);

    //supera il range dei valori disponibili per un tipo di dato.

	num1 = INT_MAX;
	num2 = INT_MAX;
	ris = num1 + num2;
	printf("Somma errata di %d + %d = %d\n\n",num1, num2, ris);

    //quello che si ottiene usando più operatori con side effects all’interno della stessa istruzione,
    num1 = 0;
    ris = (num1*3) + (++num1);
    printf("(num1*3) + (++num1) = %d\n\n", ris);

    num1 = 1;
    ris=(num1++)+(++num1);
    printf("(num1++)+(++num1) = %d\n\n", ris);

//quello che si ottiene quando le regole di conversione implicita sono applicate
    num1 = 3;
    num2 = 5;
    (float)ris;
    printf("(int)num1 * (int)num3 = (float) %d\n\n", ris);


//quello che si ottiene quando le regole di conversione implicita sono applicate

    num1 = 3;
    num2 = 5;
    float ris2;

    ris2 = num1 / num2;
    printf("Divido i due interi e poi casto a Float %d/%d = %6.4f \n", num1, num2, ris2); /* stampa 0.0000 */

    ris2 = num1 / (float)num2;
    printf("Casto il secondo a float (il primo si converte in automatico) e lo assegno ad una variabile già float %d/%d = %6.4f \n", num1, num2, ris2); /* stampa 0.5556 */


    //libreria Math.h

        printf("La radice quadrata di 4 e': %lf \n", sqrt(4.0) );
        printf("il seno di 45 e': %lf \n", sin(45));
        printf("il arcoseno di 0.5 e': %lf \n", asin(0.5));
        printf("il coseno di 45 e': %lf \n", cos(45));
        printf("il arcocoseno di 0.5 e': %lf \n", acos(0.5));
        printf("la tangente di 45 e': %lf \n", tan(45));
        printf("l'arcotangente di 45 e': %lf \n", atan(45));
        printf("e elevato alla 5: %lf \n", exp(5));
        printf("10 elevato alla 5: %lf \n", pow10(5));
        printf("ln(5) : %f \n", log(1.5));
        printf("log10(5) : %f \n", log10(5));
        printf("il valore assoluto di -5 e': %1f \n", fabs(-5));
        printf("se un triangolo ha 2 lati uguali a 2, la sua ipotenusa è: %1f \n", hypot(2.0,2.0));
        printf("5 elevato alla 3 è uguale a: %lf",pow(5.0,3.0));



	return 0;
}
