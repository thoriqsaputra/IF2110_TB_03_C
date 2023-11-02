#include "../../ADT/datetime.h"
#include "../../ADT/wordmachine.h"

#define CAPACITYDRAF 10

typedef struct
{
    int id;
    Word text;
    Word author;
    DATETIME datetime;
} Draf;

typedef struct
{
    Draf buffer[CAPACITYDRAF];
    int capacity;
} ListDrafStatik;

/*
    URUTAN CONFIG DRAF
    Baris utama ke-1, banyaknya draf
    int id;
    Word text;
    Word author;
    DATETIME datetime;

    1 draf perlu 4 baris
*/

void CreateEmptyDraf(ListDrafStatik *l);
// ListUserStatic.capacity = 0

int wordToInt(Word kata);
/*Ubah ADT Word to Int*/

void displayDataDraf(Draf *id);
/*I.S Menulis dari
  F.S
*/
void loadDrafConfig(char filename[], ListDrafStatik *LD);
/*Load Config Pengguna dari pengguna.config, lalu mengassign data data sesuai dengan kebutuhan typedef Pengguna
 */