#include "utas.h"

void BUAT_UTAS(int IDKicau,ListDinKicauan *LDK,currentUser cu,ListDinUtas *LDU){

    //   KAMUS   //

    Word kicau,input,currentuser,author;
    Word ya = {"YA",2};
    Word tidak = {"TIDAK",5};
    Utas main;
    ListLinUtas LLU;
    int IDutas;
    info_utas data;
    KICAUAN temp;

    // ALGORITMA  //

    currentuser = cu.nama;
    temp = ELMTKICAUAN(*LDK,IDKicau-1);
    author = AUTHORKICAUAN(temp);
    if(isIdxEffListDinKicauan(*LDK,IDKicau-1)){
        if (isWordEqual(AUTHORKICAUAN(temp),currentuser)) // Check author dari kicauan sama dengan current user
        {
            if (isIDKicauTaken(IDKicau,*LDU)){
                printf(" Kicauan dengan IDKicauan %d sudah berupa utas\n");
            }
            else{
                input = ya;
                printf("Utas berhasil dibuat!\n");
                CreateListLinUtas(&LLU);
                main.banyak_utas = 0;
                while (isWordEqual(input,ya)){

                    // Menerima input kicauan //
                    printf("Masukkan kicauan:\n");
                    STARTWORDINPUT();
                    kicau = currentWord;

                    // Set data Utas //
                    data.Utas = kicau;
                    data.author = currentuser;
                    data.time = grabCurrentDateTime();
                    main.banyak_utas += 1;
                    insertLastListLinUtas(&LLU,data);
                    
                    printf("\n");

                    // Pengulangan jika input ya //
                    printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK)");
                    STARTWORDINPUT();
                    input = currentWord;
                }
                IDK(main) = IDKicau;
                NEXTK(main) = FIRSTU(LLU);
                CreateMainUtas(LDU,main);
                printf("banyak_utas dalam main = %d\n",main.banyak_utas);
                printf("Utas selesai!\n");
            }
        }
        else{
            printf("Utas ini bukan milik anda!\n");
        }
        
        
    }
    else{
        printf("Kicauan tidak ditemukan\n");
    }
}

void SAMBUNG_UTAS(int IDUtas,int index,currentUser cu,ListDinUtas *LDU){
    // KAMUS //

    Word currentuser;
    Utas main;
    Address p;
    ListLinUtas LLU;
    info_utas data;

    // ALGORITMA //

    CreateListLinUtas(&LLU);
    currentuser = nameUser(cu);
    if(IDUtas > lengthListDinUtas(*LDU)){
        printf("Utas tidak ditemukan!\n");
    }
    else{
        main = ELMTUTAS(*LDU,IDUtas-1);
        LLU = NEXTK(main);
        if(isWordEqual(AUTHORUTAS(InfoU(LLU)),currentuser)){
            TambahUtas(&LLU,index,cu);
            N(main)++;
        }
        else{
            printf("Anda tidak bisa menyambung utas ini!\n");
        }
    }
}


void HAPUS_UTAS(int IDUtas, int index,currentUser cu,ListDinUtas *LDU){
    // KAMUS //

    Address p;
    Utas main;
    info_utas data;
    ListLinUtas LLU;
    Word currentuser;
    // ALGORITMA //

    CreateListLinUtas(&LLU);
    currentuser = cu.nama;
    if (index == 0){
        printf("Anda tidak bisa menghapus kicauan utama!\n");
    }
    else{
        if(IDUtas > lengthListDinUtas(*LDU)){
            printf("Utas tidak ditemukan!\n");
        }
        else{
            main = ELMTUTAS(*LDU,IDUtas-1);
            LLU = NEXTK(main); 
            if(isWordEqual(AUTHORUTAS(InfoU(LLU)),currentuser)){
                if (index > lengthListLinUtas(LLU)){
                    printf("Kicauan sambungan dengan index %d tidak ditemukan pada utas!\n",index);
                }
                else{
                    deleteUtasAt(&LLU,index-1,&data);
                    N(ELMTUTAS(*LDU,IDUtas-1))--;
                    NEXTK(ELMTUTAS(*LDU,IDUtas-1)) = FIRSTU(LLU);
                    printf("Kicauan sambungan berhasil dihapus!\n");
                }
            }
            else{
                printf("Anda tidak bisa menghapus kicauan dalam utas ini!\n");
            }  
        }
    }
}

void CETAK_UTAS(int IDUtas,currentUser cu,Graph *G,ListUserStatik *LU,ListDinKicauan *LDK,ListDinUtas *LDU){

    // KAMUS //

    Address p;
    Utas main;
    boolean isteman;
    Word author,currentuser;

    // ALGORITMA //

    currentuser = cu.nama;
    if(IDUtas > lengthListDinUtas(*LDU)){
        printf("Utas tidak ditemukan!\n");
    }
    else {
        main = ELMTUTAS(*LDU,IDUtas-1);
        author = AUTHORKICAUAN(ELMTKICAUAN(*LDK,IDK(main)));
        printWord(author);printf("\n");
        printWord(currentuser);printf("\n");
        if(!isWordEqual(author,currentuser)){
            isteman = isTeman(G,getUserId(currentuser,*LU),getUserId(author,*LU));
            if (!isteman && JENIS_USER(*LU,getUserId(author,*LU)) == 0){
                printf("Akun yang membuat utas ini adalah akun privat! Ikuti dahulu akun ini untuk melihat utasnya!\n");
                /*displayMainKicauan(IDK(main),*LDK);
                if (N(main) != 0){
                    displayUtas(main);
                }*/
            }
            else{
                displayMainKicauan(IDK(main),*LDK);
                if (N(main) != 0){
                    displayUtas(main);
                }
            }
        }
        else{
            printf("IDK(main) = %d\n",IDK(main));
            displayMainKicauan(IDK(main),*LDK);
            if (N(main) != 0){
                displayUtas(main);
            }
        }
    }
}

void loadUtasConfig(char file[],ListDinUtas *LDU){
    //Kamus//

    int n;
    Utas main;
    ListLinUtas LLU;
    info_utas data;
    DATETIME time;
    KICAUAN kicau;
    //Algoritma//


    STARTWORDFILE(file);
    n = wordToInt(currentWord);
    //printf("n = %d\n",n);
    ADVWORDFILE();
    for (int i = 0; i<n;i++){
        IDK(main) = wordToInt(currentWord);
        //printf("idkicau = %d\n", idkicau);
        ADVWORDFILE();
        N(main) = wordToInt(currentWord);
        CreateListLinUtas(&LLU);
        //printf("banyakutas = %d\n", banyakutas);
        ADVWORDFILE();
        for(int j = 0; j<N(main);j++){
            if (j == 0){
                TEXTKICAUAN(kicau) = currentWord;
                ADVWORDFILE();
                AUTHORKICAUAN(kicau) = currentWord;
                ADVWORDFILE();
                CreateDATETIMEfromWord(&time,currentWord);
                DATETIMEKICAUAN(kicau) = time;
            }
            else {
                UTAS(data) = currentWord;
                //printWord(utas);
                ADVWORDFILE();
                AUTHORUTAS(data) = currentWord;
                //printWord(author);
                ADVWORDFILE();
                CreateDATETIMEfromWord(&time,currentWord);
                TIMEUTAS(data) = time;
                insertLastListLinUtas(&LLU,data);
                //printWord(time);
            }
            
            ADVWORDFILE();
        }
        NEXTK(main) = FIRSTU(LLU);
        CreateMainUtas(LDU,main);
    }
}

/* -------------------------------------------------*/
/* ---------- Primitif List Dinamis Utas ---------- */
/* -------------------------------------------------*/

void CreatelistUtas(ListDinUtas *LDU,int capacity){
    NEFFUTAS(*LDU) = 0;
    KONTENUTAS(*LDU) = (Utas*)malloc(capacity * sizeof(Utas));
    CAPACITYUTAS(*LDU) = capacity;
}

int lengthListDinUtas(ListDinUtas l)
{
    return NEFFUTAS(l);
}

IdxType getLastIdxListDinUtas(ListDinUtas l)
{
    return NEFFUTAS(l) - 1;
}

void insertLastListDinUtas(ListDinUtas *l, Utas utas)
{   
    ELMTUTAS(*l, lengthListDinUtas(*l)) = utas;
    NEFFUTAS(*l) += 1;
}

/* ------------------------------------------------*/
/* ----------- Fungsi Bantuan Kicauan ------------ */
/* ------------------------------------------------*/

void displayMainKicauan(int IDKicau,ListDinKicauan LK)
{
    KICAUAN T;

    T = ELMTKICAUAN(LK,IDKicau-1);

    printf("| ID : ");
    printf("%d\n",IDKICAUAN(T));

    printf("| ");
    printWord(AUTHORKICAUAN(T));
    printf("\n");

    printf("| ");
    TulisDATETIME(DATETIMEKICAUAN(T));
    printf("\n");

    printf("| ");
    printWord(TEXTKICAUAN(T));
    printf("\n");
}

boolean isIdxEffListDinKicauan(ListDinKicauan LK, IdxType i)
{
    return (i >= 0) && (i < NEFFKICAUAN(LK));
}

boolean isIDKicauTaken(int IDKicauan,ListDinUtas LDU){
    boolean found;
    int i;

    found = false;
    i = 0;
    while(i < lengthListDinUtas(LDU) && !found){
        //printf("checkpoint isidkicauantaken dalam while\n");
        if (IDK(ELMTUTAS(LDU,i)) == IDKicauan){
            found = true;
        }
        i++;
    }
    return found;
}

/* ------------------------------------------------*/
/* ---------- Primitif List Linier Utas ---------- */
/* ------------------------------------------------*/

Address newNodeUtas(info_utas info){
    Address p;
    p = (Address) malloc(sizeof(Node_Utas));
    if (p != NULL){
        InfoU(p) = info;
        NEXTU(p) = NULL;
    }
    return p;
}

void CreateListLinUtas(ListLinUtas *l){
    FIRSTU(*l) = NULL;
}

void InsertUtasAt(ListLinUtas *l, info_utas info, int idx){
    int ctr;
    Address p,loc;
    p = newNodeUtas(info);
    if (p!= NULL){
        if(idx == 0){
            NEXTU(p) = *l;
            *l = p;
        }
        else{
            ctr = 0;
            loc = *l;
            while (ctr < idx-1){
                ctr++;
                loc = NEXTU(loc);
            }
            NEXTU(p) = NEXTU(loc);
            NEXTU(loc) = p;
        }
    }
}

void deleteUtasAt(ListLinUtas *l, int idx, info_utas *info){
    int ctr;
    Address p,loc;
    if (idx == 0){
        p = *l;
        *l = NEXTU(p);
    }
    else {
        ctr = 0;
        loc = *l;
        while (ctr < idx -1 ){
            ctr++;
            loc = NEXTU(loc);
        }
        p = NEXTU(loc);
        NEXTU(loc) = NEXTU(p);
    }
    *info = InfoU(p);
    free(p);
}

int lengthListLinUtas(ListLinUtas l){
    Address p;
    int ctr;
    ctr = 0;
    p = l;
    while (p != NULL){
        ctr++;
        p = NEXTU(p);
    }
    return ctr;
}

ListLinUtas concatListLinUtas(ListLinUtas l1, ListLinUtas l2) {
    Address p;
    ListLinUtas l3;
    CreateListLinUtas(&l3);
    p = l1;
    while (p != NULL){
        insertLastListLinUtas(&l3,InfoU(p));
        p = NEXTU(p);
    }
    p = l2;
    while (p != NULL){
        insertLastListLinUtas(&l3,InfoU(p));
        p = NEXTU(p);
    }
    return l3;
}

void insertFirstListLinUtas(ListLinUtas *l, info_utas data){
    Address p;
    p = newNodeUtas(data);
    if (p != NULL){
        NEXTU(p) = *l;
        *l = p;
    }
}

void insertLastListLinUtas(ListLinUtas *l, info_utas data){
    Address p,last;
    if(isEmptyListLinUtas(*l)){
        insertFirstListLinUtas(l,data);
    }
    else{
        p = newNodeUtas(data);
        if (p != NULL){
            last = *l;
            while (NEXTU(last) != NULL){
                last = NEXTU(last);
            }
            NEXTU(last) = p;
        }
    }
}

boolean isEmptyListLinUtas(ListLinUtas l){
    return FIRSTU(l) == NULL;
}

/* -----------------------------------------*/
/* ---------- Fungsi-Fungsi Utas ---------- */
/* -----------------------------------------*/

void CreateMainUtas(ListDinUtas *LDU,Utas main){
    // ------- KAMUS ------- //

    // ------- ALGORITMA ------- //
    insertLastListDinUtas(LDU,main);
}

void TambahUtas(ListLinUtas *LU,int idx,currentUser cu){
    
    Word input,currentuser;
    info_utas data;
    DATETIME timeutas;
    
    currentuser = cu.nama;
    if (idx > lengthListLinUtas(*LU)-1){
        printf("Index terlalu tinggi!\n");
    }
    else{
        printf("Masukkan kicauan:\n");
        STARTWORDINPUT();
        input = currentWord;
        UTAS(data) = input;
        AUTHORUTAS(data) = currentuser;
        TIMEUTAS(data) = grabCurrentDateTime();
        InsertUtasAt(LU,data,idx);

    }
}
void displayUtas(Utas U){
    ListLinUtas l;
    info_utas info;
    Word author;
    int i;

    CreateListLinUtas(&l);
    l = NEXTK(U);
    i = 0;
    while(l != NULL){
        info = InfoU(l);
        printf("\n    | INDEX = %d\n",i+1);
        printf("    | "); printWord(AUTHORUTAS(info)); printf("\n");
        printf("    | "); TulisDATETIME(TIMEUTAS(info)); printf("\n");
        printf("    | "); printWord(UTAS(info)); printf("\n");
        l = NEXTU(l);
        i++;
    }
}