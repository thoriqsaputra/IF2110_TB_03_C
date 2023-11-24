#ifndef __LOADNSAVE__
#define __LOADNSAVE__

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "../../inisialisasi/inisialisasi.h"

void muat(Word folder, ListUserStatik *LU, ListDinDraf *LD, ListDinKicauan *LK, ListDinUtas *LS, Graph *GP, ListTree *LT);

void simpan(ListUserStatik *LU, ListDinDraf *LD, ListDinKicauan *LK, ListDinUtas *LS, Graph *GP, ListTree *LT);

#endif