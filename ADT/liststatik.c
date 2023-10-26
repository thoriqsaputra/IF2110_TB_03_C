#include <stdio.h>
#include <math.h>

#include "liststatik.h"

void CreateListStatik(ListStatik *l)
{
    int i;
    for (i = 0; i < CAPACITYSTATIK; i++)
    {
        ELMTListStatik(*l, i) = MARK;
    }
}

int listLengthListStatik(ListStatik l)
{
    int i = 0, panjang = 0;
    while (ELMTListStatik(l, i) != MARK && i < CAPACITYSTATIK)
    {
        panjang += 1;
        i += 1;
    }
    return panjang;
}

IdxType getFirstIdxListStatik(ListStatik l)
{
    return IDX_MIN;
}

IdxType getLastIdxListStatik(ListStatik l)
{
    return (listLengthListStatik(l) - 1);
}

boolean isIdxValidListStatik(ListStatik l, IdxType i)
{
    return (i >= 0 && i < CAPACITYSTATIK);
}

boolean isIdxEffListStatik(ListStatik l, IdxType i)
{
    return (i >= 0 && i < listLengthListStatik(l));
}

boolean isEmptyListStatik(ListStatik l)
{
    return (ELMTListStatik(l, 0) == MARK);
}

boolean isFullListStatik(ListStatik l)
{
    return (ELMTListStatik(l, CAPACITYSTATIK - 1) != MARK);
}

void readListStatik(ListStatik *l)
{
    CreateListStatik(l);
    int n, i, m;
    scanf("%d", &n);
    while (n < 0 || n > CAPACITYSTATIK)
    {
        scanf("%d", &n);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &m);
        ELMTListStatik(*l, i) = m;
    }
}

void printListStatik(ListStatik l)
{
    int i;
    printf("[");
    for (i = 0; i < listLengthListStatik(l); i++)
    {
        printf("%d", ELMTListStatik(l, i));
        if (i != (listLengthListStatik(l) - 1))
        {
            printf(",");
        }
    }
    printf("]");
}

ListStatik plusMinusListStatik(ListStatik l1, ListStatik l2, boolean plus)
{
    int i;
    if (plus)
    {
        for (i = 0; i < listLengthListStatik(l1); i++)
        {
            ELMTListStatik(l1, i) += ELMTListStatik(l2, i);
        }
    }
    else
    {
        for (i = 0; i < listLengthListStatik(l1); i++)
        {
            ELMTListStatik(l1, i) -= ELMTListStatik(l2, i);
        }
    }
    return l1;
}

boolean isListEqualListStatik(ListStatik l1, ListStatik l2)
{
    boolean sama = true;
    int i;
    if (listLengthListStatik(l1) == listLengthListStatik(l2))
    {
        for (i = 0; i < listLengthListStatik(l1); i++)
        {
            if (ELMTListStatik(l1, i) != ELMTListStatik(l2, i))
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

int indexOfListStatik(ListStatik l, ElType val)
{
    int i;
    for (i = 0; i < listLengthListStatik(l); i++)
    {
        if (ELMTListStatik(l, i) == val)
        {
            return i;
        }
    }
    return IDX_UNDEF;
}

void extremeValues(ListStatik l, ElType *max, ElType *min)
{
    int i;
    *max = ELMTListStatik(l, 0);
    *min = ELMTListStatik(l, 0);
    for (i = 1; i < listLengthListStatik(l); i++)
    {
        if (ELMTListStatik(l, i) > *max)
        {
            *max = ELMTListStatik(l, i);
        }
        if (ELMTListStatik(l, i) < *min)
        {
            *min = ELMTListStatik(l, i);
        }
    }
}

void insertFirstListStatik(ListStatik *l, ElType val)
{
    int i;
    for (i = listLengthListStatik(*l); i > 0; i--)
    {
        ELMTListStatik(*l, i) = ELMTListStatik(*l, i - 1);
    }

    ELMTListStatik(*l, 0) = val;
}

void insertAtListStatik(ListStatik *l, ElType val, IdxType idx)
{
    int i;
    for (i = listLengthListStatik(*l); i > idx - 1; i--)
    {
        ELMTListStatik(*l, i) = ELMTListStatik(*l, i - 1);
    }
    ELMTListStatik(*l, idx) = val;
}

void insertLastListStatik(ListStatik *l, ElType val)
{
    ELMTListStatik(*l, listLengthListStatik(*l)) = val;
}

void deleteFirstListStatik(ListStatik *l, ElType *val)
{
    int i;
    *val = ELMTListStatik(*l, 0);
    for (i = 0; i < listLengthListStatik(*l) - 1; i++)
    {
        ELMTListStatik(*l, i) = ELMTListStatik(*l, i + 1);
    }
    ELMTListStatik(*l, listLengthListStatik(*l) - 1) = MARK;
}

void deleteAtListStatik(ListStatik *l, ElType *val, IdxType idx)
{
    int i;
    *val = ELMTListStatik(*l, idx);
    for (i = idx; i < listLengthListStatik(*l) - 1; i++)
    {
        ELMTListStatik(*l, i) = ELMTListStatik(*l, i + 1);
    }
    ELMTListStatik(*l, listLengthListStatik(*l) - 1) = MARK;
}

void deleteLast(ListStatik *l, ElType *val)
{
    *val = ELMTListStatik(*l, listLengthListStatik(*l) - 1);
    ELMTListStatik(*l, listLengthListStatik(*l) - 1) = MARK;
}

void sortListStatik(ListStatik *l, boolean asc)
{
    int i, j, swapped, temp;
    if (asc == true)
    {
        for (i = 0; i < listLengthListStatik(*l) - 1; i++)
        {
            swapped = 0;
            for (j = 0; j < listLengthListStatik(*l) - i - 1; j++)
            {
                if (ELMTListStatik(*l, j) > ELMTListStatik(*l, j + 1))
                {
                    temp = ELMTListStatik(*l, j);
                    ELMTListStatik(*l, j) = ELMTListStatik(*l, j + 1);
                    ELMTListStatik(*l, j + 1) = temp;
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
        for (i = 0; i < listLengthListStatik(*l) - 1; i++)
        {
            swapped = 0;

            for (int j = 0; j < listLengthListStatik(*l) - i - 1; j++)
            {
                if (ELMTListStatik(*l, j) < ELMTListStatik(*l, j + 1))
                {
                    temp = ELMTListStatik(*l, j);
                    ELMTListStatik(*l, j) = ELMTListStatik(*l, j + 1);
                    ELMTListStatik(*l, j + 1) = temp;
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