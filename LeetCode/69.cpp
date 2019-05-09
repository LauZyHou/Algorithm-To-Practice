class Solution {
public:
    int mySqrt(int t) {
		//f(x) = x^2 - t
		//当f(x)为0时即为所求
		//用牛顿法,x = x - f(x)/f'(x)迭代
		//在本题中即是x = (x^2+t)/2x
		if(t<=1)
			return t;
		double x = t;//不妨从x = t处开始迭代
		double e = 0.0001;
		while(x*x-t>e) { //这里不用求fabs,因为当x*x<t时就也算结束,只是有时候迭代不到这么小
			//x = (x*x+t)/(2*x);
			//加快收敛速度,上下同时除以x
			x = (x+t/x)/2.0;
		}
		//x毕竟是double,而且无法预知每次迭代速率多大,还是考虑一下其ceil
		int c = ceil(x);
		return c<=t/c ? c : floor(x);
	}
};