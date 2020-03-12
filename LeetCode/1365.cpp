class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int len = nums.size();
        if(!len)
            return nums;
        vector<int> n2(len);
        for(int i=0;i<len;i++)
            n2[i] = nums[i];
        sort(n2.begin(),n2.end());
        unordered_map<int,int> mp;
        int cnt = 0;
        int now = n2[0];
        mp[n2[0]] = 0;
        for(int i=1;i<len;i++) {
            if(now==n2[i]) {
                cnt++;
                continue;
            }
            cnt++;
            mp[n2[i]] = cnt;
            now = n2[i];
        }
        vector<int> ans(len);
        for(int i=0;i<len;i++) {
            ans[i] = mp[nums[i]];
        }
        return ans;
    }
};