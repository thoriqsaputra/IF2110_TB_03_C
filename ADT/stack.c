#include "stack.h"
#include "boolean.h"

void CreateStack(Stack *S)
{
    Top(*S) = Nil;
}

boolean IsEmptyStack(Stack S)
{
    return Top(S) == Nil;
}

boolean IsFullStack(Stack S)
{
    return Top(S) == MaxST - 1;
}

void Push(Stack *S, infotype X)
{
    Top(*S)++;
    InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, infotype *X) // Menghapus X dari Stack S.
{
    *X = InfoTop(*S);
    Top(*S)--;
}