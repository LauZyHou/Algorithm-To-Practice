class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        for(auto x:arr)
            mp[x]++;
        int num[2020];
        for(int i=0;i<2020;i++)
            num[i] = -1; // -1表示还没存数字
        for(auto x:mp){
            int key = x.first;
            int val = x.second;
            if(num[val]>=0) // >=0说明里面存了数字,-1000~1000变成0~2000
                return false;
            num[val] = key>0 ? key : -key+1000;
        }
        return true;
    }
};