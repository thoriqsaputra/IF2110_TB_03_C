#include "../../ADT/tempRun.h"
#include "kicauan.h"

int main()
{
    ListDinKicauan LKD;
    ListDinKicauan LUser;
    currentUser cUser =  {{"Ertiga", 6}, 3};

    loadKicauanConfig("../../configs/config-1/kicauan.config", &LKD);
    loadKicauanUser(LKD, &LUser, cUser);

    for (int i = 0; i < NEFFKICAUAN(LKD); i++)
    {
        displayKicauan(ELMTKICAUAN(LKD,i));
    }

    printf("NEFF = %d\n",NEFFKICAUAN(LKD));
    printf("CAPACITY = %d\n",CAPACITYKICAUAN(LKD));

    printf("============= TEST ADD =============\n");

    berkicau(&LKD, &LUser, cUser);

    printf("NEFF = %d\n",NEFFKICAUAN(LKD));
    printf("CAPACITY = %d\n",CAPACITYKICAUAN(LKD));

    editKicauanInList(&LKD, &LUser, NEFFKICAUAN(LKD), cUser);

    printf("NEFF = %d\n",NEFFKICAUAN(LKD));
    printf("CAPACITY = %d\n",CAPACITYKICAUAN(LKD));

    displayKicauan(ELMTKICAUAN(LUser,0));

    unloadListKicauan(&LKD);
    fclose(pita);
}

// cara run, masuk dulu ke direktori kicauan lalu di terminal masukkan 
// gcc tesLoadConfigKicauan.c kicauan.c -o tesLoadConfigKicauan
// ./tesLoadConfigKicauan