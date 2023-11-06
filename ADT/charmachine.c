/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include "charmachine.h"
#include <stdio.h>

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START()
{
    /* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
       Karakter pertama yang ada pada pita posisinya adalah pada jendela.
       I.S. : sembarang
       F.S. : currentChar adalah karakter pertama pada pita. Jika currentChar != MARKC maka EOP akan padam (false).
              Jika currentChar = MARKC maka EOP akan menyala (true) */

    /* Algoritma */
    pita = stdin;
    ADV();
}

void STARTFILE(char filename[])
{
    pita = fopen(filename,"r");
    ADV();
}

void ADV()
{
    /* Pita dimajukan satu karakter.
       I.S. : Karakter pada jendela =
              currentChar, currentChar != MARKC
       F.S. : currentChar adalah karakter berikutnya dari currentChar yang lama,
              currentChar mungkin = MARKC.
                    Jika  currentChar = MARKC maka EOP akan menyala (true) */

    /* Algoritma */
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARKC);
    // if (EOP)
    // {
    //     fclose(pita);
    // }
}

boolean retValues()
{
    return (retval == 1);
    // ganti retval jadi akses valuesnya dari retValues()
}