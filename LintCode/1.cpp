class Solution {
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: The sum of a and b 
     */
    int aplusb(int a, int b) {
        int c = a^b;
		int d = (a&b)<<1;
		if(c&d)
			return aplusb(c,d);
		return c^d;
    }
};