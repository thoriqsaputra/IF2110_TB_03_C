/* File: draf.h */
/* Definisi ADT Draf */

#ifndef __DRAF__
#define __DRAF__

#include "../../ADT/datetime.h"
#include "../../ADT/wordmachine.h"

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef struct
{
  int id;
  Word text;
  Word author;
  DATETIME datetime;
} Draf;

/* ********** SELEKTOR DRAF********** */
#define IDDRAF(l) (l).ID
#define TEXTDRAF(l) (l).Text
#define AUTHORDRAF(l) (l).Author
#define DATETIMEDRAF(l) (l).Datetime

typedef struct
{
  Draf *buffer;
  int nEff;
  int capacity;
} ListDinDraf;

/* ********** SELEKTOR List Dinamis********** */
#define NEFFDRAF(l) (l).nEff
#define BUFFERDRAF(l) (l).buffer
#define ELMTDRAF(l, i) (l).buffer[i]
#define CAPACITYDRAF(l) (l).capacity

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDraf(ListDinDraf *l, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity dan diisi KICAUAN */

void dealocateListDraf(ListDinDraf *l);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

void displayDataDraf(Draf id);
/*I.S Menulis dari
  F.S
*/
void loadDrafConfig(char filename[], ListDinDraf *LD);
/*Load Config Pengguna dari pengguna.config, lalu mengassign data data sesuai dengan kebutuhan typedef Pengguna
 */

void addDraf(ListDinDraf *l, Draf d);
/* I.S. l berisi draf, mungkin penuh */
/* F.S. l diisi kicauan baru nEff bertambah 1, capacity draf menyesuaikan*/

/* ********** BOOLEAN ********** */
boolean isFullOfDraf(ListDinDraf l);
/* return true jika penuh */

void deleteDrafById(ListDinDraf *l, int id);

#endif