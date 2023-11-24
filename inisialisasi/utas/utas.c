#include <stdio.h>
#include <stdlib.h>
#include "utas.h"

void CreateListUtas(ListDinUtas *l, int capacity)
{
    NEFFUTAS(*l) = 0;
    BUFFERUTAS(*l) = (ListLinUtas *)malloc(capacity * sizeof(ListLinUtas));
    CAPACITYUTAS(*l) = capacity;
}

void dealocateListUtas(ListDinUtas *l)
{
    free(BUFFERUTAS(*l));
    NEFFUTAS(*l) = 0;
    CAPACITYUTAS(*l) = 0;
}

void displayDataUtas(Utas id)
{
    printf("Index: %d\n", IDXUTAS(id));
    printf("Text: ");
    printWord(TEXTUTAS(id));
    printf("\n");
    printf("Author: ");
    printWord(AUTHORUTAS(id));
    printf("\n");
    printf("Datetime: ");
    TulisDATETIME((id).datetime);
    printf("\n");
}

void loadUtasConfig(char filename[], ListDinUtas *LD)
{
    STARTWORDFILE(filename);
    int total = currentWord.TabWord[0] % 48;
    if (total > 0)
    {
        ADVWORDFILE();
        for (int i = 0; i < total; i++)
        {
            ListLinUtas lku;
            // printf("%d\n", total);
            CreateListLinUtas(&lku);
            int idKicau = currentWord.TabWord[0] % 48;
            int idUtas = i + 1;
            ADVWORDFILE();
            int banyakUtas = currentWord.TabWord[0] % 48;
            ADVWORDFILE();
            for (int j = 0; j < banyakUtas; j++)
            {
                Utas utas;
                utas.index = j + 1;
                utas.text = currentWord;
                ADVWORDFILE();
                utas.author = currentWord;
                ADVWORDFILE();
                DATETIME t;
                Word temp = currentWord;
                int DD = (int)(temp.TabWord[0] % 48) * 10 + (int)(temp.TabWord[1] % 48);
                int MM = (int)(temp.TabWord[3] % 48) * 10 + (int)(temp.TabWord[4] % 48);
                int YY = (int)(temp.TabWord[6] % 48) * 1000 + (int)(temp.TabWord[7] % 48) * 100 + (int)(temp.TabWord[8] % 48) * 10 + (int)(temp.TabWord[9] % 48);
                int hh = (int)(temp.TabWord[11] % 48) * 10 + (int)(temp.TabWord[12] % 48);
                int mm = (int)(temp.TabWord[14] % 48) * 10 + (int)(temp.TabWord[15] % 48);
                int ss = (int)(temp.TabWord[17] % 48) * 10 + (int)(temp.TabWord[18] % 48);
                CreateDATETIME(&t, DD, MM, YY, hh, mm, ss);
                utas.datetime = t;
                // displayDataUtas(utas);
                if (j != banyakUtas - 1)
                {
                    ADVWORDFILE();
                }
                insertLastListLinUtas(&lku, utas, idKicau, idUtas);
            }
            if (i != total - 1)
            {
                ADVWORDFILE();
            }
            addLinkedUtas(LD, lku);
        }
    }
}

void addLinkedUtas(ListDinUtas *l, ListLinUtas lkd)
{
    if (isFullOfLinkedUtas(*l))
    {
        if (CAPACITYUTAS(*l) == 0)
        {
            CAPACITYUTAS(*l) = 1;
            BUFFERUTAS(*l) = (ListLinUtas *)malloc(CAPACITYUTAS(*l) * sizeof(ListLinUtas));
        }
        else
        {
            CAPACITYUTAS(*l) *= 2;
            BUFFERUTAS(*l) = (ListLinUtas *)realloc(BUFFERUTAS(*l), CAPACITYUTAS(*l) * sizeof(ListLinUtas));
        }
    }
    ELMTUTAS(*l, NEFFUTAS(*l)) = lkd;
    NEFFUTAS(*l) += 1;
}

boolean isFullOfLinkedUtas(ListDinUtas l)
{
    return (NEFFUTAS(l) == CAPACITYUTAS(l));
}

void deleteLinkedDrafByIdUtas(ListDinUtas *l, int id)
{
    int i = 0;
    while (i < NEFFUTAS(*l))
    {
        if ((*l).buffer[i]->idKicau == id)
        {
            for (int j = i; j < NEFFUTAS(*l) - 1; j++)
            {
                ELMTUTAS(*l, j) = ELMTUTAS(*l, j + 1);
            }
            NEFFUTAS(*l) -= 1;
        }
        else
        {
            i++;
        }
    }
}

AddressUtas newNodeUtas(Utas val, int idKicau, int idUtas)
{
    AddressUtas p;
    p = (AddressUtas)malloc(sizeof(NodeUtas));
    if (p != NULL)
    {
        INFOUTAS(p) = val;
        NEXTUTAS(p) = NULL;
    }
    return p;
}

void CreateListLinUtas(ListLinUtas *l)
{
    FIRSTUTAS(*l) = NULL;
}

boolean isEmptyListLinUtas(ListLinUtas l)
{
    return FIRSTUTAS(l) == NULL;
}

Utas getElmtUtas(ListLinUtas l, int idx)
{
    AddressUtas p;
    p = l;
    for (int i = 0; i < idx; i++)
    {
        p = NEXTUTAS(p);
    }
    return INFOUTAS(p);
}

void setElmtListLinUtas(ListLinUtas *l, int idx, Utas val)
{
    AddressUtas p;
    int ctr;
    p = *l;
    ctr = 0;
    while (ctr < idx)
    {
        ctr++;
        p = NEXTUTAS(p);
    }
    INFOUTAS(p) = val;
}

void insertLastListLinUtas(ListLinUtas *l, Utas val, int idKicau, int idUtas)
{
    AddressUtas p, last;
    p = newNodeUtas(val, idKicau, idUtas);
    if (p != NULL)
    {
        if (isEmptyListLinUtas(*l))
        {
            FIRSTUTAS(*l) = p;
        }
        else
        {
            last = FIRSTUTAS(*l);
            while (NEXTUTAS(last) != NULL)
            {
                last = NEXTUTAS(last);
            }
            NEXTUTAS(last) = p;
        }
    }
}

void insertAtListLinUtas(ListLinUtas *l, Utas val, int idx, int idKicau, int idUtas)
{
    AddressUtas p, prev;
    int ctr;
    p = newNodeUtas(val, idKicau, idUtas);
    if (p != NULL)
    {
        if (idx == 0)
        {
            NEXTUTAS(p) = FIRSTUTAS(*l);
            FIRSTUTAS(*l) = p;
        }
        else
        {
            prev = FIRSTUTAS(*l);
            ctr = 0;
            while (ctr < idx - 1)
            {
                ctr++;
                prev = NEXTUTAS(prev);
            }
            NEXTUTAS(p) = NEXTUTAS(prev);
            NEXTUTAS(prev) = p;
        }
    }
}

void deleteAtListLinUtas(ListLinUtas *l, int idx, Utas *val)
{
    AddressUtas p, prev;
    int ctr;
    if (idx == 0)
    {
        p = FIRSTUTAS(*l);
        *val = INFOUTAS(p);
        FIRSTUTAS(*l) = NEXTUTAS(p);
        free(p);
    }
    else
    {
        prev = FIRSTUTAS(*l);
        ctr = 0;
        while (ctr < idx - 1)
        {
            ctr++;
            prev = NEXTUTAS(prev);
        }
        p = NEXTUTAS(prev);
        *val = INFOUTAS(p);
        NEXTUTAS(prev) = NEXTUTAS(p);
        free(p);
    }
}

int lengthListLinUtas(ListLinUtas l)
{
    AddressUtas p;
    int ctr;
    p = FIRSTUTAS(l);
    ctr = 0;
    while (p != NULL)
    {
        ctr++;
        p = NEXTUTAS(p);
    }
    return ctr;
}

void displayListLinUtas(ListLinUtas l)
{
    AddressUtas p;
    p = FIRSTUTAS(l);
    while (p != NULL)
    {
        displayDataUtas(INFOUTAS(p));
        p = NEXTUTAS(p);
    }
}

boolean isuserauthor(ListDinUtas LD, int idutas, currentUser cu)
{
    Word user;
    boolean check;
    int i;
    ListLinUtas LU;

    check = false;
    LU = getlistUtasbyid(LD, idutas);
    if (LU != NULL)
    {
        if (isWordEqual(LU->info.author, cu.nama))
        {
            check = true;
        }
    }
    return check;
}

ListLinUtas getlistUtasbyid(ListDinUtas LD, int idutas)
{
    int capacity, i;
    boolean found;
    ListLinUtas LU;

    capacity = LD.capacity;
    found = false;
    while (i < capacity && !found)
    {
        if (ELMTUTAS(LD, idutas)->idUtas == idutas)
        {
            found = true;
            LU = LD.buffer[i];
        }
        else
        {
            i++;
        }
    }
    if (found)
    {
        return LU;
    }
    else
    {
        return NULL;
    }
}

void buatUtas(int idKicau, ListDinUtas *LD, ListDinKicauan LK, currentUser u)
{
    ListDinKicauan LKU;
    Word masukan = {"YA", 2};
    Word ya = {"YA", 2};
    loadKicauanUser(LK, &LKU, u);
    boolean punya = false;
    for (int i = 0; i < LKU.nEffKicauan; i++)
    {
        if (LKU.contentKicauan[i].ID == idKicau)
        {
            punya = true;
        }
    }
    if (punya)
    {
        ListLinUtas LLU;
        CreateListLinUtas(&LLU);
        int i = 1;
        while (isWordEqual(masukan, ya))
        {
            printf("Utas berhasil dibuat!\n\n");
            printf("Masukkan kicauan:\n");
            STARTWORDINPUT();
            masukan = currentWord;
            Utas new = {i,
                        masukan,
                        u.nama,
                        grabCurrentDateTime()};
            insertLastListLinUtas(&LLU, new, idKicau, LKU.nEffKicauan);
            printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK) ");
            STARTWORDINPUT();
            masukan = currentWord;
            i++;
        }
        addLinkedUtas(LD, LLU);
    }
    else
    {
        printf("Utas ini bukan milik anda!");
    }
}

void sambungUtas(ListDinUtas *LD, int idUtas, int idx, currentUser u)
{
    ListLinUtas LLU;
    int i;

    LLU = getlistUtasbyid(*LD, idUtas);
    if (LLU == NULL)
    {
        printf("Utas tidak ditemukan!\n");
    }
    else
    {
        if (!isuserauthor(*LD, idUtas, u))
        {
            printf("Anda tidak bisa menyambung utas ini!\n");
        }
        else
        {
            if (!(idx > 0 && idx < lengthListLinUtas(LLU)))
            {
                printf("Index terlalu tinggi!\n");
            }
            else
            {
                printf("Masukkan kicauan:\n");
                STARTWORDINPUT();
                Word masukan = currentWord;
                Utas new = {lengthListLinUtas(LLU) + 1,
                            masukan,
                            u.nama,
                            grabCurrentDateTime()};
                insertAtListLinUtas(&LLU, new, idx, LLU->idKicau, LLU->idUtas);
                printf("Utas berhasil disambung!\n");
            }
            LD->buffer[i] = LLU;
        }
    }
}

void hapusUtas(ListLinUtas LLU, ListDinUtas *LD, int idUtas, int idx, currentUser u)
{
    int i;
    ListLinUtas LU;

    LU = getlistUtasbyid(*LD,idUtas);
    if(LU == NULL){
        printf("Utas tidak ditemukan\n");
    }
    else{
        if(!isuserauthor(*LD,idUtas,u)){
            printf("Anda tidak bisa menghapus kicauan dalam utas ini!\n");
        }
        else{
            if (idx == 0){
                printf("Anda tidak bisa menghapus kicauan utama!\n");
            }
            else{
                if (!(idx >= 0 && idx < lengthListLinUtas(LLU)))
                {
                    printf("Kicauan sambungan dengan index %d tidak ditemukan pada utas\n",idx);
                }
                else
                {
                    Utas val;
                    deleteAtListLinUtas(&LLU, idx, &val);
                    printf("Kicauan sambungan berhasil dihapus!\n");
                }
                LD->buffer[i] = LLU;
            } 
        }
    }
}

void cetakUtas(ListDinUtas LD, int idUtas, ListDinKicauan LK)
{
    for (int i = 0; i < LD.nEff; i++)
    {
        if (idUtas == LD.buffer[i]->idUtas)
        {
            KICAUAN k;
            for (int j = 0; j < LK.nEffKicauan; j++)
            {
                if (LK.contentKicauan[j].ID == LD.buffer[i]->idKicau)
                {
                    k = LK.contentKicauan[j];
                }
            }
            displayKicauan(k);
            printf("\n");
            displayListLinUtas(LD.buffer[i]);
        }
    }
}