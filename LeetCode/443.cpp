class Solution {
public:
    int compress(vector<char>& v) {
		int len = v.size();
		int ans = 0;
		for(int i=0;i<len;i++){
			char c = v[i];
			int num = 1;
			for(int j=i+1;j<len && v[j]==v[i];j++){
				num++;
			}
			v[ans++] = v[i];
			if(num>1){
				string num_s = to_string(num);
				for(auto cc : num_s){
					v[ans++] = cc;
				}
			}
			i += num-1;
		}
		return ans;
    }
};