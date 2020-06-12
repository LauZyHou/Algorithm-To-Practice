#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    int dt;
    cin >> dt;
    pair<int,int> dead;
    cin >> dead.first >> dead.second;
    for(int i=1;i<n;i++) {
        int carry = (v[i].second + dt)/60;
        int val = (v[i].second + dt)%60;
        int new1 = v[i].first + carry;
        int new2 = val;
        if(new1 > dead.first || 
           (new1==dead.first && new2>dead.second)
          ) {
            cout << v[i-1].first << " " << v[i-1].second << endl;
            break;
        }
    }
    return 0;
}