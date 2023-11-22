#include "../../ADT/tempRun.h"
#include "kicauan.h"

int main()
{
    ListDinKicauan LKD;

    loadKicauanConfig("../../configs/config-1/kicauan.config", &LKD);

    for (int i = 0; i < NEFFKICAUAN(LKD); i++)
    {
        displayKicauan(ELMTKICAUAN(LKD,i));
    }

    printf("NEFF = %d\n",NEFFKICAUAN(LKD));
    printf("CAPACITY = %d\n",CAPACITYKICAUAN(LKD));

    printf("============= TEST ADD =============\n");
    FILE * newString = stdin;
    char currentC; Word currentSentence;
    int returned; int i = 0;
    returned = fscanf(newString,"%c",&currentC);
    while (returned == 1 && currentC != MARKC && currentC != newLine)
    {
        if (i < NMax)
        {
            currentSentence.TabWord[i] = currentC;
            i++;
        }  
        returned = fscanf(newString,"%c",&currentC);
    }
    currentSentence.Length = i;
    fclose(newString);

    currentUser cUser =  {{"Ertiga", 6}, 3};
    // CreateEmptyCurrentUser(&cUser);
    berkicau(&LKD, currentSentence, cUser);

    for (int j = 0; j < NEFFKICAUAN(LKD); j++)
    {
        displayKicauan(ELMTKICAUAN(LKD,j));
    }

    printf("NEFF = %d\n",NEFFKICAUAN(LKD));
    printf("CAPACITY = %d\n",CAPACITYKICAUAN(LKD));
    dealocateListKicauan(&LKD);
}

// cara run, masuk dulu ke direktori kicauan lalu di terminal masukkan 
// gcc tesLoadConfigKicauan.c kicauan.c -o tesLoadConfigKicauan
// ./tesLoadConfigKicauan