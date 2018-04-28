#include "bits/stdc++.h"

using namespace std;

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
    }

    return 0;
}