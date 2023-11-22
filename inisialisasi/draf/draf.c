#include <stdio.h>
#include <stdlib.h>
#include "draf.h"

void CreateListDraf(ListDinDraf *l, int capacity)
{
    NEFFDRAF(*l) = 0;
    BUFFERDRAF(*l) = (Draf *)malloc(capacity * sizeof(Draf));
    CAPACITYDRAF(*l) = capacity;
}

void dealocateListDraf(ListDinDraf *l)
{
    free(BUFFERDRAF(*l));
    NEFFDRAF(*l) = 0;
    CAPACITYDRAF(*l) = 0;
}

void createDraf(Draf *d, Word text, Word author, DATETIME datetime)
{
    (*d).id = 0;
    (*d).text = text;
    (*d).author = author;
    (*d).datetime = datetime;
}

void loadDrafConfig(char filename[], ListDinDraf *LD)
{
    boolean getN = true;
    STARTWORDFILE(filename);
    int capacity = currentWord.TabWord[0] % 48;
    CreateListDraf(LD, capacity);
    int i = 1, j = 0;
    while (getN)
    {
        if (i == (((*LD).capacity) * 4))
        {
            while (currentChar == newLine && currentChar != MARKC)
            {
                ADV();
            }
            int k = 0;
            while (k < 19)
            {
                currentWord.TabWord[k] = currentChar;
                ADV();
                k++;
            }
            currentWord.Length = k;
            getN = false;
        }
        else
        {
            ADVWORDFILE();
        }
        if (i % 4 == 1)
        {
            (*LD).buffer[j].id = (int)(currentWord.TabWord[0] % 48);
        }
        else if (i % 4 == 2)
        {
            (*LD).buffer[j].text = currentWord;
        }
        else if (i % 4 == 3)
        {
            (*LD).buffer[j].author = currentWord;
        }
        else if (i % 4 == 0)
        {
            DATETIME t;
            Word temp = currentWord;
            int DD = (int)(temp.TabWord[0] % 48) * 10 + (int)(temp.TabWord[1] % 48);
            int MM = (int)(temp.TabWord[3] % 48) * 10 + (int)(temp.TabWord[4] % 48);
            int YY = (int)(temp.TabWord[6] % 48) * 1000 + (int)(temp.TabWord[7] % 48) * 100 + (int)(temp.TabWord[8] % 48) * 10 + (int)(temp.TabWord[9] % 48);
            int hh = (int)(temp.TabWord[11] % 48) * 10 + (int)(temp.TabWord[12] % 48);
            int mm = (int)(temp.TabWord[14] % 48) * 10 + (int)(temp.TabWord[15] % 48);
            int ss = (int)(temp.TabWord[17] % 48) * 10 + (int)(temp.TabWord[18] % 48);
            CreateDATETIME(&t, DD, MM, YY, hh, mm, ss);
            (*LD).buffer[j].datetime = t;
            j++;
        }
        i++;
    }
    NEFFDRAF((*LD)) = j;
    printf("Draf berhasil di load\n");
}

void displayDataDraf(Draf id)
{
    printf("| id: ");
    printf("%d\n", (id).id);
    printf("| Text: ");
    printWord((id).text);
    printf("\n");
    printf("| Author: ");
    printWord((id).author);
    printf("\n");
    printf("| Datetime: ");
    TulisDATETIME((id).datetime);
    printf("\n");
}

/* ********** MENAMBAH DRAF DI AKHIR ********** */
void addDraf(ListDinDraf *l, Draf d)
{
    if (isFullOfDraf(*l))
    {
        if (CAPACITYDRAF(*l) == 0)
        {
            CAPACITYDRAF(*l) = 1;
        }
        else
        {
            CAPACITYDRAF(*l) *= 2;
        }
        BUFFERDRAF(*l) = (Draf *)realloc(BUFFERDRAF(*l), CAPACITYDRAF(*l) * sizeof(Draf));
    }
    ELMTDRAF(*l, NEFFDRAF(*l)) = d;
    NEFFDRAF(*l) += 1;
}

void deleteDrafById(ListDinDraf *l, int id)
{
    int i = 0;
    while (i < NEFFDRAF(*l) && ELMTDRAF(*l, i).id != id)
    {
        i++;
    }
    if (i < NEFFDRAF(*l))
    {
        for (int j = i; j < NEFFDRAF(*l); j++)
        {
            ELMTDRAF(*l, j) = ELMTDRAF(*l, j + 1);
        }
        NEFFDRAF(*l) -= 1;
    }
    if (CAPACITYDRAF(*l) > 1 && NEFFDRAF(*l) <= CAPACITYDRAF(*l) / 2)
    {
        CAPACITYDRAF(*l) /= 2;
        BUFFERDRAF(*l) = (Draf *)realloc(BUFFERDRAF(*l), CAPACITYDRAF(*l) * sizeof(Draf));
    }
}

boolean isFullOfDraf(ListDinDraf l)
{
    return (NEFFDRAF(l) == CAPACITYDRAF(l));
}