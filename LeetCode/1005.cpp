class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int len = A.size();
		if(!len) return 0;
		sort(A.begin(), A.end());
		int fu = 0;//负数个数
		for(int i=0;i<len;i++){
			if(A[i]>=0)
				break;
			fu++;
		}
		int ans = 0;
		//判断和K的大小关系,如果比K小要判断K-fu的奇偶
		if(fu>=K){
			for(int i=0;i<len;i++){
				if(i<K)
					ans += -A[i];
				else
					ans += A[i];
			}
		}else{
			if((K-fu)&1){
				//负数是0个时候最小的那个数翻转
				if(!fu){
					ans = -A[0];
					for(int i=1;i<len;i++)
						ans += A[i];
				}
				//否则min(-最大的负数,最小的非负数)翻转
				else{
					int t = min(-A[fu-1],A[fu]);
					for(int i=0;i<len;i++)
						ans += abs(A[i]);
					ans -= 2*t;
				}
			}else{
				for(int i=0;i<len;i++)
					ans += abs(A[i]);
			}
		}
		return ans;
    }
};