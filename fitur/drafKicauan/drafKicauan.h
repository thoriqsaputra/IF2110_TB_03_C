/* File: drafKicauan.h */
/* Definisi ADT Draf Kicauan */

#ifndef __DRAFKICAUAN__
#define __DRAFKICAUAN__

#include <stdio.h>
#include "../../inisialisasi/draf/draf.h"
#include "../../inisialisasi/pengguna/pengguna.h"

typedef struct node *Address;
typedef struct node
{
    Draf info;
    Address next;
} Node;

/* Type stack dengan ciri Top: */
typedef struct
{
    Address addrTop; /* alamat Top: elemen puncak */
} DrafKicauan;

/* Selektor */
#define NEXTDRAF(p) (p)->next
#define INFODRAF(p) (p)->info
#define ADDR_TOPDRAF(s) (s).addrTop
#define TOPDRAF(s) (s).addrTop->info

/* Prototype manajemen memori */
Address newNodeDraf(Draf x);
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x,
   atau
   NULL jika alokasi gagal */

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean isEmptyDraf(DrafKicauan s);
/* Mengirim true jika Stack kosong: TOP(s) = NIL */

int lengthDraf(DrafKicauan s);
/* Mengirimkan banyaknya elemen stack. Mengirimkan 0 jika Stack s kosong */

void CreateDrafKicauan(DrafKicauan *s);
/* I.S. sembarang */
/* F.S. Membuat sebuah stack s yang kosong */

void DisplayDraf(DrafKicauan s);
/* Proses : Menuliskan isi Stack, ditulis di antara kurung siku; antara dua elemen
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah,
    atau di belakang, termasuk spasi dan enter */
/* I.S. s boleh kosong */
/* F.S. Jika s tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1 (TOP), 20, 30 akan dicetak: [1,20,30] */
/* Jika Stack kosong : menulis [] */

void pushDraf(DrafKicauan *s, Draf x);
/* Menambahkan x sebagai elemen Stack s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */

void popDraf(DrafKicauan *s, Draf *x);
/* Menghapus Top dari Stack s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */

void buatDraf(DrafKicauan *s, currentUser u, ListDinDraf *l);
/* Command BUAT_DRAF */

void lihatDraf(DrafKicauan *s, ListDinDraf *l, currentUser u);
/* Command LIHAT_DRAF */

void loadDrafKicauan(ListDinDraf l, DrafKicauan *d, currentUser u);
/* Load semua draf yang ada di dalam rawdata yang dipunyai oleh currentUser*/
#endif