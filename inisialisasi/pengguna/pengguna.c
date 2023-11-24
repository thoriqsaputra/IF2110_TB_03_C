#include <stdio.h>
#include "pengguna.h"
#include "pcolor.h"
#include "pcolor.c"
#include "../../ADT/graf.h"
#include "../../fitur/teman/teman.h"
// #include "../permintaan/permintaan_pertemanan.h"
// void printWord(Word kata)
// {
//     for (int i = 0; i < kata.Length; i++)
//     {
//         printf("%c", kata.TabWord[i]);
//     }
// }
Word BlankWord = {" ", 1};

void tulisDataPengguna(Pengguna *user)
{
    printf("| ID  ");
    printf("%d\n", (*user).id);
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
    if ((*user).jenisAkun == 1)
    {
        printf("Publik");
    }
    else
    {
        printf("Privat");
    }
    printf("\n");
    printf("| FotoProfil: \n");
    displayColorMatrix((*user).fotoProfil);
}
Matrix createMatrixDefault()
/*
82 42 82 42 82 42 82 42 82 42
82 42 71 64 66 42 71 64 82 42
82 42 71 64 71 64 71 64 82 42
82 42 71 64 66 42 71 64 82 42
82 42 82 42 82 42 82 42 82 42
*/
{
    Matrix newM;
    char temp[50] = {'R', '*', 'R', '*', 'R', '*', 'R', '*', 'R', '*',
                     'R', '*', 'G', '@', 'B', '*', 'G', '@', 'R', '*', 'R', '*', 'G', '@', 'B', '@', 'G', '@', 'R', '*', 'R', '*', 'G', '@', 'B', '*', 'G', '@', 'R', '*', 'R', '*', 'R', '*', 'R', '*', 'R', '*', 'R', '*'};
    createMatrix(5, 10, &newM);
    int cnt = 0;
    while (cnt < 50)
    {
        ELMTMatrix(newM, cnt / 10, cnt % 10) = temp[cnt];
        cnt++;
    }
    return newM;
}
void displayColorMatrix(Matrix m)
{
    for (int i = 0; i < ROW_EFF(m); i++)
    {
        for (int j = 0; j < COL_EFF(m); j++)
        {
            if (ELMTMatrix(m, i, j) == 'R')
            {
                print_red(ELMTMatrix(m, i, j + 1));
            }
            else if (ELMTMatrix(m, i, j) == 'G')
            {
                print_green(ELMTMatrix(m, i, j + 1));
            }
            else if (ELMTMatrix(m, i, j) == 'B')
            {
                print_blue(ELMTMatrix(m, i, j + 1));
            }
        }
        printf("\n");
    }
}
void loadPenggunaConfig(char filename[], ListUserStatik *LU, Graph *GP)
{
    Word privateFlag = {"Privat", 6};
    Word publicFlag = {"Public", 6};
    listWord LW;
    int countWord = 0;
    boolean getN = true;

    STARTWORDFILE(filename);
    UserCount(*LU) = wordToInt(currentWord);
    if (UserCount(*LU) > 0)
    {
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
        printf("countword = %d\n", countWord);
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
                if (isWordEqual((LW).contents[i], privateFlag))
                {
                    JENIS_USER(*LU, j) = 0;
                }
                else
                {
                    JENIS_USER(*LU, j) = 1;
                }
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
                ID_USER(*LU, j) = j;
                j++;
            }
        } // selesai baca semua info pengguna
        // sekarang disini baca graf pertemanan (matriks adjacency)
        int getAdjacen = 0;
        Matrix adjMFriend;
        createMatrix(UserCount(*LU), UserCount(*LU), &adjMFriend); // handling maks user
        int rowAdj = 0;
        int colAdj = 0;
        while (getAdjacen != UserCount(*LU))
        {
            colAdj = 0;
            ADVWORDFILE();
            (LW).contents[countWord] = currentWord;

            for (int i = 0; i < currentWord.Length; i++)
            {
                if (currentWord.TabWord[i] != BLANK)
                {
                    ELMTMatrix(adjMFriend, rowAdj, colAdj) = currentWord.TabWord[i] - '0';
                    colAdj++;
                }
            }
            rowAdj++;

            getAdjacen++;
        }
        // buat graph pertemanan disini
        displayMatrix(adjMFriend);
        initGraph(GP, UserCount(*LU));
        for (int i = 0; i < ROW_EFF(adjMFriend); i++)
        {
            for (int j = 0; j < COL_EFF(adjMFriend); j++)
            {
                if (ELMTMatrix(adjMFriend, i, j) == 1)
                {
                    addEdge(GP, i, j);
                }
            }
        }
        // Buat config pertemanan
        // PrioQueueChar PQ;
        // currentUser CU;
        // ADVWORDFILE();
        // int rowMinta = wordToInt(currentWord);
        // for (int i = 0; i < rowMinta; i++)
        // {
        //     ADVWORDFILE();
        //     int iduser = currentWord.TabWord[0];
        //     CU.idUser = iduser;
        //     PQ = dpp(*p, iduser);
        //     tambahdpp(&PQ, CU, &GP);
        // }
    }
    printf("Berhasil Konfigurasi! , jumlah user di data = %d\n", UserCount(*LU));
}
void CreateEmptyPengguna(ListUserStatik *l)
{
    (*l).capacity = 0;
}
//=====================Struct currentUser=======================
void CreateEmptyCurrentUser(currentUser *CU)
{
    nameUser(*CU) = BlankWord;
    idUser(*CU) = IDX_UNDEF;
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
int getUserId(Word inputNama, ListUserStatik LU)
// Mengembalikan nilai id sesuai dengan inputNama di database pengguna
//  IDX_UNDEF apabila tidak ditemukan
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
void getInputProfil(int Nmax)
{
    // STARTWORDINPUT tapi di modif di bagian NMAX
    START();
    IgnoreBlanks();
    ignoreNewLine();
    if (currentChar == MARKINPUT)
    {
        EndInput = true;
    }
    else
    {
        EndInput = false;
        int i = 0;
        while (currentChar != MARKINPUT && retValues())
        {
            if (i < Nmax)
            {
                currentWord.TabWord[i] = currentChar;
                i++;
            }
            ADV();
        }
        currentWord.Length = i;
    }

    if (EndInput) // langsung ; jawabannya, jadi pasti string kosong
    {
        currentWord.TabWord[0] = ' ';
        currentWord.Length = 1;
    }
}
boolean isValidWeton(Word inputWeton)
// Mengembalikan nilai true apabila sesuai data Weton yang tersedia
// Pahing, Kliwon, Wage, Pon, dan Legi
{
    Word pahing = {"Pahing", 6};
    Word Kliwon = {"Kliwon", 6};
    Word Wage = {"Wage", 4};
    Word Pon = {"Pon", 3};
    Word Legi = {"Legi", 4};

    if (isWordEqual(inputWeton, pahing) || isWordEqual(inputWeton, Kliwon) || isWordEqual(inputWeton, Wage) || isWordEqual(inputWeton, Pon) || isWordEqual(inputWeton, Legi) || EndInput)
    {
        return true;
    }
    else
    {
        return false;
    }
}
boolean isValidHP(Word inputHP)
// Mengembalikan nilai true apabila sesuai data No HP
//  integer max 15 char
{

    if (inputHP.Length > 15)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < inputHP.Length; i++)
        {
            if (inputHP.TabWord[i] == BLANK || !(inputHP.TabWord[i] >= '0' && inputHP.TabWord[i] <= '9'))
            {
                return false;
            }
        }
        return true;
    }
}
void gantiProfil(ListUserStatik *LU, currentUser *CU)
{
    printf("Masukkan Bio Akun *maks 135 char* :\n");
    getInputProfil(135); // bio maks 135 char
    // misal skrg profil 1
    BIO_USER(*LU, idUser(*CU)) = currentWord;
    printf("Masukkan No HP  :\n");
    getInputProfil(NMax);
    while (isValidHP(currentWord) == false && EndInput == false)
    {
        printf("No HP tidak valid. Masukkan lagi yuk!\n\n");
        printf("Masukkan No HP :\n");
        getInputProfil(NMax);
    }

    NOHP_USER(*LU, idUser(*CU)) = currentWord;
    printf("Masukkan Weton:\n");
    getInputProfil(NMax);
    while (isValidWeton(currentWord) == false && EndInput == false)
    {
        printf("Weton anda tidak valid.\n\n");
        printf("Masukkan Weton:\n");
        getInputProfil(NMax);
    }
    WETON_USER(*LU, idUser(*CU)) = currentWord;

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
    NAMA_USER(*LU, (*LU).capacity) = currentWord;
    printf("Masukkan kata sandi:\n");
    STARTWORDINPUT();
    PASSWORD_USER(*LU, (*LU).capacity) = currentWord;

    // DEFAULT SETTING SETELAH DAFTAR
    BIO_USER(*LU, (*LU).capacity) = BlankWord;
    NOHP_USER(*LU, (*LU).capacity) = BlankWord;
    WETON_USER(*LU, (*LU).capacity) = BlankWord;
    JENIS_USER(*LU, (*LU).capacity) = 1;
    FOTO_USER(*LU, (*LU).capacity) = createMatrixDefault();
    (*LU).capacity++;
    // input  password ke LU
}
// ========================================MASUK===================================
// boolean cekSamePass(ListUserStatik LU, currentUser CU, Word inputPass)
// // mengembalikan true apabila input = password user tersebut di database (LU)
// {
//     int id = getUserIdCurrent(CU, LU);
//     return (isWordEqual(inputPass, PASSWORD_USER(LU, id)));
// }
void Masuk(ListUserStatik *LU, currentUser *CU, boolean *isLog)
// Mengubah Current user dengan user yang berhasil login
{
    printf("Masukkan nama: \n");
    STARTWORDINPUT();
    printWord(currentWord);
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
    while (isWordEqual(currentWord, PASSWORD_USER((*LU), idUser(*CU))) == false && currentWord.TabWord[0] != '-')
    {
        printf("Wah, Password tidak sesuai!\n\n");
        printf("Masukkan kata sandi:\n");
        STARTWORDINPUT();
    }
    if (currentWord.TabWord[0] == '-')
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
void lihatUser(ListUserStatik *LU, Word namaProfil, Graph *G, currentUser CU)
{
    int iduser = getUserId(namaProfil, *LU);
    if (iduser == IDX_UNDEF)
    {
        printf("Tidak ditemukan profil dengan nama '");
        printWord(namaProfil);
        printf("' \n");
    }
    else if (isTeman(G, CU.idUser, iduser) == false && (*LU).buffer[iduser].jenisAkun == 0) // kalo current user tidak berteman dengan yang dicari
    {
        printf("Wah, akun ");
        printWord((*LU).buffer[iduser].nama);
        printf(" diprivat nih. Ikuti dulu yuk untuk bisa melihat profil ");
        printWord((*LU).buffer[iduser].nama);
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
        displayColorMatrix((*LU).buffer[iduser].fotoProfil);
    }
}
//=========================KELUAR=========================
void Keluar(ListUserStatik *LU, currentUser *CU, boolean *isLog)
{
    CreateEmptyCurrentUser(CU);
    idUser(*CU) = IDX_UNDEF;
    *isLog = false;
    printf("\n\nAnda berhasil logout. Sampai jumpa di pertemuan berikutnya!\n\n");
}

//=========================ATUR JENIS AKUN=========================
void aturJenisAkun(ListUserStatik *LU, currentUser *CU)
{
    Word ya = {"YA", 2};
    Word tidak = {"TIDAK", 5};
    printf("\nSaat ini, akun Anda adalah akun ");
    if (JENIS_USER(*LU, getUserIdCurrent(*CU, *LU)) == 1)
    {
        printf("Publik.Ingin mengubah ke akun Privat?");
    }
    else
    {
        printf("Privat.Ingin mengubah ke akun Publik?");
    }
    printf("\n(YA/TIDAK)");
    STARTWORDINPUT();
    if (isWordEqual(currentWord, ya))
    {

        printf("Akun anda sudah diubah menjadi akun\n");
        if (JENIS_USER(*LU, getUserIdCurrent(*CU, *LU)) == 1)
        {
            printf("Privat");
            JENIS_USER(*LU, getUserIdCurrent(*CU, *LU)) = 0;
        }
        else
        {
            printf("Publik");
            JENIS_USER(*LU, getUserIdCurrent(*CU, *LU)) = 1;
        }
    }
    else if (isWordEqual(currentWord, tidak))
    {
        printf("Tidak ingin ubah, balik ke menu\n");
    }
    else
    {
        printf("Input tidak sesuai! keluar dari ATUR_JENIS_AKUN\n");
    }
    printf("\n");
}

void ubahFotoProfil(ListUserStatik *LU, currentUser *CU)
{

    Matrix newMatrix;
    printf("Foto profil anda saat ini adalah : \n");
    displayMatrixChar(FOTO_USER(*LU, getUserIdCurrent(*CU, *LU)));
    printf("\nMasukkan foto profil yang baru\n");
    STARTWORDINPUT();
    printf("%d", currentWord.Length);
    if (currentWord.Length != 99)
    {
        printf("Foto profil tidak sesuai matrix 5 x 5!\n");
    }
    else
    {
        printf("\n\n\n");
        // printWord(currentWord);
        printf("\n\n\n");
        createMatrix(5, 10, &newMatrix);

        for (int i = 0; i < currentWord.Length; i++)
        {
            if (currentWord.TabWord[i] != BLANK && currentWord.TabWord[i] != newLine)
            {
                // printf("%c ",currentWord.TabWord[i]);
                // printf("baris %d , kolom %d\n", i / 20, i % 20 / 2);

                ELMTMatrix(newMatrix, i / 20, i % 20 / 2) = currentWord.TabWord[i];
            }
        }
        copyMatrix(newMatrix, &FOTO_USER(*LU, getUserIdCurrent(*CU, *LU)));
        printf("\nFOTO PROFIL BARU ANDA:\n");
        displayMatrixChar(FOTO_USER(*LU, getUserIdCurrent(*CU, *LU)));
    }
}