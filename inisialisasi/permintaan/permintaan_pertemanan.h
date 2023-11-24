
#include "../../ADT/prioqueuechar.h"
#include "../../fitur/teman/teman.h"

typedef struct
{
    PrioQueueChar buffer[CAPACITYUSER];
} DPP;

#define dpp(l, i) (l).buffer[i]

void Tambah_teman(ListUserStatik *LU, DPP *p, Graph *graph, currentUser cu);
void Daftar_Permintaan_Pertemanan(ListUserStatik *LU, DPP *p, currentUser cu);
void Setujui_Pertemanan(DPP *p, currentUser user, ListUserStatik *LU, Graph *G);
void tambahdpp(PrioQueueChar *P, currentUser cu, Graph *G);
boolean isinDPP(PrioQueueChar p, int idteman);
