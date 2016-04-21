#include "BinaryTree.h"

//private
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
void BirnaryTree::Show_node(TreeNode * node) const
{
	if (!node) {
		cout << "NULL";
		return;
	}
	cout << node->data << '(';
	Show_node(node->left);
	cout << ',';
	Show_node(node->right);
	cout << ')';
}
void BirnaryTree::remove(TreeNode * node, int data)
{
	if (!node)
		return;
	TreeNode * parent;
	TreeNode * taget = search_node(node, data);
	TreeNode * temp;
	if (!taget)
	{
		cout << "Error Not data" << endl;
		return;
	}

	if (!taget->left && !taget->right)
	{
		parent = searchParent(node, data);
		if (parent->left == taget)
			parent->left = NULL;
		else
			parent->right = NULL;
		delete taget;
		return;
	}
	else if (taget->left)
	{
		temp = LeftMaxNode(taget->left);
		parent = searchParent(taget, temp->data);

		taget->data = temp->data;
		parent->left = temp->right;
	}
	else
	{
		temp = RightMinNode(taget->right);
		parent = searchParent(taget, temp->data);

		taget->data = temp->data;
		parent->right = temp->left;
	}


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
TreeNode * BirnaryTree::LeftMaxNode(TreeNode * node)
{
	if (!node->right)
		return node;
	return LeftMaxNode(node->right);
}
TreeNode * BirnaryTree::RightMinNode(TreeNode * node)
{
	if (!node->left)
		return node;
	return RightMinNode(node->left);
}
TreeNode * BirnaryTree::searchParent(TreeNode * node, int data)
{
	TreeNode * parent;
	if (root->data == NULL || data == node->data)
		return NULL;
	else if (data < node->data)
	{
		if (node->left->data == data)
			return node;
		searchParent(node->left, data);
	}
	else if (data > node->data)
	{
		if (node->right->data == data)
			return node;
	searchParent(node->right, data);
	}
	else
		return NULL;
}
//public
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
	Show_node(root);
	cout << endl;
}
BirnaryTree::~BirnaryTree()
{
	postorderDelete(root);
}

