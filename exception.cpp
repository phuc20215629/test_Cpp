#include<bits/stdc++.h>
using namespace std;

double divide(int a, int b) {
    if(b == 0) throw("Divide by zero!");
    else return (double)a / b;
}

int main() {
    int x, y;
    cin >> x >> y;
    try {
        double z = divide(x, y);
        cout << z << endl;
    } catch(const char* msg) {
        cerr << msg << endl;
    }
    cout << "Continue" << endl;

    int M[3][3] = {{1,2,3}, {4,5},};
    for(int i = 0; i < sizeof(M) / sizeof(M[1]); i++) {
        for(int j = 0; j < sizeof(M[0]) / 4; j++) cout << M[i][j] << " ";
        cout << endl; 
    }
    return 0;
}