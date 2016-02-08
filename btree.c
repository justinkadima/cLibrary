#include<stdio.h>
#include<stdlib.h>
#include"btree.h"


static bool findInsertionNode(btree* tree,node** root, void* val);
static node* searchNode(btree* tree,node* root,void* val);
static node* findMinNode(node* top);
static node* findMaxNode(node* top);
static node* deleteBtreeNode(btree* tree,node* root,void* val);
static void deleteBtreeNodes(node** root);


btree* BTree_Init(btreeFuncCompare cFunc)
{
    btree* tree=(btree*)malloc(sizeof(btree));
    if(!tree)
    {
        perror("Unable to allocate memory!");
        return NULL;
        
    }
    
    tree->root=NULL;
    tree->nrNodes=0;
    tree->compareFunc=cFunc;
    return tree;
    
}

bool BTree_AddNode(btree* tree,void* val)
{
	if(!tree)return false;
	
	
	if(tree->root==NULL)
	{
		tree->root=(node*)malloc(sizeof(node));
		if(!tree->root)
		{
		    perror("Unable to allocate memmory");
		    return false;
		}
		
		(tree->root)->val=val;
		(tree->root)->left=NULL;
		(tree->root)->right=NULL;
	}
	else
	{
	   if(!findInsertionNode(tree,&tree->root,val))
	   {
	       return false;
	   }
	}
	
    tree->nrNodes++;
    return true;

}

static bool findInsertionNode(btree* tree,node** root, void* val)
{
   if((*root)==NULL)
	{
		*root=(node*)malloc(sizeof(node));
		if(*root)
		{
			(*root)->val=val;
			(*root)->left=NULL;
			(*root)->right=NULL;
			return true;
		}
		return false;
	}
	else
	{
	    if( tree->compareFunc((*root)->val,val)>0 )
	    {
		    return findInsertionNode(tree,&((*root)->right),val);
		}
		if(tree->compareFunc((*root)->val,val)<0)
		{
			return findInsertionNode(tree,&((*root)->left),val);
		}
	}
    
    
}


void BTree_Traverse(node* root,btOrder order,btreeTraversFunc tfunc)
{
	if(root==NULL)return;
	switch(order)
	{
		case InOrder:
				BTree_Traverse(root->left,order,tfunc);
				tfunc(root->val);
				BTree_Traverse(root->right,order,tfunc);
		break;
		case PreOrder:
				tfunc(root->val);
				BTree_Traverse(root->left,order,tfunc);
				BTree_Traverse(root->right,order,tfunc);
		break;
		case PostOrder:
				BTree_Traverse(root->left,order,tfunc);
				BTree_Traverse(root->right,order,tfunc);
				tfunc(root->val);
		break;
		
	}


}


node* BTree_FindMinNode(btree* tree)
{
	return findMinNode(tree->root);
}

node* BTree_FindMaxNode(btree* tree)
{
	return findMaxNode(tree->root);
}

static node* findMinNode(node* top)
{
	if(!top)return NULL;
	if(top->right==NULL)return top;
	return findMinNode(top->right);
}

static node* findMaxNode(node* top)
{
	if(!top)return NULL;
	if(top->left==NULL)return top;
	return findMaxNode(top->left);
}


	
node* BTree_Search(btree* tree,void* val)
{
	return searchNode(tree,tree->root,val);
}

static node* searchNode(btree* tree,node* root,void* val)
{
	if(root==NULL)return NULL;
	
	if(tree->compareFunc(root->val,val)==0)
	{
		return root;
	}
	else
	{
		if(tree->compareFunc(root->val,val)<0)
		{
			return searchNode(tree,root->left,val);
		}
		if(tree->compareFunc(root->val,val)>0)
		{
			return searchNode(tree,root->right,val);
		}
	}
}





node* BTree_DeleteNode(btree* tree, void* val)
{
	
	return deleteBtreeNode(tree,tree->root,val);
	
}

static node* deleteBtreeNode(btree* tree,node* root,void* val)
{
	if(root==NULL)return NULL;
	else if(tree->compareFunc(root->val,val)<0)root->left=deleteBtreeNode(tree,root->left,val);
	else if(tree->compareFunc(root->val,val)>0)root->right=deleteBtreeNode(tree,root->right,val);
	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			free(root);
			root=NULL;
			
		}
		else if(root->left==NULL && root->right!=NULL)
		{
			node* temp=root;
			root=root->right;
			free(temp);
			
			
			
		
		}
		else if(root->right==NULL && root->left!=NULL)
		{
			node* temp=root;
			root=root->left;
			free(temp);
			
		}
		else
		{
			node* min=findMinNode(root->right);
			root->val=min->val;
			root->right=deleteBtreeNode(tree,root->right,min->val);
			
		}
		
	
	}
	
	return root;

}



void BTree_Delete(btree** tree)
{
    if(tree)
    {
        deleteBtreeNodes(&((*tree)->root));
        free(*tree);
        *tree=NULL;
        
    }
}

static void deleteBtreeNodes(node** root)
{
	if(*root)
	{
		deleteBtreeNodes(&((*root)->left));
		deleteBtreeNodes(&((*root)->right));
		free(*root);
		*root=NULL;
	}

}
