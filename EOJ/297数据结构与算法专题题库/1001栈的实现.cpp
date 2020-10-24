#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10;

int stk[N], tt;

int main() {
    int q;
    scanf("%d", &q);
    
    while (q --) {
        char op[6];
        scanf("%s", op);
        if (!strcmp(op, "push")) {
            int x;
            scanf("%d", &x);
            stk[++ tt] = x;
        }
        else if (!strcmp(op, "pop")) {
            if (tt)
                tt --;
            else
                puts("ERROR");
        }
        else if (!strcmp(op, "top")) {
            if (tt)
                printf("%d\n", op[tt]);
            else
                puts("ERROR");
        }
        else if (!strcmp(op, "size")) {
            printf("%d\n", tt);
        }
        else if (!strcmp(op, "clear")) {
            tt = 0;
        }
        else if (!strcmp(op, "empty")) {
            if (tt)
                puts("NO");
            else
                puts("YES");
        }
        else {
            puts("ERROR");
        }
    }
    
    return 0;
}
