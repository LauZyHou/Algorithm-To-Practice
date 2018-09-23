#include<bits/stdc++.h>
using namespace std;

//¼ÆËãÊýÎ»
int n;
int a, b, sum;


int main() {
    cin >> n;
    while(n--) {
        cin >> a >> b;
        sum = a + b;
        int i = 0;
        while(sum) {
            i++;
            sum /= 10;
        }
        cout << i << endl;
    }
    return 0;
}
