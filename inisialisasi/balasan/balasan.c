#include <stdio.h>
#include <stdlib.h>
#include "balasan.h"

/* ********** KONSTRUKTOR ListBalasan ********** */
/* Konstruktor : create list kosong  */
void CreateListBalasan(ListDinBalasan *l, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity dan diisi KICAUAN */
{
    NEFFBalasan(*l) = 0;
    ContentBalasan(*l) = (Balasan *)malloc(capacity * sizeof(Balasan));
    CAPACITYBalasan(*l) = capacity;
}

void dealocateBalasan(ListDinBalasan *l)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
    free(ContentBalasan(*l));
    NEFFBalasan(*l) = 0;
    CAPACITYBalasan(*l) = 0;
}

// void addBalasan(ListDinBalasan *l, Balasan B)
// /* I.S. l berisi kicauan, mungkin penuh */
// /* F.S. l diisi kicauan baru nEffBalasan bertambah 1, capacity balasan menyesuaikan*/
// {

// }


/* ********** KONSTRUKTOR ListDinBalasan ********** */
/* Konstruktor : create list kosong  */
void CreateListDinB(ListDinListB *lb, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity dan diisi KICAUAN */
{
    NEFFListB(*lb) = 0;
    ContentListB(*lb) = (ListDinBalasan *)malloc(capacity * sizeof(ListDinBalasan));
    CAPACITYListB(*lb) = capacity;
}
void dealocateListDinB(ListDinListB *lb)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
    free(ContentListB(*lb));
    NEFFListB(*lb) = 0;
    CAPACITYListB(*lb) = 0;
}

// void addBalasanKeListDin(ListDinListB *lb, Balasan B);
// /* I.S. l berisi kicauan, mungkin penuh */
// /* F.S. l diisi kicauan baru nEffBalasan bertambah 1, capacity balasan menyesuaikan*/

void loadBalasanConfig(char filename[], ListDinListB *lb)
/* I.S. l kosong; */
/* F.S. l diisi sesuai config */
{
    // Kamus Lokal
    int i, j, CapListB, CapB, IDKicauan;


    // ALGORITMA
    STARTWORDFILE(filename);
    CapListB = wordToInt(currentWord);
    CreateListDinB(lb, CapListB);

    for ( i = 0; i < CAPACITYListB(*lb); i++) {
        ListDinBalasan l;
        ADVWORDFILE();
        IDKicauan = wordToInt(currentWord);
        ADVWORDFILE();
        CapB = wordToInt(currentWord);
        CreateListBalasan(&l, CapB);
        IDKicauB(l) = IDKicauan;

        for (j = 0; j < CAPACITYBalasan(l); j++) {
            ADVWORDFILE();
            IDBalasan(ELMTBalasan(l, j)) = currentWord; //baru dalam Word, perlu dipisah kedua IDs -1 1
            ADVWORDFILE();
            TxtBalasan(ELMTBalasan(l, j)) = currentWord;
            ADVWORDFILE();
            AuthorBalasan(ELMTBalasan(l, j)) = currentWord;
            ADVWORDFILE();
            DatetimeBalasan(ELMTBalasan(l, j)) = currentWord;
        }
        NEFFBalasan(l) = CAPACITYBalasan(l);
        ELMTListB(*lb, i) = l;
    }
    NEFFListB(*lb) = CAPACITYListB(*lb);

}
/* ********** BOOLEAN ********** */
boolean isFullBalasan(ListDinBalasan l)
/* return true jika penuh */
{
    return (NEFFBalasan(l) == CAPACITYBalasan(l));
}
boolean isFullListDinB(ListDinListB lb)
/* return true jika penuh */
{
    return (NEFFListB(lb) == CAPACITYListB(lb));
}

/* ********** FUNGSI LAIN ********** */
void displayBalasan(ListDinBalasan B)
{
    // KAMUS LOKAL
    int i;

    // ALGORITMA
    printf("%d\n",IDKicauB(B));
    printf("%d\n",CAPACITYBalasan(B));
    for (i = 0; i < CAPACITYBalasan(B); i++) {
        printWord(IDBalasan(ELMTBalasan(B, i)));
        printf("\n");
        printWord(TxtBalasan(ELMTBalasan(B, i)));
        printf("\n");
        printWord(AuthorBalasan(ELMTBalasan(B, i)));
        printf("\n");
        printWord(DatetimeBalasan(ELMTBalasan(B, i)));
        printf("\n");
    }
}

void displayListB(ListDinListB lb)
{
    // KAMUS LOKAL
    int i;

    // ALGORITMA
    printf("%d\n", CAPACITYListB(lb));
    for (i = 0; i < CAPACITYListB(lb); i++)
    {
        displayBalasan(ELMTListB(lb, i));
        printf("\n");
    }


}

int wordToInt(Word kata)
{
    int res = 0;
    int i = 0;
    while (kata.TabWord[i] >= '0' && kata.TabWord[i] <= '9' && i < kata.Length) 
    // memeriksa jika char di antara kedua bilangan tersebut (Jika ditambah komen di kanan angka), dan i lebih kecil dari panjang (Jika tidak ada, karena tidak tahu mengapa begitu keluaran 24 untuk ID 2)
    {
        res = res * 10 + (kata.TabWord[i] - '0');
        i++;
    }
    return res;
}