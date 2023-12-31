#include <stdlib.h>
#include <stdio.h>
#include "teman.h"

int countTeman(Graph *graph, int userID)
{
    // KAMUS LOKAL
    int i = 0;
    int countTeman = 0;

    // ALGORITMA
    //  Melakukan pengurangan ID sesuai dengan index pada graf karena mulai dari 0
    if (userID < 1 || userID > Vertices(graph))
    {
        printf("Invalid user ID\n");
        return -1;
    }
    userID--;

    // Jika element = 1 maka counTeman akan ditambah 1
    for (i = 0; i < Vertices(graph); i++)
    {
        if (AdjMatrix(graph, userID, i) == 1)
        {
            countTeman++;
        }
    }

    return countTeman;
}

boolean isTeman(Graph *graph, int IDUser, int IDTeman)
{
    // Jika edge = 1 maka bener mereka temanan
    return hasEdge(graph, IDUser, IDTeman);
}

int daftarFriend(Graph *graph, currentUser *CU, ListUserStatik *LU)
{

    // Mendapatkan ID dan Nama current user
    int CurrentUserID = idUser(*CU);
    Word CurrentUserName = nameUser(*CU);

    // Menghitung jumlah teman
    int SumTeman = countTeman(graph, CurrentUserID);
    // Jika tidak ada teman maka print message
    if (SumTeman == 0)
    {
        printf("Bob belum mempunyai teman\n");
        return 1;
    }

    printWord(CurrentUserName);
    printf(" memiliki %d teman\n", SumTeman);
    printf("Daftar teman ");
    printWord(CurrentUserName);
    printf("\n");
    for (int i = 0; i < Vertices(graph); i++)
    {
        // Jika element = 1 maka bener teman
        if (AdjMatrix(graph, CurrentUserID, i) == 1)
        {
            // menambahkan ID + 1 untuk kembali ke semula
            int IdTeman = i++;
            // Mencari nama teman dengan ID lalu print
            Word namaTeman = NAMA_USER(*LU, IdTeman);
            printf("| ");
            printWord(namaTeman);
            printf("\n");
        }
    }
    return 0;
}

void hapusFriend(Graph *graph, currentUser *CU, ListUserStatik *LU)
{

    Word ya = {"YA", 2};
    Word tidak = {"TIDAK", 5};

    // Mendapatkan ID current user
    int CurrentUserID = getUserIdCurrent(*CU, *LU);

    // Menerima input nama
    printf("Masukkan nama pengguna:\n");
    STARTWORDINPUT();

    Word namaTeman = currentWord;
    int IDTeman = getUserId(namaTeman, *LU);

    if (!isTeman(graph, CurrentUserID, IDTeman))
    {
        printWord(namaTeman);
        printf(" bukan teman Anda.\n");
        return;
    }

    printf("Apakah anda yakin ingin menghapus ");
    printWord(namaTeman);
    printf(" dari daftar teman anda?(YA/TIDAK) ");
    STARTWORDINPUT();

    if (isWordEqual(currentWord, ya))
    {
        // Apabila input YA maka akan menghapuskan edge antara kedua ID user
        removeEdge(graph, CurrentUserID--, IDTeman--);
        printWord(namaTeman);
        printf(" berhasil dihapus dari daftar teman Anda.\n");
    }
    else if (isWordEqual(currentWord, tidak))
    {
        // Membatalkan jika input TIDAK
        printf("Penghapusan teman dibatalkan.\n");
    }
}

// void kelompokFriend(Graph *graph, currentUser *CU, ListUserStatik *LU)
// {
//     ListLin LL;
//     Address p;

//     // Membuat list linear untuk
//     CreateListLin(&LL);

//     // Mendapatkan IDuser current dan menguranginya dengan 1 untuk menyesuaikan dengan index graf
//     int IDuser = getUserIdCurrent(*CU, *LU) - 1;
//     // Membuat tempat penyimpanan edges yang connected sementara
//     int visited[MAX_VERTICES] = {0};
//     // Melalui fungsi ini mendapatkan secara rekursif iduser - 1 yang connected lalu menyimpan idnya dalam linked list
//     connectedEdges(&graph, IDuser, visited, &LL);

//     // Mendapatkan jumlah orang di kelompok
//     int sumFrens = lengthListLin(LL);

//     // Mendaptkan nama user skrg
//     Word namaUserNow = nameUser(*CU);

//     // Print daftar kelompok
//     printf("Terdapat %d orang dalam Kelompok Teman", sumFrens);
//     printWord(namaUserNow);
//     printf(" :\n");

//     p = LL;
//     while (p != NULL)
//     {
//         int idUser = INFO(p) + 1;
//         Word namaUser = NAMA_USER(*LU, idUser);
//         printWord(namaUser);
//         printf("\n");
//         p = NEXT(p);
//     }
// }