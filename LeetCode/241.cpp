class Solution {
public:
	bool contain(string& s,char c,int a,int b) {
		for(int i=a;i<=b;i++) {
			if(s[i]==c)
				return true;
		}
		return false;
	}

	//回溯过程
	vector<int> traceback(string& s,int a,int b) {//a:起点,b:终点
		vector<int> ret;

		if(a>b)
			return ret;
		
		//不包含运算符号时候直接返回数字
		if(!contain(s,'+',a,b) && !contain(s,'-',a,b) && !contain(s,'*',a,b)) {
			ret.push_back(atoi(s.substr(a,b-a+1).c_str()));
			return ret;
		}

		//寻找运算符号做划分点
		for(int i=a;i<=b;i++) {
			if(s[i]=='+' || s[i]=='-' || s[i]=='*') {
				//对其左右可能取到的每个组合起来
				for(int left:traceback(s,a,i-1)) {
					for(int right:traceback(s,i+1,b)) {
						if(s[i]=='+')
							ret.push_back(left+right);
						else if(s[i]=='-')
							ret.push_back(left-right);
						else//*
							ret.push_back(left*right);
					}
				}
			}
		}
		return ret;
	}

    vector<int> diffWaysToCompute(string s) {
		int len = s.size();
        return traceback(s,0,len-1);
    }
};