/* File: kicauan.h */
/* Definisi ADT Kicauan */

#ifndef KICAUAN_H
#define KICAUAN_H

#include "../../ADT/wordmachine.h"
#include "../../ADT/datetime.h"
#include "../pengguna/pengguna.h"

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef struct
{
    int ID;
    Word Text;
    int Like;
    Word Author;
    DATETIME Datetime;
} KICAUAN;

/* ********** SELEKTOR KICAUAN********** */
#define IDKICAUAN(l) (l).ID
#define TEXTKICAUAN(l) (l).Text
#define LIKEKICAUAN(l) (l).Like
#define AUTHORKICAUAN(l) (l).Author
#define DATETIMEKICAUAN(l) (l).Datetime

typedef struct 
{
    KICAUAN *contentKicauan; /* memori tempat penyimpan data KICAUAN (Dinamis maka pakai pointer) */
    int nEffKicauan;       /* >=0, banyaknya elemen efektif */
    int capacityKicauan;   /* ukuran elemen */
} ListDinKicauan;

/* ********** SELEKTOR List Dinamis********** */
#define NEFFKICAUAN(l) (l).nEffKicauan
#define CONTENTKICAUAN(l) (l).contentKicauan
#define ELMTKICAUAN(l, i) (l).contentKicauan[i]
#define CAPACITYKICAUAN(l) (l).capacityKicauan

/* ********** List Dinamis Kicauan Program ********** */
extern ListDinKicauan ListKicauan; 

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListKicauan(ListDinKicauan *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity dan diisi KICAUAN */

void dealocateListKicauan(ListDinKicauan *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

void loadKicauanConfig(char filename[], ListDinKicauan *l);
/* I.S. l kosong; */
/* F.S. l diisi sesuai config */

void addKicauan(ListDinKicauan *l, KICAUAN t);
/* I.S. l berisi kicauan, mungkin penuh */
/* F.S. l diisi kicauan baru nEffKicauan bertambah 1, capacity kicauan menyesuaikan*/

/* ********** BOOLEAN ********** */
boolean isFullOfKicauan(ListDinKicauan l);
/* return true jika penuh */

/* ********** FUNGSI KICAUAN ********** */
KICAUAN createNewKicauan(ListDinKicauan l, Word text, currentUser CU);

void berkicau(ListDinKicauan *l, Word message, currentUser CU);
/* I.S. l terdefinisi; */
/* F.S. anggota l bertambah 1 dengan teks <= 280 kata*/

void likeKicauConfig(ListDinKicauan *l, int ID);
/* I.S. l terdefinisi dan ID valid; */
/* F.S. likes pada kicauan ID bertambah jika dapat diakses (akun tidak private / diperbolehkan) 
        Jika tidak bisa maka akan keluar pesan, "This kicauan is privated"
        Mungkin bisa ditambahin anjuran rquest teman dengan pengarang kicauannya */

void updateKicauan(ListDinKicauan *l, int ID);
/* I.S. l terdefinisi dan ID valid yang dibuat oleh akun sekarang; */
/* F.S. Text diperbaharui */

/* ********** FUNGSI LAIN ********** */
void printWord(Word kata);

void displayKicauan(KICAUAN T);

int wordToInt(Word kata);

void CreateDATETIMEfromWord(DATETIME *D, Word kata);
/* Membentuk sebuah DATETIME dari komponen-komponennya yang valid dari kata */
/* Prekondisi : Format word (DD/MM/YYYY hh:mm:ss) */

#endif