#include "ADT/ADT.h"
#include <stdio.h>

boolean isWordEqual(Word input,Word cek)
{
    
    if(input.Length != cek.Length)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < input.Length; i++)
        {
            if(input.TabWord[i] != cek.TabWord[i])
            {
                return false;
            }
        }
        return true;     
    }
    
}


int main()
{
    boolean runProgram = true;
    Word keluarprogram = {"KELUAR",6};
    Word kicauCommand = {"KICAU",5};
    while (runProgram)
    {
        printf(">> ");
        STARTWORD();
        //command.tabword = currentWord.tabword  & command.length = currentWord.length
        Word command = currentWord;
        if (isWordEqual(command,keluarprogram))
        {
            fclose(pita);
            runProgram = false;
            printf("keluar program\n");

        }
    }
    return 0;

}


