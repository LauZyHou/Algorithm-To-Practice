class Solution {
public:
    int removeDuplicates(vector<int>& v) {
    	int len = v.size();
    	if(!len)
    		return 0;
    	int r = 1;
    	for(int i=1;i<len;i++){
    		if(v[i]==v[i-1])
    			continue;
    		v[r++] = v[i];
    	}
    	return r;
    }
};