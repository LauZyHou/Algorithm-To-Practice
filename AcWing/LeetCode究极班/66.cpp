class Solution {
public:
    vector<int> add(vector<int>& A, int b) {
        vector<int> C;
        int t = b;
        for (int i = 0; i < A.size(); i ++) {
            t += A[i];
            C.emplace_back(t % 10);
            t /= 10;
        }
        while (t) {
            C.emplace_back(t % 10);
            t /= 10;
        }
        return C;
    }

    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        auto& C = add(digits, 1);
        reverse(C.begin(), C.end());
        return C;
    }
};