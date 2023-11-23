#include "permintaan_pertemanan.c"


int main(){

    // Kamus //

    PrioQueueChar PQ;
    DPP LPQ;
    Graph G;
    ListUserStatik LU;
    currentUser cu;
    Word user1 = {"Luffy",5};
    Word user2 = {"Zoro",4};
    Word user3 = {"Ussop",5};
    Word user4 = {"Sanji",5};
    Word user5 = {"Carlos",5};
    // Algoritma //

    cu.nama = user1;
    cu.idUser = 0;
    MakeEmptyPrio(&PQ,100);
    initGraph(&G,5);
    CreateEmptyPengguna(&LU);
    for(int i = 0;i<5;i++){
        Daftar(&LU);
    }
    
}