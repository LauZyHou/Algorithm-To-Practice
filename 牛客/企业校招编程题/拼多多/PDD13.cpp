#include<bits/stdc++.h>
using namespace std;

int main() {
    int hp, na, ba;
    cin >> hp >> na >> ba;
    if(na*2 >= ba) {
        if(hp - hp/na*na > 0)
            cout << hp/na + 1 << endl;
        else
            cout << hp/na << endl;
    }
    else {
        int ans = hp/ba * 2;
        if(hp - hp/ba*ba > na)
            ans += 2;
        else
            ans += (hp-hp/ba*ba)>0;
        cout << ans << endl;
    }
    return 0;
}