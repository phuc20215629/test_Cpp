#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> res;
vector<bool> check;

void print() {
    for(int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}

void Try(int k) {
    for(int i = 0; i <= 1; i++) {
        res[k] = i;
        if(k == n - 1) print();
        else Try(k + 1);
    }
}

int main() {
    cin >> n;
    res.resize(n + 1, 0);
    //check.resize(n + 1, false);
    Try(0);
    return 0;
}