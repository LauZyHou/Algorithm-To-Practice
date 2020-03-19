class Solution {
public:
    vector<int> exchange(vector<int>& v) {
        int len = v.size();
        if(len<2)
            return v;
        int i = 0;
        int j = len-1;
        while(i<j) {
            while(i<j && v[i]%2==1) {
                i++;
            }
            while(i<j && v[j]%2==0) {
                j--;
            }
            if(i<j)
                swap(v[i], v[j]);
        }
        return v;
    }
};