#include <stdio.h>
#include <stdlib.h>
#include "kicauan.h"

int wordToInt(Word kata)
{
    int res = 0;
    int i = 0;
    while (kata.TabWord[i] >= '0' && kata.TabWord[i] <= '9' && i < kata.Length) 
    // memeriksa jika char di antara kedua bilangan tersebut (Jika ditambah komen di kanan angka), dan i lebih kecil dari panjang (Jika tidak ada, karena tidak tahu mengapa begitu keluaran 24 untuk ID 2)
    {
        res = res * 10 + (kata.TabWord[i] - '0');
        i++;
    }
    return res;
}

void CreateDATETIMEfromWord(DATETIME *D, Word kata)
{
    int day, month, year, hour, minute, second;
    day = (kata.TabWord[0] % 48 ) * 10 + (kata.TabWord[1] % 48 );
    month = (kata.TabWord[3] % 48) * 10 + (kata.TabWord[4] % 48);
    year = (kata.TabWord[6] % 48) * 1000 + (kata.TabWord[7] % 48) * 100 + (kata.TabWord[8] % 48) * 10 + (kata.TabWord[9] % 48);
    hour = (kata.TabWord[11] % 48) * 10 + (kata.TabWord[12] % 48);
    minute = (kata.TabWord[14] % 48) * 10 + (kata.TabWord[15] % 48);
    second = (kata.TabWord[17] % 48) * 10 + (kata.TabWord[18] % 48);
    CreateDATETIME(D, day, month, year, hour, minute, second);
}

// Dari pengguna.c

/* ********** KONSTRUKTOR ********** */
void CreateListKicauan(ListDinKicauan *l, int capacity)
{
    NEFFKICAUAN(*l) = 0;
    CONTENTKICAUAN(*l) = (KICAUAN *)malloc(capacity * sizeof(KICAUAN));
    CAPACITYKICAUAN(*l) = capacity;
}

void dealocateListKicauan(ListDinKicauan *l)
{
    free(CONTENTKICAUAN(*l));
    NEFFKICAUAN(*l) = 0;
    CAPACITYKICAUAN(*l) = 0;
}

void loadKicauanConfig(char filename[], ListDinKicauan *l)
{
    STARTWORDFILE(filename);
    int capacity = wordToInt(currentWord);
    CreateListKicauan(l,capacity);

    for (int i = 0; i < CAPACITYKICAUAN(*l); i++)
    {
        ADVWORDFILE();
        IDKICAUAN(ELMTKICAUAN(*l,i)) = wordToInt(currentWord);
        ADVWORDFILE();
        TEXTKICAUAN(ELMTKICAUAN(*l,i)) = currentWord;
        ADVWORDFILE();
        LIKEKICAUAN(ELMTKICAUAN(*l,i)) = wordToInt(currentWord);
        ADVWORDFILE();
        AUTHORKICAUAN(ELMTKICAUAN(*l,i)) = currentWord;
        ADVWORDFILE();
        CreateDATETIMEfromWord(&DATETIMEKICAUAN(ELMTKICAUAN(*l,i)),currentWord);
    }
    NEFFKICAUAN(*l) = CAPACITYKICAUAN(*l);
}

/* ********** MEMBUAT KICAUAN ********** */
KICAUAN createNewKicauan(Word text);


/* ********** MENAMBAH KICAUAN DI AKHIR ********** */
void addKicauan(ListDinKicauan *l, KICAUAN t)
{
    if (isFullOfKicauan(*l))
    {
        if (CAPACITYKICAUAN(*l) == 0)
        {
            CAPACITYKICAUAN(*l) = 1;
        } else
        {
            CAPACITYKICAUAN(*l) *= 2;
        }
        CONTENTKICAUAN(*l) = (KICAUAN *)realloc(CONTENTKICAUAN(*l), CAPACITYKICAUAN(*l) * sizeof(KICAUAN));
    }
    ELMTKICAUAN(*l,NEFFKICAUAN(*l)) = t;
    NEFFKICAUAN(*l)++;
}

boolean isFullOfKicauan(ListDinKicauan l)
{
    return (NEFFKICAUAN(l) == CAPACITYKICAUAN(l));
}

void displayKicauan(KICAUAN T)
{
    printf("| ID : ");
    printf("%d\n",IDKICAUAN(T));

    printf("| @");
    printWord(AUTHORKICAUAN(T));
    printf("\n");

    printf("| ");
    printWord(TEXTKICAUAN(T));
    printf("\n");

    printf("| Disukai : ");
    printf("%d\n",LIKEKICAUAN(T));

    printf("| ");
    TulisDATETIME(DATETIMEKICAUAN(T));
    printf("\n");
}