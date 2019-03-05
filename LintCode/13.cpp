class Solution {
public:
    /**
     * @param source: 
     * @param target: 
     * @return: return the index
     */
	int *next = nullptr;
	int lens = 0;
	int lenp = 0;

	~Solution(){
		delete[] next;
		next = nullptr;
	}

	void gen_next(string &ptr){
		next[0] =  -1;
		int k = -1;
		//计算next[i],即i+1长度的ptr前子串的最长前后缀相同子串的size()-1
		for(int i=1;i<lenp;i++){
			while(k>-1 && ptr[k+1]!=ptr[i]){//(k,i)从(0,1),(1,2)..回退只回退k
				k = next[k];
			}
			//比较下一个
			if(ptr[k+1] == ptr[i])
				k++;
			next[i] = k;
		}
	}


    int strStr(string &str, string &ptr) {
        //use kmp algorithm
		lens = str.size();
		lenp = ptr.size();
		if(!lenp)
			return 0;
		if(!lens)//lenp>0
			return -1;
		next = new int[lenp];
		gen_next(ptr);
		int k = -1;
		//对str一遍跑,回退只回退k(和ptr的前k+1个匹配了)
		for(int i=0;i<lens;i++){
			while(k>-1 && ptr[k+1]!=str[i])//当前存在匹配的子串,且下一个不匹配,回退k再比较
				k = next[k];
			//遇到相同的往下匹配
			if(ptr[k+1]==str[i])
				k++;
			//匹配完ptr的所有字符
			if(k+1==lenp){
				delete[] next;
				next = nullptr;
				return i-lenp+1;//返回成功匹配的开始位置
			}
		}
		delete[] next;
		next = nullptr;
		return -1;
    }
};