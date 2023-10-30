#include "ADT/tempRun.h"
#include "Lib/commands.h"
#include <stdio.h>
// #include "Lib/ganti_profil/gantiprofil.h"
#include "inisialisasi/pengguna/pengguna.c"
int main()
{ 
    boolean isLogged  = true; //sementara true
    //Inisialiasi
    ListUserStatik LU;
    CreateEmptyPengguna(&LU);
    loadPenggunaConfig("configs/config-1/pengguna.config",&LU);


    boolean runProgram = true;

    while (runProgram)
    {
        printf(">> ");
        STARTWORD();
        // command.tabword = currentWord.tabword  & command.length = currentWord.length
        Word command = currentWord;

        if (isWordEqual(command, tutupProgramCmd))
        {
            fclose(pita);
            runProgram = false;
            printf("Anda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
        }
        else if (isWordEqual(command, kicauCmd) && isLogged)
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
        else if (isWordEqual(command,gantiProfilCmd) && isLogged)
        {
            gantiProfil(&LU);
        }
        else if (isWordEqual(command,daftarCmd) && isLogged)
        {
            Daftar(&LU);
        }
        
        
        
        
    }
    return 0;
}
