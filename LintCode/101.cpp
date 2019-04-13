class Solution {
public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &v) {
		const int lx = 2;//连续的个数
        int len = v.size();
		if(len<lx)
			return 0;
		int r = lx;//新插入的位置
		//判断前面的有几个连续,连续的是谁
		int cnt = 1;
		int t = v[r-1];
		for(int i=r-2;i>=0;i--){
			if(v[i]!=t)
				break;
			cnt++;
		}
		for(int i=r;i<len;i++){
			if(v[i]==t){
				cnt++;
			}else{
				cnt = 1;
				t = v[i];
			}
			if(cnt<=2)
				v[r++] = v[i];
		}
		v.resize(r);
		return r;
    }
};