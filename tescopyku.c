#include "ADT/tempRun.h"
#include "Lib/commands.h"
#include <stdio.h>
// #include "Lib/ganti_profil/gantiprofil.h"
#include "inisialisasi/pengguna/pengguna.c"

void getInput()
{
    STARTWORDINPUT();
    if(currentChar == MARKINPUT && currentWord.Length == 0)
    {
        currentWord.TabWord[0] = ' ';
        currentWord.Length = 1;
    }
   
}
void gantiProfil(ListUserStatik *LU)
{
    printf("Masukkan Bio Akun:\n");
    getInput();
    //misal skrg profil 1
    (*LU).buffer[0].bio = currentWord;
    printf("Masukkan No HP:\n");
    getInput();
    (*LU).buffer[0].noHp = currentWord;
    printf("Masukkan Weton:\n");
    getInput();
    (*LU).buffer[0].weton = currentWord;
}


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

int main()
{
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
        else if (isWordEqual(command,gantiProfilCmd))
        {
            gantiProfil(&LU);
        }
        
    }
    return 0;
}
