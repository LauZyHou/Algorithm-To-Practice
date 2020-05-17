class Solution:
    def peopleIndexes(self, favoriteCompanies: List[List[str]]) -> List[int]:
        ans = []
        favoriteCompanies = [set(f) for f in favoriteCompanies]
        n = len(favoriteCompanies)
        for i in range(n):
            isOk = True
            for j in range(n):
                if j==i:
                    continue
                if favoriteCompanies[i].issubset(favoriteCompanies[j]):
                    isOk = False
                    break
            if isOk:
                ans.append(i)
        return ans