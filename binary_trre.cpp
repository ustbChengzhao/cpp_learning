#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNOde *right;
	TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};


int main() {
	
	/* ��ʼ�������� */
	// ��ʼ���ڵ� 
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	// �����ڵ�֮���ָ�� 
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	
	
	// ����ڵ�
	TreeNode *P = new TreeNode(0);
	n1->left =  
	return 0;
}
