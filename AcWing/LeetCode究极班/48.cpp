class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // 对角线交换
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < i; j ++)
                swap(matrix[i][j], matrix[j][i]);
        
        // 左右交换
        for (int i = 0; i < n; i ++)
            for (int l = 0, r = n - 1; l < r; l ++, r --)
                swap(matrix[i][l], matrix[i][r]);
    }
};