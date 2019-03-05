/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    // @param nestedList a list of NestedInteger
    // @return a list of integer
    vector<int> flatten(vector<NestedInteger> &nv) {
        vector<int> ans;
		if(nv.size()==0)
			return ans;
		while(nv.size()){
			//本来是在头部pop,c++的好像是反过来输入的迎合vector,很烦
			NestedInteger ni = nv[nv.size()-1];
			nv.pop_back();
			if(ni.isInteger()){
				ans.push_back(ni.getInteger());
			}
			else{
				vector<NestedInteger> nn = ni.getList();
				for(int i=nn.size()-1;i>=0;i--)
					nv.push_back(nn[i]);
			}
		}
		return ans;
    }
};