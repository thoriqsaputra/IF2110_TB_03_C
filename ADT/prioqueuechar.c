#include <stdio.h>
#include <stdlib.h>
#include "prioqueuechar.h"

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q){
    return (Head(Q) == Nil && Tail(Q) == Nil);
}

boolean IsFull (PrioQueueChar Q){
    return (NBElmt(Q) == MaxEl(Q));
}

int NBElmt (PrioQueueChar Q){
    return (Tail(Q) - Head(Q) + MaxEl(Q)) % MaxEl(Q) + !IsEmpty(Q);
}


/* *** Kreator *** */
void MakeEmpty (PrioQueueChar * Q, int Max){
    (*Q).T = (infotype*) malloc (sizeof(infotype) * (Max + 1));
    if ((*Q).T == NULL){
        MaxEl(*Q) = 0;
    } else{
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
}


/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q){
    MaxEl(*Q) = 0;
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
    free((*Q).T);
}


/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueChar * Q, infotype X){
    if (IsEmpty(*Q)){
        Head(*Q) = 0;
        Tail(*Q) = 0;
        InfoTail(*Q) = X;
    } else{
        Tail(*Q) = (Tail(*Q) + 1) % MaxEl(*Q);
        InfoTail(*Q) = X;
        
        address i;
        infotype temp;
        for(i = Head(*Q); i != Tail(*Q); i = (i + 1) % MaxEl(*Q)){
            if (Prio(InfoTail(*Q)) < Prio(Elmt(*Q,i))){
                temp = InfoTail(*Q);
                InfoTail(*Q) = Elmt(*Q,i);
                Elmt(*Q,i) = temp;
            }
        }
    }
}

void Dequeue (PrioQueueChar * Q, infotype * X){
    *X = InfoHead(*Q);
    if (NBElmt(*Q) == 1){
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    } else{
        Head(*Q) = (Head(*Q) + 1) % MaxEl(*Q);
    }
}


/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q){
    int i;

    if (!IsEmpty(Q)){
        for (i = Head(Q); i != Tail(Q); i = (i+1) % MaxEl(Q)){
            printf("%d %c\n",Prio(Elmt(Q,i)),Info(Elmt(Q,i)));
        }
        printf("%d %c\n",Prio(Elmt(Q,i)),Info(Elmt(Q,i)));
    }
    
    printf("#\n");
}