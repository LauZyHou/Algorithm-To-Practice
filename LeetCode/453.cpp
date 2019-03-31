class Solution {
public:
    int minMoves(vector<int>& v) {
        //每次操作n-1个元素加1，直到所有元素都相等 == 
		//每次操作最大值-1，直到所有元素等于最小值 == 
		//求所有元素与最小值差值的和
		int minx = INT_MAX;
		int sum = 0;
		int len = 0;
		for(auto n:v){
			if(n<minx)
				minx = n;
			len++;
		}
		for(auto n:v){
			sum += n-minx;
		}
		return sum;
    }
};