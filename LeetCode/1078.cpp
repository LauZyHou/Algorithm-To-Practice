class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
		//字符串流,从流从一个个读取也就相当于按空格split了
		stringstream ss(text);
		string now;
		int flag = 0;//0:没有遇到,1:匹配了first,2:匹配了second
		vector<string> ans;
		//一个个读
		while(ss>>now) {
			if(flag == 2)
				ans.emplace_back(now);
			if(flag == 1 && now==second)
				flag = 2;
			else if(now == first)
				flag = 1;
			else
				flag = 0;
		}
		return ans;
    }
};