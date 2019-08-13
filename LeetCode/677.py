class MapSum:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.d = {}

    def insert(self, key: str, val: int) -> None:
        t = self.d
        for c in key:
            if c not in t:
                t[c] = {}
            t = t[c]
        t['value'] = val

    def sum(self, prefix: str) -> int:
        t = self.d
        for c in prefix:
            if c not in t:
                return 0
            t = t[c]
        ans = 0

        def dfs(t):
            for key in t:
                if key == 'value':
                    nonlocal ans
                    ans += t[key]
                else:
                    dfs(t[key])

        dfs(t)
        return ans

# Your MapSum object will be instantiated and called as such:
# obj = MapSum()
# obj.insert(key,val)
# param_2 = obj.sum(prefix)
