class Solution {
public:
    vector<int> findErrorNums(vector<int>& v) {
		int len = v.size();
		bool a[10001] = {false};
		int num;
		int yh = 0;
		for(int i=0;i<len;i++) {
			if(a[v[i]])
				num = v[i];
			a[v[i]] = true;
			yh ^= (i+1)^v[i];
		}
		//至此,num记录那个重复数字,yh是两数字的异或结果
		return vector<int>({num, yh^num});
	}
};