#include<bits/stdc++.h>
using namespace std;

int t, m, n, *a, sum;

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &m, &n);
        a = new int[m];
        for(int i = 0; i < m; i++) {
            scanf("%d", a + i);
            if(i < n)
                sum += a[i];
        }
        printf("%d\n", sum);
        delete a;
        sum = 0;
    }
    return 0;
}
