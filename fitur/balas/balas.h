#include "../../inisialisasi/balasan/balasan.h"
#include "../../inisialisasi/kicauan/kicauan.h"
#include "../teman/teman.h"

/* ********* FITUR BALASAN ********* */
int BalasKicauan(ListDinKicauan *lk, int IDKicauan, int IDBalasan, currentUser *CU, ListUserStatik *LU, ListTree *lt, Graph *graph);

void DisplayBalasanRecursive(TreeNode *T, int level, ListUserStatik LU, int idCurrentUser, Graph graph);

KICAUAN *getKicauan(ListDinKicauan LD, int IDKicuan);

void DisplayBalasan(int idKicauan, ListTree lt, ListUserStatik LU, currentUser CU, ListDinKicauan LD, Graph graph);

void HapusBalasan(ListUserStatik *LU, currentUser *CU, int IDKicauan, int IDBalasan, ListTree *LT);