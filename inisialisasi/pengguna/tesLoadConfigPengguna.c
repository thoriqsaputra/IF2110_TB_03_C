#include "../../ADT/tempRun.h"
#include <stdio.h>
#include "pengguna.h"
void printWord(Word kata)
{
    for (int i = 0; i < kata.Length; i++)
    {
        printf("%c",kata.TabWord[i]);
    }
    
}
int wordToInt(Word kata)
{
    return (kata.TabWord[0] - '0');
}
void tulisDataPengguna(Pengguna * user)
{
    printWord((*user).nama);
    printf("\n");
    printWord((*user).password);
    printf("\n");
    printWord((*user).bio);
    printf("\n");
    printWord((*user).noHp);
    printf("\n");
    printWord((*user).weton);
    printf("\n");
    printWord((*user).jenisAkun);
    printf("\n");
    displayMatrixChar((*user).fotoProfil);
}

void loadPenggunaConfig(char filename[],listWord * LW, ListUser * LU)
{
    
    int countWord = 0;
    boolean getN = true;
   
    STARTWORDFILE(filename);
    while ((!(EndWord) )&& (getN))
    {
        
        (*LW).contents[countWord] = currentWord;
        ADVWORDFILE();
        countWord ++;
        (*LU).capacity = wordToInt((*LW).contents[0]);
        if(countWord ==(  (*LU).capacity * 11) + 1)
        {
            getN = false;
        }
    }
    //opsional, nanti di akhir program aja
    // fclose(pita);
    
    int j = 0;
        for (int i = 1; i < countWord; i++)
        {
            printf(", panjang word = %d skrg word ke - %d = " , (*LW).contents[i].Length,i);
            printWord((*LW).contents[i]);
            printf("\n");
            if(i % 11 == 1)
            {
                (*LU).buffer[j].nama = (*LW).contents[i];
            }
            else if (i % 11 == 2)
            {
                (*LU).buffer[j].password = (*LW).contents[i];
            }
            else if (i % 11 == 3)
            {
                (*LU).buffer[j].bio = (*LW).contents[i];
            }
            else if (i % 11 == 4)
            {
                (*LU).buffer[j].noHp = (*LW).contents[i];
            }
            else if (i % 11 == 5)
            {
                (*LU).buffer[j].weton = (*LW).contents[i];
            }
            else if (i % 11 == 6)
            {
                (*LU).buffer[j].jenisAkun = (*LW).contents[i];
            }
            else if (i % 11 == 7)
            {//Matriks ntar disini

                int rowProfile;
                int colProfile;
                int counterRow;
                createMatrix(5,10,&(*LU).buffer[j].fotoProfil);
                counterRow = i;
                colProfile = 0;
                rowProfile = 0;
                while (counterRow % 11 != 1)
                {
                    colProfile = 0;
                    for (int k = 0; k < (*LW).contents[i].Length; k++)
                    {
                        if((*LW).contents[counterRow].TabWord[k] != BLANK)
                        {
                           
                            ELMTMatrix((*LU).buffer[j].fotoProfil,rowProfile,colProfile) = (*LW).contents[counterRow].TabWord[k] ;
                            colProfile ++;
                        }
                    }
                    counterRow++;
                    rowProfile ++;
                }
            }
            else if (i % 11== 0)//reset
            {
                j++;
            }
        }

}

int main()
{
    ListUser LU;
    listWord LW;
    
    loadPenggunaConfig("../../configs/config-1/pengguna.config",&LW,&LU);
    //Nanti rencananya diganti ke listStatik biar enak
    tulisDataPengguna(&LU.buffer[0]);
    tulisDataPengguna(&LU.buffer[1]);
    tulisDataPengguna(&LU.buffer[2]);
    return 0;
}