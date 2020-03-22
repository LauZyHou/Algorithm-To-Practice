class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        int* val = new int[80000];// 记录每个数出现次数
        for(int i=0;i<80000;i++)
            val[i] = 0;
        for(int& x:A) {
            val[x]++;
        }
        int repeat = 0; // 还有多少重复数字没处理
        int ans = 0;

        for(int i=0;i<80000;i++) {
            if(val[i]>=2) {
                ans -= i*(val[i]-1);
                repeat += val[i]-1;
            }
            else if (repeat>0 && val[i]==0) { // 将之前一个重复的数字加到现在这个程度
                ans += i;
                repeat--;
            }
        }
        return ans;
    }
};