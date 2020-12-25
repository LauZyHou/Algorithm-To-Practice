class Solution {
public:
    int get_dist(vector<int>& a, vector<int>& b) {
        int dx = a[0] - b[0], dy = a[1] - b[1];
        return dx * dx + dy * dy;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> p({p1, p2, p3, p4});
        vector<int> d; // 所有距离
        // 枚举一下任意两个点，算一下距离，也就是四条边和两条对角线
        for (int i = 0; i < 4; i ++ ) {
            for (int j = i + 1; j < 4; j ++ ) {
                d.push_back(get_dist(p[i], p[j]));
            }
        }
        sort(d.begin(), d.end());
        // 如果有距离是0的，那么就说明有点重合，就一定不是正方形
        if (!d[0]) return false;
        // 判断一下最短的四条边相等，并且最长的两条边也相等
        return d[0] == d[1] && d[1] == d[2] && d[2] == d[3] && d[4] == d[5];
    }
};