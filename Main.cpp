#include "bits/stdc++.h"

using namespace std;

int main()
{
    string name = " Hardik";
    vector<int> number;
    for (int i = 0; i < 10; i++)
    {
        number.push_back(i + 1);
    }

    for (auto &i : number)
    {
        cout << i << " ";
        
    }

    return 0;
}