class Solution {
public:
    int numberOfSteps (int num) {
        int res = 0;
        while(num){
            if((num&1)==1)
                num--;
            else
                num/=2;
            res++;
        }
        return res;
    }
};