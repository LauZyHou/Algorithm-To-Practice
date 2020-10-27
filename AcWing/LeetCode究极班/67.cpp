class Solution {
public:
    // p进制高精度加法
    vector<int> add(vector<int>& A, vector<int>& B, int p) {
        if (A.size() < B.size())
            return add(B, A, p);
        
        vector<int> C;
        int t = 0;
        for (int i = 0; i < A.size(); i ++) {
            t += A[i];
            if (i < B.size())
                t += B[i];
            C.emplace_back(t % p);
            t /= p;
        }
        while (t) {
            C.emplace_back(t % p);
            t /= p;
        }
        return C;
    }

    string addBinary(string a, string b) {
        vector<int> A, B;
        for (int i = a.size() - 1; i >= 0; i --)
            A.emplace_back(a[i] - '0');
        for (int i = b.size() - 1; i >= 0; i --)
            B.emplace_back(b[i] - '0');
        const auto& C = add(A, B, 2);
        string res;
        for (int i = 0; i < C.size(); i ++)
            res = to_string(C[i]) + res;
        return res;
    }
};