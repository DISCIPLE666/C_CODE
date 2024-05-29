#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"����.h"
typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
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
// ����������
void BinaryTreeDestory(BTNode** root)
{
	assert(*root);
	
	if (*root == NULL)
		return;
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free(root);
	
}
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	assert(root);
	if (root == NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	return BinaryTreeSize(root) - 1;
}
// ��������k��ڵ����
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
// ����������ֵΪx�Ľڵ�
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
// ������ǰ����� 
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
// �������������
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
// �������������
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
// �������
void BinaryTreeLevelOrder(BTNode* root)
{
	assert(root);
	
}
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);