#include "bits/stdc++.h"
using namespace std;

void next_greater(vector<int> &a)
{
    stack<int> st;
    st.push(a[0]);
    for (int i = 1; i < a.size(); i++)
    {
        int next = a[i];
        if (!st.empty())
        {
            while (next > st.top())
            {
                cout << st.top() << "->" << next << endl;
                st.pop();
                if (st.empty())
                    break;
            }
        }
        st.push(next);
    }

    while (st.empty() == false)
    {
        cout << st.top() << "->-1" << endl;
        st.pop();
    }
}

int main()
{
    auto file = freopen("D:\\OneDrive - Microsoft\\Development\\C++\\CompetitiveProgramming\\Projects\\DS-Algo\\DS-Algo\\input.txt", "r", stdin);
    int n;
    cin >> n;
    stack<int> st_h, st_m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st_h.push(x);
    }
    int q, x;
    cin >> q >> x;
    cin.ignore();
    int coinSum = 0;
    for (int i = 0; i < q; i++)
    {
        string line;
        std::getline(cin, line);
        cout << i << ":" << line << endl;
        if (line == "Harry")
        {
            st_m.push(st_h.top());
            coinSum += st_h.top();
            st_h.pop();
        }
        else
        {
            coinSum -= st_m.top();
            st_m.pop();
        }
        if (coinSum == x)
        {
            cout << st_m.size();
        }
        else
        {
            cout << -1;
        }
    }
    return 0;
}