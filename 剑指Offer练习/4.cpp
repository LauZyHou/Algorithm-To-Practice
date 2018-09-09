#include<bits/stdc++.h>
using namespace std;

// 参数:
//        matrix:      一个二维数组
//        rows:        数组的行数 
//        columns:     数组的列数  
//        number:      要查找的数字 
// 返回值:
//        true表示找到了，false表示找不到 
bool Find(int* matrix, int rows, int columns, int number)
{
    bool found = false;//标识是否找到该数字 

    if(matrix != nullptr && rows > 0 && columns > 0)//输入合法性检查 
    {
    	//从数组右上角(0,columns-1)开始比较 
        int row = 0;
        int column = columns - 1;
        //行号在逐渐增大,列号在逐渐减小,谨防越界 
        while(row < rows && column >=0)
        {
        	//row*columns+column就是二维数组中第row行第column列的数字
			//如果这个数字和number一样,就已经找到它了 
            if(matrix[row * columns + column] == number)
            {
                found = true;//标识置为真 
                break;//退出循环 
            }
            //如果这个数字比要找的数字大 
            else if(matrix[row * columns + column] > number)
                -- column;//那么要刷去当前这一列,到左边的子二维数组去找 
            //如果这个数字比要找的数字小 
			else
                ++ row;//那么要刷去当前这一行,到下边的子二维数组去找
        }
    }

    return found;
}

int main(){
	//C++确定地初始化二维数组,则行数可以自动识别 
	int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
	cout<<boolalpha<<Find((int*)matrix, 4, 4, 7)<<endl;
	return 0;
}
