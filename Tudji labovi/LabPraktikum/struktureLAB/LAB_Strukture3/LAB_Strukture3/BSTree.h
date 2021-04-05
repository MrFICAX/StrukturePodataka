#pragma once
#include "BSTNode.h"
#include <Math.h>



class BSTree
{

protected:
	BSTNode* root;
	long numberOfElements;



public:
	BSTNode* vratiroot()
	{
		return root;
	}

	BSTree()
	{
		root = NULL;
		numberOfElements = 0;
	}

	~BSTree()
	{
		deleteTree(root);
	}

	void deleteTree(BSTNode* p)
	{
		if (p != NULL)
		{
			deleteTree(p->left);
			deleteTree(p->right);
			delete p;
		}
	}

	void insert(int el)
	{
		{
			BSTNode *p = root;
			BSTNode *prev = NULL;
			while (p != NULL)
			{
				prev = p;
				if (p->isLT(el))
					p = p->right;
				else
					p = p->left;
			}
			if (root == NULL)
				root = new BSTNode(el);
			else
				if (prev->isLT(el))
					prev->right = new BSTNode(el);
				else
					prev->left = new BSTNode(el);
			numberOfElements++;
		}
	}

	void preorder()
	{
		preorder(root);
	}

	void preorder(BSTNode* p)
	{
		if (p != NULL)
		{
			p->visit();
			preorder(p->left);
			preorder(p->right);
		}
	}

	int level1(BSTNode * p, int k,int i)
	{
		if (p == NULL)
			return -1;
		if (p->key == k)
			return i;
		else
			if (p->left == NULL && p->right == NULL)
				return -1;
			else
				return max(level1(p->left, k, i + 1), level1(p->right, k, i + 1));
		

			}
	int level(int k)
	{
		return level1(this->root, k, 0);
			

		}
	int diffLevel(BSTNode * p, int k1, int k2)
	{
		return abs(level1(root, k1, 0) - level1(root, k2, 0));
		//return level(k1)-level(k2);
	}
	
	int max(int a,int b)
	{
		if (a>b)
			return a;
		else
			return b;

} 
	



   
};