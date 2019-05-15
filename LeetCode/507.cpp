class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num<=0)
			return false;
		int sum = 0;
		//这种做法在加1时候会把num也加上,因为num/1=num
		//但题里要求是不包括num的,所以这里要和num*2比较
		int num2 = num*2;
		//防止超时,每次找到质数把对应除下来的结果也算上
		for(int i=1;i*i<=num;i++){
			if(num%i==0){
				if(i*i==num)
					sum += i;
				else
					sum += i+num/i;
			}
			if(sum>num2)
				return false;
		}
		return sum==num2;
    }
};