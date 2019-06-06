class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
		//降序排列
		sort(A.begin(),A.end(),[](int a,int b)->bool{
			return a>b;
		});
		do
		{
			int h = A[0]*10+A[1];
			int m = A[2]*10+A[3];
			if(h<24 && m<60) {
				string sh = to_string(h);
				string sm = to_string(m);
				return string(2-sh.size(),'0') + sh + ':' + string(2-sm.size(),'0') + sm;
			}
		}
		while(prev_permutation(A.begin(),A.end()));//字典序降序全排列
		return "";
    }
};