#include<bits/stdc++.h>
using namespace std;

int line=1, a[26];
string s;


int main() {
    for(int i=0;i<26;i++)
        cin >> a[i];
    cin >> s;
    int slen = s.size();
    int nowval = 0;
    for(int i=0;i<slen;i++) {
        int val = a[s[i]-'a'];
        if(nowval + val <= 100)
            nowval += val;
        else {
            nowval = val;
            line++;
        }
    }
    cout << line << " " << nowval << endl;
    return 0;
}