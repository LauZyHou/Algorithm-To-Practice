#include<bits/stdc++.h>
using namespace std;

int m, n;

int main() {
    cin >> n >> m;
    vector<int> a(n,0);
    int c;
    for(int i=0;i<m;i++) {
        cin >> c;
        a[c-1]++;
    }
    c = a[0];
    for(int i=1;i<n;i++)
        c = min(c, a[i]);
    cout << c << endl;
    return 0;
}