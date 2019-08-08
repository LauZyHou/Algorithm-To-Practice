class Solution {
public:
    int findDuplicate(vector<int>& v) {
		//找环的起点即可
        int len = v.size();
		int fast = 0, slow = 0;
		do
		{
			slow = v[slow];
			fast = v[v[fast]];
		}
		while (fast!=slow);
		int ok = 0;
		while(ok!=slow) {
			ok = v[ok];
			slow = v[slow];
		}
		return ok;
    }
};