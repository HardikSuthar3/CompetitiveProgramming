#include "bits\stdc++.h"
#include "DS\Tree.h"

int main()
{
	auto file = freopen("D:\\OneDrive - Microsoft\\Development\\C++\\CompetitiveProgramming\\Projects\\DS-Algo\\DS-Algo\\input.txt", "r", stdin);
	BinaryTree bt1, bt2;
	int N, Q;
	cin >> N >> Q;
	bt1.Make_Tree(N);
	if (bt1.Set_root(1) == false)
	{
		exit(0);
	}

	bt1.BFS(bt1.root);
	return 0;
}
