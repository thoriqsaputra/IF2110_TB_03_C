#ifndef BALASAN_H
#define BALASAN_H

#include "../../ADT/wordmachine.h"
#include "../../ADT/datetime.h"
#include "../../ADT/tree.h"
#include "../kicauan/kicauan.h"

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define INVALID_ID -999

/* Definisi elemen dan koleksi objek */
typedef struct BALASAN
{
    int idDiBalas;
    int IDBalasan;
    Word TextBalasan;
    Word Author;
    DATETIME DT;
} BALASAN;

/* ********** SELEKTOR BALASAN ********** */
#define idDiBalas(l) (l).idDiBalas
#define IDBalasan(l) (l).IDBalasan
#define TxtBalasan(l) (l).TextBalasan
#define AuthorBalasan(l) (l).Author
#define DatetimeBalasan(l) (l).DT

typedef struct
{
    int IDKicau;
    BALASAN *contentBalasan;
    int capacitybalasan;
    int nEffBalasan;
} ListDinBalasan;

/* ********** SELEKTOR List Dinamis BALASAN ********** */
#define IDKicauB(l) (l).IDKicau
#define ELMTBalasan(l, i) (l).contentBalasan[i]
#define ContentBalasan(l) (l).contentBalasan
#define NEFFBalasan(l) (l).nEffBalasan
#define CAPACITYBalasan(l) (l).capacitybalasan

typedef struct
{
    ListDinBalasan *contentList;
    int capacityList;
    int nEffList;
} ListDinListB;

/************ Selektor List Dinamis ************/
#define ELMTListB(l, i) (l).contentList[i]
#define ContentListB(l) (l).contentList
#define NEFFListB(l) (l).nEffList
#define CAPACITYListB(l) (l).capacityList

/* ********** KONSTRUKTOR ListBalasan ********** */
/* Konstruktor : create list kosong  */
void CreateListBalasan(ListDinBalasan *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity dan diisi BALASAN */

void dealocateBalasan(ListDinBalasan *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int LengthListBalasan(ListDinBalasan l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* ********** OPERASI LAIN ********** */
void copyListDinBalasan(ListDinBalasan lIn, ListDinBalasan *lOut);
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */

BALASAN *getBalasan(ListDinListB *lb, int IDKicauan, int IDBalasan);

void printBalasan(BALASAN B);

/* ********** BOOLEAN ********** */
boolean isFullBalasan(ListDinBalasan l);
/* return true jika penuh */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListDinBalasan(ListDinBalasan *l, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListDinBalasan(ListDinBalasan *l, BALASAN val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yanDg baru */

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListDinBalasan(ListDinBalasan *l, BALASAN *val);
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********** KONSTRUKTOR ListDinBalasan ********** */
/* Konstruktor : create list kosong  */
void CreateListDinB(ListDinListB *lb, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity dan diisi ListBalasan */

void dealocateListDinB(ListDinListB *lb);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int LengthListB(ListDinListB l);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* ********** OPERASI LAIN ********** */
void copyListDinB(ListDinListB lIn, ListDinListB *lOut);
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */

ListDinBalasan *getListDinBalasan(ListDinListB *lb, int IDKicauan);

/* ********** BOOLEAN ********** */
boolean isFullListDinB(ListDinListB lb);
/* return true jika penuh */

boolean isKicauanInList(ListDinListB lb, int IDKicauan);

/* ********* MENGUBAH UKURAN ARRAY ********* */
void expandListDinB(ListDinListB *l, int num);
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLastListDinB(ListDinListB *l, ListDinBalasan val);
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yanDg baru */

/* ********** MENGHAPUS ELEMEN ********** */
void deleteLastListDinB(ListDinListB *l, ListDinBalasan *val);
/* Proses : Menghapus elemen terakhir list */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* CONFIGS ********* */
void loadBalasanConfig(char filename[], ListDinListB *lb, ListTree *LT);
/* I.S. l kosong; */
/* F.S. l diisi sesuai config */

/* ********** FUNGSI LAIN ********** */
void displayBalasan(ListDinBalasan B);

void displayListB(ListDinListB lb);

int wordToInt(Word kata);

#endif