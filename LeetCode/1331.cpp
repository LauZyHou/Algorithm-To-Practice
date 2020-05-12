class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int len = arr.size();
        if(!len)
            return vector<int>();
        // 桶排序
        int maxn = INT_MIN;
        int minn = INT_MAX;
        for(int n : arr) {
            if(n > maxn) {
                maxn = n;
            }
            if(n < minn) {
                minn = n;
            }
        }
        int blen = maxn-minn+1;
        int* bucket = new int[blen];
        for(int i=0;i<blen;i++)
            bucket[i] = 0;
        for(int n : arr) {
            bucket[n-minn] = 1; // 这题坑，1,1,...,1,3那么3还是排第二
        }
        // 前缀和求每个元素前面有多少元素
        int* sumn = new int[blen];
        sumn[0] = 1; // 序号从1开始编号
        for(int i=1;i<blen;i++) {
            sumn[i] = sumn[i-1] + bucket[i-1];
        }
        // 取结果
        vector<int> ans(len);
        for(int i=0;i<len;i++) {
            ans[i] = sumn[arr[i]-minn];
        }
        return ans;
    }
};