class Solution {
public:
    vector<int> intersect(vector<int>& v1, vector<int>& v2) {
        int n1 = v1.size();
		int n2 = v2.size();
		vector<int> ans;
		if(!n1 || !n2)
			return ans;
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		int i = 0;
		int j = 0;
		while(i<n1 && j<n2) {
			while(i<n1 && v1[i]<v2[j])
				i++;
			while(i<n1 && j<n2 && v1[i]>v2[j])
				j++;
			while(i<n1 && j<n2 && v1[i]==v2[j]){
				ans.push_back(v1[i]);
				i++;
				j++;
			}
		}
		return ans;
    }
};