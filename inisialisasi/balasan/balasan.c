#include <stdio.h>
#include <stdlib.h>
#include "balasan.h"

TreeNode *createNodeWithData(NodeType type, void *data)
{
    if (data == NULL)
    {
        return NULL; // Handle invalid data
    }

    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (newNode)
    {
        newNode->type = type;
        newNode->firstChild = NULL;
        newNode->nextSibling = NULL;

        if (type == KICAUAN_NODE)
        {
            newNode->kicauanData = *((KICAUAN *)data);
        }
        else if (type == BALASAN_NODE)
        {
            newNode->balasanData = *((BALASAN *)data);
        }
    }
    return newNode;
}

void addChild(TreeNode *parent, TreeNode *child)
{
    if (parent == NULL || child == NULL)
    {
        return;
    }

    if (parent->firstChild == NULL)
    {
        parent->firstChild = child;
    }
    else
    {
        TreeNode *current = parent->firstChild;
        while (current->nextSibling != NULL)
        {
            current = current->nextSibling;
        }
        current->nextSibling = child;
    }
}

void PrintTree(TreeNode *root, int level)
{
    for (int i = 0; i < level; i++)
    {
        printf("\t");
    }

    if (root->type == KICAUAN_NODE)
    {
        printf("KICAUAN: %d\n", root->kicauanData.ID);
    }
    else
    {
        printf("BALASAN: %d\n", root->balasanData.IDBalasan);
    }

    TreeNode *current = root->firstChild;
    while (current != NULL)
    {
        PrintTree(current, level + 1);
        current = current->nextSibling;
    }
}

int countNodesExceptParent(TreeNode* node) {
    if (node == NULL) {
        return 0;
    }

    int count = 0;

    // Count the nodes in the children
    TreeNode* current = node->firstChild;
    while (current != NULL) {
        count += 1 + countNodesExceptParent(current);
        current = current->nextSibling;
    }

    return count;
}



boolean IsValidID(TreeNode *parent, int target, NodeType targetType)
{
    if (parent == NULL)
    {
        return false;
    }

    if ((parent->type == KICAUAN_NODE && IDKICAUAN(parent->kicauanData) == target) ||
        (parent->type == BALASAN_NODE && IDBalasan(parent->balasanData) == target))
    {
        return true;
    }

    TreeNode *current = parent->firstChild;
    while (current != NULL)
    {
        if (IsValidID(current, target, targetType))
        {
            return true;
        }
        current = current->nextSibling;
    }

    return false;
}

TreeNode *SearchTree(TreeNode *parent, int target, NodeType targetType)
{
    if (parent == NULL)
    {
        return NULL;
    }

    if ((parent->type == KICAUAN_NODE && IDKICAUAN(parent->kicauanData) == target) ||
        (parent->type == BALASAN_NODE && IDBalasan(parent->balasanData) == target))
    {
        return parent;
    }

    TreeNode *current = parent->firstChild;
    while (current != NULL)
    {
        TreeNode *result = SearchTree(current, target, targetType);
        if (result != NULL)
        {
            return result;
        }
        current = current->nextSibling;
    }

    return NULL;
}

void deleteNode(TreeNode *parent, int target, NodeType targetType)
{
    if (parent == NULL)
    {
        return;
    }

    TreeNode *current = parent->firstChild;
    TreeNode *prev = NULL;

    while (current != NULL)
    {
        if ((current->type == KICAUAN_NODE && IDKICAUAN(current->kicauanData) == target) ||
            (current->type == BALASAN_NODE && IDBalasan(current->balasanData) == target))
        {
            if (prev != NULL)
            {
                prev->nextSibling = current->nextSibling;
            }
            else
            {
                parent->firstChild = current->nextSibling;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->nextSibling;
    }
}

int getMaxIDBalasan(TreeNode *parent)
{
    if (parent == NULL || parent->type != KICAUAN_NODE)
    {
        // Invalid input or the parent is not a KICAUAN_NODE
        return 0;
    }

    // Check if the parent has children
    if (parent->firstChild == NULL)
    {
        // No children, return 0
        return 0;
    }

    // Initialize maxID to the IDBalasan of the first child
    int maxID = parent->firstChild->balasanData.IDBalasan;

    // Traverse the siblings to find the maximum IDBalasan
    TreeNode *current = parent->firstChild->nextSibling;
    while (current != NULL)
    {
        if (current->type == BALASAN_NODE && current->balasanData.IDBalasan > maxID)
        {
            maxID = current->balasanData.IDBalasan;
        }
        current = current->nextSibling;
    }

    return maxID;
}

/* ********** KONSTRUKTOR ListDinTree ********** */
/* Konstruktor : create list kosong  */
void CreateListTree(ListTree *lt, int capacity)
{
    lt->NEFFListTree = 0;
    lt->ContentListTree = (TreeNode **)malloc(capacity * sizeof(TreeNode *));
    if (lt->ContentListTree != NULL)
    {
        lt->CAPACITYLISTTREE = capacity;
    }
    else
    {
        lt->CAPACITYLISTTREE = 0;
    }
}

void dealocateTrees(ListTree *lt)
{
    free(lt->ContentListTree);
    lt->NEFFListTree = 0;
    lt->CAPACITYLISTTREE = 0;
}

int LengthListTree(ListTree l)
{
    return l.NEFFListTree;
}

void copyListTree(ListTree lIn, ListTree *lOut)
{
    int i;
    dealocateTrees(lOut);
    CreateListTree(lOut, lIn.CAPACITYLISTTREE);
    lOut->NEFFListTree = lIn.NEFFListTree;
    for (i = 0; i < lIn.NEFFListTree; i++)
    {
        lOut->ContentListTree[i] = lIn.ContentListTree[i];
    }
}

void deleteLastListTree(ListTree *l, TreeNode **tree)
{
    *tree = l->ContentListTree[l->NEFFListTree - 1];
    l->NEFFListTree -= 1;

    free(*tree);
}

void expandListTree(ListTree *l, int num)
{
    ListTree temp;
    CreateListTree(&temp, l->CAPACITYLISTTREE + num);
    l->CAPACITYLISTTREE += num;
    copyListTree(*l, &temp);
    free(l->ContentListTree);
    l->ContentListTree = (TreeNode **)malloc(l->CAPACITYLISTTREE * sizeof(TreeNode *));
    copyListTree(temp, l);
    dealocateTrees(&temp);
}

void insertLastListTree(ListTree *l, TreeNode *tree)
{
    int nefplus = l->NEFFListTree + 1;

    if (nefplus >= l->CAPACITYLISTTREE)
    {
        expandListTree(l, 4);
    }

    l->ContentListTree[l->NEFFListTree] = tree;
    l->NEFFListTree += 1;
}

void shrinkListDinTree(ListTree *l, int num)
{
    ListTree temp;
    CreateListTree(&temp, l->CAPACITYLISTTREE - num);
    l->CAPACITYLISTTREE -= num;
    copyListTree(*l, &temp);
    dealocateTrees(l);
    CreateListTree(l, temp.CAPACITYLISTTREE);
    copyListTree(temp, l);
    dealocateTrees(&temp);
}

TreeNode *searchListTree(ListTree l, int value)
{
    int i;
    for (i = 0; i < l.NEFFListTree; i++)
    {
        TreeNode *currentNode = l.ContentListTree[i];
        if (currentNode->type == KICAUAN_NODE && currentNode->kicauanData.ID == value)
        {
            return currentNode;
        }
        else if (currentNode->type == BALASAN_NODE && currentNode->balasanData.idDiBalas == value)
        {
            return currentNode;
        }
    }
    return NULL;
}

BALASAN *findBalasan(ListTree LT, int IDKicauan, int IDBalasan)
{
    TreeNode *kicauanNode = searchListTree(LT, IDKicauan);
    if (kicauanNode != NULL)
    {
        TreeNode *balasanNode = SearchTree(kicauanNode, IDBalasan, BALASAN_NODE);
        if (balasanNode != NULL && balasanNode->type == BALASAN_NODE)
        {
            return &(balasanNode->balasanData);
        }
    }
    return NULL;
}

/* ********* CONFIGS ********* */
void loadBalasanConfig(char filename[], ListTree *LT)
/* I.S. l kosong; */
/* F.S. l diisi sesuai config */
{
    // Kamus Lokal
    int i, j, JumlahKicauan, JumlahBalasanCurrent, IDKicauan;

    // ALGORITMA
    STARTWORDFILE(filename);
    // Mendapatkan jumlah kicaun yang memiliki balasan
    JumlahKicauan = wordToInt(currentWord);
    // Membuat list dengan banyaknya kicauan
    CreateListTree(LT, JumlahKicauan);

    for (i = 0; i < JumlahKicauan; i++)
    {
        KICAUAN kicauan;
        ADVWORDFILE();
        // Mendapatkan IDKicauan
        IDKicauan = wordToInt(currentWord);
        ADVWORDFILE();
        // // Mendapatkan Jumlah balasan pada IDKicauan
        JumlahBalasanCurrent = wordToInt(currentWord);
        // // Membuat list dengan banyaknya balasan
        // CreateListBalasan(&l, JumlahBalasanCurrent);
        // Menyimpan IDKicauan
        kicauan.ID = IDKicauan;
        // Membuat tree baru dan IDKicauan sebagai root
        TreeNode *kicauanNode = createNodeWithData(KICAUAN_NODE, &kicauan);

        // Dalam looping jumlah balasan membaca informasi terkait balasan tersebut
        for (j = 0; j < JumlahBalasanCurrent; j++)
        {
            BALASAN balasan;
            ADVWORDFILE();
            // Membaca ID yang dibalas ID balasan
            Word ID = currentWord;
            int currentResult = 0;
            boolean isNegative = false;
            for (int i = 0; i < ID.Length; i++)
            {
                if (ID.TabWord[i] == '-')
                {
                    isNegative = true;
                }
                else if (ID.TabWord[i] == ' ')
                {
                    if (isNegative)
                    {
                        currentResult = -currentResult;
                        isNegative = false;
                    }
                    // Menyimpan ID yang dibalas
                    balasan.idDiBalas = currentResult;
                    currentResult = 0;
                }
                else
                {
                    currentResult = currentResult * 10 + (ID.TabWord[i] - '0');
                }
            }
            if (isNegative)
            {
                currentResult = -currentResult;
            }
            // Menyimpan ID Balasan
            balasan.IDBalasan = currentResult;

            // Lanjut ke txt balasan dst
            ADVWORDFILE();
            balasan.TextBalasan = currentWord;
            ADVWORDFILE();
            balasan.Author = currentWord;
            ADVWORDFILE();
            // Membaca DateTime lalu mengubanya ke typdef struct DATETIME
            DATETIME t;
            Word temp = currentWord;
            int DD = (int)(temp.TabWord[0] % 48) * 10 + (int)(temp.TabWord[1] % 48);
            int MM = (int)(temp.TabWord[3] % 48) * 10 + (int)(temp.TabWord[4] % 48);
            int YY = (int)(temp.TabWord[6] % 48) * 1000 + (int)(temp.TabWord[7] % 48) * 100 + (int)(temp.TabWord[8] % 48) * 10 + (int)(temp.TabWord[9] % 48);
            int hh = (int)(temp.TabWord[11] % 48) * 10 + (int)(temp.TabWord[12] % 48);
            int mm = (int)(temp.TabWord[14] % 48) * 10 + (int)(temp.TabWord[15] % 48);
            int ss = (int)(temp.TabWord[17] % 48) * 10 + (int)(temp.TabWord[18] % 48);
            CreateDATETIME(&t, DD, MM, YY, hh, mm, ss);
            balasan.DT = t;

            TreeNode *balasanNode = createNodeWithData(BALASAN_NODE, &balasan);
            if (balasan.idDiBalas == -1)
            {
                addChild(kicauanNode, balasanNode);
            }
            else
            {
                int id = balasan.idDiBalas;
                addChild(SearchTree(kicauanNode, id, BALASAN_NODE), balasanNode);
            }
        }
        // Menambahkan tree IDKicauan pada akhir list tree
        insertLastListTree(LT, kicauanNode);
    }
}

// int wordToInt(Word kata) Pindah ke globa func
// {
//     int res = 0;
//     int i = 0;
//     while (kata.TabWord[i] >= '0' && kata.TabWord[i] <= '9' && i < kata.Length)
//     // memeriksa jika char di antara kedua bilangan tersebut (Jika ditambah komen di kanan angka), dan i lebih kecil dari panjang (Jika tidak ada, karena tidak tahu mengapa begitu keluaran 24 untuk ID 2)
//     {
//         res = res * 10 + (kata.TabWord[i] - '0');
//         i++;
//     }
//     return res;
// }

// int main() {
//     ListTree myList;
//     CreateListTree(&myList, 5);

//     // Assuming you have a BALASAN instance:
//     BALASAN balasanData;
//     balasanData.idDiBalas = 101;
//     balasanData.IDBalasan = 201;
//     // ... initialize other fields ...

//     // Create a TreeNode with BALASAN data
//     TreeNode* balasanNode = createNodeWithData(BALASAN_NODE, &balasanData);
//     // Assuming you have a BALASAN instance:
//     BALASAN balasanData2;
//     balasanData2.idDiBalas = 101;
//     balasanData2.IDBalasan = 69;
//     // ... initialize other fields ...

//     // Create a TreeNode with BALASAN data
//     TreeNode* balasanNode2 = createNodeWithData(BALASAN_NODE, &balasanData2);
//     // Assuming you have a BALASAN instance:
//     BALASAN balasanData3;
//     balasanData3.idDiBalas = 101;
//     balasanData3.IDBalasan = 1202;
//     // ... initialize other fields ...

//     // Create a TreeNode with BALASAN data
//     TreeNode* balasanNode3 = createNodeWithData(BALASAN_NODE, &balasanData3);

//     // Assuming you have a KICAUAN instance:
//     KICAUAN kicauanData;
//     kicauanData.ID = 1;
//     kicauanData.Like = 10;
//     // ... initialize other fields ...

//     // Create a TreeNode with KICAUAN data
//     TreeNode* kicauanNode = createNodeWithData(KICAUAN_NODE, &kicauanData);

//     // Print the tree
//     addChild(kicauanNode, balasanNode);
//     addChild(kicauanNode, balasanNode2);

//     PrintTree(kicauanNode, 0);
//     printf("MAX ID = %d\n", getMaxIDBalasan(kicauanNode));

//         // Example usage of IsValidID
//     if (IsValidID(kicauanNode, 69, BALASAN_NODE)) {
//         printf("ID %d found in the tree.\n", 69);
//     } else {
//         printf("ID %d not found in the tree.\n", 69);
//     }

//     // Example usage of SearchTree
//     TreeNode* resultNode = SearchTree(kicauanNode, 69, BALASAN_NODE);
//     if (resultNode != NULL) {
//         printf("Node with ID %d found in the tree.\n", 69);
//     } else {
//         printf("Node with ID %d not found in the tree.\n", 69);
//     }
//     addChild(resultNode, balasanNode3);

//     PrintTree(kicauanNode, 0);
//         // Example usage of IsValidID
//     if (IsValidID(kicauanNode, 1202, BALASAN_NODE)) {
//         printf("ID %d found in the tree.\n", 1202);
//     } else {
//         printf("ID %d not found in the tree.\n", 1202);
//     }

//     deleteNode(kicauanNode, 69, BALASAN_NODE);

//     PrintTree(kicauanNode, 0);

//     insertLastListTree(&myList, kicauanNode);

//     // Print the number of elements in the ListTree
//     printf("Number of elements in myList: %d\n", LengthListTree(myList));

//     // Search for a TreeNode in the ListTree
//     int searchValue = 1;
//     TreeNode* result = searchListTree(myList, searchValue);
//     if (result != NULL) {
//         printf("Node with value %d found in the ListTree.\n", searchValue);
//     } else {
//         printf("Node with value %d not found in the ListTree.\n", searchValue);
//     }

//     // Clean up memory
//     free(balasanNode);
//     free(kicauanNode);
//     dealocateTrees(&myList);
//     return 0;
// }
