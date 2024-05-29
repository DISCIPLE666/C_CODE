#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"队列.h"
typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	assert(a);
	if (a == NULL)
		return NULL;
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL)
	{
		perror("malloc fail");
		exit(1);
	}
	root->_data = a[(*pi)++];
	root->_left = BinaryTreeCreate(a, n, pi);
	root->_right = BinaryTreeCreate(a, n, pi);
	return root;
}
// 二叉树销毁
void BinaryTreeDestory(BTNode** root)
{
	assert(*root);
	
	if (*root == NULL)
		return;
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free(root);
	
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	assert(root);
	if (root == NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
	return BinaryTreeSize(root) - 1;
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(root);
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	assert(root);
	if (root == NULL)
		return NULL;
	if (root->_data == x)
		return root;
	BTNode* retleft=BinaryTreeFind(root->_left,x);
	if (retleft)
		return retleft;
	BTNode* retright=BinaryTreeFind(root->_right, x);
	return retright;
}
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root)
{
	assert(root);
	if (root == NULL)
	{
		printf("N");
		return;
	}
	printf("%d", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
	assert(root);
	if (root == NULL)
	{
		printf("N");
		return;
	}
	
	BinaryTreePrevOrder(root->_left);
	printf("%d", root->_data);
	BinaryTreePrevOrder(root->_right);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
	assert(root);
	if (root == NULL)
	{
		printf("N");
		return;
	}
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%d", root->_data);
}
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root)
{
	assert(root);
	
}
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);