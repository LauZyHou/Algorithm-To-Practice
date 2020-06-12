class Solution:
    def processer(self, a:str, b:str) -> bool:
        n = len(b)
        for i in range(n):
            if a[i] != b[i]:
                return False
        return True

    def isPrefixOfWord(self, sentence: str, t: str) -> int:
        slist = sentence.split(' ')
        for i,s in enumerate(slist):
            if len(s) < len(t):
                continue
            if self.processer(s, t):
                return i+1
        return -1