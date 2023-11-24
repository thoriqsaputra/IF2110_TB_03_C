/* File: utas.h */
/* Definisi ADT Utas */

#ifndef __UTAS__
#define __UTAS__

#include "../../ADT/datetime.h"
#include "../../ADT/wordmachine.h"
#include "../../inisialisasi/pengguna/pengguna.h"
#include "../../inisialisasi/kicauan/kicauan.h"
#include "../../Lib/globalFunction.h"

/* Definisi elemen dan koleksi objek */

typedef struct
{
    int index;
    Word text;
    Word author;
    DATETIME datetime;
} Utas;

/* ********** SELEKTOR UTAS********** */
#define IDXUTAS(l) (l).index
#define TEXTUTAS(l) (l).text
#define AUTHORUTAS(l) (l).author
#define DATETIMEUTAS(l) (l).datetime

typedef struct nodeUtas *AddressUtas;

typedef struct nodeUtas
{
    int idKicau;
    int idUtas;
    Utas info;
    AddressUtas next;
} NodeUtas;

#define INFOUTAS(p) (p)->info
#define NEXTUTAS(p) (p)->next

AddressUtas newNodeUtas(Utas val, int idKicau, int idUtas);

typedef AddressUtas ListLinUtas;

// #define IDX_UNDEF (-1)
#define FIRSTUTAS(l) (l)

typedef struct
{
    ListLinUtas *buffer;
    int nEff;
    int capacity;
} ListDinUtas;

/* ********** SELEKTOR List Dinamis********** */
#define NEFFUTAS(l) (l).nEff
#define BUFFERUTAS(l) (l).buffer
#define ELMTUTAS(l, i) (l).buffer[i]
#define CAPACITYUTAS(l) (l).capacity

/* ********** LIST DINAMIS UTAS ********** */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListUtas(ListDinUtas *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity dan diisi KICAUAN */

void dealocateListUtas(ListDinUtas *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

void displayDataUtas(Utas id);
/*I.S Menulis dari
  F.S
*/
void loadUtasConfig(char filename[], ListDinUtas *LD);
/*Load Config Pengguna dari pengguna.config, lalu mengassign data data sesuai dengan kebutuhan typedef Pengguna
 */

void addLinkedUtas(ListDinUtas *l, ListLinUtas lkd);
/* I.S. l berisi draf, mungkin penuh */
/* F.S. l diisi kicauan baru nEff bertambah 1, capacity draf menyesuaikan*/

/* ********** BOOLEAN ********** */
boolean isFullOfLinkedUtas(ListDinUtas l);
/* return true jika penuh */

boolean isuserauthor(ListDinUtas LD, int idutas, currentUser cu);

ListLinUtas getlistUtasbyid(ListDinUtas LD, int idutas); /*return NULL jika tidak ditemukan*/

void deleteLinkedDrafByIdUtas(ListDinUtas *l, int idKicauan);

/* ********** LIST LINIER UTAS ********** */
void CreateListLinUtas(ListLinUtas *lku);

boolean isEmptyListLinUtas(ListLinUtas lku);

Utas getElmtUtas(ListLinUtas lku, int idx);

void setElmtListLinUtas(ListLinUtas *lku, int idx, Utas val);

void insertLastListLinUtas(ListLinUtas *lku, Utas val, int idKicau, int idUtas);

void insertAtListLinUtas(ListLinUtas *lku, Utas val, int idx, int idKicau, int idUtas);

void deleteAtListLinUtas(ListLinUtas *lku, int idx, Utas *val);

int lengthListLinUtas(ListLinUtas lku);

void displayListLinUtas(ListLinUtas l);

// Fitur

void buatUtas(int idKicau, ListDinUtas *LD, ListDinKicauan LK, currentUser u);

void sambungUtas(ListDinUtas *LD, int idUtas, int idx, currentUser u);

void hapusUtas(ListLinUtas LLU, ListDinUtas *LD, int idUtas, int idx, currentUser u);

void cetakUtas(ListDinUtas LD, int idUtas, ListDinKicauan LK);

/* ********** NODE UTAS ********** */

#endif