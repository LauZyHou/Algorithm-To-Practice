class Solution {
public:
    bool judgeSquareSum(int c) {
		long long i = 0;//小的数字最小为0
		long long j = sqrt(c);//大的数字最大为其算数平方根
		while(i<=j) {
			long long v = i*i + j*j - c;
			if(v==0)
				return true;
			else if(v>0)
				j--;
			else
				i++;
		}
		return false;
    }
};