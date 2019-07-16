class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []

        def backtrack(s: str, left_num: int, right_num: int) -> None:
            """回溯过程"""
            if len(s) == 2 * n:
                ans.append(s)
                return
            if left_num < n:  # 只要左括号数目不超过N,就可以添加左括号
                backtrack(s + '(', left_num + 1, right_num)
            if right_num < left_num:  # 只要右括号数目没达到左括号数目,就可以添加右括号
                backtrack(s + ')', left_num, right_num + 1)

        backtrack("", 0, 0)
        return ans
