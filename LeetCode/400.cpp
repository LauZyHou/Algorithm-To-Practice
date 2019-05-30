class Solution {
public:
    int findNthDigit(int n) {
		if(n<10)
			 return n;
		//1~9			9个数字				1位
		//10~99			90个数字			2位
		//...
		//pow(10,i)~	9*pow(10,i)个数字	i+1位
		int i = 1;
		long long p10i = 10;
		long long len = 9;
		for(;len + p10i*9*(i+1)<n;i++) {
			len += p10i*9*(i+1);
			p10i *= 10;
		}
		//len还差多少到n,这里相对1...0的差值
		long long bias = n - len - 1;
		//几个数字
		long long nums = bias/(i+1);
		//第几位
		long long wei = bias%(i+1);
		return to_string(p10i+nums)[wei]-'0';
	}
};