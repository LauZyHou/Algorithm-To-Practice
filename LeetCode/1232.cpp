class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& vv) {
        int len = vv.size();
        if(len<3)
            return true;
        int dx = vv[1][0] - vv[0][0];
        int dy = vv[1][1] - vv[0][1];
        for(int i=2;i<len;i++) {
            int _dx = vv[i][0] - vv[i-1][0];
            int _dy = vv[i][1] - vv[i-1][1];
            if(_dy * dx != dy * _dx)
                return false;
        }
        return true;
    }
};