class Solution {
public:
    double r, x, y;
    
    Solution(double radius, double x_center, double y_center) {
        r = radius, x = x_center, y = y_center;
    }
    
    vector<double> randPoint() {
        // 随机产生-1到1之间的两个数，作为横纵坐标
        double a = (double)rand() / RAND_MAX * 2 - 1;
        double b = (double)rand() / RAND_MAX * 2 - 1;
        // 勾股定理算一下在不在半径为1的圆形内，不在就重做
        if (a * a + b * b > 1) return randPoint();
        // 使用真实半径对坐标缩放，并补上坐标偏移量
        return {r * a + x, r * b + y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */