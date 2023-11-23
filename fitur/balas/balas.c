#include "balas.h"
#include <stdio.h>
#include <stdlib.h>

/* ********* FITUR BALASAN ********* */
int BalasKicauan(ListDinKicauan *lk, int IDKicauan, int IDBalasan, currentUser* CU, ListUserStatik* LU, ListTree *lt, Graph* graph ) {
    
    //KAMUS LOKAL
    int idx = IDX_UNDEF, UserIDCurrent, UserID;

    // Mencari kicauan dengan IDKicauan 
    for (int i = 0; i < CAPACITYKICAUAN(*lk); i++) {
        if (IDKICAUAN(ELMTKICAUAN(*lk, i)) == IDKicauan) {
            idx = i;
            break;
        }
    }   

    // Jika tidak ada kicauan dengan IDKicauan tersebut return 1 (tidak terdapat kicauan)
    if (idx == IDX_UNDEF) {
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n");
        return 1;
    }
    TreeNode* KicauSkrg = searchListTree(*lt, IDKicauan);

    // Jika tidak ada balasan dengan IDBalasan return 2 (tidak terdapat balasan)
    if (!IsValidID(KicauSkrg, IDBalasan, BALASAN_NODE) || KicauSkrg == NULL) {
        printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
        return 2;
    }

    // Mencari ID user untuk validasi pembalasan       
    if (IDBalasan == -1) {
        Word nama = AUTHORKICAUAN(ELMTKICAUAN(*lk, idx));
        UserID = getUserId(nama, *LU);
    } else {
        BALASAN* balasanT = findBalasan(*lt, IDKicauan, IDBalasan);
        Word nama = AuthorBalasan(*balasanT);
        UserID = getUserId(nama, *LU);
    }
    UserIDCurrent = getUserIdCurrent(*CU, *LU);
    //Jika bukan teman dan akun tersebut privat 
    if (isTeman(graph, UserIDCurrent, UserID) == false && JENIS_USER(*LU,UserID) == 0) {
        printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman akun tersebut!\n");
        return 3;
    }

    // Semua error telah dilalui dan dilanjuti dengan melakukan input balasan
    BALASAN newBalasan;
    DATETIME TimeNow;
    
    // Ambil waktu sekarang
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    int YY = 1900 + tm_info->tm_year;
    int MM = 1 + tm_info->tm_mon;
    int DD = tm_info->tm_mday;
    int hh = tm_info->tm_hour;
    int mm = tm_info->tm_min;
    int ss = tm_info->tm_sec;
    CreateDATETIME(&TimeNow, DD, MM, YY, hh, mm, ss);

    // Melalakukan input balasan
    printf("Masukkan balasan:\n");
    STARTWORDINPUT();

    // Menyimpan data balasan;
    idDiBalas(newBalasan) = IDBalasan;
    TxtBalasan(newBalasan) = currentWord;
    // Mendapatkan nama author dengan ID current user
    Word namaAuthor = NAMA_USER(*LU, UserIDCurrent);
    AuthorBalasan(newBalasan) = namaAuthor;
    DatetimeBalasan(newBalasan) = TimeNow;

    // Jika Kicuan belum pernah dibalas maka akan membuat new node baru
    if(searchListTree(*lt, IDKicauan) == NULL) {
        KICAUAN kicauan;
        kicauan.ID = IDKicauan;
        TreeNode* kicauanNode = createNodeWithData(KICAUAN_NODE, &kicauan);
        IDBalasan(newBalasan) = 1; // IDBalasan akan menjadi 1 karena baru saja di balas kicauannya
        TreeNode* balasanNode = createNodeWithData(BALASAN_NODE, &newBalasan);
        addChild(kicauanNode, balasanNode);
        // Menambahkan tree pada list tree
        insertLastListTree(lt, kicauanNode);
        free(kicauanNode);
        free(balasanNode);
    } else { // Jika sudah maka mencari ListDinBalasan dengan IDKicauan lalu insert balasan baru
        TreeNode* kicauanNode = searchListTree(*lt, IDKicauan);

        IDBalasan(newBalasan) = getMaxIDBalasan(kicauanNode) + 1;
        // Membuat node baru dengan angka ID Balasan terbaru 
        TreeNode* balasanNode = createNodeWithData(BALASAN_NODE, &newBalasan);
        if (IDBalasan == -1) { // Jika IDBalsan -1 maka membalas root parent makan menambah langsung ke root
            addChild(kicauanNode, balasanNode);
        } else { // Jika membalasan ke Balasan maka akan mendapatkan Node IDKicauan dan searching Node IDBalasan untuk ditambahkan
            addChild(SearchTree(kicauanNode, IDBalasan, BALASAN_NODE), balasanNode);
        }
        free(kicauanNode);
        free(balasanNode);
    }
    
    printf("Selamat! balasan telah diterbitkan!\nDetil balasan:\n");
    printf("| ID = %d\n", IDBalasan(newBalasan));
    printf("| ");printWord(AuthorBalasan(newBalasan));printf("\n");
    printf("| ");TulisDATETIME(DatetimeBalasan(newBalasan));printf("\n");
    printf("| ");printWord(TxtBalasan(newBalasan));printf("\n");
    printf("\n");

    return 0;

}

void DisplayBalasanRecursive(TreeNode* T, int level,  ListUserStatik LU, int idCurrentUser, Graph graph) {
    
    TreeNode* current = AnakPertama(*T);

    while (current != NULL) {
        // Mendapatkan Balasan dengan menggunakan INFO dari ID di tree
        BALASAN B = current->balasanData;

        int idUserBalasan = getUserId(AuthorBalasan(B), LU); // Mendapatkan ID user Balasan

        if (isTeman(&graph, idCurrentUser, idUserBalasan) == false && JENIS_USER(LU, idUserBalasan) == 0) { // Jika current user dan user balasan bukan teman dan user balasan privat maka PRIVATTTT SEMUAAA
            for (int i = 0; i < level; i++) {
            printf("\t");
            }
            printf("| ID = %d\n", IDBalasan(B));
            for (int i = 0; i < level; i++) {
                printf("\t");
            }
            printf("| ");printf("PRIVAT\n");
            for (int i = 0; i < level; i++) {
                printf("\t");
            }
            printf("| ");printf("PRIVAT\n");
            for (int i = 0; i < level; i++) {
                printf("\t");
            }
            printf("| ");printf("PRIVAT\n");
        } else {
            // Print indent dan info terkait balasan
            for (int i = 0; i < level; i++) {
                printf("\t");
            }
            printf("| ID = %d\n", IDBalasan(B));
            for (int i = 0; i < level; i++) {
                printf("\t");
            }
            printf("| ");printWord(AuthorBalasan(B));printf("\n");
            for (int i = 0; i < level; i++) {
                printf("\t");
            }
            printf("| ");TulisDATETIME(DatetimeBalasan(B));printf("\n");
            for (int i = 0; i < level; i++) {
                printf("\t");
            }
            printf("| ");printWord(TxtBalasan(B));printf("\n");
            printf("\n");
        }

        // Melakukan print secara rekursif
        DisplayBalasanRecursive(current, level + 1, LU, idCurrentUser, graph);

        // Melanjutkan ke Balasan berikutnya
        current = SaudaraBerikut(*current);
    }

}

KICAUAN* getKicauan(ListDinKicauan LD, int IDKicuan) {
    for (int i = 0; i < NEFFKICAUAN(LD);i++) {
        if(IDKICAUAN(ELMTKICAUAN(LD, i)) == IDKicuan) {
            return &ELMTKICAUAN(LD, i);
        }
    }

    return NULL;
}

void DisplayBalasan(int idKicauan, ListTree lt, ListUserStatik LU, currentUser CU, ListDinKicauan LD, Graph graph) {

    KICAUAN* kicau = getKicauan(LD, idKicauan); // Mendapatkan kicauan menggunakana ID

    int idUserCurrent = getUserIdCurrent(CU, LU);
    
    if(kicau == NULL) { // Jika tidak terdapat Kicauan dengan id yang diminta
        printf("Tidak terdapat kicauan dengan id tersebut!\n");
    } else { // Jika terdapat kicauan dengan id yang diminta
        int idUserKicauan = getUserId(AUTHORKICAUAN(*kicau), LU); // Mendapatkan id user kicauan
        TreeNode* kicauanNode = searchListTree(lt, idKicauan);
        if ( kicauanNode == NULL || kicauanNode->firstChild == NULL ) { // Jika kicauan tersebut belum pernah dibalas maka tidak akan ada di tree
            printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!\n");
        } else if (isTeman(&graph, idUserCurrent, idUserKicauan) == false && JENIS_USER(LU, idUserKicauan) == 0 ){ // Jika current user dan user kicauan bukan teman dan user kicauan privat
            printf("Wah, kicauan tersebut dibuat oleh pengguna dengan akun privat!\n");
        } else { // GO THROUGHHHH ALLL
            // Memanggil fungsi rekursif untuk print balasan
            TreeNode* current = searchListTree(lt, idKicauan);
            DisplayBalasanRecursive(current, 0,  LU, idUserCurrent, graph);
        }
    }

}

void HapusBalasan(ListUserStatik *LU, currentUser *CU, int IDKicauan, int IDBalasan, ListTree *LT) {

    BALASAN* balas = findBalasan(*LT, IDKicauan, IDBalasan);
    int idCurrentUser = getUserIdCurrent(*CU,*LU);

    if (balas = NULL) {
            printf("Balasan tidak ditemukan\n");
    } else {
        if (idCurrentUser != getUserId(AuthorBalasan(*balas), *LU)) {
        printf("Hei, ini balasan punya siapa? Jangan dihapus ya!\n");
        }
        else {
            deleteNode(searchListTree(*LT, IDKicauan), IDBalasan, BALASAN_NODE);
            printf("Balasan berhasil dihapus\n");
        }
    }
}