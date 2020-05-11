class Solution {
public:
    // 将A中上面n个盘子借助B移动到C
    void move(int n, vector<int>& A, vector<int>& B, vector<int>& C) {
        if(n==1) {
            int val = A.back();
            A.pop_back();
            C.push_back(val);
        }
        else {
            move(n-1, A, C, B);
            move(1, A, B, C);
            move(n-1, B, A ,C);
        }
    }
    void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        move(A.size(), A, B, C);
    }
};