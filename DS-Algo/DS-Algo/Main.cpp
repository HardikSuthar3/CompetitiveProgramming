// Hi this is comments
#include "bits/stdc++.h"
using namespace std;
int main()
{
	freopen("D:\\OneDrive - Microsoft\\Development\\C++\\CompetitiveProgramming\\DS-Algo\\DS-Algo\\input.txt", "r", stdin);
	priority_queue<int, vector<int>, std::greater<int>> pq;

	for (int i = 0; i < 100; i++)
	{
		pq.push(i + 1);
	}

	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	return 0;
}
