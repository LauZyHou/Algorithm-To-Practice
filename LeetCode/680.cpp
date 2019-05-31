class Solution {
public:
	//验证s串从a到b是否是一个回文串,tg表示是否已经跳过一个字符了
	bool valid(string s,int a,int b,bool tg) {
		while(a<b) {
			if(s[a]==s[b]) {
				a++;
				b--;
			}
			else {
				//如果已经跳过了,就不能再跳过一次了
				if(tg)
					return false;
				return valid(s,a+1,b,true) || valid(s,a,b-1,true);
			}
		}
		return true;
	}

    bool validPalindrome(string s) {
        int len = s.size();
		return valid(s,0,len-1,false);
    }
};