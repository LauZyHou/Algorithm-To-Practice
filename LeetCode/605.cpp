class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
		int len = flowerbed.size()+2;
		vector<int> tmp(len);
		tmp[0] = tmp[len-1] = 0;
		for(int i=1;i<len-1;i++)
			tmp[i] = flowerbed[i-1];
		for(int i=1;i<len-1;i++)
			if(tmp[i-1]==0 && tmp[i]==0 && tmp[i+1]==0) {
				tmp[i] = 1;
				n--;
			}
		return n<=0;
    }
};