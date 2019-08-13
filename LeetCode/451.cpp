class Solution {
public:
    string frequencySort(string s) {
        int len = s.size();
		map<char,int> mp;
		int maxFreq = 0;
		for(int i=0;i<len;i++) {
			if(mp.find(s[i])==mp.end()) {
				mp[s[i]] = 1;
			}
			else
				mp[s[i]] += 1;
			if(mp[s[i]]>maxFreq)//桶的最大长
				maxFreq = mp[s[i]];
		}
		//建桶
		vector<char>** bucket = new vector<char>*[maxFreq+1];
		for(int i=1;i<=maxFreq;i++)
			bucket[i] = nullptr;
		for(map<char,int>::iterator it=mp.begin();it!=mp.end();it++) {
			if(bucket[it->second]==nullptr)
				bucket[it->second] = new vector<char>();
			bucket[it->second]->push_back(it->first);
		}
		//从后向前遍历桶
		int r = 0;
		char* ansc = new char[len+1];
		ansc[len] = '\0';
		for(int i=maxFreq;i>0;i--) {
			if(bucket[i]==nullptr)
				continue;
			int vlen = bucket[i]->size();
			for(int j=0;j<vlen;j++) {
				for(int k=0;k<i;k++)//重复i次
					ansc[r++] = (*bucket[i])[j];
			}
		}
		return string(ansc);
    }
};