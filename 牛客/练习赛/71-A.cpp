#include<bits/stdc++.h>
using namespace std;


int main() {
    int a[10];
    int ji = 0;
    int jinum = 0;
    int fei0 = 0;
    for (int i = 0; i < 10; i ++) {
        cin >> a[i];
        if (a[i] & 1)
            ji ++, jinum = i;
        if (ji > 1) {
            cout << -1 << endl;
            return 0;
        }
        if (i > 0)
            fei0 += a[i];
    }
    
    if (a[0] == 1 && !fei0) {
        cout << 0 << endl;
        return 0;
    }
    
    if (a[0] > 1 && fei0 < 2) {
        cout << -1 << endl;
        return 0;
    }
    
    if (a[0]) {
        string s = "";
        int i;
        for (i = 1; i < 10; i ++) {
            if (a[i]) {
                s += i + '0';
                a[i] -= 2;
                break;
            }
        }
        for (int j = 0; j < a[0] / 2; j ++)
            s += '0';
        for ( ; i < 10; i ++) {
            if (a[i]) {
                for (int j = 0; j < a[i] / 2; j ++)
                    s += i + '0';
            }
        }
        cout << s;
        if (ji)
            cout << jinum;
        reverse(s.begin(),s.end());
        cout << s << endl;
    }
    else {
        string s = "";
        int i;
        for (i = 1; i < 10; i ++) {
            if (a[i]) {
                for (int j = 0; j < a[i] / 2; j ++)
                    s += i + '0';
            }
        }
        cout << s;
        if (ji)
            cout << jinum;
        reverse(s.begin(),s.end());
        cout << s << endl;
    }
    
    return 0;
}