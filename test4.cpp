#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    if(s.length() < 2) {
        return true;
    }   
    else {
        if(s[0] != s[s.length() - 1]) return false;
        string middle = s.substr(1, s.length() - 2);
        return isPalindrome(middle);
    }
}

int main() {
    //cout << isPalindrome("madam");

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    int* p = &v.back();
    cout << *p << " " << v.at(3) << " " << p << " " << &v.at(3) << endl;
    v.push_back(5);
    cout << *p << " " << v.at(3) << " " << p << " " << &v.at(3) << endl;
    v.insert(v.begin() + 2, 14);
    exit(0);
    for(auto tmp : v) cout << tmp << " ";
    
}

