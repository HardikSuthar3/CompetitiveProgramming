#include "bits/stdc++.h"
using namespace std;

int main(){
    string name = "Hardik";
    vector<int> number;
    for (int i = 0; i < 100; ++i) {
        number.push_back(i+1);
    }

    for(auto &item : number){
        cout<< item << " ";
    }
}