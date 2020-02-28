class Solution {
public:
    int maxArea(vector<int> &v) {
        int len = v.size();
        if(len<2)
            return 0;
        int left = 0;
        int right = len-1;
        int ans = 0;
        while(left < right) {
            int now = min(v[left],v[right])*(right-left);
            if(now>ans)
                ans = now;
            if(v[left]<v[right])
                left++;
            else
                right--;
        }
        return ans;
    }
};