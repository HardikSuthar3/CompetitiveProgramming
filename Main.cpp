#include "bits/stdc++.h"

using namespace std;

int main() {
    vector<int> numbers;

                        for (int i = 0; i < 10; i++) {
        numbers.push_back(i + 1);
    }

    for (auto &item : numbers) {
        cout << item << " ";
    }
    return 0;
}


