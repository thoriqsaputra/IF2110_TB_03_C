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
    printf("| Nama: ");
    printWord((*user).nama);
    printf("\n");
    printf("| Password: ");
    printWord((*user).password);
    printf("\n");
    printf("| Bio Akun: ");
    printWord((*user).bio);
    printf("\n");
    printf("| No HP: ");
    printWord((*user).noHp);
    printf("\n");
    printf("| Weton: ");
    printWord((*user).weton);
    printf("\n");
    printf("| Jenis Akun: ");
    printWord((*user).jenisAkun);
    printf("\n");
    printf("| FotoProfil: ");
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
int getUserIdCurrent(currentUser CU, ListUserStatik LU)
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
        return -1; // tidak ditemukan IDX_UNDEF
    }
    else
    {
        return i;
    }
}
int getUserId(Word inputNama,ListUserStatik LU)
//Mengembalikan nilai id sesuai dengan inputNama di database pengguna
// IDX_UNDEF apabila tidak ditemukan
{
    int i = 0;
    while (isWordEqual(NAMA_USER(LU, i), inputNama) == false && i < UserCount(LU)) // kalau nama gak sama, next i
    {
        i++;
    }
    if (i == UserCount(LU))
    {
        return -1; // tidak ditemukan IDX_UNDEF
    }
    else
    {
        return i;
    }
}
//======================Ganti Profil==========================
boolean cekEmptyInput(char CC)
{
    return (CC == MARKINPUT && currentWord.Length == 0);
}
void getInputProfil()
{
    STARTWORDINPUT();
    if (EndInput)
    {
        currentWord.TabWord[0] = ' ';
        currentWord.Length = 1;
    }
}
boolean isValidWeton(Word inputWeton)
//Mengembalikan nilai true apabila sesuai data Weton yang tersedia
//Pahing, Kliwon, Wage, Pon, dan Legi
{
    Word pahing = {"Pahing",6};
    Word Kliwon = {"Kliwon",6};
    Word Wage = {"Wage",4};
    Word Pon = {"Pon",3};
    Word Legi = {"Legi",4};

    if(isWordEqual(inputWeton,pahing) || isWordEqual(inputWeton,Kliwon)|| isWordEqual(inputWeton,Wage) || isWordEqual(inputWeton,Pon) || isWordEqual(inputWeton,Legi) || EndInput)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void gantiProfil(ListUserStatik *LU,currentUser *CU)
{
    printf("Masukkan Bio Akun:\n");
    getInputProfil();
    // misal skrg profil 1
    BIO_USER(*LU,idUser(*CU)) = currentWord;
    printf("Masukkan No HP:\n");
    getInputProfil();
    NOHP_USER(*LU,idUser(*CU)) = currentWord;
    printf("Masukkan Weton:\n");
    getInputProfil();
    while (isValidWeton(currentWord) == false &&  EndInput == false)
    {
        printf("Weton anda tidak valid.\n\n");
        printf("Masukkan Weton:\n");
        getInputProfil();
    }
    WETON_USER(*LU,idUser(*CU)) = currentWord;

    printf("\n Profil Anda sudah berhasil diperbaharui! \n\n");
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
// boolean cekSamePass(ListUserStatik LU, currentUser CU, Word inputPass)
// // mengembalikan true apabila input = password user tersebut di database (LU)
// {
//     int id = getUserIdCurrent(CU, LU);
//     return (isWordEqual(inputPass, PASSWORD_USER(LU, id)));
// }
void Masuk(ListUserStatik *LU, currentUser *CU,boolean *isLog)
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
    nameUser(*CU) = currentWord;
    idUser(*CU) = getUserIdCurrent(*CU, *LU); // dapetin ID si username yang masuk ke program
    printf("Ketik '-' apabila ingin keluar dari 'MASUK'! \n\n");
    printf("Masukkan kata sandi:\n");
    
    STARTWORDINPUT();
    while (isWordEqual(currentWord, PASSWORD_USER((*LU), idUser(*CU))) == false && currentWord.TabWord[0] != '-' )
    {
        printf("Wah, Password tidak sesuai!\n\n");
        printf("Masukkan kata sandi:\n");
        STARTWORDINPUT();
    }
    if(currentWord.TabWord[0] == '-')
    {
        *isLog = false;
        printf("Keluar dari fitur Masuk\n");
    }
    else
    {
        *isLog = true;
        printf("Berhasil Login!\n");
    }
   
}
//=============================LIHAT PROFIL=====================================
void lihatUser(ListUserStatik *LU, Word namaProfil)
{
    int iduser = getUserId(namaProfil,*LU);
    if(iduser == IDX_UNDEF)
    {
        printf("Tidak ditemukan profil dengan nama '");
        printWord(namaProfil);
        printf("' \n");
    }
    else
    {
        printf("| Nama: ");
        printWord((*LU).buffer[iduser].nama);
        printf("\n");
        printf("| Bio Akun: ");
        printWord((*LU).buffer[iduser].bio);
        printf("\n");
        printf("| No HP: ");
        printWord((*LU).buffer[iduser].noHp);
        printf("\n");
        printf("| Weton: ");
        printWord((*LU).buffer[iduser].weton);
        printf("\n");
        printf("| FotoProfil: \n");
        displayMatrixChar((*LU).buffer[iduser].fotoProfil);
    }
    
}