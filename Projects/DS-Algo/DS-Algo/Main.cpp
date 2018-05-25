#include "bits\stdc++.h"
#include "DS\Tree.h"

int main()
{
	auto file = freopen("D:\\OneDrive - Microsoft\\Development\\C++\\CompetitiveProgramming\\Projects\\DS-Algo\\DS-Algo\\input.txt", "r", stdin);
	int n;
	cin >> n;
	vector<int> A(n + 1), F(n + 1), G(n + 1);

	for (size_t i = 1; i <= n; i++)
	{
		cin >> A[i];
	}

	// Define G and F array
	for (int i = 1; i <= n; i++)
	{
		int j;
		for (j = i + 1; j <= n; j++)
		{
			if (A[i] < A[j])
			{
				F[i] = j;
				break;
			}
		}
		if (j > n)
		{
			F[i] = -1;
		}
		for (j = i + 1; j <= n; j++)
		{
			if (A[i] > A[j])
			{
				G[i] = j;
				break;
			}
		}
		if (j > n)
		{
			G[i] = -1;
		}
	}

	// Print Output
	for (int i = 1; i <= n; i++) {
		/*if (F[i] == -1 || G[i] == -1) {
			cout << -1 << " ";
		}
		else {
			cout << A[G[F[i]]] << " ";
		}*/
		int x, y;
		x = F[i];
		if (x > 0) {
			y = G[x];
			if (y > 0) {
				cout << A[y] << " ";
			}
		}
		else {
			cout << -1 << " ";
		}
	}



	return 0;
}
