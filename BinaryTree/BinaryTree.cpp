#include "BinaryTree.h"
void BirnaryTree::insert_node(TreeNode * node, int data)
{
	if (node->data == NULL)
		node->data = data;
	else if (data <= node->data)
	{
		if (node->left != NULL)
			insert_node(node->left, data);
		else
			node->left = new TreeNode{ data,NULL,NULL };
	}
	else if (data > node->data)
	{
		if (node->right != NULL)
			insert_node(node->right, data);
		else
			node->right = new TreeNode{ data,NULL,NULL };
	}
	else
		cout << "error" << endl;
}

TreeNode * BirnaryTree::search_node(TreeNode * node, int data)
{
	if (root ->data == NULL)
		return NULL;
	if (data == node->data)
		return node;
	else if (data < node->data)
		search_node(node->left, data);
	else if (data > node->data)
		search_node(node->right, data);
	else
		return NULL;
}

void BirnaryTree::Showlevel(TreeNode * node) const
{

}

void BirnaryTree::remove(TreeNode * node, int data)
{

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
	remove(root, data);
}

int BirnaryTree::search(int data)
{
	
	TreeNode * temp = search_node(root, data);
	return temp? temp->data: -1;
}

void BirnaryTree::Show() const
{


}

BirnaryTree::~BirnaryTree()
{
	postorderDelete(root);
}
void BirnaryTree::postorderDelete(TreeNode * node)
{
	if (node != NULL)
	{
		postorderDelete(node->left);
		postorderDelete(node->right);
		delete node;
	}
}
