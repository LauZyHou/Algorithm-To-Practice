class Solution
{
public:
    int findLatestStep(vector<int> &arr, int m)
    {
        int len = arr.size();
        vector<bool> v(len, false);
        for (int a : arr)
        {
            v[a - 1] = true;
        }
        set<pair<int, int>> st;
        set<int> live;
        bool kai = false;
        int start, end;
        for (int i = 0; i < len; i++)
        {
            if (!kai && v[i])
            {
                kai = true;
                start = i; // 从0计数
            }
            else if (kai && !v[i])
            {
                kai = false;
                end = i - 1;
                // 优化
                if (end - start >= m - 1)
                {
                    st.insert(make_pair(start, end));
                    for (int k = start; k <= end; k++)
                    {
                        live.insert(k);
                    }
                }
            }
        }
        if (kai)
        {
            // 优化
            if (len - 1 - start >= m - 1)
            {
                st.insert(make_pair(start, len - 1));
                for (int k = start; k <= len - 1; k++)
                {
                    live.insert(k);
                }
            }
        }

        for (int i = len - 1; i >= 0; i--)
        {
            int idx = arr[i] - 1; // 从0计数
            // 优化
            if (!live.count(idx))
                continue;
            for (auto &x : st) // pair
            {
                if (x.second - x.first == m - 1)
                {
                    return i + 1;
                }
            }
            for (auto &x : st)
            {
                if (x.first <= idx && x.second >= idx)
                {
                    int f = x.first;
                    int s = x.second;
                    st.erase(x);
                    if (idx - 1 >= f)
                    {
                        // 优化
                        if (idx - 1 - f >= m - 1)
                            st.insert(make_pair(f, idx - 1));
                    }
                    if (idx + 1 <= s)
                    {
                        // 优化
                        if (s - idx - 1 >= m - 1)
                            st.insert(make_pair(idx + 1, s));
                    }
                    break;
                }
            }
        }
        return -1;
    }
};