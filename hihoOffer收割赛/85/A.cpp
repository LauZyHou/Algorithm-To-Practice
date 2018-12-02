#include<bits/stdc++.h>
using namespace std;

#define MX 500000

struct data {
    int a, b, w;
} mp[MX];

int N, M, W, A, B, L;
int tot = 0;
bool N_gone[1003];
int now_min = -1, now_step = 0;
int real_M = 0;

bool find_ok_map(int a, int b, int w) {
    for(int i = 0; i < M; i++)
        if(mp[i].a == a && mp[i].b == b)
            return true;
    return false;
}

void DFS(int u) {
    if(u == N) {
        if(now_min < 0 || now_step < now_min) {
            now_min = now_step;
        }
    }
    for(int i = 1; i < u; i++) {
        if(!N_gone[i] && find_ok_map(i, u, W)) {
            N_gone[i] = true;
            now_step++;
            if(now_min > 0 && now_step >= now_min) {
                goto BYE1;
            }
            DFS(i);
BYE1:
            N_gone[i] = false;
            now_step--;
        }
    }
    for(int i = u + 1; i <= N; i++) {
        if(!N_gone[i] && find_ok_map(u, i, W)) {
            N_gone[i] = true;
            now_step++;
            if(now_min > 0 && now_step >= now_min) {
                goto BYE2;
            }
            DFS(i);
BYE2:
            N_gone[i] = false;
            now_step--;
        }
    }
}

int main() {
    scanf("%d%d%d", &N, &M, &W);
    //memset(N_gone, sizeof(bool) * 1003, false);
    int A, B, L;
    for(int i = 0; i < M; i++) {
        scanf("%d%d%d", &A, &B, &L);
        if(L < W) {
            i--;
            M--;
            continue;
        }
        mp[i].w = L;
        if(B < A) {
            mp[i].a = B;
            mp[i].b = A;
        } else {
            mp[i].a = A;
            mp[i].b = B;
        }
    }
    DFS(1);
    printf("%d", now_min);
    return 0;
}
