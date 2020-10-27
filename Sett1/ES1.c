/*
Scrivere un programma C che dichiari una variabile per ogni tipo studiato (usando anche i qualificatori short, long, signed e unsigned),
ne stampi il valore e l’occupazione di memoria in byte. Utilizzare TUTTI gli argomenti della funzione printf() studiati e TUTTE le
diverse varianti (modificatore, campoMinimo, precisione, modificatoreLunghezza). Per ogni chiamata alla funzione printf(), mostrare
a video anche il numero di caratteri che quest’ultima ha stampato. Stampare inoltre il valore minimo e il valore massimo ammissibile
per ogni tipo utilizzato.
*/


#include <stdio.h>
#include <limits.h>
#include <float.h>

//definisco vari tipi di variabili
short int si=1000;
int i=1;
unsigned int ui=50;
long int li=600;
unsigned long int ul=800;
unsigned short int us=20;
unsigned char uc='a';
char c='c';
double d=5.201447;
long double dl=5.201447;
float f=2.57895;

int k=0;
//sfrutto ilritorno della printf per vedere quanti caratteri ho stampato e uso le funzioni della libreria limits
int main()
{
	k = printf("short int = %-5d Dim: %d Min; %d Max:  %d \n",si,sizeof(si),SHRT_MIN,SHRT_MAX);
	printf("caratteri stampati: %d \n",k);

	k = printf("int  = %hd Dim: %d Min: %d Max: %d\n",i,sizeof(i),INT_MIN,INT_MAX );
	printf("Caratteri stampati: %d\n",k);

	k = printf("unsigned int  = %d Dim: %d Min: %d Max: %d\n",ui,sizeof(ui),UINT_MAX );
	printf("Caratteri stampati: %d\n",k);

	k = printf("long int = %d Dim: %d Min: %d Max %d\n",li,sizeof(li),LONG_MIN,LONG_MAX );
	printf("Caratteri stampati: %d\n",k);


	k = printf("unsigned long int = %d Dim: %d Min: 0 Max %o (ottale)\n",ul,sizeof(ul),ULONG_MAX );
	printf("Caratteri stampati: %d\n",k);

	k = printf("unsigned char = %c Dim: %d Min: 0 Max %d\n",uc,sizeof(uc),UCHAR_MAX );
	printf("Caratteri stampati: %d\n",k);

	k = printf("char = %c Dim: %d Min: %d Max: %d\n",c,sizeof(c),CHAR_MIN,CHAR_MAX);
	printf("Caratteri stampati: %d\n",k);

	k = printf("unsigned short int = %d Dim: %d Min: 0 Max: %d\n",us,sizeof(us),USHRT_MAX);
	printf("Caratteri stampati: %d\n",k);

	k = printf("double = %g Dim: %d Min: %d Max: %d (Libreria non funzionante?)\n",d,sizeof(d),DBL_MIN,DBL_MAX);
	printf("Caratteri stampati: %d\n",k);

	k = printf("float = %0.3g Dim: %d Min: %d Max: %d\n",f,sizeof(f),FLT_MIN,FLT_MAX);
	printf("Caratteri stampati: %d\n",k);

	k = printf("long double = %g Dim: %d Min: %d Max: %d\n",dl,sizeof(f),LDBL_MIN,LDBL_MAX);
	printf("Caratteri stampati: %d\n",k);

	return 0;
}
