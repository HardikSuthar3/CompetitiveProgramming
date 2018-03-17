#include "bits\stdc++.h"
using namespace std;

class Node; 

Node *root;
map<int, Node *> nodeList;


class Node
{
public:
	int data;
	Node *left, *right;
	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
		nodeList.insert(make_pair(data, this));
	}
};




void inOrderTraversal(Node *start)
{
	if (start->left != NULL)
	{
		inOrderTraversal(start->left);
	}
	cout << start->data << endl;

	if (start->right != NULL)
	{
		inOrderTraversal(start->right);
	}
}

void preOrderTraversal(Node *start)
{
	cout << start->data << endl;

	if (start->left != NULL)
	{
		inOrderTraversal(start->left);
	}

	if (start->right != NULL)
	{
		inOrderTraversal(start->right);
	}
}

void postOrderTraversal(Node *start)
{
	cout << start->data << endl;

	if (start->left != NULL)
	{
		inOrderTraversal(start->left);
	}

	if (start->right != NULL)
	{
		inOrderTraversal(start->right);
	}
}