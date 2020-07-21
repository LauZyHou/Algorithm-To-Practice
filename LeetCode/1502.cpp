class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int len = arr.size();
        for(int i=1;i<len-1;i++) {
            if(arr[i]*2!=arr[i-1]+arr[i+1])
                return false;
        }
        return true;
    }
};