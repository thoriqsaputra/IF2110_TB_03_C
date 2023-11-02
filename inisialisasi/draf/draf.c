#include <stdio.h>
#include "draf.h"

int wordToInt(Word kata)
{
    return (kata.TabWord[0] - '0');
}

void CreateEmptyDraf(ListDrafStatik *l)
{
    (*l).capacity = 0;
}

void displayDataDraf(Draf *id)
{
    printf("| id: ");
    printf("%d\n", (*id).id);
    printf("| Text: ");
    printWord((*id).text);
    printf("\n");
    printf("| Author: ");
    printWord((*id).author);
    printf("\n");
    printf("| Datetime: ");
    TulisDATETIME((*id).datetime);
    printf("\n");
}

void loadDrafConfig(char filename[], ListDrafStatik *LD)
{
    boolean getN = true;
    STARTWORDFILE(filename);
    (*LD).capacity = wordToInt(currentWord);
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
            (*LD).buffer[j].id = wordToInt(currentWord);
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
    printf("Draf berhasil di load\n");
}