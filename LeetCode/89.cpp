//https://leetcode-cn.com/problems/gray-code/solution/jian-dan-de-si-lu-44ms-by-dannnn/
class Solution {
public:
	vector<int> ans;
	int n;

	void traceback(vector<int>& p,int w,bool tb) {
		/*p:回溯的数组,w:当前在该数组哪一位,tb:top or bottom,true表示走上面的路*/
		if(w==n) {
			int val = 0;
			for(int i=0;i<n;i++) {
				val <<=1;
				val += p[i];
			}
			ans.push_back(val);
			return ;
		}
		//先上0下1,再上1下0
		if(tb) {
			p[w] = 0;
			traceback(p,w+1,true);
			p[w] = 1;
			traceback(p,w+1,false);
		} else {
			p[w] = 1;
			traceback(p,w+1,true);
			p[w] = 0;
			traceback(p,w+1,false);
		}
	}

    vector<int> grayCode(int n) {
		ans = vector<int>();
		if(!n) {
			ans.push_back(0);
			return ans;
		}
		this->n = n;
		vector<int> p(n);
		traceback(p,0,true);//一开始走上面
		return ans;
    }
};