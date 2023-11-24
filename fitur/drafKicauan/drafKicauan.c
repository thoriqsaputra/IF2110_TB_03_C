#include "drafKicauan.h"
#include "../../inisialisasi/pengguna/pengguna.h"
#include "../../inisialisasi/draf/draf.h"
#include "../../Lib/globalFunction.h"
#include <time.h>
#include <stdlib.h>
#include "../../ADT/datetime.h"

// boolean isWordEqual(Word input, Word cek)  pindah ke globalFunction
// {

//     if (input.Length != cek.Length)
//     {
//         return false;
//     }
//     else
//     {
//         for (int i = 0; i < input.Length; i++)
//         {
//             if (input.TabWord[i] != cek.TabWord[i])
//             {
//                 return false;
//             }
//         }
//         return true;
//     }
// }

AddressDraf newNodeDraf(Draf x)
{
    AddressDraf P = (AddressDraf)malloc(sizeof(Draf));
    if (P != NULL)
    {
        INFODRAF(P) = x;
        NEXTDRAF(P) = NULL;
        return P;
    }
    else
    {
        return NULL;
    }
}

boolean isEmptyDraf(DrafKicauan s)
{
    return (ADDR_TOPDRAF(s) == NULL);
}

int lengthDraf(DrafKicauan s)
{
    AddressDraf P = ADDR_TOPDRAF(s);
    int count = 0;
    while (P != NULL)
    {
        count++;
        P = NEXTDRAF(P);
    }
    return count;
}

void CreateDrafKicauan(DrafKicauan *s)
{
    ADDR_TOPDRAF(*s) = NULL;
}

void DisplayDraf(DrafKicauan s)
{
    Draf d = TOPDRAF(s);
    printf("| ");
    TulisDATETIME((d).datetime);
    printf("\n");
    printf("| ");
    printWord((d).text);
    printf("\n");
}

void pushDraf(DrafKicauan *s, Draf x)
{
    AddressDraf P = newNodeDraf(x);
    if (P != NULL)
    {
        NEXTDRAF(P) = ADDR_TOPDRAF(*s);
        ADDR_TOPDRAF(*s) = P;
    }
}

void popDraf(DrafKicauan *s, Draf *x)
{
    AddressDraf P = ADDR_TOPDRAF(*s);
    *x = INFODRAF(P);
    if (NEXTDRAF(P) == NULL)
    {
        ADDR_TOPDRAF(*s) = NULL;
    }
    else
    {
        ADDR_TOPDRAF(*s) = NEXTDRAF(P);
        NEXTDRAF(P) = NULL;
    }
    free(P);
}

// Command BUAT_DRAF
void buatDraf(DrafKicauan *s, currentUser u, ListDinDraf *l)
{
    Word hapus = {"HAPUS", 5};
    Word simpan = {"SIMPAN", 6};
    Word terbit = {"TERBIT", 6};

    printf("Masukkan draf:\n");
    STARTWORDINPUT();

    Word text = currentWord;

    // Ambil waktu sekarang
    DATETIME dt;
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    int YY = 1900 + tm_info->tm_year;
    int MM = 1 + tm_info->tm_mon;
    int DD = tm_info->tm_mday;
    int hh = tm_info->tm_hour;
    int mm = tm_info->tm_min;
    int ss = tm_info->tm_sec;
    CreateDATETIME(&dt, DD, MM, YY, hh, mm, ss);

    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
    STARTWORDINPUT();

    Word pil = currentWord;
    Draf draf = {ELMTDRAF(*l, NEFFDRAF(*l) - 1).id + 1, text, u.nama, dt};
    if (isWordEqual(pil, hapus))
    {
        printf("Draf berhasil dihapus!\n");
    }
    else if (isWordEqual(pil, simpan))
    {
        pushDraf(s, draf);
        addDraf(l, draf); // Tambahkan ke raw data draf
        printf("Draf berhasil disimpan!\n");
    }
    else if (isWordEqual(pil, terbit))
    {
        // TODO
        // Masuk ke fungsi terbitnya kicauan
        printf("Selamat! Draf kicauan telah diterbitkan!\n");
    }
    else
    {
        printf("Perintah tidak dikenali\n");
    }
}

// Command LIHAT_DRAF
void lihatDraf(DrafKicauan *s, ListDinDraf *l, currentUser u)
{
    if (isEmptyDraf(*s))
    {
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    }
    else
    {
        Word hapus = {"HAPUS", 5};
        Word ubah = {"UBAH", 4};
        Word terbit = {"TERBIT", 6};
        Word kembali = {"KEMBALI", 7};

        printf("Ini draf terakhir anda:\n");

        DisplayDraf(*s);
        printf("\n");

        int ulang = 1;

        while (ulang)
        {
            ulang = 0;
            printf("Apakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
            STARTWORDINPUT();

            Word pil = currentWord;

            if (isWordEqual(pil, hapus))
            {
                Draf temp;
                popDraf(s, &temp);          // Hapus dalam stack draf current user
                deleteDrafById(l, temp.id); // Hapus dalam raw data draf
                printf("Draf telah berhasil dihapus!\n");
            }
            else if (isWordEqual(pil, ubah))
            {
                Draf temp;
                popDraf(s, &temp);
                printf("Masukkan draf yang baru:\n");

                STARTWORDINPUT();

                Word text = currentWord;

                // Ambil waktu sekarang
                DATETIME dt;
                time_t t = time(NULL);
                struct tm *tm_info = localtime(&t);
                int YY = 1900 + tm_info->tm_year;
                int MM = 1 + tm_info->tm_mon;
                int DD = tm_info->tm_mday;
                int hh = tm_info->tm_hour;
                int mm = tm_info->tm_min;
                int ss = tm_info->tm_sec;
                CreateDATETIME(&dt, DD, MM, YY, hh, mm, ss);

                Draf draf = {temp.id, text, u.nama, dt};

                pushDraf(s, draf);

                printf("Draf telah berhasil diubah!\n\n");
                ulang = 1;
            }
            else if (isWordEqual(pil, terbit))
            {
                // TODO
                // Masuk ke fungsi terbitnya kicauan
                printf("Selamat! Draf kicauan telah diterbitkan!\n");
            }
            else if (isWordEqual(pil, kembali))
            {
                printf("Kembali ke menu..\n");
            }
            else
            {
                printf("Perintah tidak dikenali\n");
            }
        }
    }
}

void loadDrafKicauan(ListDinDraf l, DrafKicauan *d, currentUser u)
{
    int i;
    for (i = 0; i < l.nEff; i++)
    {
        if (isWordEqual(l.buffer[i].author, u.nama))
        {
            pushDraf(d, l.buffer[i]);
        }
    }
}