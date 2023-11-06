#include "../../ADT/tempRun.h"
#include "kicauan.h"

int main()
{
    ListDinKicauan LKD;

    loadKicauanConfig("../../configs/config-1/kicauan.config", &LKD);

    for (int i = 0; i < NEFFKICAUAN(LKD); i++)
    {
        displayKicauan(ELMTKICAUAN(LKD,i));
    }

    printf("NEFF = %d\n",NEFFKICAUAN(LKD));
    printf("CAPACITY = %d\n",CAPACITYKICAUAN(LKD));

    dealocateListKicauan(&LKD);
}

// cara run, masuk dulu ke direktori kicauan lalu di terminal masukkan 
// gcc tesLoadConfigKicauan.c kicauan.c -o tesLoadConfigKicauan
// ./tesLoadConfigKicauan