#include "../../ADT/tempRun.h"
#include "kicauan.h"
#include "kicauan.c"

int main()
{
    ListDinKicauan LKD;

    loadKicauanConfig("../../configs/config-1/kicauan.config", &LKD);
    displayKicauan(ELMTKICAUAN(LKD,0));
    displayKicauan(ELMTKICAUAN(LKD,1));
    displayKicauan(ELMTKICAUAN(LKD,2));
    dealocateListKicauan(&LKD);
}

// cara run, masuk dulu ke direktori kicauan lalu di terminal masukkan 
// gcc driverLoadConfigKicauan.c kicauan.c -o driverLoadConfigKicauan