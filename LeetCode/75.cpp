class Solution {
public:
    void sortColors(vector<int>& nums) {
		int p0,p2,cur;
		int len = nums.size();
		//跳过开头一堆连续的0
		for(p0=0;p0<len;p0++)
			if(nums[p0]!=0)
				break;
		//跳过结尾一堆连续的2
		for(p2=len-1;p2>=0;p2--)
			if(nums[p2]!=2)
				break;
		cur = p0;
		while(cur<=p2) {
			if(nums[cur]==0) {
				swap(nums[cur],nums[p0]);
				p0++;
				//这里防止死循环,防止0和0不断交换
				//即便没有0和0交换,那也是和1交换,交换完这里是1,下次循环检测一下还是会cur++
				cur++;
			}
			else if(nums[cur]==2) {
				swap(nums[cur],nums[p2]);
				p2--;
				//2和右边的交换了之后,这里可能是1也可能是2也可能是0,下次循环继续判断
			}
			else
				cur++;
		}
    }
};