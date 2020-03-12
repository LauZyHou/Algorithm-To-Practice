#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int len = s.size();
    int ans = 0;
    bool zero = false;
    bool one = false;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '0')
            zero = true;
        else
            one = true;
        if (one && zero)
        {
            ans++;
            zero = one = false;
        }
    }
    cout << ans << endl;
    return 0;
}