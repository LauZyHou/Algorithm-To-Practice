class Solution {
public:
    bool validMountainArray(vector<int>& v) {
		int len = v.size();
		if(len<3)
			return false;
		int now = v[0];
		int i =1;
		for(;i<len;i++) {
			if(v[i]<=now)
				break;
			now = v[i];
		}
		//全是上坡的情况
		if(i==len || i==1)
			return false;
		for(;i<len;i++) {
			if(v[i]>=now)
				return false;
			now = v[i];
		}
		return true;
    }
};