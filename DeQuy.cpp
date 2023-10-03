#include<bits/stdc++.h>
using namespace std;

int Y(int n);

int X(int n) {
    if(n <= 6) return 2 * n - 2;
    else {
        return X(n - 6) - Y(n - 4) + X(n - 3) + Y(n - 1);
    }
}

int Y(int n) {
    if(n <= 6) return n;
    else {
        return Y(n - 6) - X(n - 4) + Y(n - 3) + X(n - 1);
    }
}

int main() {
    int n; cin >> n;
    int sumX = 0, sumY = 0;
    if(n == 1) {
        sumX = 0; 
        sumY = 1;
    }
    else if(n == 2) {
        sumX = 2; 
        sumY = 3;
    }
    else if(n == 3) {
        sumX = 6; 
        sumY = 6;
    }
    else if(n == 4) {
        sumX = 12; 
        sumY = 10;
    }
    else if(n == 5) {
        sumX = 20; 
        sumY = 15;
    }
    else if(n == 6) {
        sumX = 30; 
        sumY = 21;
    }
    else {
        sumX = 30;
        sumY = 21;
        int x6 = 0, x5 = 2, x4 = 4, x3 = 6, x2 = 8, x1 = 10, y6 = 1, y5 = 2, y4 = 3, y3 = 4, y2 = 5, y1 = 6;
        for(int i = 0; i <= n - 7; i++) {
            int x = x6 - y4 + x3 + y1;
            int y = y6 - x4 + y3 + x1;
            sumX += x;
            sumY += y;
            x6 = x5;
            x5 = x4;
            x4 = x3;
            x3 = x2; 
            x2 = x1;
            x1 = x;

            y6 = y5;
            y5 = y4;
            y4 = y3;
            y3 = y2; 
            y2 = y1;
            y1 = y;
        }
        cout << "Khong de quy: " << sumX + sumY << endl;
        sumX = sumY = 0;
        for(int i = 1; i <= n; i++) {
            sumX += X(i);
            sumY += Y(i);
        }
        cout << "De quy: " << sumX + sumY << endl;
    }
    return 0;
}