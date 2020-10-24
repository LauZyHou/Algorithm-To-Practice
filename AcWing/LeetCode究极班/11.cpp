class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        for (int i = 0, j = height.size() - 1; i < j; ) {
            res = max(res, min(height[i], height[j]) * (j - i));
            if (height[i] < height[j])
                i ++;
            else
                j --;
        }
        return res;
    }
};