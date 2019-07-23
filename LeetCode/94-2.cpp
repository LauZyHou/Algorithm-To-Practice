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
    vector<int> inorderTraversal(TreeNode* root) {
		/*莫里斯遍历:线索二叉树*/
        vector<int> ans;
		TreeNode* curr = root;
		while(curr) {
			//如果没有左子树,这个结点就是当前要遍历的了(左中右没有左就是中了)
			if(curr->left==nullptr) {
				ans.push_back(curr->val);
				curr = curr->right;//往右走,因为左子树已经遍历完了(在自己头顶上)
			}
			//如果有左子树,要先遍历左子树,线索从左子树的最右结点指向当前节点
			//即遍历完左子树的最右结点,下一个结点就是当前节点
			else {
				//找到左子树最右侧的节点
				TreeNode* p = curr->left;
				while(p->right!=nullptr)
					p = p->right;
				//将当前节点挂在其(指左子树的最右结点)右边
				p->right = curr;
				//当前节点指针移动到左子树上,因为左中右,先左再中
				TreeNode * left = curr->left;
				curr->left = nullptr;//注意断开左侧到左子树的连接,才能在后续循环里判断
				curr = left;
			}
		}
		return ans;
    }
};