class Solution {
public:
    /**
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1, index2] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &v, int t) {
        //使用一个map来保存target减去数组中的结果
		//然后判断下一个数是否存在这个结果的dict之中
		map<int,int> hs;
		vector<int> ans;
		int len = v.size();
		for(int i=0;i<len;i++)
			if(hs.count(v[i])){
				ans.push_back(hs[v[i]]);
				ans.push_back(i);
				break;
			}else{
				hs[t-v[i]] = i;
			}
		return ans;
    }
};