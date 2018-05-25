#include "bits/stdc++.h"
using namespace std;

<<<<<<< HEAD
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
=======
int main() {
//    freopen("/HSData/Data/Development/CPP Projects/CompetitiveProgramming/Projects/DS-Algo/DS-Algo/input.txt", "r",stdin);
    int bt1[10001], bt2[10001], map1[10001], map2[10001];
    int N, Q;
    int ind1, ind2;
    cin >> N >> Q;

    for (int i = 0; i < 10001; i++) {
        map1[i] = map2[i] = bt1[i] = bt2[i] = -1;
    }

    map1[1] = map2[1] = bt1[1] = bt2[1] = 1;

    for (int i = 0; i < N - 1; i++) {
        int x, y;
        char z;
        cin >> x >> y >> z;

        switch (z) {
            case 'L':
                ind1 = 2 * map1[x];
                ind2 = 2 * map2[x] + 1;
                break;
            default:
                ind1 = 2 * map1[x] + 1;
                ind2 = 2 * map2[x];
                break;
        }
        bt1[ind1] = y;
        bt2[ind2] = y;

        map1[y] = ind1;
        map2[y] = ind2;
    }

    while (Q--) {
        int q;
        cin >> q;
        cout << bt2[map1[q]] << endl;
>>>>>>> 65fa58f243aae2e6a7f14560efbea27e114772aa
    }
    return 0;
}