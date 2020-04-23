#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> read_vv(const char fpath[])
{
    freopen(fpath, "r", stdin);
    string testcase;
    cin >> testcase;
    // 去掉左边[[和右边]]
    testcase = testcase.substr(2, testcase.size() - 4);
    
    // 按],[进行切分
    regex out_re("\\],\\[");
    vector<string> out_vs(
        sregex_token_iterator(testcase.begin(), testcase.end(), out_re, -1),
        sregex_token_iterator());
    vector<vector<int>> ans(out_vs.size());

    // 对切分后的每个字符串(实际上表示一行数字)，按逗号切分
    for (size_t i = 0; i < out_vs.size(); i++)
    {
        string &row_s = out_vs[i];
        regex in_re(",");
        vector<string> in_vs(
            sregex_token_iterator(row_s.begin(), row_s.end(), in_re, -1),
            sregex_token_iterator());
        vector<int> row_v(in_vs.size());
        for (size_t j = 0; j < in_vs.size(); j++)
        {
            row_v[j] = stoi(in_vs[j]);
        }
        ans[i] = row_v;
    }
    return ans;
}
