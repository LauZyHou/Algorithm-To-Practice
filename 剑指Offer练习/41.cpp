#include<bits/stdc++.h>
using namespace std;

//用两个逻辑大小堆实现的,能获取中位数的数组 
template<typename T> class DynamicArray {
	public:
		//向数组中插入一个元素,即交替插入最大最小堆中的一个 
		void Insert(T num) {
			//如果数组中元素个数是偶数,不妨插入[右侧最小堆] 
			if(((min.size() + max.size()) & 1) == 0) {
				//如果数字比[左侧最大堆]的第一个元素(最大元素)小
				//那么只要[左侧最大堆]里还有元素,要考虑换一个出来 
				if(max.size() > 0 && num < max[0]) {
					max.push_back(num);//先将元素插入[左侧最大堆] 
					//push_heap可以对刚插入的尾部素做堆排序
					push_heap(max.begin(), max.end(), less<T>());
					
					//至此,[左侧最大堆]的最大元素就出现在了最左边 
					num = max[0];//这是替换出来的元素,将其记录下来 

					//将堆顶,即第一个(最大)元素移动到尾巴的位置 
					//同时将剩下的元素重新构造成(堆排序)一个新的heap
					pop_heap(max.begin(), max.end(), less<T>());
					//此时,[左侧最大堆]的最大元素就出现在了尾部,将其弹出 
					max.pop_back();
				}
				
				//也许做了替换,现在已经可以放心插入[右侧最小堆]了
				min.push_back(num);
				//push_heap可以对刚插入的尾部素做堆排序
				push_heap(min.begin(), min.end(), greater<T>());
			} 
			//如果数组中元素个数是奇数,不妨插入[左侧最大堆]
			else {
				//如果数字比[右侧最小堆]的第一个元素(最小元素)还大
				//那么只要[右侧最小堆]里还有元素,要考虑换一个出来 
				if(min.size() > 0 && min[0] < num) {
					min.push_back(num);//先将元素插入[右侧最小堆] 
					//push_heap可以对刚插入的尾部素做堆排序
					push_heap(min.begin(), min.end(), greater<T>());

					//至此,[右侧最小堆]的最小元素就出现在了最左边 
					num = min[0];//这是替换出来的元素,将其记录下来

					//将堆顶,即第一个(最小)元素移动到尾巴的位置 
					//同时将剩下的元素重新构造成(堆排序)一个新的heap
					pop_heap(min.begin(), min.end(), greater<T>());
					//此时,[右侧最小堆]的最小元素就出现在了尾部,将其弹出
					min.pop_back();
				}

				//也许做了替换,现在已经可以放心插入[左侧最大堆]了
				max.push_back(num);
				//push_heap可以对刚插入的尾部素做堆排序
				push_heap(max.begin(), max.end(), less<T>());
			}
		}
		//获取数组的中位数元素 
		T GetMedian() {
			//如果数组是空的,没法获取中位数 
			int size = min.size() + max.size();
			if(size == 0)
				throw exception();

			T median = 0;//存中位数的变量 
			if((size & 1) == 1)//如果数组内元素是奇数个
				//因为先插的小堆再插的大堆,小堆(右)比大堆(左)多一个元素 
				median = min[0];//这个元素就是[右侧最小堆]的最小元素 
			else//偶数个元素
				//两个堆一样多,取最近的两个元素求平均 
				median = (min[0] + max[0]) / 2;
			return median;
		}

	private:
		//用两个vector模拟堆,两堆元素数目之差不超过1 
		vector<T> min;//左侧最小堆 
		vector<T> max;//右侧最大堆 
};

int main() {
	DynamicArray<double> numbers;
	numbers.Insert(5);
	numbers.Insert(2);
	numbers.Insert(3);
	numbers.Insert(4);
	cout<<numbers.GetMedian()<<endl;
	numbers.Insert(0);
	cout<<numbers.GetMedian()<<endl;
	return 0;
}
