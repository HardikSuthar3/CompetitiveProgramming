// Hi this is comments
#include "bits/stdc++.h"
using namespace std;

class Node;
void inOrderTraversal(Node *);

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

Node *addNode(int s, int l, int r)
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
		if (S->left != NULL);
		else {
			S->left = NULL;
		}
	}

	if (r > 0)
	{
		S->right = (nodeList.find(r) != nodeList.end()) ? nodeList[r] : addNode(r, -1, -1);
	}
	else
	{
		if (S->right != NULL);
		else
		{
			S->right = NULL;
		}
	}
	return S;
}

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

int main()
{
	freopen("D:\\OneDrive - Microsoft\\Development\\C++\\CompetitiveProgramming\\DS-Algo\\DS-Algo\\input.txt", "r", stdin);
	int n, q;
	cin >> n >> q;
	root = new Node(1);
	nodeList.insert(make_pair(1, root));

	for (int i = 0; i < n; i++)
	{
		int x, y;
		char ch;
		cin >> x >> y >> ch;

		/*Node *a, *b;
		a = (nodeList.find(x) == nodeList.end() ? new Node(x) : nodeList[x]);
		b = (nodeList.find(y) == nodeList.end() ? new Node(y) : nodeList[y]);*/

		switch (ch)
		{
		case 'R':
			addNode(x, -1, y);
			break;
		default:
			addNode(x, y, -1);
		}
	}

	inOrderTraversal(root);
	return 0;
}
