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
	Node *left, *right, *parent;
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
		S->left->parent = S;
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
		S->right->parent = S;
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

map<int, Node *> nodeList2;
void mirrorUtil(Node *A, Node *B)
{
	if (A == NULL)
		return;

	B->left = (A->right != NULL) ? new Node(A->right->data) : NULL;
	B->right = (A->left != NULL) ? new Node(A->left->data) : NULL;

	if (B->left != NULL) {
		B->left->parent = B;
	}
	if (B->right != NULL) {
		B->right->parent = B;
	}

	nodeList2.insert(make_pair(B->left->data, B->left)); 
	nodeList2.insert(make_pair(B->right->data, B->right));

	mirrorUtil(A->left, B->right);
	mirrorUtil(A->right, B->left);
}

Node *mirrorTree()
{
	Node *r = new Node(root->data);
	nodeList2.insert(make_pair(r->data, r));
	mirrorUtil(root, r);
	return r;
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

	auto B = mirrorTree();
	inOrderTraversal(B);
	

	/*for (size_t i = 0; i < q; i++)
	{
		int x; 
		cin >> x; 
		Node * a = nodeList[x];
		Node *pa = a->parent; 

		Node *pb = nodeList2[pa->data];

		if (pa->left == a) {
			cout << (pb->left != NULL ? pb->left->data : -1) << endl;
		}
		else {
			cout << (pb->right != NULL ? pb->right->data : -1) << endl;
		}
	}*/

	/*for (auto it = nodeList.begin(); it != nodeList.end(); it++) {
		cout << it->first << " " << it->second->parent->data << endl;
	}
*/
	return 0;
}
