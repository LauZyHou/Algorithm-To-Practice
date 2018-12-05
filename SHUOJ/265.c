#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char num[32];
int value[32];
int change[10][10];
int node[10], factor, multilen;

void DFS(int n) {
    int j;
    if(node[n])
        return ;
    else {
        node[n] = 1;
        factor++;
    }
    for(j = 0; j <= 9; j++)
        if(change[n][j])
            DFS(j);
}

void multiply() {
    int carry = 0;
    for(int i = 1; i <= multilen; i++) {
        value[i] = value[i] * factor + carry;
        carry = value[i] / 10;
        value[i] %= 10;
    }
    if(carry > 0)
        value[++multilen] = carry;
}

int main() {
    int k, i, j, length;
    while(scanf("%s%d", num, &k) != EOF) {
        value[0]=0;
        value[1]=1;
        multilen=1;
        memset(change, 0, sizeof(change));
        while(k--) {
            scanf("%d%d", &i, &j);
            change[i][j] = 1;
        }
        length = strlen(num);
        for(i = 0; i < length; i++) {
            memset(node, 0, sizeof(node));
            factor = 0;
            DFS(num[i] - '0');
            multiply();
        }
        for(i = multilen; i >= 1; i--)
            printf("%d", value[i]);
        printf("\n");
    }
    return 0;
}
