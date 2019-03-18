class Solution {
public:
    int getSum(int a, int b) {
        int sum,carry;
		do{
			sum = a^b;
			carry = (a & b & INT_MAX)<<1;//&01111111以使carray最高位设置为0
			a = sum;
			b = carry;
		}while(carry!=0);
		return sum;
	}
};

