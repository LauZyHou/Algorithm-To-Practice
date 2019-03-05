class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> ans;
		set<int> a(nums1.begin(),nums1.end());
		set<int> b(nums2.begin(),nums2.end());
		set_intersection(a.begin(),a.end(),b.begin(),b.end(),insert_iterator<vector<int>>(ans,ans.begin()));
		return ans;
    }
};