#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (n < 3)
        return 0;
    for (int i = 0; i <= n - 3; i++)
    {
        // 注意外层循环也要跳过数字相同的情况
        if (i > 0 && a[i] == a[i - 1])
            continue;
        int left = i + 1;
        int right = n - 1;
        int k2 = k - a[i];
        while (left < right)
        {
            if (a[left] + a[right] < k2)
                left++;
            else if (a[left] + a[right] > k2)
                right--;
            else
            {
                // 若要通过这题,需要把这里去掉left==i+1这个条件
                if (left == i + 1 || a[left] != a[left - 1])
                    cout << a[i] << " " << a[left] << " " << a[right] << endl;
                left++;
                right--;
            }
        }
    }
    return 0;
}