#include<bits/stdc++.h>
using namespace std;

int n;

int find_max(vector<int> a, int start = 0, int end = n) {
    int max = -1001;
    for(int i = start; i < end; i++) {
        if(a[i] > max) max = a[i];
    }
    return max;
}

int find_min(vector<int> a, int start = 0, int end = n) {
    int min = 1001;
    for(int i = start; i < end; i++) {
        if(a[i] < min) min = a[i];
    }
    return min;
}

int sum(vector<int> a) {
    int s = 0;
    for(auto x : a) s += x;
    return s;
}

int main() {
    string s;
    vector<int> a;

    getline(cin, s);
    n = stoi(s);
    a.resize(n + 1, 0);

    getline(cin, s);
    int i = -1;
    while(!s.empty() && i++ < n) {
        string tmp = s.substr(0, s.find(" "));
        a[i] = stoi(tmp);
        if(s.find(" ") > s.length()) break;
        else s.erase(0, s.find(" ") + 1);
    }
    getline(cin, s);

    string order1 = "find-max", order2 = "find-min", order3 = "find-max-segment", order4 = "find-max-segment", order5 = "sum";
    vector<int> res;
    while(s != "***") {
        getline(cin, s);
        if(s == order1) res.push_back(find_max(a));
        else if(s == order2) res.push_back(find_min(a));
        else if(s == order5) res.push_back(sum(a));
        else if(s != "***") {
            string tmp = s.substr(0, s.find(" "));
            s.erase(0, s.find(" ") + 1);
            int i = stoi(s.substr(0, s.find(" ")));
            s.erase(0, s.find(" ") + 1);
            int j = stoi(s.substr(0, s.find(" ")));
            if(tmp == order3) res.push_back(find_max(a, i, j));
            else res.push_back(find_min(a, i, j));
        }
    }
    for(auto x : res) cout << x << endl;
    return 0;
}