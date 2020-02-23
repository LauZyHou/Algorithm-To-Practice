class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> nodes(n); // 每个结点引用数
        for(int i=0;i<n;i++) {
            // 检查双向父亲,要保证有孩子的情况下检查
            if(leftChild[i]>0 && (rightChild[leftChild[i]]==i || leftChild[leftChild[i]]==i))
                return false;
            if(rightChild[i]>0 && (rightChild[rightChild[i]]==i || leftChild[rightChild[i]]==i))
                return false;
            // 同时统计父结点数
            if(leftChild[i]>0)
                nodes[leftChild[i]]++;
            if(rightChild[i]>0)
                nodes[rightChild[i]]++;
        }
        // 只有一个没有父结点,其他都只能有两个结点
        int nofather = 0;
        for(int i=0;i<n;i++) {
            if(nodes[i]==0)
                nofather++;
            else if(nodes[i]>=2)
                return false;
        }
        return nofather==1;
    }
};