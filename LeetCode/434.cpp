class Solution {
public:
    int countSegments(string s) {
        int len = s.size();
		if(!len)
			return 0;
		int cnt = 0;
		for(int i=0;i<len;i++) {
			if(s[i]!=' ') {
				cnt++;
				while(i<len && s[i]!=' ')
					i++;
				//回退一个,这样才能统计,因为下次循环还要i++
				if(s[i]==' ')
					i--;
			}
		}
		return cnt;
    }
};