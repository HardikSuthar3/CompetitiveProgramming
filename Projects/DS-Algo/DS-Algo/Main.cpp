#include "bits\stdc++.h"
using namespace std;

int main()
{
	vector<int> number;
	for (size_t i = 0; i < 20; i++)
	{
		number.push_back(i + 1);
	}

	cout << number.size() << endl;
	for (auto item : number) {
		cout << item << " ";
	}
	return 0;
}
