class Solution {
private:
    const int mod = 1e9 + 7;
public:
    int numOfWays(int n) {
        // ABA 当前 XYX模式
        // BAB，CAC，BCB，BAC，CAB，合3个XYX，2个XYZ
        // ABC 当前 XYZ模式
        // BAB，BCB，CBA，BCA，合2个XYX，2个XYZ
        long xyx = 6, xyz = 6; // 第0层
        for (int i = 1; i < n; i ++) {
            long _xyx = (3 * xyx + 2 * xyz) % mod;
            long _xyz = (2 * xyx + 2 * xyz) % mod;
            xyx = _xyx;
            xyz = _xyz;
        }
        return (xyx + xyz) % mod;
    }
};