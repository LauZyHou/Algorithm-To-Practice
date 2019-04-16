class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        //最后一个字符是1,一定不行
		//最后一个字符是0,要看前面的
		//..00可以,..010的话这里1肯定不能接前面的0,因为两个的只能10或者11
		//..0110这里两个1肯定接起来,所以可以
		//..01110这里前两个1接起来,剩一个1和后面0接起来
		//看最后0前得连续1的个数,偶数个就true,奇数个就false
		int len = bits.size();
		if(!len || bits[len-1]==1)
			return false;
		int num1 = 0;
		for(int i=len-2;i>=0;i--){
			if(bits[i]==0)
				break;
			num1++;
		}
		return !(bool)(num1&1);
    }
};