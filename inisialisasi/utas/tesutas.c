#include "utas.c"


int main(){
    // Kamus //

    ListLinUtas LLU;
    ListDinKicauan LK;
    ListDinUtas LDU;
    Utas main;
    KICAUAN k,k2;
    Graph G;
    ListUserStatik LU;
    currentUser cu;
    Word author = {"Nyonya Hil",10};
    Word kicau = {"ini tes utas bagian kicauan utama",33};
    Word utas1 = {"ini tes utas bagian utas pertama",32};
    Word utas2 = {"ini tes utas bagian utas kedua",30};
    Word utas3 = {"ini tes utas bagian utas ketiga",31};

    // Algoritma //
    
    cu.nama = author;
    cu.idUser = 1;
    CreatelistUtas(&LDU,100);
    //loadUtasConfig("utas.config",&LDU);
    CreateListKicauan(&LK,100);
    k = createNewKicauanFromText(1,kicau,cu);
    addKicauan(&LK,k);
    k2 = createNewKicauanFromText(2,utas1,cu);
    addKicauan(&LK,k2);
    loadUtasConfig("utas.config",&LDU);
    CETAK_UTAS(1,cu,&G,&LU,&LK,&LDU);
    CETAK_UTAS(2,cu,&G,&LU,&LK,&LDU);
    /*BUAT_UTAS(1,&LK,cu,&LDU);
    BUAT_UTAS(2,&LK,cu,&LDU);
    CETAK_UTAS(1,cu,&G,&LU,&LK,&LDU);
    printf("\n");
    CETAK_UTAS(2,cu,&G,&LU,&LK,&LDU);
    SAMBUNG_UTAS(1,1,cu,&LDU);
    CETAK_UTAS(1,cu,&G,&LU,&LK,&LDU);
    HAPUS_UTAS(3,1,cu,&LDU);
    printf("\n");
    HAPUS_UTAS(1,0,cu,&LDU);
    printf("\n");
    HAPUS_UTAS(1,1,cu,&LDU);
    printf("\n");
    CETAK_UTAS(1,cu,&G,&LU,&LK,&LDU);*/

}