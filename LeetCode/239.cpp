class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int nlen = nums.size();
        if(!nlen)
            return vector<int>();
        int alen = nlen-k+1;
        vector<int> ans(alen);
        deque<int> dq;
        for(int i=0;i<nlen;i++) {
            if(dq.size()!=0 && dq.front()<i-k+1) {
                dq.pop_front();
            }
            
            while(dq.size()!=0 && nums[dq.back()]<=nums[i])
                dq.pop_back();
            
            dq.push_back(i);

            if(i>=k-1) {
                ans[i-k+1] = nums[dq.front()];
            }
        }
        return ans;
    }
};