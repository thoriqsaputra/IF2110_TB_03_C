#include "utas.h"

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

void insertLastListDinUtas(ListDinUtas *l, Utas utas)
{   
    ELMTUTAS(*l, lengthListDinUtas(*l)) = utas;
    NEFFUTAS(*l) += 1;
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