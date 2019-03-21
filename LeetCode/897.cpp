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
    TreeNode* increasingBST(TreeNode* root) {
        //辅助栈模拟中序遍历,并将原树重排
		stack<TreeNode*> s;
		TreeNode* ans = new TreeNode(0);//用来挂ans单枝树(在右子树)
		TreeNode* p = ans;//指向当前挂节点的Node
		while(!s.empty() || root){
			if(root){//root表示遍历到的节点,一直向左,直到左边没有节点(到了左下)
				s.push(root);
				root = root->left;
			}else{
				//左下节点是当前要操作的节点cur
				TreeNode* cur = s.top();
				s.pop();
				//挂到ans上,p往下走
				p->right = cur;
				p = cur;//即p->right
				//下一个要遍历的是其右孩子(左中右没有左,或者左已经在之前的循环处理完了)
				root = cur->right;
				//清除左指针(无论如何已经处理过左孩子了)
				cur->left = nullptr;
			}
		}
		return ans->right;
    }
};