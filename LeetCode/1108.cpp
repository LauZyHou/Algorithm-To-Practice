class Solution {
public:
	//将origin串中的所有字符c替换成字符串to
	string myReplace(string origin, char c, string to) {
		int olen = origin.size();
		int tlen = to.size();
		//计算一下字符c在origin中出现了多少次
		int cnum = 0;
		for(char oc : origin) {
			if(oc==c)
				cnum++;
		}
		//构造一个指定长度的串,然后从后往前写
		int rlen = olen+cnum*(tlen-1);
		char* ret = new char[rlen+1];
		ret[rlen] = '\0';
		int i = olen-1;
		int j = rlen-1;
		for(;i>=0;i--) {
			char now = origin[i];
			if(now!=c) {
				ret[j--] = now;
			}
			else {
				for(int k=tlen-1;k>=0;k--)
					ret[j--] = to[k];
			}
		}
		return string(ret);
	} 

    string defangIPaddr(string address) {
        return myReplace(address,'.',"[.]");
    }
};