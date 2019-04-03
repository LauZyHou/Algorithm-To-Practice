class Solution {
public:
    vector<int> twoSum(vector<int>& n, int t) {
        vector<int> ans;
		int nlen = n.size();
		if(nlen<2)
			return ans;
		int i=0,j=nlen-1;
		while(i<j){
			int r = n[i]+n[j];
			if(r==t)
				break;
			if(r<t)
				i++;
			else
				j--;
		}
		if(i<j){
			ans.push_back(i+1);
			ans.push_back(j+1);
		}
		return ans;
    }
};