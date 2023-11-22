#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "../../main.c"
#include "../../Lib/includeall.h"

void muat(ListUserStatik *LU, ListDinBalasan *LB, ListDinDraf *LD, ListDinKicauan *LK)
{
    printf("Masukkan nama folder yang hendak dimuat.");
    STARTWORDINPUT();

    Word folder = currentWord;

    // Ubah word ke array of char
    char namaFolder[folder.Length];
    int i;
    for (i = 0; i < folder.Length; i++)
    {
        namaFolder[i] = folder.TabWord[i];
    }

    char pathFolder[8 + folder.Length];
    pathFolder[0] = 'c';
    pathFolder[1] = 'o';
    pathFolder[2] = 'n';
    pathFolder[3] = 'f';
    pathFolder[4] = 'i';
    pathFolder[5] = 'g';
    pathFolder[6] = 's';
    pathFolder[7] = '/';
    int j = 0;
    for (i = 8; i < folder.Length + 8; i++)
    {
        pathFolder[i] = namaFolder[j];
        j++;
    }

    struct stat st = {0};

    if (stat(pathFolder, &st) == -1)
    {
        printf("Belum terdapat Folder tersebut. Akan dilakukan pembuatan folder tersebut terlebih dahulu.\n\n");
        printf("Mohon tunggu...\n");
        printf("1...\n");
        printf("1...\n");
        printf("2...\n");
        printf("3...\n\n");
        if (mkdir(namaFolder, 0700) == -1)
        {
            perror("ERROR: Tidak dapat membuat folder\n");
            return;
        }
        else
        {
            for (i = 0; i < folder.Length; i++)
            {
                printf("%c", namaFolder[i]);
            }
            printf("Folder sudah berhasil dibuat.\n");
        }
    }

    // Buat path-path config
    char pathBalasan[folder.Length + 8 + 15];
    for (i = 0; i < folder.Length + 8; i++)
    {
        pathBalasan[i] = pathFolder[i];
    }
    pathBalasan[folder.Length + 8] = '/';
    pathBalasan[folder.Length + 8 + 1] = 'b';
    pathBalasan[folder.Length + 8 + 2] = 'a';
    pathBalasan[folder.Length + 8 + 3] = 'l';
    pathBalasan[folder.Length + 8 + 4] = 'a';
    pathBalasan[folder.Length + 8 + 5] = 's';
    pathBalasan[folder.Length + 8 + 6] = 'a';
    pathBalasan[folder.Length + 8 + 7] = 'n';
    pathBalasan[folder.Length + 8 + 8] = '.';
    pathBalasan[folder.Length + 8 + 9] = 'c';
    pathBalasan[folder.Length + 8 + 10] = 'o';
    pathBalasan[folder.Length + 8 + 11] = 'n';
    pathBalasan[folder.Length + 8 + 12] = 'f';
    pathBalasan[folder.Length + 8 + 13] = 'i';
    pathBalasan[folder.Length + 8 + 14] = 'g';

    char pathDraf[folder.Length + 8 + 12];
    for (i = 0; i < folder.Length + 8; i++)
    {
        pathDraf[i] = pathFolder[i];
    }
    pathDraf[folder.Length + 8] = '/';
    pathDraf[folder.Length + 8 + 1] = 'd';
    pathDraf[folder.Length + 8 + 2] = 'r';
    pathDraf[folder.Length + 8 + 3] = 'a';
    pathDraf[folder.Length + 8 + 4] = 'f';
    pathDraf[folder.Length + 8 + 5] = '.';
    pathDraf[folder.Length + 8 + 6] = 'c';
    pathDraf[folder.Length + 8 + 7] = 'o';
    pathDraf[folder.Length + 8 + 8] = 'n';
    pathDraf[folder.Length + 8 + 9] = 'f';
    pathDraf[folder.Length + 8 + 10] = 'i';
    pathDraf[folder.Length + 8 + 11] = 'g';

    char pathKicauan[folder.Length + 8 + 16];
    for (i = 0; i < folder.Length + 8; i++)
    {
        pathKicauan[i] = pathFolder[i];
    }
    pathKicauan[folder.Length + 8] = '/';
    pathKicauan[folder.Length + 8 + 1] = 'k';
    pathKicauan[folder.Length + 8 + 2] = 'i';
    pathKicauan[folder.Length + 8 + 3] = 'c';
    pathKicauan[folder.Length + 8 + 4] = 'a';
    pathKicauan[folder.Length + 8 + 5] = 'u';
    pathKicauan[folder.Length + 8 + 6] = 'a';
    pathKicauan[folder.Length + 8 + 7] = 'a';
    pathKicauan[folder.Length + 8 + 8] = 'n';
    pathKicauan[folder.Length + 8 + 9] = '.';
    pathKicauan[folder.Length + 8 + 10] = 'c';
    pathKicauan[folder.Length + 8 + 11] = 'o';
    pathKicauan[folder.Length + 8 + 12] = 'n';
    pathKicauan[folder.Length + 8 + 13] = 'f';
    pathKicauan[folder.Length + 8 + 14] = 'i';
    pathKicauan[folder.Length + 8 + 15] = 'g';

    char pathPengguna[folder.Length + 8 + 16];
    for (i = 0; i < folder.Length + 8; i++)
    {
        pathPengguna[i] = pathFolder[i];
    }
    pathPengguna[folder.Length + 8] = '/';
    pathPengguna[folder.Length + 8 + 1] = 'p';
    pathPengguna[folder.Length + 8 + 2] = 'e';
    pathPengguna[folder.Length + 8 + 3] = 'n';
    pathPengguna[folder.Length + 8 + 4] = 'g';
    pathPengguna[folder.Length + 8 + 5] = 'g';
    pathPengguna[folder.Length + 8 + 6] = 'u';
    pathPengguna[folder.Length + 8 + 7] = 'n';
    pathPengguna[folder.Length + 8 + 8] = 'a';
    pathPengguna[folder.Length + 8 + 9] = '.';
    pathPengguna[folder.Length + 8 + 10] = 'c';
    pathPengguna[folder.Length + 8 + 11] = 'o';
    pathPengguna[folder.Length + 8 + 12] = 'n';
    pathPengguna[folder.Length + 8 + 13] = 'f';
    pathPengguna[folder.Length + 8 + 14] = 'i';
    pathPengguna[folder.Length + 8 + 15] = 'g';

    char pathUtas[folder.Length + 8 + 12];
    for (i = 0; i < folder.Length + 8; i++)
    {
        pathUtas[i] = pathFolder[i];
    }
    pathUtas[folder.Length + 8] = '/';
    pathUtas[folder.Length + 8 + 1] = 'u';
    pathUtas[folder.Length + 8 + 2] = 't';
    pathUtas[folder.Length + 8 + 3] = 'a';
    pathUtas[folder.Length + 8 + 4] = 's';
    pathUtas[folder.Length + 8 + 5] = '.';
    pathUtas[folder.Length + 8 + 6] = 'c';
    pathUtas[folder.Length + 8 + 7] = 'o';
    pathUtas[folder.Length + 8 + 8] = 'n';
    pathUtas[folder.Length + 8 + 9] = 'f';
    pathUtas[folder.Length + 8 + 10] = 'i';
    pathUtas[folder.Length + 8 + 11] = 'g';

    loadPenggunaConfig(pathPengguna, &LU);
    loadDrafConfig(pathDraf, &LD);
    loadKicauanConfig(pathKicauan, &LK);
    loadBalasanConfig(pathBalasan, &LB);
    // loadUtasConfig(pathUtas, &LT);
}

void simpan(ListUserStatik *LU, ListDinBalasan *LB, ListDinDraf *LD, ListDinKicauan *LK)
{
    printf("Masukkan nama folder penyimpanan");
    STARTWORDINPUT();

    Word folder = currentWord;

    // Ubah word ke array of char
    char namaFolder[folder.Length];
    int i;
    for (i = 0; i < folder.Length; i++)
    {
        namaFolder[i] = folder.TabWord[i];
    }

    char pathFolder[8 + folder.Length];
    pathFolder[0] = 'c';
    pathFolder[1] = 'o';
    pathFolder[2] = 'n';
    pathFolder[3] = 'f';
    pathFolder[4] = 'i';
    pathFolder[5] = 'g';
    pathFolder[6] = 's';
    pathFolder[7] = '/';
    int j = 0;
    for (i = 8; i < folder.Length + 8; i++)
    {
        pathFolder[i] = namaFolder[j];
        j++;
    }

    struct stat st = {0};

    if (stat(pathFolder, &st) == -1)
    {
        printf("Belum terdapat Folder tersebut. Akan dilakukan pembuatan folder tersebut terlebih dahulu.\n\n");
        printf("Mohon tunggu...\n");
        printf("1...\n");
        printf("1...\n");
        printf("2...\n");
        printf("3...\n\n");
        if (mkdir(namaFolder, 0700) == -1)
        {
            perror("ERROR: Tidak dapat membuat folder\n");
            return;
        }
        else
        {
            for (i = 0; i < folder.Length; i++)
            {
                printf("%c", namaFolder[i]);
            }
            printf("Folder sudah berhasil dibuat.\n");
        }
    }

    // Buat path-path config
    char pathBalasan[folder.Length + 8 + 15];
    for (i = 0; i < folder.Length + 8; i++)
    {
        pathBalasan[i] = pathFolder[i];
    }
    pathBalasan[folder.Length + 8] = '/';
    pathBalasan[folder.Length + 8 + 1] = 'b';
    pathBalasan[folder.Length + 8 + 2] = 'a';
    pathBalasan[folder.Length + 8 + 3] = 'l';
    pathBalasan[folder.Length + 8 + 4] = 'a';
    pathBalasan[folder.Length + 8 + 5] = 's';
    pathBalasan[folder.Length + 8 + 6] = 'a';
    pathBalasan[folder.Length + 8 + 7] = 'n';
    pathBalasan[folder.Length + 8 + 8] = '.';
    pathBalasan[folder.Length + 8 + 9] = 'c';
    pathBalasan[folder.Length + 8 + 10] = 'o';
    pathBalasan[folder.Length + 8 + 11] = 'n';
    pathBalasan[folder.Length + 8 + 12] = 'f';
    pathBalasan[folder.Length + 8 + 13] = 'i';
    pathBalasan[folder.Length + 8 + 14] = 'g';

    char pathDraf[folder.Length + 8 + 12];
    for (i = 0; i < folder.Length + 8; i++)
    {
        pathDraf[i] = pathFolder[i];
    }
    pathDraf[folder.Length + 8] = '/';
    pathDraf[folder.Length + 8 + 1] = 'd';
    pathDraf[folder.Length + 8 + 2] = 'r';
    pathDraf[folder.Length + 8 + 3] = 'a';
    pathDraf[folder.Length + 8 + 4] = 'f';
    pathDraf[folder.Length + 8 + 5] = '.';
    pathDraf[folder.Length + 8 + 6] = 'c';
    pathDraf[folder.Length + 8 + 7] = 'o';
    pathDraf[folder.Length + 8 + 8] = 'n';
    pathDraf[folder.Length + 8 + 9] = 'f';
    pathDraf[folder.Length + 8 + 10] = 'i';
    pathDraf[folder.Length + 8 + 11] = 'g';

    char pathKicauan[folder.Length + 8 + 16];
    for (i = 0; i < folder.Length + 8; i++)
    {
        pathKicauan[i] = pathFolder[i];
    }
    pathKicauan[folder.Length + 8] = '/';
    pathKicauan[folder.Length + 8 + 1] = 'k';
    pathKicauan[folder.Length + 8 + 2] = 'i';
    pathKicauan[folder.Length + 8 + 3] = 'c';
    pathKicauan[folder.Length + 8 + 4] = 'a';
    pathKicauan[folder.Length + 8 + 5] = 'u';
    pathKicauan[folder.Length + 8 + 6] = 'a';
    pathKicauan[folder.Length + 8 + 7] = 'a';
    pathKicauan[folder.Length + 8 + 8] = 'n';
    pathKicauan[folder.Length + 8 + 9] = '.';
    pathKicauan[folder.Length + 8 + 10] = 'c';
    pathKicauan[folder.Length + 8 + 11] = 'o';
    pathKicauan[folder.Length + 8 + 12] = 'n';
    pathKicauan[folder.Length + 8 + 13] = 'f';
    pathKicauan[folder.Length + 8 + 14] = 'i';
    pathKicauan[folder.Length + 8 + 15] = 'g';

    char pathPengguna[folder.Length + 8 + 16];
    for (i = 0; i < folder.Length + 8; i++)
    {
        pathPengguna[i] = pathFolder[i];
    }
    pathPengguna[folder.Length + 8] = '/';
    pathPengguna[folder.Length + 8 + 1] = 'p';
    pathPengguna[folder.Length + 8 + 2] = 'e';
    pathPengguna[folder.Length + 8 + 3] = 'n';
    pathPengguna[folder.Length + 8 + 4] = 'g';
    pathPengguna[folder.Length + 8 + 5] = 'g';
    pathPengguna[folder.Length + 8 + 6] = 'u';
    pathPengguna[folder.Length + 8 + 7] = 'n';
    pathPengguna[folder.Length + 8 + 8] = 'a';
    pathPengguna[folder.Length + 8 + 9] = '.';
    pathPengguna[folder.Length + 8 + 10] = 'c';
    pathPengguna[folder.Length + 8 + 11] = 'o';
    pathPengguna[folder.Length + 8 + 12] = 'n';
    pathPengguna[folder.Length + 8 + 13] = 'f';
    pathPengguna[folder.Length + 8 + 14] = 'i';
    pathPengguna[folder.Length + 8 + 15] = 'g';

    char pathUtas[folder.Length + 8 + 12];
    for (i = 0; i < folder.Length + 8; i++)
    {
        pathUtas[i] = pathFolder[i];
    }
    pathUtas[folder.Length + 8] = '/';
    pathUtas[folder.Length + 8 + 1] = 'u';
    pathUtas[folder.Length + 8 + 2] = 't';
    pathUtas[folder.Length + 8 + 3] = 'a';
    pathUtas[folder.Length + 8 + 4] = 's';
    pathUtas[folder.Length + 8 + 5] = '.';
    pathUtas[folder.Length + 8 + 6] = 'c';
    pathUtas[folder.Length + 8 + 7] = 'o';
    pathUtas[folder.Length + 8 + 8] = 'n';
    pathUtas[folder.Length + 8 + 9] = 'f';
    pathUtas[folder.Length + 8 + 10] = 'i';
    pathUtas[folder.Length + 8 + 11] = 'g';

    // Simpan data
    FILE *file;

    file = fopen(pathPengguna, "w");
    if (file != NULL)
    {
        // pengguna
        fclose(file);
    }

    file = fopen(pathBalasan, "w");
    if (file != NULL)
    {
        // balasan
        fclose(file);
    }

    file = fopen(pathDraf, "w");
    if (file != NULL)
    {
        // draf
        fclose(file);
    }

    file = fopen(pathKicauan, "w");
    if (file != NULL)
    {
        // kicauan
        fclose(file);
    }

    file = fopen(pathUtas, "w");
    if (file != NULL)
    {
        // utas
        fclose(file);
    }
}
