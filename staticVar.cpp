#include<bits/stdc++.h>
using namespace std;

void doSth() {
    static int x = 0;    //bien static duoc khoi tao duy nhat 1 lan khi duoc goi lan dau tien va k mat di khi ket thuc ham
    ++x;
    cout << x << endl;
}

int main() {
    doSth();
    doSth();
    doSth();
    return 0;
}
