#include<bits/stdc++.h>
using namespace std;


void getWord(char* s, char* wrd, int i, int L) {
    int pos = 0;
    while((s[i] == ' ') || (s[i] == '.') || (s[i] == ',') || (s[i] == '\t')) i++;
    if(i >= L - 1) {
        cout << "Khong tim thay!" << endl;
        exit(0);
    }
    else {
        while((s[i] != ' ') && (s[i] != '.') && (s[i] != ',') && (s[i] != '\t')){ 
            wrd[pos++] = s[i++];
        }
        wrd[pos] = '\0';    
    }
}

int main() {
    char s[] = "Hello   ,  phuc day.    ";
    char *wrd;
    getWord(s, wrd, 22, sizeof(s));
    for(int z = 0; z < sizeof(wrd); z ++) cout << wrd[z];
    return 0;
}