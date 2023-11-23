#include <stdio.h>
#include <stdlib.h>
#include "kicauan.h"

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
    int res = 0;
    int i = 0;
    while (kata.TabWord[i] >= '0' && kata.TabWord[i] <= '9' && i < kata.Length) 
    // memeriksa jika char di antara kedua bilangan tersebut (Jika ditambah komen di kanan angka), dan i lebih kecil dari panjang (Jika tidak ada, karena tidak tahu mengapa begitu keluaran 24 untuk ID 2)
    {
        res = res * 10 + (kata.TabWord[i] - '0');
        i++;
    }
    return res;
}

void CreateDATETIMEfromWord(DATETIME *D, Word kata)
{
    int day, month, year, hour, minute, second;
    day = (kata.TabWord[0] % 48 ) * 10 + (kata.TabWord[1] % 48 );
    month = (kata.TabWord[3] % 48) * 10 + (kata.TabWord[4] % 48);
    year = (kata.TabWord[6] % 48) * 1000 + (kata.TabWord[7] % 48) * 100 + (kata.TabWord[8] % 48) * 10 + (kata.TabWord[9] % 48);
    hour = (kata.TabWord[11] % 48) * 10 + (kata.TabWord[12] % 48);
    minute = (kata.TabWord[14] % 48) * 10 + (kata.TabWord[15] % 48);
    second = (kata.TabWord[17] % 48) * 10 + (kata.TabWord[18] % 48);
    CreateDATETIME(D, day, month, year, hour, minute, second);
}

// Dari pengguna.c

/* ********** KONSTRUKTOR ********** */
void CreateListKicauan(ListDinKicauan *l, int capacity)
{
    NEFFKICAUAN(*l) = 0;
    CONTENTKICAUAN(*l) = (KICAUAN *)malloc(capacity * sizeof(KICAUAN));
    CAPACITYKICAUAN(*l) = capacity;
}

void unloadListKicauan(ListDinKicauan *l) // Gunakan saat keluar program & jika logout user
{
    free(CONTENTKICAUAN(*l));
    NEFFKICAUAN(*l) = 0;
    CAPACITYKICAUAN(*l) = 0;
}

boolean isEmptyKicauan(ListDinKicauan l)
{
    return (l.nEffKicauan == 0);
}

/* ********* Load dari config ********* */
void loadKicauanConfig(char filename[], ListDinKicauan *l)
{
    STARTWORDFILE(filename);
    int capacity = wordToInt(currentWord);
    CreateListKicauan(l,capacity);

    for (int i = 0; i < CAPACITYKICAUAN(*l); i++)
    {
        ADVWORDFILE();
        IDKICAUAN(ELMTKICAUAN(*l,i)) = wordToInt(currentWord);
        ADVWORDFILE();
        TEXTKICAUAN(ELMTKICAUAN(*l,i)) = currentWord;
        ADVWORDFILE();
        LIKEKICAUAN(ELMTKICAUAN(*l,i)) = wordToInt(currentWord);
        ADVWORDFILE();
        AUTHORKICAUAN(ELMTKICAUAN(*l,i)) = currentWord;
        ADVWORDFILE();
        CreateDATETIMEfromWord(&DATETIMEKICAUAN(ELMTKICAUAN(*l,i)),currentWord);
    }
    NEFFKICAUAN(*l) = CAPACITYKICAUAN(*l);
}

/* load untuk current user */
void loadKicauanUser(ListDinKicauan l, ListDinKicauan * lOut, currentUser CU)
{
    CreateListKicauan(lOut,0);
    for (int i = 0; i < NEFFKICAUAN(l); i++)
    {
        if (isWordEqual(AUTHORKICAUAN(ELMTKICAUAN(l,i)), CU.nama))
        {
            addKicauan(lOut, ELMTKICAUAN(l,i));
        }
    }
}

/* **** **** **** KICAUAN **** **** **** */ // butuh pertemanan juga 
void showKicauanUser(ListDinKicauan lUser)
{
    for (int i = NEFFKICAUAN(lUser) - 1; i >= 0; i--)
    {
        displayKicauan(ELMTKICAUAN(lUser,i));
    }
}

/* ********** MENAMBAH KICAUAN BARU ********** */
void addKicauan(ListDinKicauan *l, KICAUAN t)
{
    if (isFullOfKicauan(*l))
    {
        if (CAPACITYKICAUAN(*l) == 0)
        {
            CAPACITYKICAUAN(*l) = 1;
        } else
        {
            CAPACITYKICAUAN(*l) *= 2;
        }
        CONTENTKICAUAN(*l) = (KICAUAN *)realloc(CONTENTKICAUAN(*l), CAPACITYKICAUAN(*l) * sizeof(KICAUAN));
    }
    ELMTKICAUAN(*l,NEFFKICAUAN(*l)) = t;
    NEFFKICAUAN(*l)++;
}

boolean createNewKicauanInput(int newID, int likes, currentUser CU, KICAUAN * kOut)
{
    STARTWORDINPUT();
    printf("\nEndInput: %d\n",EndInput);
    if (EndInput)
    {
        return false;
    }
    else
    {
        printf("\nlength cw: %d\n",currentWord.Length);
        IDKICAUAN(*kOut) = newID;
        TEXTKICAUAN(*kOut) = currentWord;
        LIKEKICAUAN(*kOut) = likes;
        AUTHORKICAUAN(*kOut) = CU.nama;
        DATETIMEKICAUAN(*kOut) = grabCurrentDateTime();
    }

    return true;
}

KICAUAN createNewKicauanFromText(int newID, Word text, currentUser CU) // untuk menambah dari draf
{
    KICAUAN nKicauan;
    IDKICAUAN(nKicauan) = newID;
    TEXTKICAUAN(nKicauan) = text;
    LIKEKICAUAN(nKicauan) = 0;
    AUTHORKICAUAN(nKicauan) = CU.nama;
    DATETIMEKICAUAN(nKicauan) = grabCurrentDateTime();
    return nKicauan;
}

void berkicau(ListDinKicauan *l, ListDinKicauan *lUser, currentUser CU)
{
    KICAUAN newKicauan;
    printf("Masukkan kicauan:\n");
    if (createNewKicauanInput(NEFFKICAUAN(*l) + 1, 0, CU, &newKicauan))
    {
        addKicauan(l,newKicauan);
        addKicauan(lUser,newKicauan);
        printf("\nSelamat! kicauan telah diterbitkan!\nDetil kicauan:\n");
        displayKicauan(newKicauan);
    }
    else
    {
        printf("Kicauan tidak boleh hanya berisi spasi!\n\n");
    }
}

void kicaukanDraf(ListDinKicauan *l, ListDinKicauan *lUser, Word text, currentUser CU)
{
    KICAUAN newKicauan;
    newKicauan = createNewKicauanFromText(NEFFKICAUAN(*l) + 1,text,CU);
    addKicauan(l,newKicauan);
    addKicauan(lUser,newKicauan);
}
/* ************************************************************************************************************ */

/* ************* Menambah Like ************ */
void likeKicauanByID(ListDinKicauan *l, int ID) // masih butuh yang pertemanan
{
    if (ID <= NEFFKICAUAN(*l) && ID > 0)
    {
        LIKEKICAUAN(ELMTKICAUAN(*l, ID - 1))++;
    }
    else
    {
        printf("Tidak ditemukan kicauan dengan ID = %d", ID);
    }
}

/* ************* Mengedit kicauan di dalam list ************ */
void editKicauanInList(ListDinKicauan *l, ListDinKicauan *lUser, int ID, currentUser CU)
{
    if (ID <= NEFFKICAUAN(*l) && ID > 0)
    {
        if (isWordEqual(CU.nama, AUTHORKICAUAN(ELMTKICAUAN(*l,ID-1))))
        {
            int iUser = 0;
            while (IDKICAUAN(ELMTKICAUAN(*lUser,iUser)) != ID)
            {
                iUser++;
            }
            printf("\nMasukkan kicauan baru:\n");
            KICAUAN edittedKicauan;
            
            if (createNewKicauanInput(ID, 0, CU, &edittedKicauan))
            {
                ELMTKICAUAN(*l,ID-1) = edittedKicauan;
                ELMTKICAUAN(*lUser,iUser) = edittedKicauan;
                printf("Selamat! kicauan telah diterbitkan!\nDetil kicauan:\n");
                displayKicauan(edittedKicauan);
            }
            else
            {
                printf("Kicauan tidak boleh hanya berisi spasi!\n");
            }
            
            printf("\n");
        }
        else
        {
            printf("Kicauan dengan ID = %d bukan milikmu!\n\n", ID);
        }
    }
    else
    {
        printf("Tidak ditemukan kicauan dengan ID = %d\n\n", ID);
    }
}

/* others */
boolean isFullOfKicauan(ListDinKicauan l)
{
    return (NEFFKICAUAN(l) == CAPACITYKICAUAN(l));
}

void displayKicauan(KICAUAN T)
{
    printf("| ID : ");
    printf("%d\n",IDKICAUAN(T));

    printf("| @");
    printWord(AUTHORKICAUAN(T));
    printf("\n");

    printf("| ");
    printWord(TEXTKICAUAN(T));
    printf("\n");

    printf("| Disukai : ");
    printf("%d\n",LIKEKICAUAN(T));

    printf("| ");
    TulisDATETIME(DATETIMEKICAUAN(T));
    printf("\n");
}