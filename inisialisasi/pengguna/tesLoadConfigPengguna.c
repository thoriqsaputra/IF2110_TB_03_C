#include "../../ADT/tempRun.h"
#include "pengguna.c"

int main()
{
    
    ListUserStatik LU;
    

    CreateEmptyPengguna(&LU);
    loadPenggunaConfig("../../configs/config-1/pengguna.config",&LU);
    //Nanti rencananya diganti ke listStatik biar enak
    tulisDataPengguna(&LU.buffer[0]);
    tulisDataPengguna(&LU.buffer[1]);
    tulisDataPengguna(&LU.buffer[2]);
    return 0;
}