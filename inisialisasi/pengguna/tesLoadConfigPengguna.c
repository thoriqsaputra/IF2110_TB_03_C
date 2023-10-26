#include "../../ADT/tempRun.h"
#include <stdio.h>
#include "listPengguna.h"


typedef struct
{
   Word contents[10000]; /* memori tempat penyimpan elemen (container) , coba coba temp 10rb */
} listWord;


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
void tulisDataPengguna(Pengguna user)
{
    printWord(user.nama);
    printf("\n");
    printWord(user.password);
    printf("\n");
    printWord(user.bio);
    printf("\n");
    printWord(user.noHp);
    printf("\n");
    printWord(user.weton);
    printf("\n");
    printWord(user.jenisAkun);
    printf("\n");
}
int main()
{
    listWord LW;
    ListUser LU;
    int countWord = 0;
    
    
    STARTWORDFILE("../../configs/config-1/pengguna.config");
    while (!(EndWord))
    {
        
        LW.contents[countWord] = currentWord;
        ADVWORDFILE();
        
        countWord ++;
    }
  
    fclose(pita);

    LU.capacity = wordToInt(LW.contents[0]);// ambil banyaknya pengguna
    int j = 0;
  
        for (int i = 1; i < countWord; i++)
        {
            // printf(", panjang word = %d skrg word ke - %d = " , LW.contents[i].Length,i);
            // printWord(LW.contents[i]);
            // printf("\n");
            if(i % 11 == 1)
            {
                LU.buffer[j].nama = LW.contents[i];
            }
            else if (i % 11 == 2)
            {
                LU.buffer[j].password = LW.contents[i];
            }
            else if (i % 11 == 3)
            {
                LU.buffer[j].bio = LW.contents[i];
            }
            else if (i % 11 == 4)
            {
                LU.buffer[j].noHp = LW.contents[i];
            }
            else if (i % 11 == 5)
            {
                LU.buffer[j].weton = LW.contents[i];
            }
            else if (i % 11 == 6)
            {
                LU.buffer[j].jenisAkun = LW.contents[i];
            }
            else if (i % 11 == 7)
            {//Matriks ntar disini
                /* code */
            }
            else if (i % 11== 0)//reset
            {
                j++;
            }
        }
    for (int i = 0; i < LU.capacity; i++)
    {
        tulisDataPengguna(LU.buffer[i]);
    }
    
    
    
/*
    URUTAN CONFIG PENGGUNA
    Baris Utama ke-1 = banyaknya pengguna (int)
    Word nama; -2 
    Word password; -3
    Word bio; -4
    Word noHp; -5
    Word weton; -6
    Word jenisAkun; -7
    Matrix fotoProfil; (ukuran 5x5) jadi 5 baris (matrix 5x5)


    brarti, 1 pengguna  itu perlu  11 baris (1+1+1+1+1+1+5)
    kelipatan 11 , mod 11
    di paling akhir, ada matrix pertemanan dan permintaan teman
*/
    
    return 0;
}

