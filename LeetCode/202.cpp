class Solution {
public:
	int next(int x){
		int res = 0;
		while(x){
			int tmp = x%10;
			res += tmp*tmp;
			x /= 10;
		}
		return res;
	}

    bool isHappy(int n) {
        //所有不快乐数的数位平方和
		//最後都会进入 4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4 的循环中
		while(n!=1){
			if(n==4)//只要判断这个循环里的任一个数字就可以了
				return false;
			n = this->next(n);
		}
		return true;
    }
};