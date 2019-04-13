class Solution {
public:
    /*
     * @param nums: An ineger array
     * @return: An integer
     */
    int removeDuplicates(vector<int> &v) {
        int len = v.size();
		if(!len)
			return 0;
		int r = 1;//下次覆盖的位置
		for(int i=1;i<len;i++){
			if(v[i]!=v[i-1]){
				v[r++] = v[i];
			}
		}
		v.resize(r);
		return r;
    }
};