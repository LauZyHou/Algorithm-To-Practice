class Solution {
public:
	void reverse(string& s,int a,int b){
		while(a<b){
			char c = s[a];
			s[a] = s[b];
			s[b] = c;
			a++;
			b--;
		}
	}

    string reverseWords(string s) {
        int len = s.size();
		vector<int> v;
		//记录空格位置
		for(int i=0;i<len;i++)
			if(s[i]==' ')
				v.push_back(i);
		if(v.size()==0){
			reverse(s,0,len-1);
			return s;
		}
		reverse(s,0,v[0]-1);
		for(int j=0;j<v.size();j++){
			if(j+1<v.size())
				reverse(s,v[j]+1,v[j+1]-1);
			else
				reverse(s,v[j]+1,len-1);
		}
		return s;
    }
};