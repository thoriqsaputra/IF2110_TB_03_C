#include <stdio.h>
#include <stdlib.h>
#include "prioqueuechar.h"

/* ********* Prototype ********* */
boolean IsEmptyPrio (PrioQueueChar Q){
    return (HeadPrioQ(Q) == Nil && TailPrioQ(Q) == Nil);
}

boolean IsFullPrio (PrioQueueChar Q){
    return (NBElmtPrio(Q) == MaxPQ(Q));
}

int NBElmtPrio (PrioQueueChar Q){
    return (TailPrioQ(Q) - HeadPrioQ(Q) + MaxPQ(Q)) % MaxPQ(Q) + !IsEmptyPrio(Q);
}


/* *** Kreator *** */
void MakeEmptyPrio (PrioQueueChar * Q, int Max){
    (*Q).T = (infotypePQ*) malloc (sizeof(infotypePQ) * (Max + 1));
    if ((*Q).T == NULL){
        MaxPQ(*Q) = 0;
    } else{
        MaxPQ(*Q) = Max;
        HeadPrioQ(*Q) = Nil;
        TailPrioQ(*Q) = Nil;
    }
}


/* *** Destruktor *** */
void DeAlokasiPrio(PrioQueueChar * Q){
    MaxPQ(*Q) = 0;
    HeadPrioQ(*Q) = Nil;
    TailPrioQ(*Q) = Nil;
    free((*Q).T);
}


/* *** Primitif Add/Delete *** */
void EnqueuePrio (PrioQueueChar * Q, infotypePQ X){
    if (IsEmptyPrio(*Q)){
        HeadPrioQ(*Q) = 0;
        TailPrioQ(*Q) = 0;
        InfoTailPrioQ(*Q) = X;
    } else{
        TailPrioQ(*Q) = (TailPrioQ(*Q) + 1) % MaxPQ(*Q);
        InfoTailPrioQ(*Q) = X;
        
        address i;
        infotypePQ temp;
        for(i = HeadPrioQ(*Q); i != TailPrioQ(*Q); i = (i + 1) % MaxPQ(*Q)){
            if (Prio(InfoTailPrioQ(*Q)) > Prio(ElmtPrioQ(*Q,i))){
                temp = InfoTailPrioQ(*Q);
                InfoTailPrioQ(*Q) = ElmtPrioQ(*Q,i);
                ElmtPrioQ(*Q,i) = temp;
            }
        }
    }
}

void DequeuePrio (PrioQueueChar * Q, infotypePQ * X){
    *X = InfoHeadPrioQ(*Q);
    if (NBElmtPrio(*Q) == 1){
        HeadPrioQ(*Q) = Nil;
        TailPrioQ(*Q) = Nil;
    } else{
        HeadPrioQ(*Q) = (HeadPrioQ(*Q) + 1) % MaxPQ(*Q);
    }
}


/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q){
    int i;

    if (!IsEmptyPrio(Q)){
        for (i = HeadPrioQ(Q); i != TailPrioQ(Q); i = (i+1) % MaxPQ(Q)){
            printf("%d %c\n",Prio(ElmtPrioQ(Q,i)),InfoPrioQ(ElmtPrioQ(Q,i)));
        }
        printf("%d %c\n",Prio(ElmtPrioQ(Q,i)),InfoPrioQ(ElmtPrioQ(Q,i)));
    }
    
    printf("#\n");
}