#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
			if(pre.size()==0 || vin.size()==0 || pre.size()!=vin.size())
				return nullptr;

			TreeNode* root=new TreeNode(pre[0]);
			int len=vin.size();
			int pos=0;
			for(; pos<len; pos++) {
				if(vin[pos]==root->val)
					break;
			}
			root->left=this->recursive(1,pos,0,pos-1,pre,vin);
			root->right=this->recursive(pos+1,len-1,pos+1,len-1,pre,vin);
			return root;
		}

		TreeNode* recursive(int qxFst,int qxEnd,int zxFst,int zxEnd,vector<int>& pre,vector<int>& vin) {
			if(qxFst>qxEnd || zxFst>zxEnd)//***
				return nullptr;
			if(qxFst==qxEnd && zxFst==zxEnd)//***
				return new TreeNode(pre[qxFst]);
			int pos=zxFst;
			for(; pos<=zxEnd; pos++) {
				if(vin[pos]==pre[qxFst])
					break;
			}
			//前序不能用中序的pos
			int llen=pos-zxFst;
			int rlen=zxEnd-pos;
			TreeNode* nowRoot=new TreeNode(pre[qxFst]);
			if(llen>0)//***
				nowRoot->left=this->recursive(qxFst+1,qxFst+llen,zxFst,pos-1,pre,vin);
			if(rlen>0)//***
				nowRoot->right=this->recursive(qxEnd-rlen+1,qxEnd,pos+1,zxEnd,pre,vin);
			return nowRoot;
		}
};


void printTN(TreeNode* t) {
	if(nullptr==t) {
		cout<<"空结点\n";
	} else {
		cout<<"val:"<<t->val;
		cout<<",left:";
		if(t->left==nullptr)
			cout<<"空";
		else
			cout<<t->left->val;
		cout<<",right:";
		if(t->right==nullptr)
			cout<<"空";
		else
			cout<<t->right->val;
		cout<<endl;
	}
}

int main() {
	vector<int> pre,vin;
//	int a_pre[]={1,2,4,7,3,5,6,8};
//	int a_vin[]={4,7,2,1,5,3,8,6};
	int a_pre[]={1,2,3,4};
	int a_vin[]={4,3,2,1};
	int len=sizeof(a_pre)/sizeof(int);
	for(int i=0;i<len;i++){
		pre.push_back(a_pre[i]);
		vin.push_back(a_vin[i]);
	}

	Solution s;
	TreeNode* t=s.reConstructBinaryTree(pre,vin);

/*
	printTN(t);
	printTN(t->left);
	printTN(t->right);
	printTN(t->left->left);
	printTN(t->left->right);
	printTN(t->right->right);
*/

	printTN(t);
	printTN(t->left);
	printTN(t->left->left);

	return 0;
}

