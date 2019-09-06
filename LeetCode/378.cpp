class Solution {
public:
	int xlen;
	int ylen;
	int left;
	int right;
	int mid;

	int findSmEq(vector<vector<int>>& vv) {
		//找vv中<=mid的元素个数
		int ret=0;
		for(int i=0;i<xlen;i++) {
			for(int j=0;j<ylen;j++) {
				if(vv[i][j]>mid) {
					ret += j;
					goto NEXT;
				}
			}
			ret += ylen;
			NEXT:
				;
		}
		return ret;
	}

    int kthSmallest(vector<vector<int>>& vv, int k) {
        xlen = vv.size();
		if(!xlen)
			return -1;
		ylen = vv[0].size();
		if(!ylen)
			return -1;
		//整数值二分
		left = vv[0][0];
		right = vv[xlen-1][ylen-1];
		while(left<right) {
			mid = (left+right)/2;
			int smEqNum = findSmEq(vv);
			if(smEqNum<k) {
				left = mid+1;
			} else {//smEqNum>=k
				right = mid;//注意,即使==也要往左找,因为可能1,2,4所求为2当前为3
			}
		}
		return left;//left==right
    }
};