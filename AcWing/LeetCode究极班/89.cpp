class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res(1, 0); // n = 0时就是一个0
        while (n --) {
            for (int i = res.size() - 1; i >= 0; i --) {
                res[i] <<= 1; // 前一半的数补0
                res.emplace_back(res[i] + 1); // 复制后一半的数，后一半的数补1
            }
        }
        return res;
    }
};