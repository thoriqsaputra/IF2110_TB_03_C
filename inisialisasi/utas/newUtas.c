#include <stdio.h>
#include <stdlib.h>
#include "newUtas.h"

void CreateListUtas(ListDinUtas *l, int capacity)
{
    NEFFUTAS(*l) = 0;
    BUFFERUTAS(*l) = (Utas *)malloc(capacity * sizeof(Utas));
    CAPACITYUTAS(*l) = capacity;
}

void dealocateListUtas(ListDinUtas *l)
{
    free(BUFFERUTAS(*l));
    NEFFUTAS(*l) = 0;
    CAPACITYUTAS(*l) = 0;
}

void displayDataUtas(Utas id)
{
    printf("ID Kicau: %d\n", IDKICAUUTAS(id));
    printf("ID Utas: %d\n", IDUTAS(id));
    printf("Text: ");
    printWord(TEXTUTAS(id));
    printf("\n");
    printf("Author: ");
    printWord(AUTHORUTAS(id));
    printf("\n");
    printf("Datetime: ");
    TulisDATETIME((id).datetime);
    printf("\n");
}

void loadUtasConfig(char filename[], ListDinUtas *LD)
{
    STARTWORDFILE(filename);
    int capacity = currentWord.TabWord[0] % 48;
    CreateListUtas(LD, capacity);
    if (capacity != 0)
    {
        ADVWORDFILE();
    }
    int idUtas = 1;
    for (int i = 0; i < capacity; i++)
    {
        int idKicau = currentWord.TabWord[0] % 48;
        ADVWORDFILE();
        int banyakUtas = currentWord.TabWord[0] % 48;
        ADVWORDFILE();
        for (int j = 0; j < banyakUtas; j++)
        {
            Utas temp;
            temp.idKicau = idKicau;
            temp.idUtas = idUtas;
            idUtas++;
            temp.text = currentWord;
            ADVWORDFILE();
            temp.author = currentWord;
            ADVWORDFILE();
            DATETIME t;
            int DD = (int)(currentWord.TabWord[0] % 48) * 10 + (int)(currentWord.TabWord[1] % 48);
            int MM = (int)(currentWord.TabWord[3] % 48) * 10 + (int)(currentWord.TabWord[4] % 48);
            int YY = (int)(currentWord.TabWord[6] % 48) * 1000 + (int)(currentWord.TabWord[7] % 48) * 100 + (int)(currentWord.TabWord[8] % 48) * 10 + (int)(currentWord.TabWord[9] % 48);
            int hh = (int)(currentWord.TabWord[11] % 48) * 10 + (int)(currentWord.TabWord[12] % 48);
            int mm = (int)(currentWord.TabWord[14] % 48) * 10 + (int)(currentWord.TabWord[15] % 48);
            int ss = (int)(currentWord.TabWord[17] % 48) * 10 + (int)(currentWord.TabWord[18] % 48);
            CreateDATETIME(&t, DD, MM, YY, hh, mm, ss);
            temp.datetime = t;
            addUtas(LD, temp);
            if (j != banyakUtas - 1)
            {
                ADVWORDFILE();
            }
        }
        if (i != capacity - 1)
        {
            ADVWORDFILE();
        }
    }
}

void addUtas(ListDinUtas *l, Utas u)
{
    if (isFullOfUtas(*l))
    {
        if (CAPACITYUTAS(*l) == 0)
        {
            CAPACITYUTAS(*l) = 1;
            BUFFERUTAS(*l) = (Utas *)malloc(CAPACITYUTAS(*l) * sizeof(Utas));
        }
        else
        {
            CAPACITYUTAS(*l) *= 2;
            BUFFERUTAS(*l) = (Utas *)realloc(BUFFERUTAS(*l), CAPACITYUTAS(*l) * sizeof(Utas));
        }
    }
    ELMTUTAS(*l, NEFFUTAS(*l)) = u;
    NEFFUTAS(*l) += 1;
}

boolean isFullOfUtas(ListDinUtas l)
{
    return (NEFFUTAS(l) == CAPACITYUTAS(l));
}

void deleteLinkedDrafByIdUtas(ListDinUtas *l, int id)
{
    int i = 0;
    while (i < NEFFUTAS(*l))
    {
        if (ELMTUTAS(*l, i).idKicau == id)
        {
            for (int j = i; j < NEFFUTAS(*l) - 1; j++)
            {
                ELMTUTAS(*l, j) = ELMTUTAS(*l, j + 1);
            }
            NEFFUTAS(*l) -= 1;
        }
        else
        {
            i++;
        }
    }
}