#include<bits/stdc++.h>
using namespace std;

bool scanUnsignedInteger(const char** str);
bool scanInteger(const char** str);

// 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，其中A和C都是
// 整数（可以有正负号，也可以没有），而B是一个无符号整数
bool isNumeric(const char* str) {
	//输入非空校验 
	if(str == nullptr)
		return false;
	//在开头尝试扫描一下有符号整数 
	//如果扫描到就扫完了A,接下来要遇到.B或者指数部分或者啥也没有 
	//如果没扫到,接下来就必须要遇到.B 
	bool numeric = scanInteger(&str);//在这个函数内会移动str(字符串的一级指针) 

	//如果出现'.',则接下来是数字的小数部分,即B部分 
	if(*str == '.') {
		++str;//越过这个'.'
		 
		//如果之前numeric为真,说明扫过了A,即便有.有没有B也无所谓,如'233.'即233.0合法 
		//没扫过A时,一定要扫'.'然后扫B部分,扫B部分用无符号整数,如'.233'即0.233合法 
		numeric = scanUnsignedInteger(&str) || numeric;
	}
	
	//如果没有扫到A也没有出现'.',这时候已经非法了
	//可以在这里直接返回,但后面的代码也适用,不会将false变成true
	//书上就是没有直接返回,接着用后面的代码,因为都是与运算,所以没关系 
	//总之,到现在为止如果numeric为true最后不一定true,但是为false最后一定false了 
	
	//所以不妨加个剪枝提高效率
	if(!numeric)
		return false;
	//注意!加了这个剪枝以后,后面实际上就没必要再和numeric做&&运算了,但这里还是保留书上的代码 
	
	//如果出现'e'或者'E',接下来跟着的是数字的指数部分
	if(*str == 'e' || *str == 'E') {
		++str;//越过这个'e'或者'E' 

		//下面一行代码用&&的原因:
		//当e或E前面没有数字时,整个字符串不能表示数字,例如.e1、e1；
		//当e或E后面没有整数时,整个字符串不能表示数字,例如12e、12e+5.4
		numeric = numeric && scanInteger(&str);
	}
	//当然也可以不出现指数部分,那么后面就要直接结束了
	
	//结束时还要判断一下已经走到了字符串结尾,而不会有遗留的未匹配到的部分 
	return numeric && *str == '\0';
}

//扫描无符号整数,传入一个字符串位置的二级指针,扫描成功返回true
//(对于B直接调用它,因为B不能带符号)
bool scanUnsignedInteger(const char** str) {
	const char* before = *str;//将当前扫描的起始地址记录下来
	//只要没到字符串末尾,而且出现的都是'0'~'9'之间的字符 
	while(**str != '\0' && **str >= '0' && **str <= '9')
		++(*str);//就一直向下扫描 
	return *str > before;//前面的循环至少进行一次才会大于,即整数必须存在
	//那么对于可以不存在这种情况(如A),应由函数的调用方来维护 
}

//扫描整数,传入一个字符串位置的二级指针,扫描成功返回true
//(对于A和C调用它,因为A和C是可以带符号的) 
bool scanInteger(const char** str) {
	if(**str == '+' || **str == '-')//如果以'+'或者'-'号开头
		++(*str);//让其一级指针+1以跳过这个符号,它是允许出现在头部的符号,也可以不出现 
	//此时这个二级指针指向的是那个+1后的一级指针了 
	return scanUnsignedInteger(str);//调用扫描无符号整数的方法,还是传入这个二级指针就行 
}

int main(){
	cout<<boolalpha<<isNumeric("1.79769313486232E+308")<<endl;
	cout<<boolalpha<<isNumeric(".e1")<<endl;
	return 0;
}
