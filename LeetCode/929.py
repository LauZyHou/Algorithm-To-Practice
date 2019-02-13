import re


class Solution(object):
    def numUniqueEmails(self, emails):
        """
        :type emails: List[str]
        :rtype: int
        """
        st = set()
        for e in emails:
            lst = e.split("@")
            lst[0] = lst[0].replace(".", "")
            lst[0] = lst[0].split("+")[0]
            ok = lst[0] + "@" + lst[1]
            st.add(ok)
        return len(st)


if __name__ == '__main__':
    pass
