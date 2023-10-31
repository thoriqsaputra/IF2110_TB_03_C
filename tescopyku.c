#include "ADT/tempRun.h"
#include "Lib/commands.h"
#include <stdio.h>
// #include "Lib/ganti_profil/gantiprofil.h"
#include "inisialisasi/pengguna/pengguna.c"
int main()
{
    boolean isLogged = false; // sementara true
    // Inisialiasi
    ListUserStatik LU;
    currentUser CU;
    CreateEmptyPengguna(&LU);
    loadPenggunaConfig("configs/config-1/pengguna.config", &LU);

    boolean runProgram = true;
    CreateEmptyCurrentUser(&CU);
    while (runProgram)
    {

        printf(">> ");
        STARTWORD();
        // command.tabword = currentWord.tabword  & command.length = currentWord.length
        Word command = currentWord;
        while ((isLogged == false))
        {
            if (isWordEqual(command, masukCmd))
            {
                Masuk(&LU, &CU,&isLogged);
            }
            else if (isWordEqual(command, daftarCmd))
            {
                Daftar(&LU);
            }
            else if (isWordEqual(command, tutupProgramCmd))
            {
                isLogged = true; // biar keluar loop
                command = currentWord;
                break;
            }
            else
            {
                printf("Anda Belum Logged in, silahkan daftar dahulu!\n");
            }
            printf(">> ");
            STARTWORD();
            command = currentWord;
        }
        if (isWordEqual(command, tutupProgramCmd))
        {
            fclose(pita);
            runProgram = false;
            printf("Anda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
        }
        else if (isWordEqual(command, kicauCmd))
        {
            ADVWORD();
            Word kicau = currentWord;
            printf("kamu masuk kicau\n");

            for (int i = 0; i < kicau.Length; i++)
            {
                printf("%c", kicau.TabWord[i]);
            }
            printf("\n");
        }
        else if (isWordEqual(command, gantiProfilCmd))
        {
            gantiProfil(&LU,&CU);
        }
        //Buat Debugging
        else if (isWordEqual(command,currentU))
        {
            tulisDataPengguna(&LU.buffer[idUser(CU)]);
        }
        else if (isWordEqual(command,lihatProfilCmd))
        {
            STARTWORDINPUT();
            Word findusername = currentWord;
            lihatUser(&LU,findusername);
        }

        else
        {
            printf("Tidak ada command itu\n\n");
        }
    }
    return 0;
}
