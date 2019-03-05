class Solution {
public:
    /**
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */
    void rotateString(string &str, int of) {
        int len = str.size();
		if(len==0)
			return;
		of = of % len;
		string s(len,'0');
		int i=0;
		while(i<of){
			s[i]=str[len-of+i];
			i++;
		}
		int k = 0;
		while(i<len){
			s[i++]=str[k++];
		}
		str = s;
    }
};