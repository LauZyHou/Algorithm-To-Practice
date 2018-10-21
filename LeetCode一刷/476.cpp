class Solution {
public:
    int findComplement(int num) {
        if(0==num)
            return 1;
        int n=num;
        int k=1;
        while(n){
            n=n>>1;
            k=k<<1;
        }
        k-=1;
        return num ^ k;
    }
};
