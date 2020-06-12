#include <bits/stdc++.h>
using namespace std;

int n;
int a;

int main() {
    cin >> n;
    int ans = 0;
    for(int i=0;i<n;i++) {
        cin >> a;
        ans += a;
    }
    cout << ans-n << endl;
    return 0;
}