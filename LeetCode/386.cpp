class Solution {
public:
	int n;
	vector<int> ans;

	void traceback(int num) {
		//num自己已经放进去过了,现在在后面补个0
		num *= 10;
		//这一位一共从0到9
		for(int i=0;i<=9;i++) {
			if(num+i<=n) {
				ans.push_back(num+i);
				traceback(num+i);
			}
			else
				return ;//后面只会更大
		}
	}

	vector<int> lexicalOrder(int n) {
		ans = vector<int>();
		this->n = n;
		//最外一层(单个数字的1~9)
		for(int i=1;i<10;i++) {
			if(i<=n) {
				ans.push_back(i);
				traceback(i);
			}
			else
				break;
		}
		return ans;
	}
};