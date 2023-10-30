#include <stdio.h>
#include "pengguna.h"
void printWord(Word kata)
{
    for (int i = 0; i < kata.Length; i++)
    {
        printf("%c",kata.TabWord[i]);
    }
    
}
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

void loadPenggunaConfig(char filename[], ListUserStatik * LU)
{
    listWord LW;
    int countWord = 0;
    boolean getN = true;
   
    STARTWORDFILE(filename);
    UserCount(*LU) = wordToInt(currentWord);
    countWord ++;
    while (getN)
    {
        ADVWORDFILE();
        (LW).contents[countWord] = currentWord;
        countWord ++;
        if(countWord ==((*LU).capacity * 11) + 1)
        {
            getN = false;
        }
    }
    //opsional, nanti di akhir program aja
    // fclose(pita);
    
    int j = 0;
        for (int i = 1; i < countWord; i++)
        {
            if(i % 11 == 1)
            {
                NAMA_USER(*LU,j)= (LW).contents[i];
            }
            else if (i % 11 == 2)
            {
                PASSWORD_USER(*LU,j) = (LW).contents[i];
            }
            else if (i % 11 == 3)
            {
                BIO_USER(*LU,j) = (LW).contents[i];
            }
            else if (i % 11 == 4)
            {
                NOHP_USER(*LU,j)= (LW).contents[i];
            }
            else if (i % 11 == 5)
            {
                WETON_USER(*LU,j) = (LW).contents[i];
            }
            else if (i % 11 == 6)
            {
                JENIS_USER(*LU,j) = (LW).contents[i];
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
                    for (int k = 0; k < (LW).contents[i].Length; k++)
                    {
                        if((LW).contents[counterRow].TabWord[k] != BLANK)
                        {
                           
                            ELMTMatrix(FOTO_USER(*LU,j),rowProfile,colProfile) = (LW).contents[counterRow].TabWord[k] ;
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
    printf("Berhasil Konfigurasi!\n");
}
void CreateEmptyPengguna(ListUserStatik * l)
{
    (*l).capacity = 0;
}

//======================Ganti Profil==========================
void getInputProfil()
{
    STARTWORDINPUT();
    if(currentChar == MARKINPUT && currentWord.Length == 0)
    {
        currentWord.TabWord[0] = ' ';
        currentWord.Length = 1;
    }
   
}
void gantiProfil(ListUserStatik *LU)
{
    printf("Masukkan Bio Akun:\n");
    getInputProfil();
    //misal skrg profil 1
    (*LU).buffer[0].bio = currentWord;
    printf("Masukkan No HP:\n");
    getInputProfil();
    (*LU).buffer[0].noHp = currentWord;
    printf("Masukkan Weton:\n");
    getInputProfil();
    (*LU).buffer[0].weton = currentWord;
}
//======================Daftar==========================
boolean cekSameNama(ListUserStatik LU,Word inputWord)
{
    
    int i = 0;
    boolean flag = true;
    while (i < LU.capacity)
    {
         if((isWordEqual(LU.buffer[i].nama,inputWord)))
         {
            flag = false;
         }
         i++;
    }
    return flag;
    
    
    
}
void Daftar(ListUserStatik *LU)
{
    printf("Masukkan Nama Akun:\n");
    STARTWORDINPUT();
    while (!(cekSameNama(*LU,currentWord)))
    {
        printf("Wah, sayang sekali nama tersebut telah diambil.!:\n");
        printf("Masukkan Nama Akun:\n");
        STARTWORDINPUT();
    }

    printf("Masukkan kata sandi:\n");
    STARTWORDINPUT();
    //input  password ke LU
    
}
void Masuk(ListUserStatik *LU)
{

}