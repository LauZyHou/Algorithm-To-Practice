class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []

        # 这里生成字符串和验证字符串都先用列表,最后再变成str
        def gen(A):
            """生成"""
            if len(A) == 2 * n:
                if valid(A):
                    ans.append("".join(A))
            else:
                # 后面接上左或者右括号,然后在这个基础上继续生成
                A.append('(')
                gen(A)
                A.pop()
                A.append(')')
                gen(A)
                A.pop() # 注意这里也要退格回去,Python中都是引用传递

        def valid(A):
            """验证"""
            balance = 0  # 左括号减去右括号的数目
            for c in A:
                if c == '(':
                    balance += 1
                else:
                    balance -= 1
                if balance < 0:  # 出现了无法匹配的右括号
                    return False
            return balance == 0  # 如果出现无法匹配的左括号,这里会大于0

        gen([])
        return ans
