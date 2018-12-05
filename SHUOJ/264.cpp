#include<bits/stdc++.h>
using namespace std;
int n, k, sum = 0, s[22];
int prime(int x) {
    int i;
    for(i = 2; i * i <= x; i++)
        if(x % i == 0)
            break;
    if(i * i <= x || x == 1)
        return 0;
    return 1;
}
void DFS(int treelenth, int nowsum, int nowwhere) {
    if(treelenth == k && prime(nowsum)) {
        sum++;
        return ;
    } else
        for(int i = nowwhere; i <= n; i++)
            DFS(treelenth + 1, nowsum + s[i], i + 1);
}
int main() {
    while(cin >> n >> k) {
        for(int i = 1; i <= n; i++)
            cin >> s[i];
        DFS(0, 0, 1);
        cout << sum << endl;
        sum = 0;
    }
    return 0;
}
