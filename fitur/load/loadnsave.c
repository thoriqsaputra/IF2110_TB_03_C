#include <stdio.h>
#include <stdlib.h>
#include "../../Lib/includeall.h"
#include "loadnsave.h"

void muat(Word folder, ListUserStatik *LU, ListDinDraf *LD, ListDinKicauan *LK, ListDinUtas *LS, Graph *GP, ListTree *LT)
{

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

    // Buat path-path config
    char pathBalasan[folder.Length + 8 + 16];
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
    pathBalasan[folder.Length + 8 + 15] = '\0';

    char pathDraf[folder.Length + 8 + 13];
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
    pathDraf[folder.Length + 8 + 12] = '\0';

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
    pathKicauan[folder.Length + 8 + 7] = 'n';
    pathKicauan[folder.Length + 8 + 8] = '.';
    pathKicauan[folder.Length + 8 + 9] = 'c';
    pathKicauan[folder.Length + 8 + 10] = 'o';
    pathKicauan[folder.Length + 8 + 11] = 'n';
    pathKicauan[folder.Length + 8 + 12] = 'f';
    pathKicauan[folder.Length + 8 + 13] = 'i';
    pathKicauan[folder.Length + 8 + 14] = 'g';
    pathKicauan[folder.Length + 8 + 15] = '\0';

    char pathPengguna[folder.Length + 8 + 17];
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
    pathPengguna[folder.Length + 8 + 16] = '\0';

    char pathUtas[folder.Length + 8 + 13];
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
    pathUtas[folder.Length + 8 + 12] = '\0';
    loadDrafConfig(pathDraf, LD);
    loadKicauanConfig(pathKicauan, LK);
    loadPenggunaConfig(pathPengguna, LU, GP);
    loadUtasConfig(pathUtas, LS);
    loadBalasanConfig(pathBalasan, LT);
}

void simpan(ListUserStatik *LU, ListDinDraf *LD, ListDinKicauan *LK, ListDinUtas *LS, Graph *GP, ListTree *LT)
{
    // printf("Masukkan nama folder penyimpanan");
    // STARTWORDINPUT();

    // Word folder = currentWord;

    // // Ubah word ke array of char
    // char namaFolder[folder.Length];
    // int i;
    // for (i = 0; i < folder.Length; i++)
    // {
    //     namaFolder[i] = folder.TabWord[i];
    // }

    // char pathFolder[8 + folder.Length];
    // pathFolder[0] = 'c';
    // pathFolder[1] = 'o';
    // pathFolder[2] = 'n';
    // pathFolder[3] = 'f';
    // pathFolder[4] = 'i';
    // pathFolder[5] = 'g';
    // pathFolder[6] = 's';
    // pathFolder[7] = '/';
    // int j = 0;
    // for (i = 8; i < folder.Length + 8; i++)
    // {
    //     pathFolder[i] = namaFolder[j];
    //     j++;
    // }

    // struct stat st = {0};

    // if (stat(pathFolder, &st) == -1)
    // {
    //     printf("Belum terdapat Folder tersebut. Akan dilakukan pembuatan folder tersebut terlebih dahulu.\n\n");
    //     printf("Mohon tunggu...\n");
    //     printf("1...\n");
    //     printf("1...\n");
    //     printf("2...\n");
    //     printf("3...\n\n");
    //     if (mkdir(namaFolder, 0700) == -1)
    //     {
    //         perror("ERROR: Tidak dapat membuat folder\n");
    //         return;
    //     }
    //     else
    //     {
    //         for (i = 0; i < folder.Length; i++)
    //         {
    //             printf("%c", namaFolder[i]);
    //         }
    //         printf("Folder sudah berhasil dibuat.\n");
    //     }
    // }

    // // Buat path-path config
    // char pathBalasan[folder.Length + 8 + 16];
    // for (i = 0; i < folder.Length + 8; i++)
    // {
    //     pathBalasan[i] = pathFolder[i];
    // }
    // pathBalasan[folder.Length + 8] = '/';
    // pathBalasan[folder.Length + 8 + 1] = 'b';
    // pathBalasan[folder.Length + 8 + 2] = 'a';
    // pathBalasan[folder.Length + 8 + 3] = 'l';
    // pathBalasan[folder.Length + 8 + 4] = 'a';
    // pathBalasan[folder.Length + 8 + 5] = 's';
    // pathBalasan[folder.Length + 8 + 6] = 'a';
    // pathBalasan[folder.Length + 8 + 7] = 'n';
    // pathBalasan[folder.Length + 8 + 8] = '.';
    // pathBalasan[folder.Length + 8 + 9] = 'c';
    // pathBalasan[folder.Length + 8 + 10] = 'o';
    // pathBalasan[folder.Length + 8 + 11] = 'n';
    // pathBalasan[folder.Length + 8 + 12] = 'f';
    // pathBalasan[folder.Length + 8 + 13] = 'i';
    // pathBalasan[folder.Length + 8 + 14] = 'g';
    // pathBalasan[folder.Length + 8 + 15] = '\0';

    // char pathDraf[folder.Length + 8 + 13];
    // for (i = 0; i < folder.Length + 8; i++)
    // {
    //     pathDraf[i] = pathFolder[i];
    // }
    // pathDraf[folder.Length + 8] = '/';
    // pathDraf[folder.Length + 8 + 1] = 'd';
    // pathDraf[folder.Length + 8 + 2] = 'r';
    // pathDraf[folder.Length + 8 + 3] = 'a';
    // pathDraf[folder.Length + 8 + 4] = 'f';
    // pathDraf[folder.Length + 8 + 5] = '.';
    // pathDraf[folder.Length + 8 + 6] = 'c';
    // pathDraf[folder.Length + 8 + 7] = 'o';
    // pathDraf[folder.Length + 8 + 8] = 'n';
    // pathDraf[folder.Length + 8 + 9] = 'f';
    // pathDraf[folder.Length + 8 + 10] = 'i';
    // pathDraf[folder.Length + 8 + 11] = 'g';
    // pathDraf[folder.Length + 8 + 12] = '\0';

    // char pathKicauan[folder.Length + 8 + 16];
    // for (i = 0; i < folder.Length + 8; i++)
    // {
    //     pathKicauan[i] = pathFolder[i];
    // }
    // pathKicauan[folder.Length + 8] = '/';
    // pathKicauan[folder.Length + 8 + 1] = 'k';
    // pathKicauan[folder.Length + 8 + 2] = 'i';
    // pathKicauan[folder.Length + 8 + 3] = 'c';
    // pathKicauan[folder.Length + 8 + 4] = 'a';
    // pathKicauan[folder.Length + 8 + 5] = 'u';
    // pathKicauan[folder.Length + 8 + 6] = 'a';
    // pathKicauan[folder.Length + 8 + 7] = 'n';
    // pathKicauan[folder.Length + 8 + 8] = '.';
    // pathKicauan[folder.Length + 8 + 9] = 'c';
    // pathKicauan[folder.Length + 8 + 10] = 'o';
    // pathKicauan[folder.Length + 8 + 11] = 'n';
    // pathKicauan[folder.Length + 8 + 12] = 'f';
    // pathKicauan[folder.Length + 8 + 13] = 'i';
    // pathKicauan[folder.Length + 8 + 14] = 'g';
    // pathKicauan[folder.Length + 8 + 15] = '\0';

    // char pathPengguna[folder.Length + 8 + 17];
    // for (i = 0; i < folder.Length + 8; i++)
    // {
    //     pathPengguna[i] = pathFolder[i];
    // }
    // pathPengguna[folder.Length + 8] = '/';
    // pathPengguna[folder.Length + 8 + 1] = 'p';
    // pathPengguna[folder.Length + 8 + 2] = 'e';
    // pathPengguna[folder.Length + 8 + 3] = 'n';
    // pathPengguna[folder.Length + 8 + 4] = 'g';
    // pathPengguna[folder.Length + 8 + 5] = 'g';
    // pathPengguna[folder.Length + 8 + 6] = 'u';
    // pathPengguna[folder.Length + 8 + 7] = 'n';
    // pathPengguna[folder.Length + 8 + 8] = 'a';
    // pathPengguna[folder.Length + 8 + 9] = '.';
    // pathPengguna[folder.Length + 8 + 10] = 'c';
    // pathPengguna[folder.Length + 8 + 11] = 'o';
    // pathPengguna[folder.Length + 8 + 12] = 'n';
    // pathPengguna[folder.Length + 8 + 13] = 'f';
    // pathPengguna[folder.Length + 8 + 14] = 'i';
    // pathPengguna[folder.Length + 8 + 15] = 'g';
    // pathPengguna[folder.Length + 8 + 16] = '\0';

    // char pathUtas[folder.Length + 8 + 13];
    // for (i = 0; i < folder.Length + 8; i++)
    // {
    //     pathUtas[i] = pathFolder[i];
    // }
    // pathUtas[folder.Length + 8] = '/';
    // pathUtas[folder.Length + 8 + 1] = 'u';
    // pathUtas[folder.Length + 8 + 2] = 't';
    // pathUtas[folder.Length + 8 + 3] = 'a';
    // pathUtas[folder.Length + 8 + 4] = 's';
    // pathUtas[folder.Length + 8 + 5] = '.';
    // pathUtas[folder.Length + 8 + 6] = 'c';
    // pathUtas[folder.Length + 8 + 7] = 'o';
    // pathUtas[folder.Length + 8 + 8] = 'n';
    // pathUtas[folder.Length + 8 + 9] = 'f';
    // pathUtas[folder.Length + 8 + 10] = 'i';
    // pathUtas[folder.Length + 8 + 11] = 'g';
    // pathUtas[folder.Length + 8 + 12] = '\0';

    // // Simpan data
    // FILE *file;

    // // file = fopen(pathPengguna, "w");
    // // if (file != NULL)
    // // {
    // //     // pengguna
    // //     fprintf(file, "%d\n", LU->capacity);
    // //     for (int i = 0; i < LU->capacity; i++)
    // //     {
    // //         for (int j = 0; j < LU->buffer[i].nama.Length; j++)
    // //         {
    // //             fprintf(file, "%c", LU->buffer[i].nama.TabWord[j]);
    // //         }
    // //         fprintf(file, "\n");
    // //         for (int j = 0; j < LU->buffer[i].password.Length; j++)
    // //         {
    // //             fprintf(file, "%c", LU->buffer[i].password.TabWord[j]);
    // //         }
    // //         fprintf(file, "\n");
    // //         for (int j = 0; j < LU->buffer[i].bio.Length; j++)
    // //         {
    // //             fprintf(file, "%c", LU->buffer[i].bio.TabWord[j]);
    // //         }
    // //         fprintf(file, "\n");
    // //         for (int j = 0; j < LU->buffer[i].noHp.Length; j++)
    // //         {
    // //             fprintf(file, "%c", LU->buffer[i].noHp.TabWord[j]);
    // //         }
    // //         fprintf(file, "\n");
    // //         for (int j = 0; j < LU->buffer[i].weton.Length; j++)
    // //         {
    // //             fprintf(file, "%c", LU->buffer[i].weton.TabWord[j]);
    // //         }
    // //         fprintf(file, "\n");
    // //         if (LU->buffer[i].jenisAkun == 1)
    // //         {
    // //             fprintf(file, "Publik\n");
    // //         }
    // //         else
    // //         {
    // //             fprintf(file, "Privat\n");
    // //         }
    // //         for (int j = 0; j < LU->buffer[i].fotoProfil.rowEff; j++)
    // //         {
    // //             for (int k = 0; k < LU->buffer[i].fotoProfil.colEff; k++)
    // //             {
    // //                 fprintf(file, "%c", LU->buffer[i].fotoProfil.mem[j][k]);
    // //                 if (k != LU->buffer[i].fotoProfil.colEff - 1)
    // //                 {
    // //                     fprintf(file, " ");
    // //                 }
    // //             }
    // //             if (j != LU->buffer[i].fotoProfil.rowEff - 1)
    // //             {
    // //                 fprintf(file, "\n");
    // //             }
    // //         }
    // //         if (i != LU->capacity - 1)
    // //         {
    // //             fprintf(file, "\n");
    // //         }
    // //     }
    // //     fclose(file);
    // // }

    // file = fopen(pathBalasan, "w");
    // if (file != NULL)
    // {
    //     // balasan
    //     fprintf(file, "%d\n", LT->NEFFListTree);

    //     fclose(file);
    // }

    // file = fopen(pathDraf, "w");
    // if (file != NULL)
    // {
    //     fprintf(file, "%d\n", LD->nEff);
    //     for (int i = 0; i < LD->nEff; i++)
    //     {
    //         fprintf(file, "%d\n", LD->buffer[i].id);
    //         for (int j = 0; j < LD->buffer[i].author.Length; j++)
    //         {
    //             fprintf(file, "%c", LD->buffer[i].author.TabWord[j]);
    //         }
    //         fprintf(file, "\n");
    //         for (int j = 0; j < LD->buffer[i].text.Length; j++)
    //         {
    //             fprintf(file, "%c", LD->buffer[i].text.TabWord[j]);
    //         }
    //         fprintf(file, "\n");
    //         fprintf(file, "%02d", LD->buffer[i].datetime.DD);
    //         fprintf(file, "/");
    //         fprintf(file, "%02d", LD->buffer[i].datetime.MM);
    //         fprintf(file, "/");
    //         fprintf(file, "%04d ", LD->buffer[i].datetime.YYYY);
    //         fprintf(file, "%02d", LD->buffer[i].datetime.T.HH);
    //         fprintf(file, ":");
    //         fprintf(file, "%02d", LD->buffer[i].datetime.T.MM);
    //         fprintf(file, ":");
    //         fprintf(file, "%02d", LD->buffer[i].datetime.T.SS);
    //         if (i != LD->nEff - 1)
    //         {
    //             fprintf(file, "\n");
    //         }
    //     }
    //     fclose(file);
    // }

    // file = fopen(pathKicauan, "w");
    // if (file != NULL)
    // {
    //     // kicauan
    //     fprintf(file, "%d\n", LK->nEffKicauan);
    //     for (int i = 0; i < LK->nEffKicauan; i++)
    //     {
    //         fprintf(file, "%d\n", LK->contentKicauan[i].ID);
    //         for (int j = 0; j < LK->contentKicauan[i].Text.Length; j++)
    //         {
    //             fprintf(file, "%c", LK->contentKicauan[i].Text.TabWord[j]);
    //         }
    //         fprintf(file, "\n");
    //         fprintf(file, "%d\n", LK->contentKicauan[i].Like);
    //         for (int j = 0; j < LK->contentKicauan[i].Author.Length; j++)
    //         {
    //             fprintf(file, "%c", LK->contentKicauan[i].Author.TabWord[j]);
    //         }
    //         fprintf(file, "\n");
    //         fprintf(file, "%02d", LK->contentKicauan[i].Datetime.DD);
    //         fprintf(file, "/");
    //         fprintf(file, "%02d", LK->contentKicauan[i].Datetime.MM);
    //         fprintf(file, "/");
    //         fprintf(file, "%04d ", LK->contentKicauan[i].Datetime.YYYY);
    //         fprintf(file, "%02d", LK->contentKicauan[i].Datetime.T.HH);
    //         fprintf(file, ":");
    //         fprintf(file, "%02d", LK->contentKicauan[i].Datetime.T.MM);
    //         fprintf(file, ":");
    //         fprintf(file, "%02d", LK->contentKicauan[i].Datetime.T.SS);
    //         if (i != LK->nEffKicauan - 1)
    //         {
    //             fprintf(file, "\n");
    //         }
    //     }
    //     fclose(file);
    // }

    // file = fopen(pathUtas, "w");
    // if (file != NULL)
    // {
    //     // utas
    //     fprintf(file, "%d\n", LS->nEff);
    //     for (int i = 0; i < LS->nEff; i++)
    //     {
    //         fprintf(file, "%d\n", LS->buffer[i]->idKicau);
    //         fprintf(file, "%d\n", lengthListLinUtas(LS->buffer[i]));
    //         AddressUtas p;
    //         p = FIRSTUTAS(LS);
    //         while (p != NULL)
    //         {
    //             for (int j = 0; j < p->info.text.Length; j++)
    //             {
    //                 fprintf(file, "%c", p->info.text.TabWord[j]);
    //             }
    //             fprintf(file, "\n");
    //             for (int j = 0; j < p->info.author.Length; j++)
    //             {
    //                 fprintf(file, "%c", p->info.author.TabWord[j]);
    //             }
    //             fprintf(file, "\n");
    //             fprintf(file, "%02d", LD->buffer[i].datetime.DD);
    //             fprintf(file, "/");
    //             fprintf(file, "%02d", LD->buffer[i].datetime.MM);
    //             fprintf(file, "/");
    //             fprintf(file, "%04d ", LD->buffer[i].datetime.YYYY);
    //             fprintf(file, "%02d", LD->buffer[i].datetime.T.HH);
    //             fprintf(file, ":");
    //             fprintf(file, "%02d", LD->buffer[i].datetime.T.MM);
    //             fprintf(file, ":");
    //             fprintf(file, "%02d", LD->buffer[i].datetime.T.SS);
    //             if (p->next != NULL)
    //             {
    //                 fprintf(file, "\n");
    //             }
    //             p = NEXTUTAS(p);
    //         }
    //         if (i != LS->nEff - 1)
    //         {
    //             fprintf(file, "\n");
    //         }
    //     }
    //     fclose(file);
    // }
}
