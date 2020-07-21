class Solution {
private:
    int ff(int v, int r) {
        if(v < r) {
            return v*2;
        }
        return (v-r)*2+1;
    }
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        for(int i=0;i<2*n;i++) {
            int j = i;
            while(nums[i]>=0) {
                j = ff(j, n);
                /*
                if(j<n)
                    j *= 2;
                else 
                    j = (j-n)*2+1;
                */
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = -t;
            }
        }
        for(int i=0; i<2*n; i++) {
            nums[i] = -nums[i];
        }
        return nums;
    }
};