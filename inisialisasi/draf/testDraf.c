#include "../../ADT/tempRun.h"
#include "draf.c"
int main()
{
    ListDrafStatik LD;
    CreateEmptyDraf(&LD);
    loadDrafConfig("../../configs/config-1/draf.config", &LD);
    printf("Capacity: %d\n", LD.capacity);
    for (int i = 0; i < LD.capacity; i++)
    {
        displayDataDraf(&(LD).buffer[i]);
    }
    return 0;
}