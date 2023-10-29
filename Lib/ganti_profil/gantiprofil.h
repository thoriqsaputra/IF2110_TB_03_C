
// #include "../../ADT/tempRun.h"

#include <stdio.h>
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


// int main()
// {
//     ListUserStatik LU;
//     CreateEmptyPengguna(&LU);
//     gantiProfil(&LU);
//     tulisDataPengguna(&LU.buffer[0]);
    
//     return 0;
// }