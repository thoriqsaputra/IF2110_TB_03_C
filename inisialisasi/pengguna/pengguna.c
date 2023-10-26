#include <stdio.h>
#include "../ADT/listdin.h"

int main()
{
    FILE *config_file = fopen("../configs/config-1/pengguna.config", "r");
    if (config_file == NULL)
    {
        printf("Error: could not open config file\n");
        return 1;
    }

    char buffer[100];
    fgets(buffer, 100, config_file);
    int banyakPengguna = buffer[0]; // baris pertama
    int i;
    for (i = 0; i < banyakPengguna; i++)
    {

        // fgets(buffer, 100, config_file); kalau mau ambil line selanjutnya
    }
    fclose(config_file);
    return 0;
}