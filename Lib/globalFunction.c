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