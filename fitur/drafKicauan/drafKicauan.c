#include "drafKicauan.h"
#include "../../inisialisasi/pengguna/pengguna.h"
#include <time.h>
#include "../../ADT/datetime.h"

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

Address newNodeDraf(Draf x)
{
    Address P = (Address)malloc(sizeof(Draf));
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
    Address P = ADDR_TOPDRAF(s);
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
    // Gadigunain
    // if (isEmptyDraf(s))
    // {
    //     printf("[]");
    // }
    // else
    // {
    //     Address P = ADDR_TOPDRAF(s);
    //     printf("[");
    //     while (P != NULL)
    //     {
    //         displayDataDraft(INFODRAF(P));
    //         if (NEXTDRAF(P) != NULL)
    //         {
    //             printf(",");
    //         }
    //         P = NEXTDRAF(P);
    //     }
    //     printf("]");
    // }
}

void pushDraf(DrafKicauan *s, Draf x)
{
    Address P = newNodeDraf(x);
    if (P != NULL)
    {
        NEXTDRAF(P) = ADDR_TOPDRAF(*s);
        ADDR_TOPDRAF(*s) = P;
    }
}

void popDraf(DrafKicauan *s, Draf *x)
{
    Address P = ADDR_TOPDRAF(*s);
    *x = INFODRAF(P);
    ADDR_TOPDRAF(*s) = NEXTDRAF(P);
    NEXTDRAF(P) = NULL;
    free(P);
}

// Command BUAT_DRAF
void buatDraf(DrafKicauan *s, currentUser u, ListDinDraf l)
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
    Draf draf = {NEFFDRAF(l) + 1, text, u.nama, dt};
    if (isWordEqual(pil, hapus))
    {
        printf("Draf berhasil dihapus!\n");
    }
    else if (isWordEqual(pil, simpan))
    {
        pushDraf(s, draf);
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
void lihatDraf(DrafKicauan s, ListDinDraf l, currentUser u)
{
    if (isEmptyDraf(s))
    {
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D\n");
    }
    else
    {
        Word hapus = {"HAPUS", 5};
        Word ubah = {"UBAH", 4};
        Word terbit = {"TERBIT", 6};
        Word kembali = {"KEMBALI", 7};

        printf("Apakah anda ingin mengubah, menghapus, atau menerbitkan draf ini? (KEMBALI jika ingin kembali)\n");
        STARTWORDINPUT();

        Word pil = currentWord;

        if (isWordEqual(pil, hapus))
        {
            Draf temp;
            popDraf(&s, &temp);
            printf("Draf telah berhasil dihapus!\n");
        }
        else if (isWordEqual(pil, ubah))
        {
            Draf temp;
            popDraf(&s, &temp);
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
            pushDraf(&s, draf);

            printf("Draf telah berhasil diubah!\n");
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

        DisplayDataDraf(TOPDRAF(s));
        printf("\n");
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