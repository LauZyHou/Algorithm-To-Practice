class Solution {
public:
    bool lemonadeChange(vector<int>& b) {
        int len = b.size();
		int f5=0,f10=0;
		for(int i=0;i<len;i++){
			if(b[i]==5)
				f5++;
			else if(b[i]==10){
				if(f5==0)
					return false;
				f10++;
				f5--;
			}else if(b[i]==20){
				if(f10 && f5){
					f10--;
					f5--;
				}else if(f5>=3)
					f5-=3;
				else
					return false;
			}
		}
		return true;
    }
};