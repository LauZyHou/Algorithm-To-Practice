class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        //一个完整的B可能首部用到A的一部分，尾部用到A的一部分，像这样A'[AA....AA]A' , [ ] 内必然<=B的长度，故总长<=2*A+B
		int alen = A.size();
		int blen = B.size();
		int maxlen = 2*alen + blen;
		int ans = 1;
		string tmp = A;
		while(ans*alen<=maxlen) {
			//找到了
			if(tmp.find(B)!=string::npos)
				return ans;
			//没找到
			else {
				ans++;
				tmp = tmp + A;
			}
		}
		return -1;
    }
};