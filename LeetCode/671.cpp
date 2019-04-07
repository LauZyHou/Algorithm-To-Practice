/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
	int a[2];
	int cnt;
public:
    int findSecondMinimumValue(TreeNode* root) {
        a[0] = a[1] = INT_MAX;
		cnt = 0;
		dfs(root);
		if(cnt<2 || a[0]==a[1])
			return -1;
		if(a[0]<a[1])
			return a[1];
		return a[0];
    }

	void dfs(TreeNode* r){
		if(!r)
			return ;
		dfs(r->left);
		if(r->val<a[0] || r->val<a[1]){
			if(r->val==a[0] || r->val==a[1])//如果已经记录过了,就不要再记录了
				;
			else {
				if(a[0]<a[1])
					a[1] = r->val;
				else
					a[0] = r->val;
				cnt++;//cnt用于记录对子改变了几次,至少两次才有"第二小"
				//如果不用这种方式,而用INT_MAX判断的话,当输入数据第二小是INT_MAX时就不对了
			}
		}
		dfs(r->right);
	}
};