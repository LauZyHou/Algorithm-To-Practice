#include<bits/stdc++.h>
using namespace std;

int a[26] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
int b[10] = {1,1,4,4,4,4,4,5,4,5};

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    while(cin >> s) {
        int ans = 0;
        for(auto c:s) {
            if(isdigit(c))
                ans += b[c-'0'];
            else
                ans += a[c-'a'];
        }
        cout << ans << endl;
    }
    return 0;
}