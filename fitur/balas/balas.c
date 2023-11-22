


/* ********* FITUR BALASAN ********* */
int BalasKicauan(ListDinKicauan *lk, int IDKicauan, int IDBalasan, currentUser* CU, ListUserStatik* LU, ListTree *lt, ListDinListB *lb, Graph* graph ) {
    
    //KAMUS LOKAL
    int idx = IDX_UNDEF, UserIDCurrent, UserID;

    // Mencari kicauan dengan IDKicauan 
    for (int i = 0; i < CAPACITYKICAUAN(*lk); i++) {
        if (IDKICAUAN(ELMTKICAUAN(*lk, i)) == IDKicauan) {
            idx = i;
            break;
        }
    }   

    // Jika tidak ada kicauan dengan IDKicauan tersebut return tidak terdapat kicauan
    if (idx == IDX_UNDEF) {
        printf("Wah, tidak terdapat kicauan yang ingin Anda balas!\n");
        return 1;
    }
    TreeNode* KicauSkrg = searchListTree(*lt, IDKicauan);

    // Jika tidak ada balasan dengan IDBalasan return tidak terdapat balasan
    if (!IsValidID(KicauSkrg, IDBalasan)) {
        printf("Wah, tidak terdapat balasan yang ingin Anda balas!\n");
        return 2;
    }

    // Mencari ID user untuk validasi pembalasan       
    if (IDBalasan == -1) {
        Word nama = AUTHORKICAUAN(ELMTKICAUAN(*lk, idx));
        UserID = getUserId(nama, *LU);
    } else {
        BALASAN* balasanT = getBalasan(lb, IDKicauan, IDBalasan);
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
    CreateDATETIME(&TimeNow, 10, 10, 2023, 19, 39, 13); // Waktu sementara

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

    // Jika Kicuan belum pernah dibalas maka membuat ListDinBalasan baru
    if(!isKicauanInList(*lb, IDKicauan)) {
        ListDinBalasan LDB;
        CreateListBalasan(&LDB,10);
        IDBalasan(newBalasan) = 1; // IDBalasan akan menjadi 1 karena baru saja di balas kicauannya

        // Membuat node baru 
        TreeNode* NodeKicau = createNode(IDKicauan);
        // ID 1 karena baru ada 1 balasan pada kicauan tersebut
        TreeNode* NodeBalasan = createNode(1);
        // Menambahkan Balasan baru ke kicauan
        addChild(NodeKicau, NodeKicau);
        // Menambahkan tree pada list tree
        insertLastListTree(lt, NodeKicau);

        insertLastListDinBalasan(&LDB, newBalasan);  // Insert Balasan ke ListDinBalasan
        insertLastListDinB(lb, LDB); // Insert ListDinBalasan ke ListDinB
 
    } else { // Jika sudah maka mencari ListDinBalasan dengan IDKicauan lalu insert balasan baru
        ListDinBalasan* LDB;
        LDB = getListDinBalasan(lb, IDKicauan);
        IDBalasan(newBalasan) = NEFFBalasan(*LDB)+1;
        
        // Membuat node baru dengan angka ID Balasan terbaru 
        TreeNode* NodeBalasan = createNode(IDBalasan(newBalasan));
        if (IDBalasan == -1) { // Jika IDBalsan -1 maka membalas root parent makan menambah langsung ke root
            addChild(searchListTree(*lt,IDKicauan), NodeBalasan);
        } else { // Jika membalasan ke Balasan maka akan mendapatkan Node IDKicauan dan searching Node IDBalasan untuk ditambahkan
            addChild(SearchTree(searchListTree(*lt, IDKicauan), IDBalasan), NodeBalasan);
        }
    }
    
    printf("Selamat! balasan telah diterbitkan!\nDetil balasan:\n");
    printBalasan(newBalasan);

    return 0;

}

void DisplayBalasanRecursive(TreeNode* T, int level, ListDinListB *lb, int idKicauan, ListUserStatik LU, int idCurrentUser, Graph graph) {
    
    TreeNode* current = AnakPertama(*T);

    while (current != NULL) {
        // Mendapatkan Balasan dengan menggunakan INFO dari ID di tree
        BALASAN* B = getBalasan(lb,idKicauan, INGFO(*current));

        int idUserBalasan = getUserId(AuthorBalasan(*B), LU); // Mendapatkan ID user Balasan

        if (isTeman(&graph, idCurrentUser, idUserBalasan) == false && JENIS_USER(LU, idUserBalasan) == 0) { // Jika current user dan user balasan bukan teman dan user balasan privat maka PRIVATTTT SEMUAAA
            for (int i = 0; i < level; i++) {
            printf("\t");
            }
            printf("| ID = %d\n", IDBalasan(*B));
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
            printf("| ID = %d\n", IDBalasan(*B));
            for (int i = 0; i < level; i++) {
                printf("\t");
            }
            printf("| ");printWord(AuthorBalasan(*B));printf("\n");
            for (int i = 0; i < level; i++) {
                printf("\t");
            }
            printf("| ");TulisDATETIME(DatetimeBalasan(*B));printf("\n");
            for (int i = 0; i < level; i++) {
                printf("\t");
            }
            printf("| ");printWord(TxtBalasan(*B));printf("\n");
            printf("\n");
        }

        // Melakukan print secara rekursif
        DisplayBalasanRecursive(current, level + 1, lb, idKicauan);

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

void DisplayBalasan(int idKicauan, ListDinListB lb, ListTree lt, ListUserStatik LU, currentUser CU, ListDinKicauan LD, Graph graph) {

    ListDinBalasan* ListBalasan = getListDinBalasan(&lb, idKicauan );

    int idUserCurrent = getUserIdCurrent(CU, LU);
    
    if(ListBalasan == NULL) { // Jika tidak terdapat Kicauan dengan id yang diminta
        printf("Tidak terdapat kicauan dengan id tersebut!\n");
    } else { // Jika terdapat kicauan dengan id yang diminta
        KICAUAN* kicau = getKicauan(LD, idKicauan); // Mendapatkan kicauan menggunakana ID
        int idUserKicauan = getUserId(AUTHORKICAUAN(*kicau), LU); // Mendapatkan id user kicauan
        if (searchListTree(lt, idKicauan) == NULL) { // Jika kicauan tersebut belum pernah dibalas maka tidak akan ada di tree
            printf("Belum terdapat balasan apapun pada kicauan tersebut. Yuk balas kicauan tersebut!\n");
        } else if (isTeman(&graph, idUserCurrent, idUserKicauan) == false && JENIS_USER(LU, idUserKicauan) == 0 ){ // Jika current user dan user kicauan bukan teman dan user kicauan privat
            printf("Wah, kicauan tersebut dibuat oleh pengguna dengan akun privat!\n");
        } else { // GO THROUGHHHH ALLL
            // Memanggil fungsi rekursif untuk print balasan
            TreeNode* current = searchListTree(lt, idKicauan);
            DisplayBalasanRecursive(current, 0, &lb, idKicauan, LU, idUserCurrent, graph);
        }
    }

}

void HapusBalasan()