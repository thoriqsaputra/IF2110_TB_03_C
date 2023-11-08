#ifndef TREE_H
#define TREE_H

#include "boolean.h"

/* Definisi elemen dan koleksi objek */
typedef struct TreeNode {
    int data;
    struct TreeNode* firstChild;
    struct TreeNode* nextSibling;
} TreeNode;

/* ********** SELEKTOR TREE ********** */
#define INGFO(node) (node).data
#define AnakPertama(node) (node).firstChild
#define SaudaraBerikut(node) (node).nextSibling

/* Definisi elemen dan koleksi objek */
typedef struct {
    TreeNode* *contentTree;
    int capacityListTree;
    int nEffListTree;
} ListTree;

/* ********** SELEKTOR ListTree ********** */
#define ELMTListTree(l, i) (l).contentTree[i]
#define ContentListTree(l) (l).contentTree
#define NEFFListTree(l) (l).nEffListTree
#define CAPACITYLISTTREE(l) (l).capacityListTree

/* ********** KONSTRUKTOR TREE ********** */
/* Konstruktor : create list kosong  */
TreeNode* createNode(int data);

void deallocateTree(TreeNode* root);

void addChild(TreeNode* parent, TreeNode* child);

void PrintTree(TreeNode* root, int level);

void deleteNode(TreeNode* parent, int target);

TreeNode* SearchTree(ListTree *lt, int target);

/* ********** KONSTRUKTOR ListDinTree ********** */
/* Konstruktor : create list kosong  */
void CreateListTree(ListTree *lt, int capacity);
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity dan diisi tree */

void dealocateTrees(ListTree *lt);
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** BOOLEAN ********** */
boolean IsValidID(TreeNode* parent, int target);

#endif