#include <stdio.h>
#include <stdlib.h>
#include "../../ADT/tempRun.h"
#include "../../inisialisasi/pengguna/pengguna.c"

int main()
{
    // STARTWORDINPUT();
    // Word fold. = currentWord;
    // char namaFold.[fold..Length];
    // int i;
    // for (i = 0; i < fold..Length; i++)
    // {
    //     namaFold.[i] = fold..TabWord[i];
    // }

    // char pathFold.[8 + fold..Length];
    // pathFold.[0] = 'c';
    // pathFold.[1] = 'o';
    // pathFold.[2] = 'n';
    // pathFold.[3] = 'f';
    // pathFold.[4] = 'i';
    // pathFold.[5] = 'g';
    // pathFold.[6] = 's';
    // pathFold.[7] = '/';
    // int j = 0;
    // for (i = 8; i < fold..Length + 8; i++)
    // {
    //     pathFold.[i] = namaFold.[j];
    //     j++;
    // }

    // char pathBalasan[fold..Length + 8 + 15];
    // for (i = 0; i < fold..Length + 8; i++)
    // {
    //     pathBalasan[i] = pathFold.[i];
    // }
    // pathBalasan[fold..Length + 8] = '/';
    // pathBalasan[fold..Length + 8 + 1] = 'b';
    // pathBalasan[fold..Length + 8 + 2] = 'a';
    // pathBalasan[fold..Length + 8 + 3] = 'l';
    // pathBalasan[fold..Length + 8 + 4] = 'a';
    // pathBalasan[fold..Length + 8 + 5] = 's';
    // pathBalasan[fold..Length + 8 + 6] = 'a';
    // pathBalasan[fold..Length + 8 + 7] = 'n';
    // pathBalasan[fold..Length + 8 + 8] = '.';
    // pathBalasan[fold..Length + 8 + 9] = 'c';
    // pathBalasan[fold..Length + 8 + 10] = 'o';
    // pathBalasan[fold..Length + 8 + 11] = 'n';
    // pathBalasan[fold..Length + 8 + 12] = 'f';
    // pathBalasan[fold..Length + 8 + 13] = 'i';
    // pathBalasan[fold..Length + 8 + 14] = 'g';

    // char pathDraf[fold..Length + 8 + 12];
    // for (i = 0; i < fold..Length + 8; i++)
    // {
    //     pathDraf[i] = pathFold.[i];
    // }
    // pathDraf[fold..Length + 8] = '/';
    // pathDraf[fold..Length + 8 + 1] = 'd';
    // pathDraf[fold..Length + 8 + 2] = 'r';
    // pathDraf[fold..Length + 8 + 3] = 'a';
    // pathDraf[fold..Length + 8 + 4] = 'f';
    // pathDraf[fold..Length + 8 + 5] = '.';
    // pathDraf[fold..Length + 8 + 6] = 'c';
    // pathDraf[fold..Length + 8 + 7] = 'o';
    // pathDraf[fold..Length + 8 + 8] = 'n';
    // pathDraf[fold..Length + 8 + 9] = 'f';
    // pathDraf[fold..Length + 8 + 10] = 'i';
    // pathDraf[fold..Length + 8 + 11] = 'g';

    // char pathKicauan[fold..Length + 8 + 16];
    // for (i = 0; i < fold..Length + 8; i++)
    // {
    //     pathKicauan[i] = pathFold.[i];
    // }
    // pathKicauan[fold..Length + 8] = '/';
    // pathKicauan[fold..Length + 8 + 1] = 'k';
    // pathKicauan[fold..Length + 8 + 2] = 'i';
    // pathKicauan[fold..Length + 8 + 3] = 'c';
    // pathKicauan[fold..Length + 8 + 4] = 'a';
    // pathKicauan[fold..Length + 8 + 5] = 'u';
    // pathKicauan[fold..Length + 8 + 6] = 'a';
    // pathKicauan[fold..Length + 8 + 7] = 'a';
    // pathKicauan[fold..Length + 8 + 8] = 'n';
    // pathKicauan[fold..Length + 8 + 9] = '.';
    // pathKicauan[fold..Length + 8 + 10] = 'c';
    // pathKicauan[fold..Length + 8 + 11] = 'o';
    // pathKicauan[fold..Length + 8 + 12] = 'n';
    // pathKicauan[fold..Length + 8 + 13] = 'f';
    // pathKicauan[fold..Length + 8 + 14] = 'i';
    // pathKicauan[fold..Length + 8 + 15] = 'g';

    // char pathPengguna[fold..Length + 8 + 16];
    // for (i = 0; i < fold..Length + 8; i++)
    // {
    //     pathPengguna[i] = pathFold.[i];
    // }
    // pathPengguna[fold..Length + 8] = '/';
    // pathPengguna[fold..Length + 8 + 1] = 'p';
    // pathPengguna[fold..Length + 8 + 2] = 'e';
    // pathPengguna[fold..Length + 8 + 3] = 'n';
    // pathPengguna[fold..Length + 8 + 4] = 'g';
    // pathPengguna[fold..Length + 8 + 5] = 'g';
    // pathPengguna[fold..Length + 8 + 6] = 'u';
    // pathPengguna[fold..Length + 8 + 7] = 'n';
    // pathPengguna[fold..Length + 8 + 8] = 'a';
    // pathPengguna[fold..Length + 8 + 9] = '.';
    // pathPengguna[fold..Length + 8 + 10] = 'c';
    // pathPengguna[fold..Length + 8 + 11] = 'o';
    // pathPengguna[fold..Length + 8 + 12] = 'n';
    // pathPengguna[fold..Length + 8 + 13] = 'f';
    // pathPengguna[fold..Length + 8 + 14] = 'i';
    // pathPengguna[fold..Length + 8 + 15] = 'g';

    // char pathUtas[fold..Length + 8 + 12];
    // for (i = 0; i < fold..Length + 8; i++)
    // {
    //     pathUtas[i] = pathFold.[i];
    // }
    // pathUtas[fold..Length + 8] = '/';
    // pathUtas[fold..Length + 8 + 1] = 'u';
    // pathUtas[fold..Length + 8 + 2] = 't';
    // pathUtas[fold..Length + 8 + 3] = 'a';
    // pathUtas[fold..Length + 8 + 4] = 's';
    // pathUtas[fold..Length + 8 + 5] = '.';
    // pathUtas[fold..Length + 8 + 6] = 'c';
    // pathUtas[fold..Length + 8 + 7] = 'o';
    // pathUtas[fold..Length + 8 + 8] = 'n';
    // pathUtas[fold..Length + 8 + 9] = 'f';
    // pathUtas[fold..Length + 8 + 10] = 'i';
    // pathUtas[fold..Length + 8 + 11] = 'g';

    // for (i = 0; i < fold..Length + 8 + 12; i++)
    // {
    //     printf("%c", pathDraf[i]);
    // }
    // printf("\n");
    // return 0;
    ListUserStatik LU;
    loadPenggunaConfig("../../configs/config-1/pengguna.config", &LU);
    FILE *file;
    file = fopen("test.config", "w");
    if (file != NULL)
    {
        // pengguna
        fprintf(file, "%d\n", LU.capacity);
        for (int i = 0; i < LU.capacity; i++)
        {
            for (int j = 0; j < LU.buffer[i].nama.Length; j++)
            {
                fprintf(file, "%c", LU.buffer[i].nama.TabWord[j]);
            }
            fprintf(file, "\n");
            for (int j = 0; j < LU.buffer[i].password.Length; j++)
            {
                fprintf(file, "%c", LU.buffer[i].password.TabWord[j]);
            }
            fprintf(file, "\n");
            for (int j = 0; j < LU.buffer[i].bio.Length; j++)
            {
                fprintf(file, "%c", LU.buffer[i].bio.TabWord[j]);
            }
            fprintf(file, "\n");
            for (int j = 0; j < LU.buffer[i].noHp.Length; j++)
            {
                fprintf(file, "%c", LU.buffer[i].noHp.TabWord[j]);
            }
            fprintf(file, "\n");
            for (int j = 0; j < LU.buffer[i].weton.Length; j++)
            {
                fprintf(file, "%c", LU.buffer[i].weton.TabWord[j]);
            }
            fprintf(file, "\n");
            if (LU.buffer[i].jenisAkun == 1)
            {
                fprintf(file, "Publik\n");
            }
            else
            {
                fprintf(file, "Privat\n");
            }
            for (int j = 0; j < LU.buffer[i].fotoProfil.rowEff; j++)
            {
                for (int k = 0; k < LU.buffer[i].fotoProfil.colEff; k++)
                {
                    fprintf(file, "%c", LU.buffer[i].fotoProfil.mem[j][k]);
                    if (k != LU.buffer[i].fotoProfil.colEff - 1)
                    {
                        fprintf(file, " ");
                    }
                }
                if (j != LU.buffer[i].fotoProfil.rowEff - 1)
                {
                    fprintf(file, "\n");
                }
            }
            if (i != LU.capacity - 1)
            {
                fprintf(file, "\n");
            }
        }
        fclose(file);
    }

    return 0;
}