#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    double x,y;
    cin >> x >> y;
    double a = y*log(x);
    double b = x*log(y);
    if (a > b) {
        cout << ">" << endl;
    }
    else if (a < b) {
        cout << "<" << endl;
    }
    else {
        cout << "=" << endl;
    }
    return 0;
}