#include <bits/stdc++.h>
using namespace std;

int ofst, n, l1, l2;
int s1, e1, s2, e2;

int main() {
    while(cin >> ofst >> n >> l1 >> l2) {
        s1 = min(ofst, l1);
        e1 = min(ofst+n, l1);
        s2 = min(max(ofst-l1, 0), l2);
        e2 = min(max(ofst-l1+n, 0), l2);
        cout << s1 <<" " << e1 << " " << s2 << " " << e2 << endl;
    }
    return 0;
}