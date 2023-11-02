#include "../../ADT/tempRun.h"
#include "balasan.h"
#include "balasan.c"

int main() {
    ListDinListB LB;

    loadBalasanConfig("../../configs/config-1/balasan.config", &LB);
    displayListB(LB);
    dealocateListDinB(&LB);
}