#include <bits/stdc++.h>
using namespace std;

int x;

int main() {
    cin >> x;
    int v = x/5;
    if(x%5)
        cout << v+1 << endl;
    else
        cout << v << endl;
    return 0;
}