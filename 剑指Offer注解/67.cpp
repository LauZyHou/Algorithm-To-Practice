#include<bits/stdc++.h>
using namespace std;

enum Status {kValid = 0, kInvalid};//枚举值表示状态:未出错,出错 
int g_nStatus = kValid;//全局变量记录是否出错,默认是未出错 

//minus指示是否为负,digit是未经检查的纯数字串
//转换成long long类型的数字,这样能在一定程度上检测是否int溢出
//如果直接用int,完全不能检测int自己的溢出... 
long long StrToIntCore(const char* digit, bool minus) {
	long long num = 0;//用来保存转换后的数字 

	while(*digit != '\0') {//没到串结束符 
		if(*digit >= '0' && *digit <= '9') {//在0~9这个合法范围内 
			int flag = minus ? -1 : 1;//是负的后面就要乘以-1 
			//高位*10+低位 
			num = num * 10 + flag * (*digit - '0');//这里直接在每一位上乘了flag 
			
			//正数溢出,或者负数溢出
			//一个好处是及时判断,快速失败
			//另一好处是,本来long long只能在一定程度上检测是否int溢出
			//(即如果long long自己溢出了就可能检测不到int溢出了)
			//这里及时判断一定可以检测int溢出
			//因为long long比int的范围多了不止一位数 
			if((!minus && num > 0x7FFFFFFF)
			        || (minus && num < (signed int)0x80000000)) {
				num = 0;//没法转换,就给个0 
				break;//跳出循环 
			}

			digit++;//这一位转换完了,往后走一位 
		} else {//如果有字符不在合法范围 
			num = 0;//没法转换,就给个0 
			break;//跳出循环 
		}
	}

	if(*digit == '\0')//正常结束循环的标识 
		g_nStatus = kValid;//记录可以成功转换 

	return num;
}

//字符串转整数 
int StrToInt(const char* str) {//这里const指针防止修改字符串的值 
	g_nStatus = kInvalid;//先设置为出错状态 
	long long num = 0;//转换来的整数 

	if(str != nullptr && *str != '\0') {//不是空指针也不是空串 
		bool minus = false;//指示是否是负数,默认不是 
		//这里基本就是写个Parser 
		if(*str == '+')//如果是+号开头 
			str ++;//跳过加号
		else if(*str == '-') {//-号开头 
			str ++;//跳过减号 
			minus = true;//记录是负数 
		}
		
		//至此,正负记录完毕,指针应该指向数字部分最高位 
		
		if(*str != '\0')//检查一下不是串结束符 
			num = StrToIntCore(str, minus);//从该位置开始调用纯数字的转换 
	}

	return (int)num;//long long转成int,溢出检查已经在Core里做了 
}

int main() {
	cout<<StrToInt("-2147483648")<<endl;//有效的最小负整数,0x80000000
	return 0;
}
