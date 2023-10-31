#include <stdio.h>
#include "pengguna.h"
void printWord(Word kata)
{
    for (int i = 0; i < kata.Length; i++)
    {
        printf("%c", kata.TabWord[i]);
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
void tulisDataPengguna(Pengguna *user)
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

void loadPenggunaConfig(char filename[], ListUserStatik *LU)
{
    listWord LW;
    int countWord = 0;
    boolean getN = true;

    STARTWORDFILE(filename);
    UserCount(*LU) = wordToInt(currentWord);
    countWord++;
    while (getN)
    {
        ADVWORDFILE();
        (LW).contents[countWord] = currentWord;
        countWord++;
        if (countWord == ((*LU).capacity * 11) + 1)
        {
            getN = false;
        }
    }
    // opsional, nanti di akhir program aja
    //  fclose(pita);

    int j = 0;
    for (int i = 1; i < countWord; i++)
    {
        if (i % 11 == 1)
        {
            NAMA_USER(*LU, j) = (LW).contents[i];
        }
        else if (i % 11 == 2)
        {
            PASSWORD_USER(*LU, j) = (LW).contents[i];
        }
        else if (i % 11 == 3)
        {
            BIO_USER(*LU, j) = (LW).contents[i];
        }
        else if (i % 11 == 4)
        {
            NOHP_USER(*LU, j) = (LW).contents[i];
        }
        else if (i % 11 == 5)
        {
            WETON_USER(*LU, j) = (LW).contents[i];
        }
        else if (i % 11 == 6)
        {
            JENIS_USER(*LU, j) = (LW).contents[i];
        }
        else if (i % 11 == 7)
        { // Matriks ntar disini

            int rowProfile;
            int colProfile;
            int counterRow;
            createMatrix(5, 10, &(*LU).buffer[j].fotoProfil);
            counterRow = i;
            colProfile = 0;
            rowProfile = 0;
            while (counterRow % 11 != 1)
            {
                colProfile = 0;
                for (int k = 0; k < (LW).contents[i].Length; k++)
                {
                    if ((LW).contents[counterRow].TabWord[k] != BLANK)
                    {

                        ELMTMatrix(FOTO_USER(*LU, j), rowProfile, colProfile) = (LW).contents[counterRow].TabWord[k];
                        colProfile++;
                    }
                }
                counterRow++;
                rowProfile++;
            }
        }
        else if (i % 11 == 0) // reset
        {
            j++;
        }
    }
    printf("Berhasil Konfigurasi!\n");
}
void CreateEmptyPengguna(ListUserStatik *l)
{
    (*l).capacity = 0;
}
//=====================Struct currentUser=======================
void CreateEmptyCurrentUser(currentUser *CU)
{
    (*CU).nama.TabWord[0] = BLANK;
}
int getUserId(currentUser CU, ListUserStatik LU)
// Cek nama yang sama di data base lalu kembalikan id nya
//  Mengembalikan nilai id dari current User sekarang yang login, apabila tidak ditemukan maka IDX_UNDEF
{
    int i = 0;
    while (isWordEqual(NAMA_USER(LU, i), CU.nama) == false && i < UserCount(LU)) // kalau nama gak sama, next i
    {
        i++;
    }
    if (i == UserCount(LU))
    {
        return IDX_UNDEF; // tidak ditemukan
    }
    else
    {
        return i;
    }
}

//======================Ganti Profil==========================
void getInputProfil()
{
    STARTWORDINPUT();
    if (currentChar == MARKINPUT && currentWord.Length == 0)
    {
        currentWord.TabWord[0] = ' ';
        currentWord.Length = 1;
    }
}
void gantiProfil(ListUserStatik *LU)
{
    printf("Masukkan Bio Akun:\n");
    getInputProfil();
    // misal skrg profil 1
    (*LU).buffer[0].bio = currentWord;
    printf("Masukkan No HP:\n");
    getInputProfil();
    (*LU).buffer[0].noHp = currentWord;
    printf("Masukkan Weton:\n");
    getInputProfil();
    (*LU).buffer[0].weton = currentWord;
}
//======================Daftar==========================
boolean cekSameNama(ListUserStatik LU, Word inputWord)
// mengembalikan nilai true apabila ada nama sama di database pengguna
{

    int i = 0;
    boolean flag = false;
    while (i < LU.capacity)
    {
        if ((isWordEqual(LU.buffer[i].nama, inputWord)))
        {
            flag = true;
        }
        i++;
    }
    return flag;
}

void Daftar(ListUserStatik *LU)
{
    printf("Masukkan Nama Akun:\n");
    STARTWORDINPUT();
    while ((cekSameNama(*LU, currentWord) == true))
    {
        printf("Wah, sayang sekali nama tersebut telah diambil.!:\n");
        printf("Masukkan Nama Akun:\n");
        STARTWORDINPUT();
    }
    // handling masukin data input nama yang berhasil ke database pengguna
    printf("Masukkan kata sandi:\n");
    STARTWORDINPUT();
    // input  password ke LU
}
// ========================================MASUK===================================
boolean cekSamePass(ListUserStatik LU, currentUser CU, Word inputPass)
// mengembalikan true apabila input = password user tersebut di database (LU)
{
    printf("CEK PAS");
    int id = getUserId(CU, LU);
    printf("id %d\n", id);
    printWord(inputPass);
    printf("\n");
    printWord(PASSWORD_USER(LU, id));
    return (isWordEqual(inputPass, PASSWORD_USER(LU, id)));
}
void Masuk(ListUserStatik *LU, currentUser *CU)
// Mengubah Current user dengan user yang berhasil login
{
    printf("Masukkan nama: \n");
    STARTWORDINPUT();
    while ((cekSameNama(*LU, currentWord) == false))
    {
        printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n\n");
        printf("Masukkan nama: \n");
        STARTWORDINPUT();
    }
    // nama sesuai dengan database LUs
    (*CU).nama = currentWord;
    int id = getUserId(*CU, *LU);
    printf("%d\n", id);
    printf("Masukkan kata sandi:\n");
    STARTWORDINPUT();
    printf("%d", cekSamePass(*LU, *CU, currentWord));
    while (cekSamePass(*LU, *CU, currentWord) == false)
    {
        printf("Wah, Password tidak sesuai!\n\n");
        printf("Masukkan kata sandi:\n");
        STARTWORDINPUT();
    }
}