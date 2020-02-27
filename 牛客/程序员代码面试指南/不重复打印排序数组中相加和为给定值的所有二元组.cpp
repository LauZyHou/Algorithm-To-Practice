#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n < 2)
        return 0;
    int begin = 0;
    int end = n - 1;
    while (begin < end)
    {
        if (a[begin] + a[end] < k)
            begin++;
        else if (a[begin] + a[end] > k)
            end--;
        else
        {
            // 注意这一组要不能重复
            if (begin == 0 || a[begin] != a[begin - 1])
                cout << a[begin] << " " << a[end] << endl;
            begin++;
            end--;
        }
    }
    return 0;
}