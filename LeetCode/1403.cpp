class Solution {
public:
    vector<int> minSubsequence(vector<int>& v) {
        sort(v.begin(), v.end(), greater<int>());
        int sum = 0;
        for(auto x:v) {
            sum += x;
        }
        sum /= 2;
        int n = 0;
        int val = 0;
        while(n<v.size()) {
            val += v[n];
            n++;
            if(val>sum)
                break;
        }
        return vector(v.begin(), v.begin()+n);
    }
};