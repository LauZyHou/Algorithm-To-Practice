class Solution {
public:
    int distributeCandies(vector<int>& candies) {
		set<int> cat;
		int len = candies.size();
		for(int i=0;i<len;i++)
			cat.insert(candies[i]);
        return min((int)cat.size(),len/2);
    }
};