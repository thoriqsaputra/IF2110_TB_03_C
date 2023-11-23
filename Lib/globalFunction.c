#include "globalFunction.h"
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

int wordToInt(Word kata)
{
    int res = 0;
    int i = 0;
    while (kata.TabWord[i] >= '0' && kata.TabWord[i] <= '9' && i < kata.Length)
    {
        res = res * 10 + (kata.TabWord[i] - '0');
        i++;
    }
    return res;
}
