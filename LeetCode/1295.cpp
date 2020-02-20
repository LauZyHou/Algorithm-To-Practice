class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans = 0;
        for(int n:nums){
            int i = 0;
            do {
                n /= 10;
                i++;
            } while(n);
            if ((i&1)==0)
                ans++;
            // cout << i <<endl;
        }
        return ans;
    }
};