class Solution {
public:
    int maxProfit(vector<int>& v, int fee) {
		int len = v.size();
		if(len<2)
			return 0;
        int cash = 0;//当前不持有股票最大利润
		int hash = -v[0];//当前持有股票最大利润
		for(int i=1;i<len;i++) {
			cash = max(cash,hash+v[i]-fee);
			hash = max(hash,cash-v[i]);
		}
		return cash;//最后一定是不持有股票,即退出股市把最后一笔钱拿回来,利润最大
    }
};