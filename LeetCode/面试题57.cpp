class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
        int len = v.size();
        if(!len)
            return vector<int>();
        int i=0, j=len-1;
        while(i<j) {
            int sum = v[i]+v[j];
            if(sum<t)
                i++;
            else if(sum>t)
                j--;
            else
                return vector<int>({v[i],v[j]});
        }
        return vector<int>();
    }
};