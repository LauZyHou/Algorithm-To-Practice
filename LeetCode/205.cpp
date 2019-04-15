class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len = s.size();
        char a[256];
		bool b[256]={false};
		//两个字符不能映射到同一字符
		set<char> st;
		//s->t
		for(int i=0;i<len;i++){
			if(!b[s[i]]){
				if(st.count(t[i])>0)
					return false;
				a[s[i]] = t[i];
				b[s[i]] = true;
				st.insert(t[i]);
			}else{
				if(a[s[i]]!=t[i])
					return false;
			}
		}
        return true;
    }
};