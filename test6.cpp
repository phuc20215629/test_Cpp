#include <bits/stdc++.h> 
using namespace std;

vector<vector<double>> c;

double C(int k, int n) {
    if(c[k][n] != -1) return c[k][n];
    if(k == 0 || k == n) return c[k][n] = 1;
    if(k > n) return c[k][n] = 0;
    else return c[k][n] = C(k - 1, n - 1) + C(k, n - 1);
}

int main() 
{ 
    int k, n;
    cin >> k >> n;
    c.resize(k + 1, vector<double>(n + 1, -1));
    double res = C(k, n);
    cout << res << endl;
    return 0;
}