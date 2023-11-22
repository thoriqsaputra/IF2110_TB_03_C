#ifndef PENGGUNA_H
#define PENGGUNA_H

#include "../../ADT/wordmachine.h"
#include "../../ADT/matrix.h"

#define IDX_UNDEF -1

/*
ListUserStatik menggunakan dasar dari listatik, karena ListUser ini terdiri merupakan array statis dari ElTypePengguna (maks 20)
listWord juga menggunakan dasar dari listatik
*/

#define CAPACITYUSER 20
#define CAPACITYWORD 500
#define IDX_TAIL(q) (q).idxTail
#define NAMA_USER(l, q) (l).buffer[q].nama
#define PASSWORD_USER(l, q) (l).buffer[q].password
#define BIO_USER(l, q) (l).buffer[q].bio
#define NOHP_USER(l, q) (l).buffer[q].noHp
#define WETON_USER(l, q) (l).buffer[q].weton
#define JENIS_USER(l, q) (l).buffer[q].jenisAkun
#define FOTO_USER(l, q) (l).buffer[q].fotoProfil
#define ID_USER(l, q) (l).buffer[q].id
#define UserCount(l) (l).capacity
#define idUser(c) (c).idUser
#define nameUser(c) (c).nama

// l -> LU (ListUserStatik)  c -> CU (currentUser)
typedef struct
{
    int id;
    Word nama;
    Word password;
    Word bio;
    Word noHp;
    Word weton;
    int jenisAkun; // kalo 1 = publik, kalo 0 private
    Matrix fotoProfil;
} Pengguna;

typedef struct
{
    Pengguna buffer[CAPACITYUSER]; // maks user 20
    int capacity;
} ListUserStatik;
typedef struct
{
    Word contents[CAPACITYWORD]; /* memori tempat penyimpan elemen (container) , coba coba temp 10rb */
    // jumlah user fixed, jadi capacity word pasti fixed juga, <= 20 x 11
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

// Define primitif

//=====================DEKLARASI==============================

void CreateEmptyPengguna(ListUserStatik *l);
// ListUserStatic.capacity = 0

void CreateEmptyCurrentUser(currentUser *CU);
// CU.nama = BLANK, CU.id = IDX_UNDEF

Matrix createMatrixDefault();
// Membuat matrix default sesuai spek

//===================GETTER============================

int getUserIdCurrent(currentUser CU, ListUserStatik LU);

int getUserId(Word inputNama, ListUserStatik LU);

//========================UTILITY==========================
// void printWord(Word kata);
/*Print ADT Word*/

boolean isValidHP(Word inputHP);

int wordToInt(Word kata);
/*Ubah ADT Word to Int*/

void tulisDataPengguna(Pengguna *user);
/*I.S Menulis dari
  F.S
*/
void getInputProfil(int Nmax);

boolean cekSameNama(ListUserStatik LU, Word inputWord);

boolean isWordEqual(Word input, Word cek);
// cek word sama
boolean isValidWeton(Word inputWeton);

void displayColorMatrix(Matrix m);
//=========================LOADCONFIG=========================================
void loadPenggunaConfig(char filename[], ListUserStatik *LU);
/*Load Config Pengguna dari pengguna.config, lalu mengassign data data sesuai dengan kebutuhan typedef Pengguna
 */

//====================FITUR===============================

void Daftar(ListUserStatik *LU);

void Masuk(ListUserStatik *LU, currentUser *CU, boolean *isLog);

void gantiProfil(ListUserStatik *LU, currentUser *CU);

void lihatUser(ListUserStatik *LU, Word namaProfil);

void Keluar(ListUserStatik *LU, currentUser *CU, boolean *isLog);

void aturJenisAkun(ListUserStatik *LU, currentUser *CU);
void ubahFotoProfil(ListUserStatik *LU, currentUser *CU);

#endif