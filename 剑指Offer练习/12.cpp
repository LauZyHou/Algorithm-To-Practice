#include<bits/stdc++.h>
using namespace std;


// 参数:
//        matrix:      字符矩阵首地址
//        rows:        矩阵的行数
//        cols:        矩阵的列数
//        row:         当前行
//        col:         当前列
//        str:         要检验的字符序列数组
//        pathLength:  当下这个点匹配的路径长度
//        visited:     访问情况矩阵
// 返回值:
//        继续向后匹配,true表示成功匹配,false表示匹配失败
bool hasPathCore(const char* matrix, int rows, int cols, int row,
                 int col, const char* str, int& pathLength, bool* visited) {
	if(str[pathLength] == '\0')//如果已经匹配完整个字符序列,到结尾了
		return true;//自然直接返回true,表示已完成整个字符串匹配

	bool hasPath = false;//记录是否存在该位置的匹配
	//如果游标在合法范围内,且这个位置的值正好匹配,且没有访问过
	if(row >= 0 && row < rows && col >= 0 && col < cols
	        && matrix[row * cols + col] == str[pathLength]
	        && !visited[row * cols + col]) {
		++pathLength;//路径向前+1
		visited[row * cols + col] = true;//将这个位置标记为访问过了

		//递归调用自身,向左/上/右/下四个方向匹配
		hasPath = hasPathCore(matrix, rows, cols, row, col - 1,
		                      str, pathLength, visited)
		          || hasPathCore(matrix, rows, cols, row - 1, col,
		                         str, pathLength, visited)
		          || hasPathCore(matrix, rows, cols, row, col + 1,
		                         str, pathLength, visited)
		          || hasPathCore(matrix, rows, cols, row + 1, col,
		                         str, pathLength, visited);
		//如果四个方向都不存在匹配,说明这个位置走错了
		if(!hasPath) {
			--pathLength;//向后倒退一步
			visited[row * cols + col] = false;//这个位置取消标记
		}
	}
	return hasPath;//返回从这个位置能否完成匹配
}

// 参数:
//        matrix:      字符矩阵首地址
//        rows:        矩阵的行数
//        cols:        矩阵的列数
//        str:         要检验的字符序列数组
// 返回值:
//        true表示找到,false表示找不到
bool hasPath(const char* matrix, int rows, int cols, const char* str) {
	//输入合法性检查
	if(matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
		return false;

	//和字符矩阵大小一样的布尔值矩阵,用来标识某个位置是否访问过了
	bool *visited = new bool[rows * cols];
	memset(visited, 0, rows * cols);//设置为0即设置为false

	int pathLength = 0;//路径的长度,初始设为0
	//遍历整个矩阵
	for(int row = 0; row < rows; ++row) {
		for(int col = 0; col < cols; ++col) {
			//调用匹配的函数,从矩阵上的每个点开始尝试能否完成匹配
			if(hasPathCore(matrix, rows, cols, row, col, str,
			               pathLength, visited)) {
			    delete[] visited;//书上的代码缺这一行,成功的情况也要正确回收 
				return true;
				//只要完成一次匹配就返回true了,所以不用再清除标记矩阵
				//而是将其彻底回收 
			}
		}
	}
	delete[] visited;//释放辅助矩阵的空间
	return false;//运行至此,说明匹配失败,返回false 
}


//ABTG
//CFCS
//JDEH
int main() {
	const char* matrix = "ABTGCFCSJDEH";
	const char* str = "BFCE";
	cout<<boolalpha<<hasPath(matrix,4,4,str)<<endl;
	return 0;
}

