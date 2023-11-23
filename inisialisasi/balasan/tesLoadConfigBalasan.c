#include "balasan.h"
#include "balasan.c"

int main() {
    ListTree LT;
    loadBalasanConfig("../../configs/config-1/balasan.config", &LT);
    PrintTree(LT.ContentListTree[0], 0);

    BALASAN* result = findBalasan(LT, 5, 1);

    if (result != NULL) {
        // Print or use the result as needed
        printWord(result->TextBalasan);
    } else {
        printf("Balasan not found.\n");
    }
    dealocateTrees(&LT);
}