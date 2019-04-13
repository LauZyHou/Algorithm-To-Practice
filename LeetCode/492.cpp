class Solution {
public:
    vector<int> constructRectangle(int area) {
        double d = sqrt(area);
		int k = (int)d;
		vector<int> ans;
		while(k>=1){
			if(area%k==0){
				ans.push_back(area/k);
				ans.push_back(k);
				break;
			}
			k--;
		}
		return ans;
    }
};