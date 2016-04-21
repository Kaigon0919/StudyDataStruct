#ifndef __BIRNARYTREE_H_
#define __BIRNARYTREE_H_
#include<iostream>
using namespace std;
struct TreeNode
{
	int data;
	TreeNode * left;
	TreeNode * right;
};

class BirnaryTree
{
private:
	TreeNode * root;
private:
	void insert_node(TreeNode * node, int data);
	TreeNode * search_node(TreeNode * node, int data);
	void Show_node(TreeNode * node)const;
	void remove(TreeNode * node, int data);
	void postorderDelete(TreeNode * node);
	TreeNode * LeftMaxNode(TreeNode * node);
	TreeNode * RightMinNode(TreeNode * node);
	TreeNode * searchParent(TreeNode * node, int data);
public:
	BirnaryTree();
	void insert(int data);
	void remove(int data);
	int search(int data);
	void Show()const;
	~BirnaryTree();
};

#endif