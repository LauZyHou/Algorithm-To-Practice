class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        //一个从右往左,一个从左往右,加和都是sum/3时就是true了
		//考虑一种情况,是否有可能找到了加和是sum/3然后实际上再往下走的才是解?
		//不必,假如往下走才是解,说明这是x+b-b=sum/3,那么这一段给中间的也一样是x+b-b
		int len = A.size();
		int sum = 0;
		for(int i=0;i<len;i++)
			sum+=A[i];
		if(sum%3)
			return false;
		int x = sum/3;
		int i = 0;
		int j = len-1;
		int lft = 0;
		int rgt = 0;
		while(i<j){
			if(lft!=x)
				lft += A[i++];
			if(rgt!=x && i<j)
				rgt += A[j--];
			if(x==lft && x==rgt)
				return true;
		}
		return false;
    }
};