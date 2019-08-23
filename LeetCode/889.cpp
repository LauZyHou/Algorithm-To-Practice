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
					vector<int>& post,int t1,int t2) {
		if(e1>e2)//必定t1>t2
			return nullptr;
		if(e1==e2)
			return new TreeNode(pre[e1]);
		//关键:找左子树根在后序序列中的位置,以判定左子树节点数
		//注意:前序和后序不能唯一确定树,这里假定非叶子一定有左子树,所以e+1是左子树根
		int leftRootVal = pre[e1+1];
		int leftNum = 0;
		for(int i=t1;i<=t2;i++) {
			if(post[i]==leftRootVal) {
				leftNum = i-t1+1;//注意是节点数目,是相对值
				break;
			}
		}
		TreeNode* ret = new TreeNode(pre[e1]);
		ret->left = traceback(pre,e1+1,e1+1+leftNum-1,post,t1,t1+leftNum-1);
		ret->right = traceback(pre,e1+1+leftNum,e2,post,t1+leftNum,t2-1);
		return ret;
	}

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int elen = pre.size();
		int tlen = post.size();
		if(elen!=tlen || elen==0)
			return nullptr;
		return traceback(pre,0,elen-1,post,0,elen-1);//tlen==elen
    }
};