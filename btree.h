#ifndef BTREE_H
#define BTREE_H

#include<stdbool.h>


typedef struct _node  // the structure of a binary tree node
{
	void* val;
	struct _node* right;
	struct _node* left;
}node;


typedef int (*btreeFuncCompare)(void*,void*);
typedef void (*btreeTraversFunc)(void*);

typedef struct 
{
    node* root;
    btreeFuncCompare compareFunc;
    int nrNodes;
}btree;

typedef enum
{
    InOrder,
    PreOrder,
    PostOrder
}btOrder;



btree* BTree_Init(btreeFuncCompare cFunc);
bool   BTree_AddNode(btree* tree,void* val);
void   BTree_Traverse(node* root,btOrder order,btreeTraversFunc tfunc);
node*  BTree_Search(btree* tree,void* val);
node*  BTree_FindMinNode(btree* tree);
node*  BTree_FindMaxNode(btree* tree);
node*  BTree_DeleteNode(btree* tree, void* val);
void   BTree_Delete(btree** tree);



static bool findInsertionNode(btree* tree,node** root, void* val);
static node* searchNode(btree* tree,node* root,void* val);
static node* findMinNode(node* top);
static node* findMaxNode(node* top);
static node* deleteBtreeNode(btree* tree,node* root,void* val);
static void deleteBtreeNodes(node** root);

#endif
