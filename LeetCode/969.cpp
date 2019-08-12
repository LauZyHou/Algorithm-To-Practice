class Solution {
public:
	int findMax(vector<int>& v,int b) {
		int ret = 0;
		for(int i=1;i<b;i++) {
			if(v[i]>v[ret])
				ret = i;
		}
		return ret;
	}

    vector<int> pancakeSort(vector<int>& v) {
        int len = v.size();
		vector<int> ans;
		for(int i=0;i<len;i++) {
			int idx = findMax(v,len-i);
			if(idx==len-1-i) {//已经在末尾
				;
			}
			else if(idx==0) {//在开头
				reverse(v.begin(),v.begin()+len-i);
				ans.push_back(len-i);
			}
			else {//其它位置
				reverse(v.begin(),v.begin()+idx+1);
				ans.push_back(idx+1);
				reverse(v.begin(),v.begin()+len-i);
				ans.push_back(len-i);
			}
		}
		return ans;
    }
};