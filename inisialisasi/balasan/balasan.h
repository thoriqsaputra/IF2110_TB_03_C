#ifndef BALASAN_H
#define BALASAN_H

#include "../../ADT/tempRun.h"
#include "../../ADT/datetime.h"
#include "../kicauan/kicauan.h"

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/
#define INVALID_ID -999

/* Definisi elemen dan koleksi objek */
typedef struct BALASAN
{
    int idDiBalas;
    int IDBalasan;
    Word TextBalasan;
    Word Author;
    DATETIME DT;
} BALASAN;

/* ********** SELEKTOR BALASAN ********** */
#define idDiBalas(l) (l).idDiBalas
#define IDBalasan(l) (l).IDBalasan
#define TxtBalasan(l) (l).TextBalasan
#define AuthorBalasan(l) (l).Author
#define DatetimeBalasan(l) (l).DT

// Enumeration to represent the type of node
typedef enum { KICAUAN_NODE, BALASAN_NODE } NodeType;

// TreeNode structure
typedef struct TreeNode {
    NodeType type;  // Type of the node
    union {
        KICAUAN kicauanData;  // Data for KICAUAN node
        BALASAN balasanData;  // Data for BALASAN node
    };
    struct TreeNode* firstChild;
    struct TreeNode* nextSibling;
} TreeNode;

// ListTree structure
typedef struct {
    TreeNode** ContentListTree;  // Array of pointers to TreeNode
    int NEFFListTree;            // Number of elements in the list
    int CAPACITYLISTTREE;        // Capacity of the list
} ListTree;


// Function to create a node with specific type and data
TreeNode* createNodeWithData(NodeType type, void* data);

// Function to add a child node to the parent node
void addChild(TreeNode* parent, TreeNode* child);

// Function to print the tree
void PrintTree(TreeNode* root, int level);

boolean IsValidID(TreeNode* parent, int target, NodeType targetType);

TreeNode* SearchTree(TreeNode* parent, int target, NodeType targetType);

void deleteNode(TreeNode* parent, int target, NodeType targetType);

int getMaxIDBalasan(TreeNode* parent);

/* ********** KONSTRUKTOR ListDinTree ********** */
/* Konstruktor : create list kosong  */
void CreateListTree(ListTree* lt, int capacity);

void dealocateTrees(ListTree* lt);

int LengthListTree(ListTree l);

void copyListTree(ListTree lIn, ListTree* lOut);

void deleteLastListTree(ListTree* l, TreeNode** tree);

void expandListTree(ListTree* l, int num);

void insertLastListTree(ListTree* l, TreeNode* tree);

void shrinkListDinTree(ListTree* l, int num);

TreeNode* searchListTree(ListTree l, int value);

BALASAN* findBalasan(ListTree LT, int IDKicauan, int IDBalasan);

/* ********* CONFIGS ********* */
void loadBalasanConfig(char filename[], ListTree *LT);
/* I.S. l kosong; */
/* F.S. l diisi sesuai config */

// /* ********** FUNGSI LAIN ********** */
// void displayBalasan(ListDinBalasan B);

// void displayListB(ListDinListB lb);

int wordToInt(Word kata);

#endif