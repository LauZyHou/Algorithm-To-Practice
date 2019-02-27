class Solution {
public:
    /**
     * @param number: A 3-digit number.
     * @return: Reversed number.
     */
    int reverseInteger(int number) {
        int a = number%10;
		int b = number/10%10;
		int c = number/100;
		return a*100+b*10+c;
    }
};