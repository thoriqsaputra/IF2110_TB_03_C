#include "../../ADT/wordmachine.h"
#include "../../ADT/matrix.h"
/*
ListUserStatik menggunakan dasar dari listatik, karena ListUser ini terdiri merupakan array statis dari ElTypePengguna (maks 20)
listWord juga menggunakan dasar dari listatik
*/

#define CAPACITYUSER 20
#define IDX_TAIL(q) (q).idxTail
#define NAMA_USER(l, q) (l).buffer[q].nama
#define PASSWORD_USER(l, q) (l).buffer[q].password
#define BIO_USER(l, q) (l).buffer[q].bio
#define NOHP_USER(l, q) (l).buffer[q].noHp
#define WETON_USER(l, q) (l).buffer[q].weton
#define JENIS_USER(l, q) (l).buffer[q].jenisAkun
#define FOTO_USER(l, q) (l).buffer[q].fotoProfil
#define UserCount(l) (l).capacity
#define idUser(c) (c).idUser
#define nameUser(c) (c).nama
// l -> LU (ListUserStatik)  c -> CU (currentUser)
typedef struct
{
    Word nama;
    Word password;
    Word bio;
    Word noHp;
    Word weton;
    Word jenisAkun;
    Matrix fotoProfil;
} Pengguna;

typedef struct
{
    Pengguna buffer[20]; // maks user 20
    int capacity;
} ListUserStatik;
typedef struct
{
    Word contents[10000]; /* memori tempat penyimpan elemen (container) , coba coba temp 10rb */
} listWord;
typedef struct
{
    Word nama;
    int idUser; // id user di LU
    // ListDin ListofKicauan
} currentUser;

/*
    URUTAN CONFIG PENGGUNA
    Baris Utama ke-1 = banyaknya pengguna (int)
    Word nama; -2
    Word password; -3
    Word bio; -4
    Word noHp; -5
    Word weton; -6
    Word jenisAkun; -7
    Matrix fotoProfil; (ukuran 5x5) jadi 5 baris (matrix 5x5)


    brarti, 1 pengguna  itu perlu  11 baris (1+1+1+1+1+1+5)
    kelipatan 11 , mod 11
    di paling akhir, ada matrix pertemanan dan permintaan teman
*/



//=====================DEKLARASI==============================

void CreateEmptyPengguna(ListUserStatik *l);
// ListUserStatic.capacity = 0

void CreateEmptyCurrentUser(currentUser *CU);

//===================GETTER============================

int getUserIdCurrent(currentUser CU, ListUserStatik LU);

int getUserId(Word inputNama, ListUserStatik LU);

//========================UTILITY==========================
void printWord(Word kata);
/*Print ADT Word*/

int wordToInt(Word kata);
/*Ubah ADT Word to Int*/

void tulisDataPengguna(Pengguna *user);
/*I.S Menulis dari
  F.S
*/
void getInputProfil();

boolean cekSameNama(ListUserStatik LU, Word inputWord);

boolean isWordEqual(Word input, Word cek);
// cek word sama
boolean isValidWeton(Word inputWeton);
//=========================LOADCONFIG=========================================
void loadPenggunaConfig(char filename[], ListUserStatik *LU);
/*Load Config Pengguna dari pengguna.config, lalu mengassign data data sesuai dengan kebutuhan typedef Pengguna
 */

//====================FITUR===============================

void Daftar(ListUserStatik *LU);

void Masuk(ListUserStatik *LU, currentUser *CU,boolean *isLog);

void gantiProfil(ListUserStatik *LU,currentUser *CU);