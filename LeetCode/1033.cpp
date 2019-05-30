class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        int m[] = {a,b,c};
		sort(m,m+3);
		a = m[0];
		b = m[1];
		c = m[2];
		vector<int> ans(2);
		ans[1] = c-b-1 + b-a-1;
		if(b-a==1 && c-b==1)
			ans[0] = 0;
		//这里注意2,4,6这里把2移动到5即可,仅仅一步
		//相应地,也可以把6移动到3,也只是一步
		//所以只要有相隔2的那就是移动一步就可以了
		else if(b-a==2 || c-b==2)
			ans[0] = 1;
		//如果相隔1的,又不是前面的情况
		//比如1,2,7,那么只能老实移动一端
		else if(b-a==1 || c-b==1)
			ans[0] = 1;
		//剩下的就是左边隔了,右边也隔了,两边都移动
		else
			ans[0] = 2;
		return ans;
    }
};