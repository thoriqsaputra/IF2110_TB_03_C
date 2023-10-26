#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "listdin.h"

void CreateListDin(ListDin *l, int capacity)
{
    NEFF(*l) = 0;
    BUFFER(*l) = (ElType *)malloc(capacity * sizeof(ElType));
    CAPACITYDINAMIS(*l) = capacity;
}

void dealocateListDin(ListDin *l)
{
    free(BUFFER(*l));
    CAPACITYDINAMIS(*l) = 0;
    NEFF(*l) = 0;
}

int lengthListDin(ListDin l)
{
    return NEFF(l);
}

IdxType getFirstIdxListDin(ListDin l)
{
    return IDX_MIN;
}

IdxType getLastIdxListDin(ListDin l)
{
    return NEFF(l) - 1;
}

boolean isIdxValidListDin(ListDin l, IdxType i)
{
    return (i >= 0) && (i < CAPACITYDINAMIS(l));
}

boolean isIdxEffListDin(ListDin l, IdxType i)
{
    return (i >= 0) && (i < NEFF(l));
}

boolean isEmptyListDin(ListDin l)
{
    return NEFF(l) == 0;
}

boolean isFullListDin(ListDin l)
{
    return NEFF(l) == CAPACITYDINAMIS(l);
}

void readListListDin(ListDin *l)
{
    int n, i, m;
    scanf("%d", &n);
    while (n < 0 || n > CAPACITYDINAMIS(*l))
    {
        scanf("%d", &n);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &m);
        ELMTListDin(*l, i) = m;
    }
    NEFF(*l) = n;
}

void printListListDin(ListDin l)
{
    int i;
    printf("[");
    for (i = 0; i < NEFF(l); i++)
    {
        if (i != NEFF(l) - 1)
        {
            printf("%d,", ELMTListDin(l, i));
        }
        else
        {
            printf("%d", ELMTListDin(l, i));
        }
    }
    printf("]");
}

ListDin plusMinusListDin(ListDin l1, ListDin l2, boolean plus)
{
    int i;
    ListDin temp;
    CreateListDin(&temp, CAPACITYDINAMIS(l1));
    NEFF(temp) = NEFF(l1);
    if (plus)
    {
        for (i = 0; i < NEFF(l1); i++)
        {
            ELMTListDin(temp, i) = ELMTListDin(l1, i) + ELMTListDin(l2, i);
        }
        return temp;
    }
    else
    {
        for (i = 0; i < NEFF(l2); i++)
        {
            ELMTListDin(temp, i) = ELMTListDin(l1, i) - ELMTListDin(l2, i);
        }
        return temp;
    }
}

boolean isListDinEqual(ListDin l1, ListDin l2)
{
    if (NEFF(l1) == NEFF(l2))
    {
        int i;
        for (i = 0; i < NEFF(l1); i++)
        {
            if (ELMTListDin(l1, i) != ELMTListDin(l2, i))
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

IdxType indexOfListDin(ListDin l, ElType val)
{
    int i;
    for (i = 0; i < NEFF(l); i++)
    {
        if (ELMTListDin(l, i) == val)
        {
            return i;
        }
    }
    return IDX_UNDEF;
}

void extremeValuesListDin(ListDin l, ElType *max, ElType *min)
{
    int i;
    *max = ELMTListDin(l, 0);
    *min = ELMTListDin(l, 0);
    for (i = 1; i < NEFF(l); i++)
    {
        if (*max < ELMTListDin(l, i))
        {
            *max = ELMTListDin(l, i);
        }
        if (*min > ELMTListDin(l, i))
        {
            *min = ELMTListDin(l, i);
        }
    }
}
void copyListDin(ListDin lIn, ListDin *lOut)
{
    int i;
    dealocateListDin(lOut);
    CreateListDin(lOut, CAPACITYDINAMIS(lIn));
    NEFF(*lOut) = NEFF(lIn);
    for (i = 0; i < NEFF(lIn); i++)
    {
        ELMTListDin(*lOut, i) = ELMTListDin(lIn, i);
    }
}

ElType sumListDin(ListDin l)
{
    int i;
    ElType sum = 0;
    for (i = 0; i < NEFF(l); i++)
    {
        sum += ELMTListDin(l, i);
    }
    return sum;
}

int countValListDin(ListDin l, ElType val)
{
    int i, sum = 0;
    for (i = 0; i < NEFF(l); i++)
    {
        if (ELMTListDin(l, i) == val)
        {
            sum += 1;
        }
    }
    return sum;
}

void sortListDin(ListDin *l, boolean asc)
{
    int i, j, swapped, temp;
    if (asc)
    {
        for (i = 0; i < lengthListDin(*l) - 1; i++)
        {
            swapped = 0;
            for (j = 0; j < lengthListDin(*l) - i - 1; j++)
            {
                if (ELMTListDin(*l, j) > ELMTListDin(*l, j + 1))
                {
                    temp = ELMTListDin(*l, j);
                    ELMTListDin(*l, j) = ELMTListDin(*l, j + 1);
                    ELMTListDin(*l, j + 1) = temp;
                    swapped = 1;
                }
            }
            if (swapped == 0)
            {
                break;
            }
        }
    }
    else
    {
        for (i = 0; i < lengthListDin(*l) - 1; i++)
        {
            swapped = 0;

            for (int j = 0; j < lengthListDin(*l) - i - 1; j++)
            {
                if (ELMTListDin(*l, j) < ELMTListDin(*l, j + 1))
                {
                    temp = ELMTListDin(*l, j);
                    ELMTListDin(*l, j) = ELMTListDin(*l, j + 1);
                    ELMTListDin(*l, j + 1) = temp;
                    swapped = 1;
                }
            }

            if (swapped == 0)
            {
                break;
            }
        }
    }
}

void insertLastListDin(ListDin *l, ElType val)
{
    ELMTListDin(*l, lengthListDin(*l)) = val;
    NEFF(*l) += 1;
}

void deleteLastListDin(ListDin *l, ElType *val)
{
    *val = ELMTListDin(*l, lengthListDin(*l) - 1);
    NEFF(*l) -= 1;
}

void expandListDin(ListDin *l, int num)
{
    ListDin temp;
    CreateListDin(&temp, CAPACITYDINAMIS(*l) + num);
    CAPACITYDINAMIS(*l) += num;
    copyListDin(*l, &temp);
    free(BUFFER(*l));
    BUFFER(*l) = (ElType *)malloc(CAPACITYDINAMIS(temp) * sizeof(ElType));
    copyListDin(temp, l);
    dealocateListDin(&temp);
}

void shrinkListDin(ListDin *l, int num)
{
    ListDin temp;
    CreateListDin(&temp, CAPACITYDINAMIS(*l) - num);
    CAPACITYDINAMIS(*l) -= num;
    copyListDin(*l, &temp);
    dealocateListDin(l);
    CreateListDin(l, CAPACITYDINAMIS(temp));
    copyListDin(temp, l);
    dealocateListDin(&temp);
}

void compressListDin(ListDin *l)
{
    shrinkListDin(l, CAPACITYDINAMIS(*l) - NEFF(*l));
}