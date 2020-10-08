class Solution {
public:
    int maxSatisfaction(vector<int>& v) {
        sort(v.begin(), v.end(), greater<int>());
        int sm = 0;
        int i = 0;
        while (sm >= 0 && i < v.size())
            sm += v[i ++];
        i --;
        if (sm < 0)
            i -- ;

        // cout << sm << endl;

        int ans = 0;
        for (int j = i; j >= 0; j --) {
            ans += v[j] * (i - j + 1);
        }
        return ans;
    }
};