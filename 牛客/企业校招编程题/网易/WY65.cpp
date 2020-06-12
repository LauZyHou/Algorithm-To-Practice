#include <bits/stdc++.h>
using namespace std;

int a[3];

int main() {
    for(int i=0;i<3;i++) cin >> a[i];
    sort(a, a+3);
    cout << max(max(a[0]*a[1]*a[2], (a[0]+a[1])*a[2]), a[0]+a[1]+a[2]) << endl;
    return 0;
}