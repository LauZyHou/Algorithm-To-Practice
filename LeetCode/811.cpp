class Solution {
public:
	map<string,int> mp;
	vector<int> nums;//to every on in fake_c.(try ["654 yaw.lmm.ca","1225 lmm.ca"])

	void deal(string &a,int index){
		int len = a.size();
		//others(not contains the a itself)
		for(int i=0;i<len;i++){
			if(a[i]=='.'){
				string ok = a.substr(i+1,len-i-1);
				if(mp[ok])
					mp[ok] += nums[index];
				else
					mp[ok] = nums[index];
			}
		}
	}

    vector<string> subdomainVisits(vector<string>& c) {
		int len = c.size();
		vector<string> fake_c(len);//not capacity!!!!it is size!!!!
		//split and init num
		for(int i=0;i<len;i++){
			int slen = c[i].size();
			int j=0;
			for(;j<slen;j++)
				if(c[i][j]==' ' && c[i][j+1]!=' ')
					break;
			//get numstr
			string numstr = c[i].substr(0,j);
			//str to int
			stringstream stream(numstr);
			int num;
			stream>>num;
			//get urlstr
			string urlstr = c[i].substr(j+1,slen-j-1);
			//sto in map and fake_c vec
			if(mp[urlstr])
				mp[urlstr] += num;
			else
				mp[urlstr] = num;
			fake_c[i]=urlstr;//so not use push_back!!
			nums.push_back(num);
		}
		//deal with all url
		for(int i=0;i<len;i++)
			deal(fake_c[i],i);
		//gen answer
		vector<string> ans;
		map<string,int>::iterator it;
		for(it=mp.begin();it!=mp.end();it++){
			ans.push_back(to_string(it->second)+" "+it->first);
		}
		return ans;
    }
};