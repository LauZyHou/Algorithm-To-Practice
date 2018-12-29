#include<bits/stdc++.h>
using namespace std;

//输入一行字符，分别统计其中 英文字母、空格、数字和其他字符的个数
char str[65535];
//size_t len;
int c, n, o;

int main() {
    while(gets(str)) {
//        len=strlen(str);
        for(int i = 0; str[i] != '\0'; i++) {
            if(str[i] >= 'a' && str[i] <= 'z' || str[i] <= 'Z' && str[i] >= 'A')
                c++;
            else if(str[i] <= '9' && str[i] >= '0')
                n++;
            else
                o++;
        }
        printf("%d %d %d\n", c, n, o);
    }
    return 0;
}
