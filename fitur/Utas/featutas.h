#ifndef featUTAS_H
#define featUTAS_H


#include "../../inisialisasi/kicauan/kicauan.h"
#include "../../teman/teman.h"
#include <stdlib.h>
#include "../../ADT/boolean.h"

typedef struct node* Address;

typedef struct {
    Word Utas;
    Word author;
    DATETIME time;
} info_utas;

typedef struct node {
    info_utas infou;
    Address nextu;
} Node_Utas;

typedef Address ListLinUtas;

typedef struct {
    int IDKicau;
    int banyak_utas; 
    Address nextk;
} Utas;

typedef struct
{
   Utas *kontenUtas; /* memori tempat penyimpan elemen (container) */
   int nEffUtas;       /* >=0, banyaknya elemen efektif */
   int capacityUtas;   /* ukuran elemen */
} ListDinUtas;


// List Din //
#define NEFFUTAS(l) (l).nEffUtas
#define KONTENUTAS(l) (l).kontenUtas
#define ELMTUTAS(l, i) (l).kontenUtas[i]
#define CAPACITYUTAS(l) (l).capacityUtas

// List Lin //
//#define IDX_UNDEF_Utas (-1)
//#define FIRST(l) (l)


// Utas //
#define IDK(x) (x).IDKicau
#define N(x) (x).banyak_utas
#define NEXTK(x) (x).nextk

// info_utas //
#define UTAS(x) (x).Utas
#define AUTHORUTAS(p) (p).author
#define TIMEUTAS(x) (x).time

// Node_utas //
#define InfoU(p) (p)->infou
#define NEXTU(p) (p)->nextu
#define FIRSTU(l) (l)


void BUAT_UTAS(int IDKicau,ListDinKicauan *LDK,currentUser cu,ListDinUtas *LDU);

void SAMBUNG_UTAS(int IDUtas,int index,currentUser cu,ListDinUtas *LDU);


void HAPUS_UTAS(int IDUtas, int index,currentUser cu,ListDinUtas *LDU);

void CETAK_UTAS(int IDUtas,currentUser cu,Graph *G,ListUserStatik *LU,ListDinKicauan *LDK,ListDinUtas *LDU);



/* -------------------------------------------------*/
/* ---------- Primitif List Dinamis Utas ---------- */
/* -------------------------------------------------*/

int lengthListDinUtas(ListDinUtas l);

IdxType getLastIdxListDinUtas(ListDinUtas l);

void insertLastListDinUtas(ListDinUtas *l, Utas utas);

boolean isIDKicauTaken(int IDKicauan,ListDinUtas LDU);


/* ------------------------------------------------*/
/* ----------- Fungsi Bantuan Kicauan ------------ */
/* ------------------------------------------------*/

void displayMainKicauan(int IDKicau,ListDinKicauan LK);

boolean isIdxEffListDinKicauan(ListDinKicauan lk, IdxType i);




/* ------------------------------------------------*/
/* ---------- Primitif List Linier Utas ---------- */
/* ------------------------------------------------*/

Address newNodeUtas(info_utas info);

void CreateListLinUtas(ListLinUtas *l);

void InsertUtasAt(ListLinUtas *l, info_utas info, int idx);

void deleteUtasAt(ListLinUtas *l, int idx, info_utas *info);

int lengthListLinUtas(ListLinUtas l);

ListLinUtas concatListLinUtas(ListLinUtas l1, ListLinUtas l2);

void insertFirstListLinUtas(ListLinUtas *l, info_utas data);

void insertLastListLinUtas(ListLinUtas *l, info_utas data);

boolean isEmptyListLinUtas(ListLinUtas l);

/* -----------------------------------------*/
/* ---------- Fungsi-Fungsi Utas ---------- */
/* -----------------------------------------*/

void CreateMainUtas(ListDinUtas *LDU, Utas main);

void TambahUtas(ListLinUtas *LDU,int idx,currentUser cu);

void displayUtas(Utas U);

boolean isWordEqual(Word input, Word cek);


#endif