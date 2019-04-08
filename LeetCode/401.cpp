class Solution {
private:
	vector<string> ans;
	set<string> hs;//小时
	set<string> ms;//分钟
	int h[4] = {1,2,4,8};
	int m[6] = {1,2,4,8,16,32};
	
	//生成小时,还需要取a个数,现在索引在i,当前hnow小时
	void genhs(int a,int i,int hnow){
		if(4-i<a)//剩下的不够取
			return ;
		if(hnow>=12){//超出12小时
			return ;
		}
		else if(a==0){//取完
			hs.insert(to_string(hnow));
		}
		else{//没取完
			//两种情况
			//(1)索引i的数字取
			genhs(a-1,i+1,hnow+h[i]);
			//(2)索引i的数字不取
			genhs(a,i+1,hnow);
		}
	}

	//生成分钟
	void genms(int b,int i,int mnow){
		if(6-i<b || mnow>=60)
			return ;
		else if(b==0)
			ms.insert(mnow>=10?to_string(mnow):("0"+to_string(mnow)));
		else{
			genms(b-1,i+1,mnow+m[i]);
			genms(b,i+1,mnow);
		}
	}

	void genTime(int a,int b){//时钟a个,分钟b个
		genhs(a,0,0);
		genms(b,0,0);
	}
public:
    vector<string> readBinaryWatch(int num) {
		if(num>8)
			return ans;
		vector<string>().swap(ans);//clear
		int maxi = min(3,num);//时钟灯最多亮着个数
		for(int i=0;i<=maxi;i++){
			genTime(i,num-i);
			//根据生成的时间组合
			for(auto _h:hs)
				for(auto _m:ms)
					ans.push_back(_h+":"+_m);
			//清除上一轮生成的时间
			hs.clear();
			ms.clear();
		}
		return ans;
    }
};