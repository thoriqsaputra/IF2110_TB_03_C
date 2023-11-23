#include "../../ADT/wordmachine.h"
#include "../../ADT/graf.h"
#include "pengguna/pengguna.h"


int countTeman(Graph* graph, int userID);

boolean isTeman(Graph* graph, int IDUser, int IDTeman);

int daftarFriend(Graph* graph, currentUser * CU, ListUserStatik * LU);

void hapusFriend(Graph* graph, currentUser * CU, ListUserStatik * LU);