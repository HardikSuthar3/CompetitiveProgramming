#include "bits\stdc++.h"
using namespace std;

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

Node *root;
map<int, Node *> nodeList;

void addNode(int s, int l, int r)
{
	if (s < 0)
	{
		return;
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

	S->left = (nodeList.find(l) == nodeList.end()) ? nodeList[l] : NULL;
	S->right = (nodeList.find(r) == nodeList.end()) ? nodeList[r] : NULL;

}

void inOrderTraversal() {

}