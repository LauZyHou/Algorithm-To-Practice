#include<bits/stdc++.h>
using namespace std;

int n, a[100];

int main() {
    cin >> n;
    for(int i=0;i<2*n;i++)
        cin >> a[i];
    int ans = 0;
    unordered_set<int> st;
    for(int i=0;i<2*n && st.size()<n;i++) {
        if(st.find(a[i])!=st.end())
            continue;
        for(int j=i+1;a[j]!=a[i];j++)
            if(st.find(a[j])==st.end())
                ans++;
        st.insert(a[i]);
    }
    cout << ans << endl;
    return 0;
}