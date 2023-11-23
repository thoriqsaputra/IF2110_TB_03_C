/* File: utas.h */
/* Definisi ADT utas */

#ifndef __NEWUTAS__
#define __NEWUTAS__

#include "../../ADT/datetime.h"
#include "../../ADT/wordmachine.h"

/* Definisi elemen dan koleksi objek */

typedef struct
{
    int idKicau;
    int idUtas;
    Word text;
    Word author;
    DATETIME datetime;
} Utas;

/* ********** SELEKTOR UTAS********** */
#define IDKICAUUTAS(l) (l).idKicau
#define IDUTAS(l) (l).idUtas
#define TEXTUTAS(l) (l).text
#define AUTHORUTAS(l) (l).author
#define DATETIMEUTAS(l) (l).datetime

typedef struct
{
    Utas *buffer;
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
void loadDrafConfig(char filename[], ListDinUtas *LD);
/*Load Config Pengguna dari pengguna.config, lalu mengassign data data sesuai dengan kebutuhan typedef Pengguna
 */

void addUtas(ListDinUtas *l, Utas u);
/* I.S. l berisi draf, mungkin penuh */
/* F.S. l diisi kicauan baru nEff bertambah 1, capacity draf menyesuaikan*/

/* ********** BOOLEAN ********** */
boolean isFullOfUtas(ListDinUtas l);
/* return true jika penuh */

void deleteLinkedDrafByKicauId(ListDinUtas *l, int idKicauan);

#endif