class Solution:
    def arrangeWords(self, text: str) -> str:
        mylist = text.split(" ")
        mylist = [s.lower() for s in mylist]
        mylist.sort(key=lambda x: len(x))
        if len(mylist) > 0:
            mylist[0] = mylist[0][0:1].upper() + mylist[0][1:]
        return " ".join(mylist)