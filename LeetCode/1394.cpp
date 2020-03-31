class Solution {
public:
    int findLucky(vector<int>& arr) {
        int a[510] = {0};
        for(auto& x:arr) {
            a[x]++;
        }
        for(int i=500;i>=1;i--) {
            if(i==a[i])
                return i;
        }
        return -1;
    }
};