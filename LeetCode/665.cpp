class Solution {
public:
    bool checkPossibility(vector<int>& a) {
		//非递减数列,当a[i]>a[i+1]时候要变换一次
		//考虑变小a[i]还是变大a[i+1]
		//这个要考虑前面的a[i-1]
		//1,3,2要将3变成1
		//2,3,1要将1变成3
		//如果是1,3,1那最好是把3变成1
		//而当i=0时候,不存在i-1索引,这个时候就直接把a[i]变成a[i+1]就完事了
		int len = a.size();
		if(len<3)
			return true;
		int cnt = 0;//变换次数
		if(a[0]>a[1]) {
			cnt++;
			a[0] = a[1];
		}
		for(int i=1;i<len-1;i++) {
			if(a[i]>a[i+1]) {
				cnt++;
				if(cnt>1)
					return false;
				if(a[i-1]<=a[i+1])
					a[i] = a[i+1];
				else
					a[i+1] = a[i];
			}
		}
		return true;
    }
};