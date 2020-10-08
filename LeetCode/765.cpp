class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int len = row.size();
        int ans = 0;

        vector<int> idx(len);

        for (int i = 0; i < len; i ++)
            idx[row[i]] = i;

        for (int i = 0; i < len; i += 2) {
            if (row[i + 1] / 2 != row[i] / 2) {
                int target = (row[i] & 1) ? row[i] - 1 : row[i] + 1;
                int tidx = idx[target];

                idx[row[i + 1]] = tidx;
                idx[row[tidx]] = i + 1;
                swap(row[i + 1], row[tidx]);
                ans ++;
            }
        }

        return ans;
    }
};