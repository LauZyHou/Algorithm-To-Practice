class Solution {
public:
    bool isRectangleOverlap(vector<int>& r1, vector<int>& r2) {
        int ax1 = r1[0], ay1 = r1[1], ax2 = r1[2], ay2 = r1[3];
        int bx1 = r2[0], by1 = r2[1], bx2 = r2[2], by2 = r2[3];
        if(
            ax1 >= bx2 ||
            bx1 >= ax2 ||
            ay1 >= by2 ||
            by1 >= ay2
        )
            return false;
        return true;
    }
};