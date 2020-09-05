class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int len = arr.size();
        if(len<2)
            return 0;
        if(len==2 && arr[1]<arr[0])
            return 1;
        int left = 1;
        int right = len-2;
        for (;left<len && arr[left]>=arr[left-1];left++)
            ;
        if(left==len)
            return 0;
        for(;right>=0 && arr[right]<=arr[right+1];right--)
            ;
        int ans_base = right-left+1; // 必须加的
        if(left>right) {
            ans_base = 0;
        }
        right++;
        left--;
        // 求左侧界index
        int lidx = left;
        for(;lidx>=0 && arr[lidx]>arr[right];lidx--)
            ;
        // 遍历从lidx+1的位置到left的位置
        if(lidx==left)
            return ans_base;
        int ans_add = INT_MAX;
        for(int i=lidx;i<=left;i++) {
            if(i==-1)
                continue;
            int cnt = left-i;
            for(int j=right;j<len && arr[j]<arr[i];j++)
                cnt++;
            if(cnt < ans_add)
                ans_add = cnt;
        }
        return ans_base + min(min(ans_add, left+1),len-right);
    }
};