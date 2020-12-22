class Solution {
public:
    vector<int> nums;
    vector<bool> st; // 表示每根木棍有没有被用过

    bool dfs(int start, int cur, int length, int cnt) {
        // 如果已经拼出三根了，那么最后一根就不用管了，一定能拼出来
        if (cnt == 3) return true;
        // 如果当前长度就是每条边要拼的总长度，说明已经拼出来了新的一根
        if (cur == length) return dfs(0, 0, length, cnt + 1);
        // 从start开始枚举
        for (int i = start; i < nums.size(); i ++ ) {
            // 如果当前火柴已经被用过了就跳过
            if (st[i]) continue;
            // 如果当前火柴加当前长度是不超过总长度的，那么就要搜一下
            if (cur + nums[i] <= length) {
                st[i] = true;
                // 这里搜索的时候是i+1，这是剪枝的一种，要求按编号递增地搜索
                if (dfs(i + 1, cur + nums[i], length, cnt)) return true;
                st[i] = false;
            }
            // 如果是在第一根或者最后一根失败的，就剪掉当前分支
            if (!cur || cur + nums[i] == length) return false;
            // 将当前相同长度的木棍跳过
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i ++ ;
        }
        return false;
    }

    bool makesquare(vector<int>& _nums) {
        nums = _nums;
        if (nums.empty()) return false; // 特判为空的情况
        st.resize(nums.size());
        int sum = 0;
        for (auto x: nums) sum += x;
        if (sum % 4 != 0) return false;
        sum /= 4;
        sort(nums.begin(), nums.end(), greater<int>());
        return dfs(0, 0, sum, 0); // 从第0个火柴开始枚举，当前长度是0，每条边的总长度是sum，当前拼的是第0根
    }
};