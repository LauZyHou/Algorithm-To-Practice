class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int odd = 0, even = 1;
        int sum = 0;
        long long res = 0;
        for (int a: arr) {
            sum += a;
            if (sum & 1) {
                res += even;
                odd ++ ;
            }
            else {
                res += odd;
                even ++ ;
            }
        }
        return res % (int)(1e9 + 7);
    }
};