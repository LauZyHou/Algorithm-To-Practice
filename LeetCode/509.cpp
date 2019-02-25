class Solution {
private:
	int f[31]={0};
public:
    int fib(int N) {
        if(f[N])
			return f[N];
		if(N==0)
			f[N]=0;
		else if(N==1)
			f[N]=1;
		else
			f[N]=fib(N-1)+fib(N-2);
		return f[N];
    }
};