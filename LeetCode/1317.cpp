class Solution {
public:
    bool check(int r) {
        while(r) {
            if(r%10==0)
                return false;
            r/=10;
        }
        return true;
    }

    vector<int> getNoZeroIntegers(int n) {
        int m = n/2;
        for(int i=1;i<=m;i++) {
            if(!check(i))
                continue;
            int j = n-i;
            if(check(j))
                return {i,j};
        }
        return {-1,-1};
    }
};