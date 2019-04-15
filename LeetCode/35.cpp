class Solution {
public:
    int searchInsert(vector<int>& v, int t) {
        int len = v.size();
		for(int i=0;i<len;i++){
			if(v[i]>=t)
				return i;
		}
		return len;
    }
};