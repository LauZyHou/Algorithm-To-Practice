#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    if (n <= 1)
    {
        cout << n << endl;
        return 0;
    }
    // 最大整合长度
    int ans = 1;
    //若一段无重复的数中，最大值减去最小值+1等于该数组长度，则数组可整合
    unordered_set<int> um; // 集合判断重复
    for (int i = 0; i < n; i++)
    {
        // 最大最小值，每次新一轮时都要重新找
        int maxval = a[i];
        int minval = a[i];
        for (int j = i; j < n; j++)
        {
            // 发现重复时退出
            if (um.find(a[j]) != um.end())
                break;
            um.insert(a[j]);
            // 更新最大最小值
            if (a[j] < minval)
                minval = a[j];
            if (a[j] > maxval)
                maxval = a[j];
            // 判断是不是符合整合数组要求，判断是否需要更新
            if (maxval - minval == j - i && maxval - minval + 1 > ans)
                ans = maxval - minval + 1;
        }
        um.clear();
    }
    cout << ans << endl;
    return 0;
}

/*
先给出可整合数组的定义：如果一个数组在排序之后，每相邻两个数的差的绝对值都为1，或者该数组长度为1，则该数组为可整合数组。例如，[5, 3, 4, 6, 2]排序后为[2, 3, 4, 5, 6]，符合每相邻两个数差的绝对值都为1，所以这个数组为可整合数组
给定一个数组arr, 请返回其中最大可整合子数组的长度。例如，[5, 5, 3, 2, 6, 4, 3]的最大可整合子数组为[5, 3, 2, 6, 4]，所以请返回5

第一行一个整数N，表示数组长度
第二行N个整数，分别表示数组内的元素

输出一个整数，表示最大可整合子数组的长度

7 5 5 3 2 6 4 3

5
*/