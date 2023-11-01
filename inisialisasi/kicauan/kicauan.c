#include <stdio.h>
#include <stdlib.h>
#include "kicauan.h"

// void printWord(Word kata)
// {
//     for (int i = 0; i < kata.Length; i++)
//     {
//         printf("%c",kata.TabWord[i]);
//     }
//     printf("\n");   
// }

boolean isWordEqual(Word input, Word cek)
{
    if (input.Length != cek.Length)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < input.Length; i++)
        {
            if (input.TabWord[i] != cek.TabWord[i])
            {
                return false;
            }
        }
        return true;
    }
}

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

    for (int i = 0; i < 2; i++)
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
        DATETIMEKICAUAN(ELMTKICAUAN(*l,i)) = currentWord;
    }
}

/* ********** MEMBACA KICAUAN ********** */


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
    printf("%d\n",IDKICAUAN(T));
    printWord(TEXTKICAUAN(T));
    printf("%d\n",LIKEKICAUAN(T));
    printWord(AUTHORKICAUAN(T));
    printWord(DATETIMEKICAUAN(T));
}