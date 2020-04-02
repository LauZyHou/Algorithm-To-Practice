#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int f(int m) {
    int ret = 0;
    int s = sqrt(m);
    for(int i=1;i<s;i++) {
        if(m%i==0)
            ret += i+m/i;
    }
    if(s*s==m)
        ret += s;
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,a,b;
    cin >> n;
    while(n--) {
        cin >> a;
        int b = a;
        int cnt = 0;
        while((b=f(b))!=1) {
            cnt++;
            if(b==a || b==f(b))
                break;
        }
        if(b==a)
            cout << "infinity" << endl;
        else
            cout << cnt << endl;
    }

    return 0;
}