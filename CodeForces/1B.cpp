#include <iostream>

#define N 100010

using namespace std;

int t;
char s[N];
char a[N]; //存字母
int b[2];  //存数字

//将列号转为A..Z这样的字母形式
void printAZCol()
{
    //例如28->AB
    //28%26=2 ->B
    //28/26=1
    //1%26=1 ->A
    //1/26=0 结束,结果长度不会超过N,用a[N]存

    //注意整除情况,例如26->Z
    //26%26=0 ???
    //26/26=1

    //所以应该,%得0时给Z,除以之前做个-1操作
    //28->AB
    //28%26=2 ->B
    //(28-1)/26=1
    //1%26=1 ->A
    //(1-1)/26=0

    //494->RZ
    //494%26=0 ->Z
    //(494-1)/26=18
    //18%26=18 ->R
    //(18-1)/26=0

    int i = 0;
    while (b[1] != 0)
    {
        if (0 == b[1] % 26)
            a[i] = 'Z';
        else
            a[i] = b[1] % 26 + 'A' - 1;
        b[1] = (b[1] - 1) / 26;
        i++;
    }

    //倒过来输出
    for (int r = i - 1; r >= 0; r--)
    {
        printf("%c", a[r]);
    }
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int j = 0, k = 0;
        b[0] = b[1] = 0;
        bool kua = false; //记录是否之前经历了数字

        scanf("%s", s);
        for (int i = 0; s[i]; i++)
        {
            //数字(j={0,1})
            if (s[i] >= '0' && s[i] <= '9')
            {
                b[j] = b[j] * 10 + s[i] - '0';
                kua = true;
            }
            //字母
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                a[k++] = s[i]; //字母按顺序往下存(如果是RxxxCxxx这时候不用在意字母了)
                if (kua)
                    j = 1; //接下来遇到数字存到b[1]位置
            }
        }

        //excel模式,本质就是从1(A)开始到26(Z)的26进制,不带0
        if (j == 0) //说明是[字母,数字],遇到数字后没有再遇到字母,不是[字母,数字,字母,数字]
        {
            //处理{A..Z}串
            int ans = 0;
            for (int i = 0; i < k; i++)
                ans = ans * 26 + a[i] - 'A' + 1; //从1开始,所以字母A其实是1不是0
            printf("R%dC%d\n", b[0], ans);
        }
        //RXCY模式,b[0]是行号不用处理,b[1]是列号要转成字符串
        else
        {
            //处理b[1]并输出
            printAZCol();
            //b[0]
            printf("%d\n", b[0]);
        }
    }

    return 0;
}