#include "BinaryTree.h"

void BirnaryTree::insert_node(TreeNode * node, int data)
{
	if (node->data == NULL)
		node->data = data;
	else if (data <= node->data)
		insert_node(node->left, data);
	else if (data > node->data)
		insert_node(node->right, data);
	else
		cout << "error" << endl;
}

TreeNode * BirnaryTree::search_node(TreeNode * node, int data)
{
	if (data == node->data)
		return node;
	else if (data < node->data)
		search_node(node->left, data);
	else if (data > node->data)
		search_node(node->right, data);
	else
		return NULL;
}

TreeNode * BirnaryTree::remove(TreeNode * node, int data)
{
	if (data == node->data)
	{
		
	}
	return nullptr;
}

BirnaryTree::BirnaryTree()
{
	root = new TreeNode{ NULL,NULL,NULL };
}
void BirnaryTree::insert(int data)
{
	insert_node(root, data);
}
void BirnaryTree::remove(int data)
{

}

int BirnaryTree::search(int data)
{
	return search_node(root, data)->data;
}

BirnaryTree::~BirnaryTree()
{

}
