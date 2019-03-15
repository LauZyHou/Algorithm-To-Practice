class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& fn, vector<int>& n) {
        int len1 = fn.size();
		int len2 = n.size();
		vector<int> ans;
		if(!len1 || !len2)
			return ans;
		stack<int> s;
		map<int,int> mp;
		//n
		for(int i=0;i<len2;i++){
			if(!s.empty() && n[i]<s.top()){
				s.push(n[i]);
				continue;
			}
			while(!s.empty() && n[i]>s.top()){
				int x = s.top();
				mp.insert(pair<int,int>(x,n[i]));
				s.pop();
			}
			s.push(n[i]);
		}
		//fn
		for(int i=0;i<len1;i++)
			if(mp.find(fn[i])!=mp.end())
				ans.push_back(mp[fn[i]]);
			else
				ans.push_back(-1);
		return ans;
    }
};