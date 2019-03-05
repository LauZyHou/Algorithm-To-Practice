class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> v;
		int len = ops.size();
		for(int i=0;i<len;i++){
			if(strcmp(ops[i].c_str(),"C")==0){
				if(v.size())
					v.pop_back();
			}
			else if(strcmp(ops[i].c_str(),"D")==0){
				if(v.size()>0)
					v.push_back(2*v[v.size()-1]);
			}
			else if(strcmp(ops[i].c_str(),"+")==0){
				if(v.size()>0)
					v.push_back(v[v.size()-1]);
				if(v.size()>1)
					v[v.size()-1]+=v[v.size()-3];
			}
			else{
				int num;
				stringstream stream(ops[i]);
				stream>>num;
				v.push_back(num);
			}
		}
		//cal sum
		int sum = 0;
		int vlen = v.size();
		for(int i=0;i<vlen;i++)
			sum+=v[i];
		return sum;
    }
};