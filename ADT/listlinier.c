#include "listlinier.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>


Address newNode(ElType val){
    Address p;
    p = (Address) malloc(sizeof(Node));
    if (p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListLin(ListLin *l){
    FIRST(*l) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmptyListLin(ListLin l){
    return FIRST(l) == NULL;
}
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElType getElmtListLin(ListLin l, int idx){
    Address p;
    p =l;
    for (int i =0 ; i<idx; i++){
        p = NEXT(p);
    }
    return INFO(p);
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmtListLin(ListLin *l, int idx, ElType val){
    Address p;
    int ctr;
    p = *l;
    ctr = 0;
    while (ctr<idx){
        ctr++;
        p = NEXT(p);
    }
    INFO(p) = val;
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOfListLin(ListLin l, ElType val){
    int idx;
    Address p;
    boolean found;
    p = l;
    found = false;
    idx = 0;
    while (found == false && p != NULL){
        if (INFO(p) == val){
            found = true;
        }
        else {
            idx++;
            p = NEXT(p);
        }
    }
    if(found){
        return idx;
    }
    else{
        return IDX_UNDEF;
    }
}
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirstListLin(ListLin *l, ElType val){
    Address p;
    p = newNode(val);
    if (p != NULL){
        NEXT(p) = *l;
        *l = p;
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLastListLin(ListLin *l, ElType val){
    Address p,last;
    if(isEmpty(*l)){
        insertFirst(l,val);
    }
    else{
        p = newNode(val);
        if (p != NULL){
            last = *l;
            while (NEXT(last) != NULL){
                last = NEXT(last);
            }
            NEXT(last) = p;
        }
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAtListLin(ListLin *l, ElType val, int idx){
    int ctr;
    Address p,loc;
    if (idx == 0){
        insertFirst(l,val);
    }
    else {
        p = newNode(val);
        if (p != NULL){
            ctr = 0;
            loc = *l;
            while (ctr < idx-1){
                ctr++;
                loc = NEXT(loc);
            }
            NEXT(p) = NEXT(loc);
            NEXT(loc) = p;
        }
    }
}
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirstListLin(ListLin *l, ElType *val){
    Address p;
    p = *l;
    *val = INFO(p);
    *l = NEXT(p);
    free(p);
    
}
/* I.S. ListLin l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */

void deleteLastListLin(ListLin *l, ElType *val){
    Address p,loc;
    p = *l;
    loc = NULL;
    while (NEXT(p) != NULL){
        loc = p;
        p = NEXT(p);
    }
    if (loc == NULL){
        *l = NULL;
    }
    else {
        NEXT(loc) = NULL;
    }
    *val = INFO(p);
    free(p);

}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAtListLin(ListLin *l, int idx, ElType *val){
    int ctr;
    Address p,loc;
    if (idx == 0){
        deleteFirst(l,val);
    }
    else {
        ctr = 0;
        loc = *l;
        while (ctr < idx -1 ){
            ctr++;
            loc = NEXT(loc);
        }
        p = NEXT(loc);
        *val = INFO(p);
        NEXT(loc) = NEXT(p);
        free(p);
    }

}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayListListLin(ListLin l){
    Address p;
    p = l;
    printf("[");
    if (isEmpty(l) == false){
        printf("%d", INFO(p));
        p = NEXT(p);
        while (p != NULL){
            printf(",%d", INFO(p));
            p = NEXT(p);
        }
    }
    printf("]");
}
// void printInfo(ListLin l);
/* I.S. ListLin mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int lengthListLin(ListLin l){
    Address p;
    int ctr;
    ctr = 0;
    p = l;
    while (p != NULL){
        ctr++;
        p = NEXT(p);
    }
    return ctr;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
ListLin concatListLin(ListLin l1, ListLin l2) {
    Address p;
    ListLin l3;
    CreateList(&l3);
    p = l1;
    while (p != NULL){
        insertLast(&l3,INFO(p));
        p = NEXT(p);
    }
    p = l2;
    while (p != NULL){
        insertLast(&l3,INFO(p));
        p = NEXT(p);
    }
    return l3;
}
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */