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
    ContentBalasan(*l) = (BALASAN *)malloc(capacity * sizeof(BALASAN));
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

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int LengthListBalasan(ListDinBalasan l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
    return NEFFBalasan(l);
}

/* ********** OPERASI LAIN ********** */
void copyListDinBalasan(ListDinBalasan lIn, ListDinBalasan *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
{
    int i;
    dealocateBalasan(lOut);
    CreateListBalasan(lOut, CAPACITYBalasan(lIn));
    NEFFBalasan(*lOut) = NEFFBalasan(lIn);
    for (i = 0; i < NEFFBalasan(lIn); i++)
    {
        ELMTBalasan(*lOut, i) = ELMTBalasan(lIn, i);
    }
}

BALASAN* getBalasan(ListDinListB *lb, int IDKicauan, int IDBalasan) {

    ListDinBalasan* l = getListDinBalasan(lb, IDKicauan);

    if (l == NULL || IDKicauB(*l) == INVALID_ID) {

        return NULL;
    }

    for (int i = 0; i < NEFFBalasan(*l); i++) {
        if (IDBalasan(ELMTBalasan(*l, i)) == IDBalasan) {
            return &ELMTBalasan(*l, i);
        }
    }

    // Return a special value to indicate not found
    return NULL;
}

/* ********** BOOLEAN ********** */
boolean isFullBalasan(ListDinBalasan l)
/* return true jika penuh */
{
    return (NEFFBalasan(l) == CAPACITYBalasan(l));
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListDinBalasan(ListDinBalasan *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    ListDinBalasan temp;
    CreateListBalasan(&temp, CAPACITYBalasan(*l) + num);
    CAPACITYBalasan(*l) += num;
    copyListDinBalasan(*l, &temp);
    free(ContentBalasan(*l));
    ContentBalasan(*l) = (BALASAN *)malloc(CAPACITYBalasan(temp) * sizeof(BALASAN));
    copyListDinBalasan(temp, l);
    dealocateBalasan(&temp);
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListDinBalasan(ListDinBalasan *l, BALASAN val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yanDg baru */
/* ********** MENGHAPUS ELEMEN ********** */
{
    int nefplus = NEFFBalasan(*l)+1;

    if (nefplus >= CAPACITYBalasan(*l)) {
        expandListDinBalasan(l, 4);
    }
    ELMTBalasan(*l, LengthListBalasan(*l)) = val;
    NEFFBalasan(*l) += 1;
}
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListDinBalasan(ListDinBalasan *l, BALASAN *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
    *val = ELMTBalasan(*l, LengthListBalasan(*l) - 1);
    NEFFBalasan(*l) -= 1;
}

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

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int LengthListB(ListDinListB l)
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */
{
    return NEFFListB(l);
}

/* ********** OPERASI LAIN ********** */
void copyListDinB(ListDinListB lIn, ListDinListB *lOut)
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
{
    int i;
    dealocateListDinB(lOut);
    CreateListDinB(lOut, CAPACITYListB(lIn));
    NEFFListB(*lOut) = NEFFListB(lIn);
    for (i = 0; i < NEFFListB(lIn); i++)
    {
        ELMTListB(*lOut, i) = ELMTListB(lIn, i);
    }
}

ListDinBalasan* getListDinBalasan(ListDinListB *lb, int IDKicauan) {
    
    for (int i = 0; i < NEFFListB(*lb); i++) {
        if (IDKicauB(ELMTListB(*lb, i)) == IDKicauan) {
            return &ELMTListB(*lb, i);
        }
    }

    // Return a special value to indicate not found
    return NULL;
}

/* ********** BOOLEAN ********** */
boolean isFullListDinB(ListDinListB lb)
/* return true jika penuh */
{
    return (NEFFListB(lb) == CAPACITYListB(lb));
}

boolean isKicauanInList(ListDinListB lb, int IDKicauan) {

    for(int i = 0; i < NEFFListB(lb); i++) {
        if(IDKicauB(ELMTListB(lb, i)) == IDKicauan) {
            return true;
        }
    }
    return false;
}

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListDinB(ListDinListB *l, int num)
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */
{
    ListDinListB temp;
    CreateListDinB(&temp, CAPACITYListB(*l) + num);
    CAPACITYListB(*l) += num;
    copyListDinB(*l, &temp);
    free(ContentListB(*l));
    ContentListB(*l) = (ListDinBalasan *)malloc(CAPACITYListB(temp) * sizeof(ListDinBalasan));
    copyListDinB(temp, l);
    dealocateListDinB(&temp);
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListDinB(ListDinListB *l, ListDinBalasan val)
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yanDg baru */
{
    int nefplus = NEFFListB(*l)+1;

    if ( nefplus >= CAPACITYListB(*l)) {
        expandListDinB(l, 4);
    }
    
    ELMTListB(*l, LengthListB(*l)) = val;
    NEFFListB(*l) += 1;
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListDinB(ListDinListB *l, ListDinBalasan *val)
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */
{
    *val = ELMTListB(*l, LengthListB(*l) - 1);
    NEFFListB(*l) -= 1;
}


/* ********* CONFIGS ********* */
void loadBalasanConfig(char filename[], ListDinListB *lb, ListTree *LT)
/* I.S. l kosong; */
/* F.S. l diisi sesuai config */
{
    // Kamus Lokal
    int i, j, CapListB, CapB, IDKicauan;

    // ALGORITMA
    STARTWORDFILE(filename);
    // Mendapatkan jumlah kicaun yang memiliki balasan
    CapListB = wordToInt(currentWord);
    // Membuat list dengan banyaknya kicauan
    CreateListDinB(lb, CapListB);

    for ( i = 0; i < CAPACITYListB(*lb); i++) {
        ListDinBalasan l;
        ADVWORDFILE();
        // Mendapatkan IDKicauan
        IDKicauan = wordToInt(currentWord);
        ADVWORDFILE();
        // Mendapatkan Jumlah balasan pada IDKicauan
        CapB = wordToInt(currentWord);
        // Membuat list dengan banyaknya balasan
        CreateListBalasan(&l, CapB);
        // Menyimpan IDKicauan
        IDKicauB(l) = IDKicauan;
        // Membuat tree baru dan IDKicauan sebagai root
        TreeNode* parent = createNode(IDKicauan);

        // Dalam looping jumlah balasan membaca informasi terkait balasan tersebut
        for (j = 0; j < CAPACITYBalasan(l); j++) {
            ADVWORDFILE();
            // Membaca ID yang dibalas ID balasan
            Word ID = currentWord;
            int currentResult = 0;
            boolean isNegative = false;  
            for (int i = 0; i < ID.Length; i++) {
                if (ID.TabWord[i] == '-') {
                    isNegative = true;  
                } else if (ID.TabWord[i] == ' ') {
                    if (isNegative) {
                        currentResult = -currentResult;  
                        isNegative = false;
                    }
                    // Menyimpan ID yang dibalas
                    idDiBalas(ELMTBalasan(l, j)) = currentResult;
                    currentResult = 0;
                } else {
                    currentResult = currentResult * 10 + (ID.TabWord[i] - '0');
                }
            }
            if (isNegative) {
                currentResult = -currentResult;  
            }
            // Menyimpan ID Balasan
            IDBalasan(ELMTBalasan(l, j)) = currentResult;

            // Membuat node baru sebagai anak dari root ID Kicauan
            TreeNode* Child = createNode(IDBalasan(ELMTBalasan(l,j)));
            
            // Proses pemasukan ke tree dengan menggunakan IDBalasan/IDKicauan
            if (idDiBalas(ELMTBalasan(l, j)) == -1) {
                addChild(parent, Child);
            } else {
                addChild(SearchTree(parent, idDiBalas(ELMTBalasan(l, j))), Child);
            }

            // Lanjut ke txt balasan dst
            ADVWORDFILE();
            TxtBalasan(ELMTBalasan(l, j)) = currentWord;
            ADVWORDFILE();
            AuthorBalasan(ELMTBalasan(l, j)) = currentWord;
            ADVWORDFILE();
            // Membaca DateTime lalu mengubanya ke typdef struct DATETIME
            DATETIME t;
            Word temp = currentWord;
            int DD = (int)(temp.TabWord[0] % 48) * 10 + (int)(temp.TabWord[1] % 48);
            int MM = (int)(temp.TabWord[3] % 48) * 10 + (int)(temp.TabWord[4] % 48);
            int YY = (int)(temp.TabWord[6] % 48) * 1000 + (int)(temp.TabWord[7] % 48) * 100 + (int)(temp.TabWord[8] % 48) * 10 + (int)(temp.TabWord[9] % 48);
            int hh = (int)(temp.TabWord[11] % 48) * 10 + (int)(temp.TabWord[12] % 48);
            int mm = (int)(temp.TabWord[14] % 48) * 10 + (int)(temp.TabWord[15] % 48);
            int ss = (int)(temp.TabWord[17] % 48) * 10 + (int)(temp.TabWord[18] % 48);
            CreateDATETIME(&t, DD, MM, YY, hh, mm, ss);
            DatetimeBalasan(ELMTBalasan(l, j)) = t;

            }
        // Menambahkan tree IDKicauan pada akhir list tree
        insertLastListTree(LT, parent);
        // NEFF jadi jumlah balasan
        NEFFBalasan(l) = CAPACITYBalasan(l);
        // Menyimpang list balasan pada ListB
        ELMTListB(*lb, i) = l;

    }
    // Neff menjadi banyaknya Kicauan yang memiliki balasan
    NEFFListB(*lb) = CAPACITYListB(*lb);
}

void displayConfigBalasan(ListDinBalasan B)
{
    // KAMUS LOKAL
    int i;

    // ALGORITMA
    printf("%d\n",IDKicauB(B));
    printf("%d\n",CAPACITYBalasan(B));
    for (i = 0; i < CAPACITYBalasan(B); i++) {
        printf("%d %d\n", idDiBalas(ELMTBalasan(B,i)), IDBalasan(ELMTBalasan(B,i)));
        printWord(TxtBalasan(ELMTBalasan(B, i)));
        printf("\n");
        printWord(AuthorBalasan(ELMTBalasan(B, i)));
        printf("\n");
        TulisDATETIME(DatetimeBalasan(ELMTBalasan(B, i)));
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
        displayConfigBalasan(ELMTListB(lb, i));
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

