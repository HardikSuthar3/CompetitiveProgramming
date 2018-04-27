// Hi this is comments
//#include "bits/stdc++.h"

#include "bits/stdc++.h"
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

void BFS(Node * start) {
	if (start == NULL) {
		return;
	}
	unordered_map<int, bool> isVisited;
	queue<Node *> que;
	que.push(start);
	set<int> visited;

	while (!que.empty()) {
		Node * tmp = que.front();
		que.pop();
		visited.insert(tmp->data);

		cout << tmp->data << " ";

		if (tmp->left != NULL && binary_search(visited.begin(), visited.end(), tmp->left->data) == false) {
			que.push(tmp->left);
		}

		if (tmp->right != NULL && binary_search(visited.begin(), visited.end(), tmp->right->data) == false) {
			que.push(tmp->right);
		}
	}

}

void Make_tree() {
	int N, Q;
	std::cin >> N >> Q;

	for (int i = 0; i < N - 1; i++) {
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


int main()
{
	auto file = freopen("D:\\OneDrive - Microsoft\\Development\\C++\\CompetitiveProgramming\\Projects\\DS-Algo\\DS-Algo\\input.txt", "r", stdin);
	Make_tree();
	BFS(nodeList[1]);

	return 0;
}
