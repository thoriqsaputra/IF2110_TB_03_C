#include "../../ADT/tempRun.h"
#include "utas.c"
#include "../../inisialisasi/kicauan/kicauan.c"

int main()
{
    ListDinUtas LU;
    CreateListUtas(&LU, 5);
    loadUtasConfig("../../configs/config-1/utas.config", &LU);
    for (int i = 0; i < NEFFUTAS(LU); i++)
    {
        displayListLinUtas(LU.buffer[i]);
        printf("\n");
    }
    return 0;
}