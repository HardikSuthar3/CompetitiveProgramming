#include "bits/stdc++.h"
using namespace std;
//class Node;
//Node *root;
//map<int, Node *> nodeList;

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
		//nodeList.insert(make_pair(data, this));
	}
};

class BinaryTree
{
  public:
	Node *root;
	map<int, Node *> nodeList;
	Node *addNode(int s, int l, int r);
	void Make_Tree(int N);
	bool Set_root(int r);
	void inOrderTraversal(Node *start);
	void preOrderTraversal(Node *start);
	void postOrderTraversal(Node *start);
	void BFS(Node *start);
	void DFS(Node *start);
};

Node *BinaryTree::addNode(int s, int l, int r)
{
	if (s < 0)
	{
		return NULL;
	}

	Node *S;

	if (nodeList.find(s) == nodeList.end())
	{
		S = new Node(s);
		nodeList.insert(make_pair(s, S));
	}
	else
	{
		S = nodeList[s];
	}

	if (l > 0)
	{
		S->left = (nodeList.find(l) != nodeList.end()) ? nodeList[l] : addNode(l, -1, -1);
	}
	else
	{
		if (S->left != NULL)
			;
		else
		{
			S->left = NULL;
		}
	}

	if (r > 0)
	{
		S->right = (nodeList.find(r) != nodeList.end()) ? nodeList[r] : addNode(r, -1, -1);
	}
	else
	{
		if (S->right != NULL)
			;
		else
		{
			S->right = NULL;
		}
	}
	return S;
}

void BinaryTree::Make_Tree(int N)
{
	for (int i = 0; i < N - 1; i++)
	{
		int par, child;
		char ch;
		cin >> par >> child >> ch;
		switch (ch)
		{
		case 'L':
			addNode(par, child, -1);
			break;
		default:
			addNode(par, -1, child);
			break;
		}
	}
}

bool BinaryTree::Set_root(int r)
{
	if (nodeList.find(r) == nodeList.end())
	{
		return false;
	}

	this->root = nodeList.at(r);
	return true;
}

void BinaryTree::inOrderTraversal(Node *start)
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

void BinaryTree::preOrderTraversal(Node *start)
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

void BinaryTree::postOrderTraversal(Node *start)
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

void BinaryTree::BFS(Node *start)
{
	if (start == NULL)
	{
		return;
	}

	Node *u = start;

	set<int> visited;

	queue<Node *> que;
	que.push(u);

	while (!que.empty())
	{
		Node *node = que.front();
		que.pop();
		visited.insert(node->data);

		cout << node->data << " ";
		if (node->left != NULL && binary_search(visited.begin(), visited.end(), node->left->data) == false)
		{
			que.push(node->left);
		}

		if (node->right != NULL && binary_search(visited.begin(), visited.end(), node->right->data) == false)
		{
			que.push(node->right);
		}
	}
}

void BinaryTree::DFS(Node *start)
{
	static set<int> visited;

	if (start == NULL)
	{
		return;
	}

	if (binary_search(visited.begin(), visited.end(), start->data))
	{
		return;
	}

	int x = start->data;
	visited.insert(x);
	cout << x << " ";

	auto tmp = start;

	if (tmp->left != NULL)
	{
		DFS(tmp->left);
	}

	if (tmp->right != NULL)
	{
		DFS(tmp->right);
	}
}
