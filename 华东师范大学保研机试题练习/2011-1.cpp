#include<bits/stdc++.h>
using namespace std;

//×÷·Ï

int n, mx, nowmax, cnt, ke = -1,i;
char a[65535];
bool ok = true;


int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &mx);
        getchar();
        gets(a);
        for(i = 0; a[i] != '\0'; i++) {
            if(a[i] != '.' && a[i] != '?' && a[i] != '!')
                continue;
            if(nowmax + i - ke > mx) {
                if(nowmax == 0) {
                    ok = false;
                    break;
                } else {
                    cnt++;
                    nowmax = i - ke;
                    ke = i;
                }
            } else {
                nowmax += i - ke;
                ke = i;
            }
        }
        if(!ok)
            printf("Impossible");
        else if(ke != i - 1)
            cnt += 1;
        if(ok)
            printf("%d\n", cnt);
        nowmax = cnt = 0;
        ke = -1;
    }

    return 0;
}
