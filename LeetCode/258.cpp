class Solution {
public:
    int addDigits(int num) {
        //100x+10y+z = 99x+9y+(x+y+z)
		//x+y+z = 10a+b =9+(a+b)
		//36 -> 3+6=9
		//0 -> 0
		return num==0?0:num%9==0?9:num%9;
	}
};