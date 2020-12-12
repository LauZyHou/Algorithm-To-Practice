class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // 摩尔投票法
        // 两个仓库和两个仓库里的数字的数量
        int r1, r2, c1 = 0, c2 = 0;
        for (auto x: nums) {
            if (c1 && r1 == x)
                c1 ++ ;
            else if (c2 && r2 == x)
                c2 ++ ;
            else if (!c1) r1 = x, c1 = 1;
            else if (!c2) r2 = x, c2 = 1;
            else c1 --, c2 -- ;
        }

        c1 = c2 = 0;
        for (auto x: nums)
            if (x == r1) c1 ++ ;
            else if (x == r2) c2 ++ ;

        vector<int> res;
        if (c1 > nums.size() / 3) res.emplace_back(r1);
        if (c2 > nums.size() / 3) res.emplace_back(r2);
        return res;
    }
};