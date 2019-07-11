vector<string> vv;

class Solution {
public:

struct cmp
{
	bool operator()(const int &a,const int &b) {
		//1 取内容子串
		int i=0;
		int vvalen = vv[a].size();
		for(;i<vvalen && vv[a][i]!=' ';i++)
			;
		string acontent = vv[a].substr(i);//a对应的日志的内容
		i=0;
		int vvblen = vv[b].size();
		for(;i<vvblen && vv[b][i]!=' ';i++)
			;
		string bcontent = vv[b].substr(i);//b对应的日志的内容
		//比较两个内容串
		int cmp = acontent.compare(bcontent);
		if(cmp<0)
			return true;
		else if(cmp>0)
			return false;
		//两个内容串相同时,直接比较整个日志
		if(vv[a].compare(vv[b])<0)
			return true;
		return false;//这里不可能有两个日志完全相同,直接返回false了
	}
};

	//用于为字母日志索引排序的比较函数
	/*
	static bool mycmp(const int &a,const int &b) {

	}
	*/

    vector<string> reorderLogFiles(vector<string>& v) {
		vv = v;//复制到成员里,给比较函数用
        int len = v.size();
		int nums = 0;//统计数字日志的个数
		for(string s:v) {
			int slen = s.size();
			if(s[slen-1]<='9' && s[slen-1]>='0')
				nums++;
		}
		vector<int> nv(nums);//存数字日志的索引
		int n=0;
		vector<int> wv(len-nums);//存字母日志的索引
		int w=0;
		//记录索引
		for(int i=0;i<len;i++) {
			int slen = v[i].size();
			if(v[i][slen-1]<='9' && v[i][slen-1]>='0')
				nv[n++] = i;
			else
				wv[w++] = i;
		}
		//对字母日志的索引排序
		sort(wv.begin(),wv.end(),cmp());
		//构造结果
		vector<string> ans(len);
		int j=0;
		for(int i=0;i<w;i++)
			ans[i] = v[wv[j++]];
		j=0;
		for(int i=0;i<n;i++)
			ans[i+w] = v[nv[j++]];
		return ans;
    }
};