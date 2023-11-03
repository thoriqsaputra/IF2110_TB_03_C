#include "../../ADT/tempRun.h"
#include "draf.c"
int main()
{
    ListDinDraf LD;
    CreateListDraf(&LD, LD.capacity);
    loadDrafConfig("../../configs/config-1/draf.config", &LD);
    printf("Capacity: %d\n", LD.capacity);
    for (int i = 0; i < LD.capacity; i++)
    {
        displayDataDraf(&(LD).buffer[i]);
    }
    Draf temp = {3,
                 {"Hoho", 4},
                 {"Panji", 5},
                 {3, 12, 2020, {9, 37, 12}}};
    addDraf(&LD, temp);
    printf("\n");
    for (int i = 0; i < LD.nEff; i++)
    {
        displayDataDraf(&(LD).buffer[i]);
    }
    printf("Capacity: %d\n", LD.capacity);

    deleteDrafById(&LD, 2);

    printf("\n");
    for (int i = 0; i < LD.nEff; i++)
    {
        displayDataDraf(&(LD).buffer[i]);
    }
    printf("Capacity: %d\n", LD.capacity);
    return 0;
}