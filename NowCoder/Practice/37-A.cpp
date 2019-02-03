#include <iostream>
#include <string>
#include <cmath>
using namespace std;

#define MAXN 166667

char a[][6] = {"01-10", "02-20", "03-30", "10-01", "11-11", "12-21"};

/*
bool su(int n)
{
    if (n < 2)
        return false;
    if (n <= 3)
        return true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
*/

bool su(int n)
{
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int step;
int bais;
int t, s, year = 2001;
int y[MAXN];

int main()
{
    int i = 0;
    while (i < MAXN && year < 9999)
    {
        year += 2;

        if (su(year))
        {
            y[i++] = year;
        }
    }

    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &s);
        bais = s % 6;
        if (bais != 0 || s < 6)
            step = s / 6;
        else
            step = s / 6 - 1;
        // cout << bais << endl;
        printf("%d-%s\n", y[step],a[(bais + 6 - 1) % 6]);
    }
    return 0;
}