#include <stdio.h>

#include "queue.h"

void CreateQueue(Queue *q)
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmptyQueue(Queue q)
{
    return IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF;
}

boolean isFullQueue(Queue q)
{
    return IDX_HEAD(q) == (IDX_TAIL(q) + 1) % CAPACITYQUEUE;
}

int lengthQueue(Queue q)
{
    if (isEmptyQueue(q))
    {
        return 0;
    }
    else
    {
        if (IDX_TAIL(q) == IDX_HEAD(q))
        {
            return 1;
        }
        else if (IDX_TAIL(q) < IDX_HEAD(q))
        {
            return (IDX_TAIL(q) + CAPACITYQUEUE - IDX_HEAD(q) + 1);
        }
        else
        {
            return (IDX_TAIL(q) - IDX_HEAD(q) + 1);
        }
    }
}

void enqueue(Queue *q, ElType val)
{
    if (isEmptyQueue(*q))
    {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        TAIL(*q) = val;
        HEAD(*q) = val;
    }
    else
    {
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITYQUEUE;
        TAIL(*q) = val;
    }
}

void dequeue(Queue *q, ElType *val)
{
    if (lengthQueue(*q) == 1)
    {
        *val = HEAD(*q);
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else
    {
        *val = HEAD(*q);
        IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITYQUEUE;
    }
}

void displayQueue(Queue q)
{
    if (isEmptyQueue(q))
    {
        printf("[]\n");
    }
    else
    {
        printf("[");
        int len = lengthQueue(q), i, temp, thead = IDX_HEAD(q);
        for (i = thead; i < thead + len; i++)
        {
            dequeue(&q, &temp);
            enqueue(&q, temp);
            printf("%d", temp);
            if (i != (thead) + len - 1)
            {
                printf(",");
            }
        }
        printf("]\n");
    }
}