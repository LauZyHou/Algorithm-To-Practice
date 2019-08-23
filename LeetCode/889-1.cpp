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
public:
	TreeNode* traceback(vector<int>& pre,int e1,int e2,
						vector<int>& rpost,int t1,int t2) {
		if(e1>e2)
			return nullptr;
		TreeNode* t = new TreeNode(pre[e1]);//pre[e1]==rpost[t1]
		if(e1==e2)
			return t;
		else if(pre[e1+1]==rpost[t1+1]) {//说明有一边是null,不妨都放到左子树
			t->left = traceback(pre,e1+1,e2,rpost,t1+1,t2);
		} else {
			//还是找左右子树分割点
			//在"中左右"中找"右"的开始点
			int rBgnZZY=e1+2;
			for(;rBgnZZY<=e2;rBgnZZY++)
				if(pre[rBgnZZY]==rpost[t1+1])
					break;
			//在"中右左"中找"左"的开始点
			int lBgnZYZ=t1+2;
			for(;lBgnZYZ<=t2;lBgnZYZ++)
				if(rpost[lBgnZYZ]==pre[e1+1])
					break;
			t->left = traceback(pre,e1+1,rBgnZZY-1,rpost,lBgnZYZ,t2);
			t->right = traceback(pre,rBgnZZY,e2,rpost,t1+1,lBgnZYZ-1);
		}
		return t;
	}

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int elen = pre.size();
		int tlen = post.size();
		if(elen!=tlen || elen==0)
			return nullptr;
		reverse(post.begin(),post.end());
		return traceback(pre,0,elen-1,post,0,tlen-1);
    }
};