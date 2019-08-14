class Solution:
    def intervalIntersection(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        ans = []
        alen = len(A)
        blen = len(B)
        i = 0
        j = 0
        while i < alen and j < blen:
            max_left = max(A[i][0], B[j][0])
            min_right = min(A[i][1], B[j][1])
            if max_left <= min_right:
                ans.append([max_left, min_right])
            if A[i][1] < B[j][1]:
                i += 1
            else:
                j += 1
        return ans
