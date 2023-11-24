#include "permintaan_pertemanan.h"
#include <stdio.h>

void Tambah_teman(ListUserStatik *LU, DPP *p, Graph *graph, currentUser cu)
{
    //  Kamus  //

    int id, idteman;
    PrioQueueChar P, Q;
    Word teman;
    infotypePQ infouser;

    // Algoritma //

    STARTWORDINPUT();
    teman = currentWord;
    id = idUser(cu);
    idteman = getUserId(teman, *LU);
    P = dpp(*p, id);
    Q = dpp(*p, idteman);
    if (!IsEmptyPrio(P))
    {
        printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.");
    }
    else
    {
        if (cekSameNama(*LU, teman))
        {
            if (isinDPP(Q, idteman))
            {
                printf("Anda sudah mengirimkan permintaan pertemanan kepada ");
                printWord(teman);
                printf(". Silakan tunggu hingga permintaan Anda disetujui.\n");
            }
            else
            {
                printf("Permintaan pertemanan kepada Bob telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.");
                tambahdpp(&Q, cu, graph);
            }
        }
        else
        {
            printf("Pengguna bernama ");
            printWord(teman);
            printf(" tidak ditemukan.\n");
        }
    }
}
void Daftar_Permintaan_Pertemanan(ListUserStatik *LU, DPP *p, currentUser cu)
{
    // Kamus //

    PrioQueueChar P;
    int i, idteman, count, idcurrentuser;

    // Algoritma //

    idcurrentuser = cu.idUser;
    P = dpp(*p, idcurrentuser);
    if (!IsEmptyPrio(P))
    {
        count = NBElmtPrio(P);
        printf("Terdapat %d permintaan pertemanan untuk Anda.\n", count);
        for (i = HeadPrioQ(P); i != TailPrioQ(P); i = (i + 1) % MaxPQ(P))
        {
            idteman = InfoPrioQ(ElmtPrioQ(P, i));
            printf("\n| ");
            printWord(NAMA_USER(*LU, idteman));
            printf("\n| Jumlah teman: %d\n", Prio(ElmtPrioQ(P, i)));
        }
        printf("\n| ");
        printWord(NAMA_USER(*LU, idteman));
        printf("\n| Jumlah teman: %d\n", Prio(ElmtPrioQ(P, i)));
    }
    else
    {
        printf("Tidak ada permintaan pertemanan untuk Anda.\n");
    }
}
void Setujui_Pertemanan(DPP *p, currentUser user, ListUserStatik *LU, Graph *G)
{
    // Kamus //

    PrioQueueChar P;
    int id, idteman;
    Word teman, input;
    Word ya = {"YA", 2};
    Word tidak = {"TIDAK", 5};
    infotypePQ x;

    // Algoritma //

    id = idUser(user);
    P = dpp(*p, id);
    idteman = InfoPrioQ(InfoHeadPrioQ(P));
    teman = NAMA_USER(*LU, idteman);

    printf("Permintaan pertemanan teratas dari\n");
    printWord(NAMA_USER(*LU, idteman));
    printf("\n| ");
    printWord(NAMA_USER(*LU, idteman));
    printf("\n| Jumlah teman: %d\n", Prio(InfoHeadPrioQ(P)));
    printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK) ");

    STARTWORDINPUT();

    input = currentWord;
    if (isWordEqual(input, ya))
    {
        addEdge(G, id, idteman);
        printf("Permintaan pertemanan dari ");
        printWord(teman);
        printf(" telah disetujui. Selamat! Anda telah berteman dengan ");
        printWord(teman);
        printf(".\n");
    }
    else // input == tidak
    {
        printf("Permintaan pertemanan dari ");
        printWord(teman);
        printf(" telah ditolak.\n");
    }
    DequeuePrio(&P, &x);
}

void tambahdpp(PrioQueueChar *P, currentUser cu, Graph *G) // P adalah DPP dari yang ingin dipertemankan ex: X ingin berteman dengan Y maka P = DPP dari Y
{
    infotypePQ Q;
    int idcurrentuser;

    idcurrentuser = cu.idUser;
    // MakeEmpty(&P,19);
    Prio(Q) = countTeman(G, idcurrentuser);
    InfoPrioQ(Q) = idcurrentuser;
    EnqueuePrio(P, Q);
}

boolean isinDPP(PrioQueueChar p, int idteman)
{
    infotypePQ x;
    PrioQueueChar temp;
    boolean found;
    temp = p;
    found = false;
    while (!IsEmptyPrio(temp) && found == false)
    {
        if (InfoPrioQ(InfoHeadPrioQ(p)) == idteman)
        {
            found = true;
        }
        else
        {
            DequeuePrio(&temp, &x);
        }
    }
    return found;
}