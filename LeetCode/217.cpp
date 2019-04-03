class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> m;
		for(auto n : nums){
			if(m.count(n))
				return true;
			m.insert(n);
		}
		return false;
    }
};