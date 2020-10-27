/* Scrivete un programma che generi una “passeggiata aleatoria” (random walk) in un array bidimensionale di dimensione 10×10.
 L’array sarà riempito di caratteri (inizialmente da punti). Il programma dovrà muoversi di elemento in elemento spostandosi
Ogni volta di un passo in direzione su, giù, destra o sinistra. Gli elementi visitati andranno etichettati con le lettere
dalla A alla Z, nell’ordine in cui vengono visitati. E’ importante controllare ad ogni passo che la passeggiata non esca
dall’array e che non ritorni su posizioni già visitate. Quando si verifica una di queste condizioni, provate in altre
direzioni. Se tutte e quattro le direzioni sono bloccate, il programma deve uscire.

Ecco un esempio di funzionamento completo:

A . . . . . . . . . .

B C D . . . . . . .

. F E . . . . . . .

H G . . . . . . . .

I . . . . . . . . .

J . . . . . . . Z .

K . . R S T U V Y .

L M P Q . . . W X .

. N O . . . . . . .

. . . . . . . . . .

Ecco un esempio di uscita prematura dal programma:

A B G H I . . . . .
. C F . J K . . . .
. D E . M L . . . .
. . . . N O . . . .
. . W X Y P Q . . .
. . V U T S R . . .
. . . . . . . . . .
. . . . . . . . . .
. . . . . . . . . .
. . . . . . . . . .

Y è bloccata in tutte le direzioni quindi non c’è modo di inserire Z. */

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main(){
srand(time(0));
char vett[10][10];
char lettera = 'A';
int su, destra, giu, sinistra = 1;
int direzione = rand() % 4;
//popolo matrice con  '.'
for (int i = 0; i<10 ; i++)
    {
        for(int k = 0; k<10; k++)
        {
            vett[i][k] = '.';
        }
    }





int x = 4;
int y = 4;

vett[x][y] = lettera;

//entra nel while solo se non si è raggiunta la lettera z e se è disponibile almeno una direzione
while(lettera < 90 && (su == 1 || destra == 1 || giu == 1|| sinistra == 1)){

//randomizzo la scelta della direzione
direzione = rand() % 4 + 1;

//ogni case ha un if, se true aggiungo la lettera alla casella e considero tutte le direzioni ancora disponibili.
switch(direzione)
{
case 1:
    if (x != 0 && vett[x-1][y] == '.')
    {
        lettera++;
        x--;
        vett[x][y] = lettera;
        su =1;
        giu =1;
        destra =1;
        sinistra = 1;
    }
    else{
        su = 0;
    }
    break;

case 2:
    if (y != 9 && vett[x][y+1] == '.')
    {

        lettera++;
        y++;
        vett[x][y] = lettera;
        su =1;
        giu =1;
        destra =1;
        sinistra = 1;
    }
    else{
        destra = 0;

    }
    break;

case 3:
    if (x != 9 && vett[x+1][y] == '.')
    {


        lettera++;
        x++;
        vett[x][y] = lettera;
        su =1;
        giu =1;
        destra =1;
        sinistra = 1;
    }
    else{
        giu = 0;
    }
    break;

case 4:
    if (y != 0 && vett[x][y-1] == '.')
    {

        lettera++;
        y--;
        vett[x][y] = lettera;
        su =1;
        giu =1;
        destra =1;
        sinistra = 1;
    }
    else{
        sinistra = 0;
    }
    break;

}

}



//stampa dei caratteri
for (int i = 0; i<10 ; i++)
    {
        for(int k = 0; k<10; k++)
        {
            printf("%c ",vett[i][k]);

        }
        printf("\n");
    }
}

