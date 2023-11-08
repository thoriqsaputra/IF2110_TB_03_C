#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode) {
        INGFO(*newNode)= data; 
        AnakPertama(*newNode) = NULL;
        SaudaraBerikut(*newNode) = NULL;
    }
    return newNode;
}

void deallocateTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    deallocateTree(AnakPertama(*root));
    deallocateTree(SaudaraBerikut(*root));

    free(root);
}

void addChild(TreeNode* parent, TreeNode* child) {
    if (parent == NULL || child == NULL) {
        return;
    }

    if (AnakPertama(*parent) == NULL) {
        AnakPertama(*parent) = child;
    } else {
        TreeNode* current = AnakPertama(*parent);
        while (SaudaraBerikut(*current) != NULL) {
            current = SaudaraBerikut(*current);
        }
        SaudaraBerikut(*current) = child;
    }
}

void PrintTree(TreeNode* root, int level) {
    for (int i = 0; i < level; i++) {
        printf("\t");
    }
    printf("%d\n", INGFO(*root));

    TreeNode* current = AnakPertama(*root);
    while (current != NULL) {
        PrintTree(current, level + 1);
        current = SaudaraBerikut(*current);
    }
}

void deleteNode(TreeNode* parent, int target) {
    if (parent == NULL) {
        return;
    }

    TreeNode* current = AnakPertama(*parent);
    TreeNode* prev = NULL;

    while (current != NULL) {
        if (INGFO(*current) == target) {
            if (prev != NULL) {
                SaudaraBerikut(*prev) = SaudaraBerikut(*current);
            } else {
                AnakPertama(*parent) = SaudaraBerikut(*current);
            }
            free(current);
            return;
        }
        prev = current;
        current = SaudaraBerikut(*current);
    }

    current = AnakPertama(*parent);
    while (current != NULL) {
        current = SaudaraBerikut(*current);
    }
}

TreeNode* SearchTree(ListTree *lt, int target){

    for(int i = 0; i < NEFFListTree(*lt); i++) {
        if(INGFO(*ELMTListTree(*lt, i)) == target) {
            return ELMTListTree(*lt,i);
        }
    }
    printf("Tidak terdapat Tree dengan target tersebut pada list tree\n");      
}


boolean IsValidID(TreeNode* parent, int target) {
    if (parent == NULL) {
        return false;
    }

    TreeNode* current = AnakPertama(*parent);

    while (current != NULL) {
        if (INGFO(*current) == target) {
            return true;
        }
        current = SaudaraBerikut(*current);
    }

    return false;
}

/* ********** KONSTRUKTOR ListDinTree ********** */
/* Konstruktor : create list kosong  */
void CreateListTree(ListTree *lt, int capacity)
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity dan diisi tree */
{
    NEFFListTree(*lt) = 0;
    ContentListTree(*lt) = (ListTree *)malloc(capacity * sizeof(ListTree));
    CAPACITYLISTTREE(*lt) = capacity;
}
void dealocateTrees(ListTree *lt)
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */
{
    free(ContentListTree(*lt));
    NEFFListTree(*lt) = 0;
    CAPACITYLISTTREE(*lt) = 0;
}