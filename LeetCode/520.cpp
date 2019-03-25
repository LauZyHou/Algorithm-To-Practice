class Solution {
public:
    bool detectCapitalUse(string word) {
		int len = word.size();
		if(len<1)
			return false;
		char fnt = word[0];
		if(fnt>='a' && fnt<='z'){
			for(int i=1;i<len;i++)
				if(word[i]<'a' || word[i]>'z')
					return false;
		}else if(fnt>='A' && fnt<='Z'){
			if(len==1)
				return true;
			int scd = word[1];
			if(scd>='a' && scd<='z'){
				for(int i=2;i<len;i++)
					if(word[i]<'a' || word[i]>'z')
						return false;
			}else if(scd>='A' && scd<='Z'){
				for(int i=2;i<len;i++)
					if(word[i]<'A' || word[i]>'Z')
						return false;
			}else
				return false;
		}else{
			return false;
		}
		return true;
    }
};