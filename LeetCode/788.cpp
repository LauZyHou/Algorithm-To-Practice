class Solution {
public:
	bool check108(char c){
		return c=='1' || c=='0' || c=='8';
	}

	bool check2569(char c){
		return c=='2' || c=='5' || c=='6' || c=='9';
	}

    int rotatedDigits(int N) {
		int ans = 0;
		for(int d=1;d<=N;d++){
			//1,10,80这种仅仅带1,0,8的旋转后还是自己,所以不是
			//每位都在(2, 5, 6, 9, 0, 1, 8)内,至少一位在(2, 5, 6, 9)内
			string s = to_string(d);
			int len = s.size();
			bool atLeastOne=false;
			for(int i=0;i<len;i++){
				if(check2569(s[i]))
					atLeastOne = true;
				else if(!check108(s[i]))
					goto CONTI;
			}
			if(atLeastOne)
				ans++;
			CONTI:
				;
		}
		return ans;
    }
};