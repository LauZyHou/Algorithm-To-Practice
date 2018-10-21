#include<bits/stdc++.h>
using namespace std;

//字符统计类 
class CharStatistics {
	public:
		//构造器初始化
		CharStatistics() : index(0) {//读入的下标从0开始 
			for(int i = 0; i < 256; ++i)
				occurrence[i] = -1;//初始化所有字符为"未出现" 
		}

		//读入一个字符ch时,更新状态表 
		void Insert(char ch) {
			if(occurrence[ch] == -1)//没读入过->读入了,记录读入到的下标 
				occurrence[ch] = index;
			else if(occurrence[ch] >= 0)//读入过->出现超过一次 
				occurrence[ch] = -2;
			index++;//读下一个位置的字符,位置+1 
		}

		//找出读到当前位置的第一次出现一次的字符 
		char FirstAppearingOnce() {
			char ch = '\0';//找不到就是'\0' 
			//编译器允许的最大int 
			int minIndex = numeric_limits<int>::max();
			//遍历哈希表,找到最小的那个非负数(出现位置)对应的字符 
			for(int i = 0; i < 256; ++i) {
				//非负(状态② )且小于当前找到的最小(不可能出现等于的情况) 
				if(occurrence[i] >= 0 && occurrence[i] < minIndex) {
					ch = (char) i;//更新字符 
					minIndex = occurrence[i];//更新最小下标 
				}
			}
			return ch;
		}

	private:
		// occurrence[i]: A character with ASCII value i;
		// occurrence[i] = -1: The character has not found;
		// occurrence[i] = -2: The character has been found for mutlple times
		// occurrence[i] >= 0: The character has been found only once
		int occurrence[256];//哈希表,occurrence是出现的意思 
		int index;
};

int main() {
	CharStatistics cs;
	cs.Insert('g');
	cout<<cs.FirstAppearingOnce()<<endl;//g
	cs.Insert('o');
	cout<<cs.FirstAppearingOnce()<<endl;//g
	cs.Insert('o');
	cout<<cs.FirstAppearingOnce()<<endl;//g
	cs.Insert('g');
	cout<<cs.FirstAppearingOnce()<<endl;//
	cs.Insert('l');
	cout<<cs.FirstAppearingOnce()<<endl;//l
	cs.Insert('e');
	cout<<cs.FirstAppearingOnce()<<endl;//l
	return 0;
}

