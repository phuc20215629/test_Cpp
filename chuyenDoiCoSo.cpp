#include<bits/stdc++.h>
using namespace std;

void conv(int n, int b) {
    if(n <= 1) {
        cout << n % b;
    }
    else {      
        conv(n / b, b);    
        cout << n % b;
    }
}
int main() {
    long n;
    int b; 
    stack<int> s;
    cin >> n >> b;
    conv(n, b);
    cout << endl;
    // while(n >= 1) {
    //     int tmp = n % b;
    //     s.push(tmp);
    //     n = n / b;
    // }
    // while(!s.empty()) {
    //     int ans = s.top();
    //     cout << ans;
    //     s.pop();
    // }

    while(n > 1) {
        s.push(n);
        n = n / b;
    }
    cout << n % b;

    while(!s.empty()) {
        int tmp = s.top();
        s.pop();
        cout << tmp % b;
    }
    
    return 0;
}