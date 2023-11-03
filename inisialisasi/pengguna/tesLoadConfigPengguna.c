#include "../../ADT/tempRun.h"
#include "pengguna.c"

int main()
{
    
    ListUserStatik LU;
    

    CreateEmptyPengguna(&LU);
    loadPenggunaConfig("../../configs/config-1/pengguna.config",&LU);
    //Nanti rencananya diganti ke listStatik biar enak
    for (int i = 0; i < LU.capacity; i++)
    {
        tulisDataPengguna(&LU.buffer[i]);
        
    }

    return 0;
}