class Solution {
public:
    bool isPerfectSquare(int num) {
        //完全平方数肯定是前n个连续奇数的和
		int i = 1;
		long long sum = 1;
		if(num<1)
			return false;
		while(sum<num){
			i += 2;
			sum += i;
		}
		return sum==num;
    }
};