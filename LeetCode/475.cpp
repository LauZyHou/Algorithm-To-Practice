/*
对每个房子找到最近的供暖器坐标(左边/右边里面离它近的)
对每个房子求到最近供暖器的距离
*/
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
		int ans = 0;
        //测试用例中headers没排序
		sort(heaters.begin(),heaters.end());
		int len = houses.size();
		for(int i=0;i<len;i++) {
			int distance = INT_MAX;
			//求大于当前元素值的第一个迭代器
			auto larger = lower_bound(heaters.begin(),heaters.end(),houses[i]);
			//找到了这样一个供暖器
			if(larger!=heaters.end()) {
				distance = *larger - houses[i];
			}
			//判断一下这个供暖期是不是第一个,只要不是第一个,那么房子左边一定还有个供暖期
			if(larger!=heaters.begin()) {
				distance = min(distance,houses[i]-*(larger-1));
			}
			ans = max(ans,distance);
		}
		return ans;
    }
};