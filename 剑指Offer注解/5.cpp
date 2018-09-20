#include<bits/stdc++.h>
using namespace std;

// 参数:
//        str:         原字符数组 
//        length:      字符数组的总容量
// 返回值:
//        没有返回值,在原字符数组上直接操作 
void ReplaceBlank(char str[], int length)
{
	//输入合法性校验 
    if(str == nullptr && length <= 0)
        return;

    int originalLength = 0;//字符串str的实际长度
    int numberOfBlank = 0;//字符串中空格的数目 
    int i = 0;//游标 
    //遍历整个字符串 
    while(str[i] != '\0')
    {
        ++ originalLength;//记录实际长度 

		//记录空格数目 
        if(str[i] == ' ')
            ++ numberOfBlank;

        ++ i;//游标移动,其实可以将i优化掉,直接用originalLength
    }

	//把空格替换成'%20'之后的长度为当前长度+空格数目*2 
    int newLength = originalLength + numberOfBlank * 2;
    //如果替换后长度超过了字符数组总容量,无法完成替换 
    if(newLength > length)
        return;

	//原串游标:初始本应在原串长度-1,但要考虑到'\0'所以不减1 
    int indexOfOriginal = originalLength;
    //新串游标:初始本应在计算出的新串长度-1,但要考虑到'\0'所以不减1 
    int indexOfNew = newLength;
    //当新串游标>原串游标>=0时,复制替换操作尚未结束 
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
    	//当原串游标移动到空格时 
        if(str[indexOfOriginal] == ' ')
        {
        	//在新串游标位置向前倒着打上%20 
            str[indexOfNew --] = '0';
            str[indexOfNew --] = '2';
            str[indexOfNew --] = '%';
        }
        //如果是空格以外的其它字符 
        else
        {
        	//直接替换掉新串的对应位置 
            str[indexOfNew --] = str[indexOfOriginal];
        }

        -- indexOfOriginal;//这里统一维护原串游标,可以省略而放到前面的操作里去 
    }
}

int main(){
	const int length = 100;
	//测试前面空格/中间空格/连续空格/末尾空格 
	char str[length] = " L Z   H ";
	ReplaceBlank(str,length);
	int i=0;
	while('\0'!=str[i]){
		cout<<str[i];
		i++;
	}
	return 0;
}
