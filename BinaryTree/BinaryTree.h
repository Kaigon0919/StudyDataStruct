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
	void insert_node(TreeNode * node, int data);
	TreeNode * search_node(TreeNode * node, int data);
	void Showlevel(TreeNode * node)const;
	void remove(TreeNode * node, int data);
	void postorderDelete(TreeNode * node);
public:
	BirnaryTree();
	void insert(int data);
	void remove(int data);
	int search(int data);
	void Show()const;
	~BirnaryTree();
};

#endif