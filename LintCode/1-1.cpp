class Solution {
public:
    /**
     * @param a: An integer
     * @param b: An integer
     * @return: The sum of a and b 
     */
    int aplusb(int a, int b) {
		while(a&b){
			a=a^b;
			b=((a^b)&b)<<1;
		}
		return a^b;
    }
};